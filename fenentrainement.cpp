#include "fenentrainement.h"
#include "ui_fenentrainement.h"
#include "fenedition.h"
#include "ui_fenedition.h"
#include "fenstart.h"
#include "ui_fenstart.h"
#include "timer.h"
#include "sheet.h"
#include "boum.h"
#include <Windows.h>
#include <QKeyEvent>
#include "pa_asio.h"

FenEntrainement::FenEntrainement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenEntrainement)
{
    ui->setupUi(this);

    QPalette p(palette());
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/images/MesImages/fondEcranEntrainement.jpg")));
    setPalette(p); //Met l'image en fond d'écran

    ui->partition->setFocus();
    Boum *instanceDeBoum = new Boum;
    instanceDeBoum->moveToThread (&threadBoum);
    connect (&threadBoum, &QThread::finished,instanceDeBoum, &QObject::deleteLater);
    connect(this, &FenEntrainement::operate, instanceDeBoum, &Boum::doWork);
    connect(instanceDeBoum, &Boum::resultReady, this, &FenEntrainement::handleResults);
    connect(this, &FenEntrainement::timerLance, instanceDeBoum, &Boum::lancerTimer);
    QObject::connect(ui->partition,SIGNAL(changementPerformance(int)),ui->affichagePerformance,SLOT(display(int)));
    ui->partition->parentFenetre = this;
    ui->partition->uiParentFenetre = this->ui;
    threadBoum.start();
}

FenEntrainement::~FenEntrainement()
{
    delete ui;
    threadBoum.quit();
    threadBoum.wait();
}

//SLOTS pour passer de page en page
void FenEntrainement::on_boutonRetourMenu_clicked() //Bouton pour revenir à la page d'accueil depuis l'interface d'entraînement
{
    QMessageBox confirmationRetourMenu;
    confirmationRetourMenu.setText(tr("Etes-vous sûr de vouloir retourner à la page d'accueil ?"));
    confirmationRetourMenu.setWindowTitle("DrumMastery");
    QAbstractButton* boutonOui = confirmationRetourMenu.addButton(tr("Oui"), QMessageBox::YesRole);
    confirmationRetourMenu.addButton(tr("Annuler"), QMessageBox::RejectRole);

    confirmationRetourMenu.exec();

    if (confirmationRetourMenu.clickedButton()==boutonOui)
        {
            FenStart *fenetreDemarrage;
            fenetreDemarrage = new FenStart;
            fenetreDemarrage->show();
            this->hide();
         }
}

//SLOTS associés aux clics sur les boutons
void FenEntrainement::on_boutonPlayPause_clicked() //permet de passer du bouton play au bouton pause et inversement
{
    if (ui->partition->getMesure()->getNote() == NULL) //empêche de lancer le jeu si aucun fichier n'est chargé
    {
        QMessageBox erreurChargement;
        erreurChargement.setText(tr("Veuillez charger une partition"));
        erreurChargement.setWindowTitle("Attention");
        QAbstractButton* boutonOk = erreurChargement.addButton(tr("Ok"), QMessageBox::YesRole);

        erreurChargement.exec();

        if (erreurChargement.clickedButton()== boutonOk)
            {
            QDir::setCurrent("../fenetreEdition/MesPartitions");
            QString fichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir :: currentPath(), tr("Fichier Drum Mastery (*.dm);;All files (*.*)"));
            if(!fichier.isEmpty())
                {
                QFile file(fichier);
                if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                        return;
                QTextStream text(&file);
                ui->partition->load(&text);
                }
            ui->partition->setStarted(true);
             }
    }

    if (!ui->partition->getStarted()) //Si la partition n'est pas lancée, on la lance (copier coller de la partie lancement de "sheet.cpp")
    {
        ui->boutonPlayPause->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/pauseoff.png) 0 0 0 0 stretch stretch; border-width : 0px; background-position : center; min-width : 70px; max-width : 70px; min-height : 70px; max-height : 70px; color : transparent;}");
        this->operate(); //signal qui lance la fonction Boum grâce au connect
        ui->partition->setFocus();
        this->timerLance();
        ui->affichagePerformance->display(0);
        ui->partition->start();

    }

    else
    {
        ui->boutonPlayPause->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/playoff.png) 0 0 0 0 stretch stretch; border-width : 0px; background-position : center; min-width : 70px; max-width : 70px; min-height : 70px; max-height : 70px; color : transparent;}");
        ui->partition->stop();
    }
}


