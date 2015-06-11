#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>
#include <QPushButton>

#include <QAudio>

#include "timer.h"
#include "stdlib.h"
#include "audio.h"

Timer::Timer(QWidget *parent)
    : QWidget(parent)
{
    step = 50; //coordonnées en x du départ du curseur
    pt = 0; //variable qui parcourt le tableau de note, de 0 à 3
    vue = false;
    c_parti = false;

    vitesse = 6;

    /*tableau des temps de notes à jouer*/
    tps_a_jouer[0] = 50*vitesse;
    tps_a_jouer[1] = 50*vitesse*3;
    tps_a_jouer[2] = 50*vitesse*5;
    tps_a_jouer[3] = 50*vitesse*7;

    //timer.start(vitesse, this); //envoie un event tous les 6 ms
    //time.start(); //départ du chrono

    //connect(go, SIGNAL(clicked()), timer.start(6, this));
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
    painter.drawLine(150, 190, 150, 210);// barre de mesure
    painter.drawLine(250, 190, 250, 210);// barre de mesure
    painter.drawLine(350, 190, 350, 210);// barre de mesure

    /*Dessin des 4 noires*/
    painter.setPen(QPen(Qt::black, 10));
    painter.drawPoint(100,60);
    painter.drawPoint(200,60);
    painter.drawPoint(300,60);
    painter.drawPoint(400,60);

    /*Dessin des 4 noires sur la mesure d'essai*/
    if(vue)
    {
        painter.setPen(QPen(Qt::black, 10));
        painter.drawPoint(100,200);
        painter.drawPoint(200,200);
        painter.drawPoint(300,200);
        painter.drawPoint(400,200);
    }

    /*barre défilante*/
    if(c_parti)
    {
        painter.setPen(QPen(Qt::black, 3));
        painter.drawLine(step, 40, step, 80); //mesure à jouer
        painter.drawLine(step, 180, step, 220); //mesure d'essais
    }

    if(step > 450) // si la barre arrive à la fin, on revient au début
    {
        pt = 0;
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
            painter.setPen(QPen(QColor(200, 0, 0), 10));

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

    int temps_tape = time.elapsed();

    if (event->key() == Qt::Key_Space) // mais on veut que la touche espace
    {
        // on écrit dans b[] si ce qu'on joue est bon ou pas
        int k = 0;
        bool ok = false; // si la note jouée correspond ou non à une des notes à jouer
        for(k = 0; k < 4; k++) // on compare ce qu'on a joué à toutes les notes
        {
            qDebug("Time elapsed: %d ms", temps_tape);
            qDebug("Temps à taper: %d ms", tps_a_jouer[k]);

            if (abs(temps_tape - tps_a_jouer[k]) < 20)
            {
                b[pt] = true;
                ok = true; // ça correspond bien
            }
         }

        if(!ok)
            b[pt]=false;

        t[pt] = QPointF(step,200);
        update(); //idem, update du widget

        ++pt;
    }
    if(event->key() == Qt::Key_Alt)
    {
        if(!c_parti)
        {
            timer.start(vitesse, this);
            time.start();
            c_parti = true;
        }
        else
        {
            timer.stop();
            c_parti = false;
            pt = 0;
            step = 50;
        }

    }

}
