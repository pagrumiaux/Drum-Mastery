#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>

#include "timer.h"

Timer::Timer(QWidget *parent)
    : QWidget(parent)
{
    step = 50;
    pt = 0;
    timer.start(6, this); //envoie un event tous les 6 ms
}

void Timer::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::SquareCap));
    painter.drawLine(50, 60, 450, 60); // barre horizontale
    painter.drawLine(50, 45, 50, 75); // barre début mesure
    painter.drawLine(450, 45, 450, 75); // barre fin mesure

    painter.drawLine(50, 200, 450, 200); // mesure d'essais
    painter.drawLine(50, 185, 50, 215);
    painter.drawLine(450, 185, 450, 215);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::SquareCap));
    painter.drawLine(150, 50, 150, 70);// barre de mesure
    painter.drawLine(250, 50, 250, 70);// barre de mesure
    painter.drawLine(350, 50, 350, 70);// barre de mesure

    /*Dessin des 4 noires*/
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::SquareCap));
    painter.drawPoint(100,60);
    painter.drawPoint(200,60);
    painter.drawPoint(300,60);
    painter.drawPoint(400,60);

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::SquareCap));
    painter.drawLine(step, 40, step, 80); // barre défilante

    if(step > 450) // si le barre arrive à la fin, on revient au début
        step = 50;

    int i;
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::SquareCap));
    for (i = 0; i < pt; i++ )
        painter.drawPoint(t[pt-1]);
}

void Timer::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timer.timerId())
    {
        ++step;
        update();
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void Timer::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        ++pt;
        t[pt-1] = QPointF(step,200);
        update();
    }
}