void FenEntrainement::on_ouvrirExploreur_clicked() //SLOT pour ouvrir l'exploreur
{
    QDir::setCurrent("../fenetreEdition/MesPartitions");
    QString fichier = QFileDialog::getOpenFileName(this, tr("Ouvrir un fichier"), QDir :: currentPath(), tr("Fichier Drum Mastery (*.dm);;All files (*.*)"));
    if(!fichier.isEmpty())
    {
        QFile file(fichier);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        ui->partition->load(&text);
    }
}

void FenEntrainement::on_boutonMetronome_clicked() //Pour activer ou désactiver le métronome
{
    if (ui->boutonMetronome->text() == "On")
    {
        ui->boutonMetronome->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/metronome_off.png) 0 0 0 0 stretch stretch; border-width : 0px; background-position : center; min-width : 70px; max-width : 70px; min-height : 70px; max-height : 70px; color : transparent;}");
        ui->boutonMetronome->setText("Off");
        ui->partition->setMetronome();

    }

    else
    {
        ui->boutonMetronome->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/metronome_on.png) 0 0 0 0 stretch stretch; border-width : 0px; background-position : center; min-width : 70px; max-width : 70px; min-height : 70px; max-height : 70px; color : transparent;}");
        ui->boutonMetronome->setText("On");
        ui->partition->setMetronome();
    }
}

void FenEntrainement::on_boutonVolume_valueChanged(int position)
{
    ui->partition->setKickVolume(position);
    ui->partition->setMetronomeVolume(position);
}

void FenEntrainement::on_boutonSonOn_clicked()
{
    if (ui->boutonSonOn->text() == "son_on")
    {
        ui->boutonSonOn->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/volumeOff.png) 0 0 0 0 stretch stretch; border-width : 10px; background-position : center; min-width : 50px; max-width : 50px; min-height : 50px; max-height : 50px; color : transparent;}");
        ui->boutonVolume->setSliderPosition(0);
        ui->boutonSonOn->setText("son_off");
    }

    else
    {
        ui->boutonSonOn->setStyleSheet("QPushButton{border-image : url(:/images/MesImages/volume.png) 0 0 0 0 stretch stretch; border-width : 0px; background-position : center; min-width : 70px; max-width : 70px; min-height : 70px; max-height : 70px; color : transparent;}");
        ui->boutonSonOn->setText("son_on");
        ui->boutonVolume->setSliderPosition(99);
    }
}

void simulationEspace ()
{
    //qDebug("espace simulé");
    //ui->partition->setFocus();
        INPUT simulationAppuiEspace [1];

                        simulationAppuiEspace[0].type = 1; //Pour dire que c'est un keyboard event.
                        simulationAppuiEspace[0].ki.wVk = VK_SPACE;
                        simulationAppuiEspace[0].ki.time = 0;

        INPUT simulationRelacheEspace [1];

                        simulationRelacheEspace[0].type = 1;
                        simulationRelacheEspace[0].ki.wVk = VK_SPACE;
                        simulationRelacheEspace[0].ki.dwFlags = KEYEVENTF_KEYUP;
                        simulationRelacheEspace[0].ki.time = 0;

        SendInput (1,simulationAppuiEspace, sizeof(simulationAppuiEspace));
        SendInput (1,simulationRelacheEspace, sizeof(simulationRelacheEspace));
}

void FenEntrainement::handleResults()
{
    //this->simulationEspace();
}


void FenEntrainement::on_boutonBpm_valueChanged(int bpm)
{
    ui->partition->setBpm(bpm);
    ui->partition->setDuree1Temps(bpm);
    ui->partition->setDuree1Mesure(bpm);
    ui->partition->getZoneColoree()->setDuree1Mesure(bpm);
}

