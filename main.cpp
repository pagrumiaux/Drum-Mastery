#include <QApplication>

#include "timer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Timer timer(0);
    timer.setFixedSize(500,250);
    timer.show();

    return app.exec();
}
