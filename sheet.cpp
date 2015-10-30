#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>
#include <QPushButton>
#include <QPixmap>

#include "sheet.h"
#include "stdlib.h"
#include "note.h"
#include "measure.h"
#include "notes_jugees.h"
#include "math.h"

Sheet::Sheet(QWidget *parent)
    : QWidget(parent)
{
    step = 50; //coordonnées en x du départ du curseur
    vue = true;
    started = false;
    metronome_active = false;
    m_taille_mesure = 500;

    /*initialisation des listes de notes jugées*/
    int i;
    for(i=0; i<10; i++)
    {
        tab_liste_jugee[i] = new Note_jugee();
    }
    indice_j = 1;
    indice_essai = 1;

    /*initialisation du son*/
    const QString filePath = "C:/Users/P-A/Documents/Drum Mastery/kick2.wav";
    kick.setMedia(QUrl::fromLocalFile(filePath));
    const QString filePath2 = "C:/Users/P-A/Documents/Drum Mastery/metronome2.wav";
    metronome.setMedia(QUrl::fromLocalFile(filePath2));

    bpm = 120; //on travaille en 4/4 pour l'instant
    vitesse = (4*60*1000)/(m_taille_mesure*bpm); //calcul de la vitesse de déplacement du curseur (nbre de msec entre chaque pixel)
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

    //qDebug("début : %d", time.elapsed());

    QString p, q;
    p.append(QString("%1%").arg(getPerformance()));
    q.append(QString("essai : %1").arg(getIndice_essai()));
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    painter.drawText(10, 25, p);
    font.setPointSize(10);
    painter.setFont(font);
    painter.drawText(55, 15, q);

    /*affichage du décompte*/
    QString n_compte;
    font.setPointSize(100);
    painter.setPen(QPen(Qt::blue, 3));
    painter.setFont(font);
    if(decompte && started)
    {
        if(0 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse/4)
            n_compte.append(QString("%1").arg(4));
        if(m_taille_mesure*vitesse/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*2/4)
            n_compte.append(QString("%1").arg(3));
        if(m_taille_mesure*vitesse*2/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*3/4)
            n_compte.append(QString("%1").arg(2));
        if(m_taille_mesure*vitesse*3/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*4/4)
            n_compte.append(QString("%1").arg(1));
        painter.drawText(250,200, n_compte);
    }

    if(metronome_active)
    {
        if ((0 <= time.elapsed() && time.elapsed() <=vitesse+1) || (m_taille_mesure*vitesse-(floor(vitesse/2)+1) <= time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse+(floor(vitesse/2)+1)) || (m_taille_mesure*vitesse/4-(floor(vitesse/2)+1) <= time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse/4+(floor(vitesse/2)+1))
                || (m_taille_mesure*vitesse*2/4-(floor(vitesse/2)+1) <= time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*2/4+(floor(vitesse/2)+1)) || (m_taille_mesure*vitesse*3/4-(floor(vitesse/2)+1) <= time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*3/4+(floor(vitesse/2)+1)))
        {
            metronome.play();
            qDebug("m : %d", time.elapsed());
        }
    }

    /*mesure à jouer*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine(50, 60, 50 + m_taille_mesure, 60); // barre horizontale
    painter.drawLine(50, 45, 50, 75); // barre début mesure
    painter.drawLine(m_taille_mesure + 50, 45, m_taille_mesure + 50, 75); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(m_taille_mesure/4 + 50, 50, m_taille_mesure/4 + 50, 70);// barre de mesure
    painter.drawLine(2*m_taille_mesure/4 + 50, 50, 2*m_taille_mesure/4 + 50, 70);// barre de mesure
    painter.drawLine(3*m_taille_mesure/4 + 50, 50, 3*m_taille_mesure/4 + 50, 70);// barre de mesure

    /*trait séparation*/
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(0, 100, 1200, 100);

    /*mesure d'essais*/
    int a;
    for (a=0; a < indice_essai; a++)
    {
        painter.setPen(QPen(QColor(80,80,80,255), 3));
        painter.drawLine(50, 150+a*75, m_taille_mesure + 50, 150+a*75); // barre horizontale
        painter.drawLine(50, 135+a*75, 50, 165+a*75); // barre début mesure
        painter.drawLine(m_taille_mesure + 50, 135+a*75, m_taille_mesure + 50, 165+a*75); // barre fin mesure
        painter.setPen(QPen(QColor(80,80,80,255), 1));
        painter.drawLine(m_taille_mesure/4 + 50, 140+a*75, m_taille_mesure/4 + 50, 160+a*75);// barre de mesure
        painter.drawLine(2*m_taille_mesure/4 + 50, 140+a*75, 2*m_taille_mesure/4 + 50, 160+a*75);// barre de mesure
        painter.drawLine(3*m_taille_mesure/4 + 50, 140+a*75, 3*m_taille_mesure/4 + 50, 160+a*75);// barre de mesure
    }

    /*Dessin des notes sur la mesure à jouer*/
    painter.setPen(QPen(Qt::black, 10));
    QRectF source(0, 0, 30, 58);

    int x = 50;
    Note *note_int = m_mesure.getNote(); //note intermédiaire pour parcourir la liste de notes
    float valeur_prec = note_int->getValeur(); //retient en mémoire la valeur de la note d'avant
    painter.drawPixmap(QRectF(x, 13, 30, 58), ImageOfNote(note_int, 'n'), source);

    while (note_int->estDerniere() != true)
    {
        x += int(valeur_prec*m_taille_mesure);
        note_int = note_int->getSuivante();
        painter.drawPixmap(QRectF(x, 13, 30, 58), ImageOfNote(note_int, 'n'), source);
        valeur_prec = note_int->getValeur();
    }


    /*Dessin sur la mesure d'essai*/
    if(vue)
    {
        int b;
        for (b=0; b<indice_essai; b++)
        {
            painter.setPen(QPen(Qt::black, 10));
            int x = 50;
            Note *note_int = m_mesure.getNote(); //note intermédiaire pour parcourir la liste de notes
            float valeur_prec = note_int->getValeur(); //retient en mémoire la valeur de la note d'avant
            painter.drawPixmap(QRectF(x, 103+75*b, 30, 58), QPixmap("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_g.png"), source);

            while (note_int->estDerniere() != true)
            {
                x += valeur_prec*m_taille_mesure;                
                note_int = note_int->getSuivante();
                painter.drawPixmap(QRectF(x, 103+75*b, 30, 58), ImageOfNote(note_int, 'g'), source);
                valeur_prec = note_int->getValeur();
            }
        }
    }

    /*barre défilante*/
    if(started)
    {
        if(!decompte)
        {
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine(step, 40, step, 80); //mesure à jouer
        }
    }

    /*pour revenir au début et commencer un nouvel essai*/
    if(time.elapsed() >= vitesse*m_taille_mesure)
    {
        step = 50;
        time.restart();
        if(!decompte)
            indice_essai++;
        if (decompte)
            decompte = false;
        //qDebug("%d", indice_essai);
        indice_j = 1;
    }

    /*quand on a fini les 10 essais, ça s'arrête, et on remet tout à 0*/
    if(indice_essai > 10)
    {
        timer.stop();
        started = false;
        step = 50;
        indice_essai = 1;

        int j;
        for (j=0; j<indice_essai; j++)
        {
            Note_jugee* note_int = tab_liste_jugee[j];
            int k = 1;
            int i;

            while (!note_int->estDerniere())
            {
                note_int = note_int->getSuivante();
                k++;
            }
            for (i=k; i>1; i--)
            {
                delete getNoteJugee(i-1, tab_liste_jugee[j])->getSuivante();
            }
            tab_liste_jugee[j]->setTemps(0);
            tab_liste_jugee[j]->setCorrecte(false);
            tab_liste_jugee[j]->setDerniere(true);
            tab_liste_jugee[j]->setSuivante(NULL);
        }

        indice_j = 1;

    }

    /*écriture et coloration des notes jouées sur la mesure d'essais*/
   if(!decompte)
   {
    int c;
    int xn, yn;
    painter.setPen(QPen(Qt::black, 10));
    QPixmap image2;
    QRectF source2(0, 0, 30, 58);
    for(c=0; c<indice_essai; c++)
    {
        Note_jugee *liste_note = tab_liste_jugee[c];
        while (!liste_note->estDerniere())
        {
            if ((liste_note->getTemps()+50 > 2000))
            {
                xn = liste_note->getTemps()/vitesse+50 - 500;
                yn = 103 + (c+1)*75;
            }
            else
            {
                xn = liste_note->getTemps()/vitesse+50;
                yn = 103 + c*75;
            }

            if(liste_note->getCorrecte())
                image2.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_v.png");
            if(!liste_note->getCorrecte())
                image2.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_r.png");

            if (!((liste_note->getTemps() == 0) && (liste_note->getSuivante() == NULL) && (liste_note->getCorrecte() == false)))
                painter.drawPixmap(QRectF(xn, yn, 30, 58), image2, source2);
            liste_note = liste_note->getSuivante();
        }
        if(!liste_note->estDefaut())
        {
            if ((liste_note->getTemps()+50 > 2000))
            {
                xn = liste_note->getTemps()/vitesse+50 - 500;
                yn = 103 + (c+1)*75;
            }
            else
            {
                xn = liste_note->getTemps()/vitesse+50;
                yn = 103 + c*75;
            }

            if(liste_note->getCorrecte())
                image2.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_v.png");
            if(!liste_note->getCorrecte())
                image2.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_r.png");

            if (!((liste_note->getTemps() == 0) && (liste_note->getSuivante() == NULL) && (liste_note->getCorrecte() == false)))
                painter.drawPixmap(QRectF(xn, yn, 30, 58), image2, source2); //dessin de la derniere note jugee
        }
    }
   }
    //qDebug("fin : %d", time.elapsed());
}

