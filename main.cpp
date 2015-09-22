#include <QApplication>

#include "sheet.h"
#include "note.h"
#include "measure.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Sheet sheet(0);
    sheet.setFixedSize(500,250);
    sheet.show();

    return app.exec();
}
