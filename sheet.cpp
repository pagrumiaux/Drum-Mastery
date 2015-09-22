#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>
#include <QPushButton>

#include "sheet.h"
#include "stdlib.h"
#include "note.h"
#include "measure.h"
#include "notes_jugees.h"

Sheet::Sheet(QWidget *parent)
    : QWidget(parent)
{
    step = 50; //coordonnées en x du départ du curseur
    vue = true;
    started = false;
    m_taille_mesure = 400;

    /*const QString filePath = "C:/Users/P-A/Documents/Drum Mastery/kick2.wav";
    kick.setMedia(QUrl::fromLocalFile(filePath));

    const QString filePath2 = "C:/Users/P-A/Documents/Drum Mastery/metronome.wav";
    metronome.setMedia(QUrl::fromLocalFile(filePath2));*/

    bpm = 120; //on travaille en 4/4 pour l'instant
    vitesse = ((4/(bpm/60))*1000)/ m_taille_mesure; //calcul de la vitesse de déplacement du curseur (nbre de msec entre chaque pixel)
    qDebug("vitesse : %d", vitesse);

    //création de la mesure à jouer
    Note *note_1 = new Note(1, 0.25);
    Note *note_2 = new Note(1, 0.25);
    Note *note_3 = new Note(1, 0.25);
    Note *note_4 = new Note(1, 0.125);
    Note *note_5 = new Note(1, 0.125);
    note_1->ajouter_suivante(note_2);
    note_2->ajouter_suivante(note_3);
    note_3->ajouter_suivante(note_4);
    note_4->ajouter_suivante(note_5);
    m_mesure.setNote(note_1);



}

void Sheet::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //qDebug("%d", time.elapsed());

    /*if ((299 <= time.elapsed() && time.elapsed() <= 301) || (899 <=time.elapsed() && time.elapsed() <= 901)
            || (1499 <= time.elapsed() && time.elapsed() <= 1501) || (2099 <= time.elapsed() && time.elapsed() <= 2101))
    {
        metronome.play();
        qDebug("%d ms", time.elapsed());
    }*/

    /*mesure à jouer*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(50, 60, 50 + m_taille_mesure, 60); // barre horizontale
    painter.drawLine(50, 45, 50, 75); // barre début mesure
    painter.drawLine(m_taille_mesure + 50, 45, m_taille_mesure + 50, 75); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(m_taille_mesure/4 + 50, 50, m_taille_mesure/4 + 50, 70);// barre de mesure
    painter.drawLine(2*m_taille_mesure/4 + 50, 50, 2*m_taille_mesure/4 + 50, 70);// barre de mesure
    painter.drawLine(3*m_taille_mesure/4 + 50, 50, 3*m_taille_mesure/4 + 50, 70);// barre de mesure

    /*mesure d'essais*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(50, 200, m_taille_mesure + 50, 200); // barre horizontale
    painter.drawLine(50, 185, 50, 215); // barre début mesure
    painter.drawLine(m_taille_mesure + 50, 185, m_taille_mesure + 50, 215); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(m_taille_mesure/4 + 50, 190, m_taille_mesure/4 + 50, 210);// barre de mesure
    painter.drawLine(2*m_taille_mesure/4 + 50, 190, 2*m_taille_mesure/4 + 50, 210);// barre de mesure
    painter.drawLine(3*m_taille_mesure/4 + 50, 190, 3*m_taille_mesure/4 + 50, 210);// barre de mesure

    /*Dessin des notes*/
    painter.setPen(QPen(Qt::black, 10));
    int x = 50;
    Note *note_int = m_mesure.getNote(); //note intermédiaire pour parcourir la liste de notesi
    float valeur_prec = note_int->getValeur(); //retient en mémoire la valeur de la note d'avant
    painter.drawPoint(x,60);

    while (note_int->estDerniere() != true)
    {
        x += valeur_prec*m_taille_mesure;
        painter.drawPoint(x,60);
        note_int = note_int->getSuivante();
        valeur_prec = note_int->getValeur();
    }


    /*Dessin sur la mesure d'essai*/
    if(vue)
    {
        painter.setPen(QPen(Qt::black, 10));
        int x = 50;
        Note *note_int = m_mesure.getNote(); //note intermédiaire pour parcourir la liste de notes
        float valeur_prec = note_int->getValeur(); //retient en mémoire la valeur de la note d'avant
        painter.drawPoint(x,200);

        while (note_int->estDerniere() != true)
        {
            x += valeur_prec*m_taille_mesure;
            painter.drawPoint(x,200);
            note_int = note_int->getSuivante();
            valeur_prec = note_int->getValeur();
        }
    }

    /*barre défilante*/
    if(started)
    {
        painter.setPen(QPen(Qt::black, 3));
        painter.drawLine(step, 40, step, 80); //mesure à jouer
        painter.drawLine(step, 180, step, 220); //mesure d'essais
    }

    if(step > 450) // si la barre arrive à la fin, on revient au début
    {
        step = 50;
        time.restart();
    }

    /*écriture et coloration des notes jouées sur la mesure d'essais
     le tableau b contient les booléens pour savoir si les notes sont bonnes ou pas*/
    painter.setPen(QPen(Qt::black, 10));
    Note_jugee *liste_note = liste_notes_jugees;
    while (!liste_note->estDerniere())
    {
        if(liste_note->getCorrecte())
            painter.setPen(QPen(QColor(0, 100, 0), 10));
        if(!liste_note->getCorrecte())
            painter.setPen(QPen(QColor(200, 0, 0), 10));

        painter.drawPoint(123, 200);
        liste_note = liste_note->getSuivante();
    }

    if(liste_note->getCorrecte())
        painter.setPen(QPen(QColor(0, 100, 0), 10));
    if(!liste_note->getCorrecte())
        painter.setPen(QPen(QColor(200, 0, 0), 10));
    painter.drawPoint(liste_note->getTemps()/vitesse, 200); //dessin de la derniere note jugee
}

