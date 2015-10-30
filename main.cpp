#include <QApplication>
#include <QScrollArea>

#include "sheet.h"
#include "note.h"
#include "measure.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Sheet *sheet = new Sheet(0);
    sheet->setFixedWidth(600);
    sheet->setMinimumHeight(1000);
    QScrollArea *scrollArea = new QScrollArea;

    scrollArea->setWidget(sheet);
    scrollArea->setFixedWidth(600);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //scrollArea->ensureVisible(0, 500);

    sheet->setFocus();
    sheet->show();
    scrollArea->show();


    /*Sheet sheet(0);
    sheet.setFixedSize(500,250);
    sheet.show();*/

    return app.exec();
}
