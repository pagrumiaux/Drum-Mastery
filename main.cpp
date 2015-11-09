#include <QApplication>
#include <QScrollArea>

#include "sheet.h"
#include "note.h"
#include "measure.h"
#include "colored.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Sheet *sheet = new Sheet(0);
    sheet->setFixedWidth(600);
    /*QScrollArea *scrollArea = new QScrollArea;

    scrollArea->setWidget(sheet);
    scrollArea->setFixedWidth(600);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);*/
    sheet->show();
    //scrollArea->show();

    return app.exec();
}
