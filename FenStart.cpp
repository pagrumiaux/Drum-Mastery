#include "fenstart.h"
#include "ui_fenstart.h"
#include "fenedition.h"
#include "ui_fenedition.h"
#include "fenentrainement.h"
#include "ui_fenentrainement.h"
#include "timer.h"

FenStart::FenStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenStart)
{
    ui->setupUi(this);

    QPalette p(palette());
    p.setBrush(QPalette::Window, QBrush(QPixmap(":/images/MesImages/pageStart.jpg")));
    setPalette(p); //Met l'image en fond d'écran
}

FenStart::~FenStart()
{
    delete ui;
}


//SLOTS de changement de page
void FenStart::on_boutonModeEntrainement_clicked() //pour passer de l'écran d'accueil à l'écran du mode entraînement
{
    FenEntrainement *fenetreEntrainement;
    fenetreEntrainement = new FenEntrainement;
    fenetreEntrainement->show();
    this->hide();
}

void FenStart::on_BoutonModePartition_clicked() //pour passer de l'écran d'accueil à l'écran du mode partition
{
    /*FenEdition *fenetreEdition;
    fenetreEdition = new FenEdition;
    fenetreEdition->show();
    this->hide();*/
}