void Sheet::timerEvent(QTimerEvent *event) //event envoyé tous les vitesse ms
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

void Sheet::keyPressEvent(QKeyEvent *event) //event envoyé quand une touche est pressée
{

    int temps_tape = time.elapsed();

    if (event->key() == Qt::Key_Space) // mais on veut que la touche espace
    {

        liste_notes_jugees->setTemps(temps_tape);
        Note_jugee *liste_int = liste_notes_jugees;
        while (!liste_int->estDerniere())
        {
            qDebug("getTemps : %d ms", liste_int->getTemps());
            liste_int = liste_int->getSuivante();
        }
        qDebug("getTemps : %d ms", liste_int->getTemps());

        //kick.play();

        // on écrit dans liste_note_jugee si ce qu'on joue est bon ou pas
        float temps_cumule = 0;
        Note *note_int = m_mesure.getNote();
        bool ok = false;
        while(temps_cumule + 20 < temps_tape) //
        {
            //qDebug("Time elapsed: %d ms", temps_tape);
            //qDebug("Temps cumule: %f ms", temps_cumule);
            //qDebug("oioioi: %f ms", note_int->getValeur()*400*float(vitesse));

            temps_cumule += note_int->getValeur()*400*float(vitesse);

            if(abs(temps_tape - temps_cumule) < 50)
            {
                liste_notes_jugees->setCorrecte(true);
                liste_notes_jugees->creer_suivante();
                ok = true;
            }

            note_int = note_int->getSuivante();
        }
        if(!ok)
        {
            liste_notes_jugees->setCorrecte(false);
            liste_notes_jugees->creer_suivante();
        }
        liste_notes_jugees=liste_notes_jugees->getSuivante();

        update(); //idem, update du widget

    }
    if(event->key() == Qt::Key_Alt)
    {
        if(!started)
        {
            timer.start(vitesse, this);
            time.start();
            started = true;
        }
        else
        {
            timer.stop();
            started = false;
            step = 50;
        }

    }

}
