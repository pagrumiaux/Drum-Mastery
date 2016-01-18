/********************************************************************************
** Form generated from reading UI file 'fenstart.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENSTART_H
#define UI_FENSTART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenStart
{
public:
    QLabel *Logo;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Franais;
    QLabel *Aide;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *boutonModeEntrainement;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *BoutonModePartition;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *FenStart)
    {
        if (FenStart->objectName().isEmpty())
            FenStart->setObjectName(QStringLiteral("FenStart"));
        FenStart->resize(1425, 700);
        FenStart->setStyleSheet(QLatin1String("QWidget#FenStart\n"
"{\n"
"background-image : url(:/images/MesImages/pageStart.jpg);\n"
"}"));
        Logo = new QLabel(FenStart);
        Logo->setObjectName(QStringLiteral("Logo"));
        Logo->setGeometry(QRect(0, -50, 261, 191));
        Logo->setStyleSheet(QStringLiteral(""));
        Logo->setPixmap(QPixmap(QString::fromUtf8("logo transp.png")));
        Logo->setScaledContents(true);
        label = new QLabel(FenStart);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, -10, 20, 481));
        label->setPixmap(QPixmap(QString::fromUtf8("fond-noir.png")));
        horizontalLayoutWidget = new QWidget(FenStart);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(1180, 10, 226, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Franais = new QLabel(horizontalLayoutWidget);
        Franais->setObjectName(QStringLiteral("Franais"));
        Franais->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"}"));
        Franais->setPixmap(QPixmap(QString::fromUtf8(":/images/MesImages/Fr.png")));
        Franais->setScaledContents(true);

        horizontalLayout->addWidget(Franais);

        Aide = new QLabel(horizontalLayoutWidget);
        Aide->setObjectName(QStringLiteral("Aide"));
        Aide->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"min-width : 70px;\n"
"max-width : 70px;\n"
"min-height : 70px;\n"
"max-height : 70px;\n"
"}"));
        Aide->setPixmap(QPixmap(QString::fromUtf8(":/images/MesImages/Aide.png")));
        Aide->setScaledContents(true);

        horizontalLayout->addWidget(Aide);

        horizontalLayoutWidget_3 = new QWidget(FenStart);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 510, 1401, 204));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        boutonModeEntrainement = new QPushButton(horizontalLayoutWidget_3);
        boutonModeEntrainement->setObjectName(QStringLiteral("boutonModeEntrainement"));
        QFont font;
        font.setFamily(QStringLiteral("LeviReBrushed"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        boutonModeEntrainement->setFont(font);
        boutonModeEntrainement->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	max-height : 150px;\n"
"	min-height : 150px;\n"
"	max-width : 350px;\n"
"	min-width : 350px;\n"
"}"));

        horizontalLayout_3->addWidget(boutonModeEntrainement);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        BoutonModePartition = new QPushButton(horizontalLayoutWidget_3);
        BoutonModePartition->setObjectName(QStringLiteral("BoutonModePartition"));
        QFont font1;
        font1.setFamily(QStringLiteral("LeviReBrushed"));
        font1.setPointSize(20);
        BoutonModePartition->setFont(font1);
        BoutonModePartition->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	max-height : 150px;\n"
"	min-height : 150px;\n"
"	max-width : 350px;\n"
"	min-width : 350px;\n"
"}"));

        horizontalLayout_3->addWidget(BoutonModePartition);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        retranslateUi(FenStart);

        QMetaObject::connectSlotsByName(FenStart);
    } // setupUi

    void retranslateUi(QWidget *FenStart)
    {
        FenStart->setWindowTitle(QApplication::translate("FenStart", "Accueil - DrumMastery", 0));
        Logo->setText(QString());
        label->setText(QString());
        Franais->setText(QString());
        Aide->setText(QString());
        boutonModeEntrainement->setText(QApplication::translate("FenStart", "Entra\303\256ne toi !", 0));
        BoutonModePartition->setText(QApplication::translate("FenStart", "Cr\303\251e ta s\303\251quence \n"
"rythmique !", 0));
    } // retranslateUi

};

namespace Ui {
    class FenStart: public Ui_FenStart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENSTART_H
