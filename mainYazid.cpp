#include "MainWindow.h"
#include "timer.h"
#include "fenedition.h"
#include "fenstart.h"
#include "fenentrainement.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

   FenEntrainement fenetreun;
   fenetreun.show();

    return app.exec();
}