void Sheet::timerEvent(QTimerEvent *event) //event envoyé tous les vitesse ms
{
    if (event->timerId() == timer.timerId())
    {
        step = time.elapsed()*500/2000+50;
        //qDebug("%d ; %d", step, time.elapsed());
        update(); // pour que le widget s'update
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

QPixmap Sheet::ImageOfNote(Note *note, char c)
{
    double i = note->getValeur();
    QPixmap pix;
    if(c == 'n')
    {
        if (i == 1.0)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/ronde_n.png");
        if (i == 0.5)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/blanche_n.png");
        if (i == 0.25)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_n.png");
        if (i == 0.125)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/croche_n.png");
        if (i == 0.0625)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/double_croche_n.png");
        if (i == 0.03125)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/triple_croche_n.png");
    }
    if(c == 'g')
    {
        if (i == 1.0)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/ronde_g.png");
        if (i == 0.5)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/blanche_g.png");
        if (i == 0.25)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/noire_g.png");
        if (i == 0.125)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/croche_g.png");
        if (i == 0.0625)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/double_croche_g.png");
        if (i == 0.03125)
            pix.load("C:/Users/P-A/Documents/Drum Mastery/Images/Notes/triple_croche_g.png");
    }

    return pix;
}

int Sheet::getIndice_essai()
{
    return indice_essai;
}

int Sheet::getPerformance()
{
    int nbreVert = 0;
    int nbreTotal =0;
    int i;
    Note_jugee *liste_note;
    for(i=0; i<indice_essai; i++)
    {
        liste_note = tab_liste_jugee[i];
        while(!liste_note->estDerniere())
        {
            nbreTotal++;
            if(liste_note->getCorrecte())
                nbreVert++;
            liste_note = liste_note->getSuivante();
        }
        nbreTotal++;
        if(liste_note->getCorrecte())
            nbreVert++;
    }
    performance = nbreVert*100/nbreTotal;
    return performance;
}

Note_jugee* Sheet::getNoteJugee(int numero, Note_jugee* premiere_note)
{
    if(numero == 1)
        return premiere_note;
    else
    {
        int i;
        Note_jugee* note_int = premiere_note;
        for (i=1; i < numero; i++)
        {
            note_int = note_int->getSuivante();
        }
        return note_int;
    }
}

void Sheet::setMetronome()
{
    if(metronome_active)
        metronome_active = false;
    if(!metronome_active)
        metronome_active = true;
}

void Sheet::keyPressEvent(QKeyEvent *event) //event envoyé quand une touche est pressée
{

    int temps_tape = time.elapsed();

    if (event->key() == Qt::Key_Space) // quand on tape sur la touche espace
    {
        /*if(!started) //pour commencer direct en jouant
        {
            int j;
            for (j=0; j<10; j++)
            {
                Note_jugee* note_int = tab_liste_jugee[j];
                int k = 1;
                int i;

                while (!note_int->estDerniere())
                {
                    note_int = note_int->getSuivante();
                    k++;
                }
                for (i=k; i>1; i--)
                {
                    delete getNoteJugee(i-1, tab_liste_jugee[j])->getSuivante();
                }
                tab_liste_jugee[j]->setTemps(0);
                tab_liste_jugee[j]->setCorrecte(false);
                tab_liste_jugee[j]->setDerniere(true);
                tab_liste_jugee[j]->setSuivante(NULL);
            }

            indice_essai = 1;
            indice_j = 1;
            timer.start(vitesse, this);
            time.start();
            started = true;
        }*/

        kick.play();
        qDebug("t : %d ; p : %d", time.elapsed(), time.elapsed()/vitesse+50);

        if (!(indice_j == 1))
            getNoteJugee(indice_j-1, tab_liste_jugee[indice_essai-1])->creer_suivante();

        getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setTemps(temps_tape);

        Note *note_int = m_mesure.getNote();
        float temps_cumule = 0;
        bool ok;
        while (temps_cumule + 20 < temps_tape)
        {
            temps_cumule += note_int->getValeur()*m_taille_mesure*float(vitesse);
            //qDebug("temps cumulé : %f", temps_cumule);
            if(abs(temps_tape - temps_cumule) < 20)
            {
                getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
                ok = true;
            }

            note_int = note_int->getSuivante();
        }
        if(abs(temps_tape - temps_cumule) < 20)
        {
            getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
            ok = true;
        }

        if(!ok)
        {
            getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(false);
        }

        indice_j += 1;

        /*Note_jugee* liste_int = tab_liste_jugee[0];
        while(!liste_int->estDerniere())
        {
            qDebug("%d", liste_int->getTemps());
            liste_int = liste_int->getSuivante();
        }
        qDebug("%d", liste_int->getTemps());*/


        update(); //idem, update du widget

    }
    if(event->key() == Qt::Key_Alt)
    {
        if(!started)
        {
            int j;
            for (j=0; j<indice_essai; j++)
            {
                Note_jugee* note_int = tab_liste_jugee[j];
                int k = 1;
                int i;

                while (!note_int->estDerniere())
                {
                    note_int = note_int->getSuivante();
                    k++;
                }
                for (i=k; i>1; i--)
                {
                    delete getNoteJugee(i-1, tab_liste_jugee[j])->getSuivante();
                }
                tab_liste_jugee[j]->setTemps(0);
                tab_liste_jugee[j]->setCorrecte(false);
                tab_liste_jugee[j]->setDerniere(true);
                tab_liste_jugee[j]->setSuivante(NULL);
            }

            decompte = true;
            indice_essai = 1;
            indice_j = 1;
            timer.start(vitesse, this);
            time.start();
            started = true;
        }
        else
        {
            timer.stop();
            started = false;
            step = 50;
            qDebug("perf : %d", getPerformance());
            decompte = false;
        }

    }

}
