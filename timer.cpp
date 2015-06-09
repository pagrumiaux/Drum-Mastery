#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>

#include <QAudio>

#include "timer.h"
#include "stdlib.h"
#include "audio.h"

Timer::Timer(QWidget *parent)
    : QWidget(parent)
{
    step = 50; //coordonnées en x du départ du curseur
    pt = 0; //variable qui parcourt le tableau de note, de 0 à 3

    /*tableau des temps de notes à jouer*/
    tps_a_jouer[0] = 300;
    tps_a_jouer[1] = 900;
    tps_a_jouer[2] = 1500;
    tps_a_jouer[3] = 2100;

    timer.start(6, this); //envoie un event tous les 6 ms
    time.start(); //départ du chrono
}

void Timer::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    /*mesure à jouer*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(50, 60, 450, 60); // barre horizontale
    painter.drawLine(50, 45, 50, 75); // barre début mesure
    painter.drawLine(450, 45, 450, 75); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(150, 50, 150, 70);// barre de mesure
    painter.drawLine(250, 50, 250, 70);// barre de mesure
    painter.drawLine(350, 50, 350, 70);// barre de mesure

    /*mesure d'essais*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(50, 200, 450, 200); // barre horizontale
    painter.drawLine(50, 185, 50, 215); // barre début mesure
    painter.drawLine(450, 185, 450, 215); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(150, 50, 150, 70);// barre de mesure
    painter.drawLine(250, 50, 250, 70);// barre de mesure
    painter.drawLine(350, 50, 350, 70);// barre de mesure

    /*Dessin des 4 noires*/
    painter.setPen(QPen(Qt::black, 10));
    painter.drawPoint(100,60);
    painter.drawPoint(200,60);
    painter.drawPoint(300,60);
    painter.drawPoint(400,60);

    /*barre défilante*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(step, 40, step, 80);

    if(step > 450) // si la barre arrive à la fin, on revient au début
    {
        step = 50;
        time.restart();
    }

    /*écriture et coloration des notes jouées sur la mesure d'essais
     le tableau b contient les booléens pour savoir si les notes sont bonnes ou pas*/
    int i;
    painter.setPen(QPen(Qt::black, 10));
    for (i = 0; i < pt; i++)
    {
        if(b[i])
            painter.setPen(QPen(QColor(0, 100, 0), 10));
        if(!b[i])
            painter.setPen(QPen(QColor(100, 0, 0), 10));

        painter.drawPoint(t[i].rx(),t[i].ry());
     }
}

void Timer::timerEvent(QTimerEvent *event) //event envoyé tous les 6 ms
{
    if (event->timerId() == timer.timerId())
    {
        ++step;
        update(); // pour que le widget s'update
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

void Timer::keyPressEvent(QKeyEvent *event) //event envoyé quand une touche est pressée
{
    // pour ne pas dépasser des limites du tableau
    if (pt > 3)
        pt = 0;

    //inutile, c'était pour des tests
    qDebug("Time elapsed: %d ms", time.elapsed());
    qDebug("Temps à taper: %d ms", tps_a_jouer[pt]);

    if (event->key() == Qt::Key_Space) // mais on veut que la touche espace
    {
        // on écrit dans b[] si ce qu'on joue est bon ou pas
        if (abs(time.elapsed() - tps_a_jouer[pt]) < 20)
        {
            b[pt] = true;
        }
        else
            b[pt] = false;

        t[pt] = QPointF(step,200);
        update(); //idem, update du widget

        ++pt;
    }
}
