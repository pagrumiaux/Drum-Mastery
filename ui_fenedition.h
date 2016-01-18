/********************************************************************************
** Form generated from reading UI file 'fenedition.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENEDITION_H
#define UI_FENEDITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timer.h>

QT_BEGIN_NAMESPACE

class Ui_FenEdition
{
public:
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QFrame *line_4;
    QPushButton *annuler;
    QPushButton *retablir;
    QSpacerItem *horizontalSpacer;
    QPushButton *boutonRetourArriere;
    QPushButton *boutonLangueFr;
    QPushButton *boutonAide;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *boutonPlayPause;
    QPushButton *record;
    QPushButton *stop;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *nouveau;
    QPushButton *ouvrirExploreur;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *boutonSonOn;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_20;
    QPushButton *boutonMetronome;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_23;
    QLabel *tempo;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_22;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QLabel *blanche;
    QSpacerItem *horizontalSpacer_7;
    QLabel *noire;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *doubleCroche;
    QSpacerItem *horizontalSpacer_10;
    QLabel *croche;
    QSpacerItem *horizontalSpacer_11;
    QLabel *tripleCroche;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QLabel *soupir;
    QSpacerItem *horizontalSpacer_14;
    QLabel *demiSoupir;
    QSpacerItem *horizontalSpacer_15;
    QLabel *quartDeSoupir;
    QSpacerItem *horizontalSpacer_16;
    QLabel *huitiemeDeSoupir;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_17;
    QLabel *pause;
    QSpacerItem *horizontalSpacer_19;
    QLabel *demiPause;
    QSpacerItem *horizontalSpacer_18;
    Timer *PartitionEdition;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_6;

    void setupUi(QWidget *FenEdition)
    {
        if (FenEdition->objectName().isEmpty())
            FenEdition->setObjectName(QStringLiteral("FenEdition"));
        FenEdition->resize(1425, 700);
        FenEdition->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color : white;\n"
"}"));
        verticalLayoutWidget = new QWidget(FenEdition);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, -10, 1401, 76));
        horizontalLayout = new QHBoxLayout(verticalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        line_4 = new QFrame(verticalLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        annuler = new QPushButton(verticalLayoutWidget);
        annuler->setObjectName(QStringLiteral("annuler"));
        annuler->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/annuler.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout->addWidget(annuler);

        retablir = new QPushButton(verticalLayoutWidget);
        retablir->setObjectName(QStringLiteral("retablir"));
        retablir->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/retablir.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout->addWidget(retablir);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        boutonRetourArriere = new QPushButton(verticalLayoutWidget);
        boutonRetourArriere->setObjectName(QStringLiteral("boutonRetourArriere"));
        boutonRetourArriere->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/retour_arriere.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout->addWidget(boutonRetourArriere);

        boutonLangueFr = new QPushButton(verticalLayoutWidget);
        boutonLangueFr->setObjectName(QStringLiteral("boutonLangueFr"));
        boutonLangueFr->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/Fr.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width :70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout->addWidget(boutonLangueFr);

        boutonAide = new QPushButton(verticalLayoutWidget);
        boutonAide->setObjectName(QStringLiteral("boutonAide"));
        boutonAide->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/Aide.png) 0 0 0 0 stretch stretch;\n"
"border-width : 2px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"border-color : red;\n"
"border-style : solid;\n"
"}"));

        horizontalLayout->addWidget(boutonAide);

        horizontalLayoutWidget = new QWidget(FenEdition);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(360, 80, 1051, 74));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        boutonPlayPause = new QPushButton(horizontalLayoutWidget);
        boutonPlayPause->setObjectName(QStringLiteral("boutonPlayPause"));
        boutonPlayPause->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/playoff.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(boutonPlayPause);

        record = new QPushButton(horizontalLayoutWidget);
        record->setObjectName(QStringLiteral("record"));
        record->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/plyoff.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(record);

        stop = new QPushButton(horizontalLayoutWidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesIages/playoff.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(stop);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_24);

        nouveau = new QPushButton(horizontalLayoutWidget);
        nouveau->setObjectName(QStringLiteral("nouveau"));
        nouveau->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/nouveau.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(nouveau);

        ouvrirExploreur = new QPushButton(horizontalLayoutWidget);
        ouvrirExploreur->setObjectName(QStringLiteral("ouvrirExploreur"));
        ouvrirExploreur->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/ouvrir.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(ouvrirExploreur);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/save.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayoutWidget_2 = new QWidget(FenEdition);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 78, 341, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_21);

        boutonSonOn = new QPushButton(verticalLayoutWidget_2);
        boutonSonOn->setObjectName(QStringLiteral("boutonSonOn"));
        boutonSonOn->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/volume.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width :70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_3->addWidget(boutonSonOn);

        horizontalSlider = new QSlider(verticalLayoutWidget_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_20);

        boutonMetronome = new QPushButton(verticalLayoutWidget_2);
        boutonMetronome->setObjectName(QStringLiteral("boutonMetronome"));
        boutonMetronome->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/metronome_on.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_4->addWidget(boutonMetronome);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_23);

        tempo = new QLabel(verticalLayoutWidget_2);
        tempo->setObjectName(QStringLiteral("tempo"));
        tempo->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"border-image : url(:/images/MesImages/tempo.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));
        tempo->setPixmap(QPixmap(QString::fromUtf8(":/images/MesImages/tempo.png")));

        horizontalLayout_9->addWidget(tempo);

        spinBox = new QSpinBox(verticalLayoutWidget_2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setStyleSheet(QLatin1String("QSpinBox\n"
"{\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 30px;\n"
"max-height : 30px;\n"
"}"));
        spinBox->setMinimum(60);
        spinBox->setMaximum(200);
        spinBox->setValue(120);

        horizontalLayout_9->addWidget(spinBox);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_22);


        verticalLayout->addLayout(horizontalLayout_9);

        line_5 = new QFrame(verticalLayoutWidget_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        blanche = new QLabel(verticalLayoutWidget_2);
        blanche->setObjectName(QStringLiteral("blanche"));
        blanche->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/blanche.gif")));

        horizontalLayout_5->addWidget(blanche);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);

        noire = new QLabel(verticalLayoutWidget_2);
        noire->setObjectName(QStringLiteral("noire"));
        noire->setEnabled(true);
        noire->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/noire.gif")));

        horizontalLayout_5->addWidget(noire);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        doubleCroche = new QLabel(verticalLayoutWidget_2);
        doubleCroche->setObjectName(QStringLiteral("doubleCroche"));
        doubleCroche->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/double-croche.gif")));

        horizontalLayout_6->addWidget(doubleCroche);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);

        croche = new QLabel(verticalLayoutWidget_2);
        croche->setObjectName(QStringLiteral("croche"));
        croche->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"height : 200px;\n"
"}"));
        croche->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/croche.gif")));

        horizontalLayout_6->addWidget(croche);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        tripleCroche = new QLabel(verticalLayoutWidget_2);
        tripleCroche->setObjectName(QStringLiteral("tripleCroche"));
        tripleCroche->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/triple-croche.png")));

        horizontalLayout_6->addWidget(tripleCroche);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/notes/MesNotes/tripleCroche.jpg) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_6->addWidget(pushButton_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        soupir = new QLabel(verticalLayoutWidget_2);
        soupir->setObjectName(QStringLiteral("soupir"));
        soupir->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/soupir.png")));

        horizontalLayout_7->addWidget(soupir);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_14);

        demiSoupir = new QLabel(verticalLayoutWidget_2);
        demiSoupir->setObjectName(QStringLiteral("demiSoupir"));
        demiSoupir->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/demi-soupir.png")));

        horizontalLayout_7->addWidget(demiSoupir);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_15);

        quartDeSoupir = new QLabel(verticalLayoutWidget_2);
        quartDeSoupir->setObjectName(QStringLiteral("quartDeSoupir"));
        quartDeSoupir->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/quart de soupir.png")));

        horizontalLayout_7->addWidget(quartDeSoupir);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_16);

        huitiemeDeSoupir = new QLabel(verticalLayoutWidget_2);
        huitiemeDeSoupir->setObjectName(QStringLiteral("huitiemeDeSoupir"));
        huitiemeDeSoupir->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/huiti\303\250me de soupir.png")));

        horizontalLayout_7->addWidget(huitiemeDeSoupir);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_17);

        pause = new QLabel(verticalLayoutWidget_2);
        pause->setObjectName(QStringLiteral("pause"));
        pause->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/pause.png")));

        horizontalLayout_8->addWidget(pause);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_19);

        demiPause = new QLabel(verticalLayoutWidget_2);
        demiPause->setObjectName(QStringLiteral("demiPause"));
        demiPause->setPixmap(QPixmap(QString::fromUtf8(":/notes/MesNotes/demi-pause.png")));

        horizontalLayout_8->addWidget(demiPause);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);


        verticalLayout->addLayout(horizontalLayout_8);

        PartitionEdition = new Timer(FenEdition);
        PartitionEdition->setObjectName(QStringLiteral("PartitionEdition"));
        PartitionEdition->setGeometry(QRect(550, 250, 651, 421));
        PartitionEdition->setFocusPolicy(Qt::StrongFocus);
        line_2 = new QFrame(FenEdition);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(350, 150, 1091, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(FenEdition);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(350, 80, 20, 641));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(FenEdition);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(-20, 60, 1451, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        retranslateUi(FenEdition);

        QMetaObject::connectSlotsByName(FenEdition);
    } // setupUi

    void retranslateUi(QWidget *FenEdition)
    {
        FenEdition->setWindowTitle(QApplication::translate("FenEdition", "Fen\303\252tre \303\251dition - DrumMastery", 0));
        annuler->setText(QApplication::translate("FenEdition", "Play", 0));
        retablir->setText(QApplication::translate("FenEdition", "Play", 0));
        boutonRetourArriere->setText(QApplication::translate("FenEdition", "PushButton", 0));
        boutonLangueFr->setText(QApplication::translate("FenEdition", "PushButton", 0));
        boutonAide->setText(QApplication::translate("FenEdition", "PushButton", 0));
        boutonPlayPause->setText(QApplication::translate("FenEdition", "Play", 0));
        record->setText(QApplication::translate("FenEdition", "Play", 0));
        stop->setText(QApplication::translate("FenEdition", "Play", 0));
        nouveau->setText(QApplication::translate("FenEdition", "PushButton", 0));
        ouvrirExploreur->setText(QApplication::translate("FenEdition", "PushButton", 0));
        pushButton->setText(QApplication::translate("FenEdition", "PushButton", 0));
        boutonSonOn->setText(QApplication::translate("FenEdition", "son_on", 0));
        boutonMetronome->setText(QApplication::translate("FenEdition", "PushButton", 0));
        tempo->setText(QString());
        blanche->setText(QString());
        noire->setText(QString());
        doubleCroche->setText(QString());
        croche->setText(QString());
        tripleCroche->setText(QString());
        pushButton_3->setText(QApplication::translate("FenEdition", "PushButton", 0));
        soupir->setText(QString());
        demiSoupir->setText(QString());
        quartDeSoupir->setText(QString());
        huitiemeDeSoupir->setText(QString());
        pause->setText(QString());
        demiPause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FenEdition: public Ui_FenEdition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENEDITION_H
