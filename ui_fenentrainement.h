/********************************************************************************
** Form generated from reading UI file 'fenentrainement.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENENTRAINEMENT_H
#define UI_FENENTRAINEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <sheet.h>

QT_BEGIN_NAMESPACE

class Ui_FenEntrainement
{
public:
    QWidget *verticalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *line;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *nouveau;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *boutonRetourMenu;
    QPushButton *boutonLangueFr;
    QPushButton *boutonAide;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *boutonPlayPause;
    QPushButton *boutonStop;
    QPushButton *ouvrirExploreur;
    QSpacerItem *horizontalSpacer_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *boutonSonOn;
    QSlider *boutonVolume;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *boutonMetronome;
    QPushButton *boutonModeVue;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *tempo;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_22;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLCDNumber *affichagePerformance;
    QTextBrowser *pourcent;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_6;
    QScrollArea *scrollArea;
    Sheet *partition;

    void setupUi(QWidget *FenEntrainement)
    {
        if (FenEntrainement->objectName().isEmpty())
            FenEntrainement->setObjectName(QStringLiteral("FenEntrainement"));
        FenEntrainement->resize(1464, 700);
        FenEntrainement->setFocusPolicy(Qt::ClickFocus);
        FenEntrainement->setStyleSheet(QLatin1String("QWidget#FenEntrainement\n"
"{\n"
"	background-image : url(:/images/MesImages/pageEntrainement.jpg);\n"
"}"));
        verticalLayoutWidget = new QWidget(FenEntrainement);
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

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        nouveau = new QPushButton(verticalLayoutWidget);
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

        horizontalLayout->addWidget(nouveau);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        boutonRetourMenu = new QPushButton(verticalLayoutWidget);
        boutonRetourMenu->setObjectName(QStringLiteral("boutonRetourMenu"));
        boutonRetourMenu->setStyleSheet(QLatin1String("QPushButton\n"
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

        horizontalLayout->addWidget(boutonRetourMenu);

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

        horizontalLayoutWidget = new QWidget(FenEntrainement);
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

        boutonStop = new QPushButton(horizontalLayoutWidget);
        boutonStop->setObjectName(QStringLiteral("boutonStop"));
        boutonStop->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/Stop.jpg) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 50px;\n"
"max-width : 50px;\n"
"min-height : 50px;\n"
"max-height : 50px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_2->addWidget(boutonStop);

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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayoutWidget_2 = new QWidget(FenEntrainement);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 78, 341, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
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

        boutonVolume = new QSlider(verticalLayoutWidget_2);
        boutonVolume->setObjectName(QStringLiteral("boutonVolume"));
        boutonVolume->setValue(99);
        boutonVolume->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(boutonVolume);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
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

        boutonModeVue = new QPushButton(verticalLayoutWidget_2);
        boutonModeVue->setObjectName(QStringLiteral("boutonModeVue"));
        boutonModeVue->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"border-image : url(:/images/MesImages/vue_on.png) 0 0 0 0 stretch stretch;\n"
"border-width : 0px;\n"
"background-position : center;\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"color : transparent;\n"
"}"));

        horizontalLayout_4->addWidget(boutonModeVue);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
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
        spinBox->setMinimumSize(QSize(102, 47));
        QFont font;
        font.setPointSize(14);
        spinBox->setFont(font);
        spinBox->setLayoutDirection(Qt::LeftToRight);
        spinBox->setStyleSheet(QLatin1String("QSpinBox\n"
"{\n"
"min-width : 100px;\n"
"max-width : 100px;\n"
"min-height : 45px;\n"
"max-height : 45px;\n"
"}"));
        spinBox->setMinimum(60);
        spinBox->setMaximum(200);
        spinBox->setValue(120);

        horizontalLayout_9->addWidget(spinBox);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_22);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        affichagePerformance = new QLCDNumber(verticalLayoutWidget_2);
        affichagePerformance->setObjectName(QStringLiteral("affichagePerformance"));
        affichagePerformance->setMaximumSize(QSize(60, 60));
        QFont font1;
        font1.setPointSize(20);
        affichagePerformance->setFont(font1);
        affichagePerformance->setAutoFillBackground(false);
        affichagePerformance->setFrameShape(QFrame::NoFrame);
        affichagePerformance->setDigitCount(1);
        affichagePerformance->setProperty("value", QVariant(0));

        horizontalLayout_6->addWidget(affichagePerformance);

        pourcent = new QTextBrowser(verticalLayoutWidget_2);
        pourcent->setObjectName(QStringLiteral("pourcent"));
        pourcent->setMaximumSize(QSize(60, 60));
        pourcent->setStyleSheet(QLatin1String("QTextBrowser\n"
"{\n"
"maximum-height : 60px;\n"
"maximum-width : 60px;\n"
"background-color : transparent;\n"
"}"));
        pourcent->setFrameShape(QFrame::NoFrame);
        pourcent->setLineWidth(0);

        horizontalLayout_6->addWidget(pourcent);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        line_2 = new QFrame(FenEntrainement);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(350, 150, 1091, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(FenEntrainement);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(350, 80, 16, 641));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(FenEntrainement);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(-20, 60, 1451, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(FenEntrainement);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(510, 190, 601, 431));
        scrollArea->setFocusPolicy(Qt::NoFocus);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        partition = new Sheet();
        partition->setObjectName(QStringLiteral("partition"));
        partition->setEnabled(true);
        partition->setGeometry(QRect(0, 0, 599, 429));
        partition->setFocusPolicy(Qt::StrongFocus);
        scrollArea->setWidget(partition);

        retranslateUi(FenEntrainement);

        QMetaObject::connectSlotsByName(FenEntrainement);
    } // setupUi

    void retranslateUi(QWidget *FenEntrainement)
    {
        FenEntrainement->setWindowTitle(QApplication::translate("FenEntrainement", "Fen\303\252tre entrainement - DrumMastery", 0));
        nouveau->setText(QApplication::translate("FenEntrainement", "PushButton", 0));
        boutonRetourMenu->setText(QApplication::translate("FenEntrainement", "PushButton", 0));
        boutonLangueFr->setText(QApplication::translate("FenEntrainement", "PushButton", 0));
        boutonAide->setText(QApplication::translate("FenEntrainement", "PushButton", 0));
        boutonPlayPause->setText(QApplication::translate("FenEntrainement", "Play", 0));
        boutonStop->setText(QApplication::translate("FenEntrainement", "Play", 0));
        ouvrirExploreur->setText(QApplication::translate("FenEntrainement", "PushButton", 0));
        boutonSonOn->setText(QApplication::translate("FenEntrainement", "son_on", 0));
        boutonMetronome->setText(QApplication::translate("FenEntrainement", "On", 0));
        boutonModeVue->setText(QApplication::translate("FenEntrainement", "On", 0));
        tempo->setText(QString());
        pourcent->setHtml(QApplication::translate("FenEntrainement", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">%</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class FenEntrainement: public Ui_FenEntrainement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENENTRAINEMENT_H

