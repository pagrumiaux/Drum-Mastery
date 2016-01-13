#include <QWidget>
#include <QPainter>
#include <QTimerEvent>
#include <QKeyEvent>
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
    metronome_active = true;
    m_taille_mesure = 500;
    preecoute = false;
    nbre_mesures = 1;

    /*initialisation des listes de notes jugées*/
    int i;
    for(i=0; i<10; i++)
    {
        tab_liste_jugee[i] = new Note_jugee();
    }
    indice_j = 1;
    indice_essai = 1;

    /*initialisation du son*/
    const QString filePath = "C:/Users/PA/Documents/Drum Mastery/kick2.wav";
    kick.setMedia(QUrl::fromLocalFile(filePath));
    const QString filePath2 = "C:/Users/PA/Documents/Drum Mastery/metronome2.wav";
    metronome.setMedia(QUrl::fromLocalFile(filePath2));

    bpm = 160; //on travaille en 4/4 pour l'instant
    vitesse = 4; //calcul de la vitesse de déplacement du curseur (nbre de msec entre chaque pixel)
    duree1Temps = 60*1000/bpm;
    duree1Mesure = duree1Temps * 4;

    //création des mesures à jouer
    nbre_mesures = 1;
    mesure_actuelle = 1;
    m_mesure = new Measure();

    /*mise en place de la zone coloree*/
    zone_coloree = new Colored(0, m_taille_mesure, tab_liste_jugee, m_mesure, vitesse, nbre_mesures, duree1Temps, duree1Mesure);
    zone_coloree->setMinimumSize(1100, (nbre_mesures > 2)? 1555 : 760);
    scrollArea = new QScrollArea;
    scrollArea->setWidget(zone_coloree);
    scrollArea->setFixedWidth(1100);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVisible(true);

    layoutV = new QVBoxLayout(this);
    layoutV->addWidget(scrollArea);
    layoutV->insertSpacing(0, 150);
    layoutV->setMargin(0);
}

void Sheet::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //qDebug("début : %d", time.elapsed());

    /*affichage pourcentage + numero essai*/
    QString p;
    p.append(QString("%1%").arg(getPerformance()));
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    painter.drawText(10, 25, p);

    /*affichage du décompte*/
    QString n_compte;
    font.setPointSize(60);
    painter.setPen(QPen(Qt::blue, 3));
    painter.setFont(font);
    if((decompte && started) && !preecoute)
    {
        if(0 <=time.elapsed() && time.elapsed() <= duree1Temps)
            n_compte.append(QString("%1").arg(4));
        if(duree1Temps <=time.elapsed() && time.elapsed() <= duree1Temps*2)
            n_compte.append(QString("%1").arg(3));
        if(duree1Temps*2 <=time.elapsed() && time.elapsed() <= duree1Temps*3)
            n_compte.append(QString("%1").arg(2));
        if(duree1Temps*3 <=time.elapsed() && time.elapsed() <= duree1Temps*4)
            n_compte.append(QString("%1").arg(1));
        painter.drawText(525,70, n_compte);
    }

    /*lecture du metronome*/
    if(metronome_active && !preecoute)
    {
        if(started)
        {
            if((time.elapsed() % (duree1Temps) <= 8) || ((time.elapsed() % (duree1Temps) >= (duree1Temps)-8)))
            {
                metronome.play();
                //qDebug("m %d", time.elapsed());
            }
        }
    }

    /*préécoute*/
    /*if(preecoute)
    {
        qDebug("%d", time.elapsed());
        if(time.elapsed() >= duree1Mesure * cumul_preecoute - 10 && time.elapsed() <= duree1Mesure * cumul_preecoute + 10)
        {
            qDebug("PLAY : cumul = %f", cumul_preecoute);
            if(!(note_preecoute->estDerniere() && mesure_preecoute->getDerniere()))
            {
                kick.play();
                qDebug("kick");
            }
            if(note_preecoute->estDerniere() && !mesure_preecoute->getDerniere())
            {
                cumul_preecoute += note_preecoute->getValeur();
                mesure_preecoute = m_mesure->getSuivante();
                note_preecoute = m_mesure->getNote();
            }
            else if (note_preecoute->estDerniere() && mesure_preecoute->getDerniere())
            {
                qDebug("dernière");
                stop();
                started = false;
                preecoute = false;
            }
            else
            {
                cumul_preecoute += note_preecoute->getValeur();
                note_preecoute = note_preecoute->getSuivante();
            }
        }
    }*/


    /*graduations*/
    /*painter.setPen(QPen(Qt::black, 1));
    QString grad1, grad2, grad3;
    grad1.append(QString("%1").arg(300));
    grad2.append(QString("%1").arg(550));
    grad3.append(QString("%1").arg(800));
    font.setPointSize(10);
    painter.setPen(QPen(Qt::blue, 1));
    painter.setFont(font);
    painter.drawText(300,30, grad1);
    painter.drawText(550,30, grad2);
    painter.drawText(800,30, grad3);
    painter.drawLine(300, 10, 300, 15);
    painter.drawLine(550, 10, 550, 15);
    painter.drawLine(800, 10, 800, 15);*/

    /*mesures à jouer*/
    painter.setPen(QPen(Qt::black, 3));
    painter.drawLine((nbre_mesures > 1 )? 50 : 300, 60,(nbre_mesures > 1 )? 50 + 2*m_taille_mesure : 300 + m_taille_mesure, 60); // barre horizontale
    painter.drawLine((nbre_mesures > 1 )? 50 : 300, 45,(nbre_mesures > 1 )? 50 : 300, 75); // barre début mesure
    painter.drawLine((nbre_mesures > 1 )? 2*m_taille_mesure + 50 : m_taille_mesure + 300, 45,(nbre_mesures > 1 )? 2*m_taille_mesure + 50 : m_taille_mesure + 300, 75); // barre fin mesure
    painter.setPen(QPen(Qt::black, 1));

    if (nbre_mesures == 1)
    {
        painter.drawLine(m_taille_mesure/4 + 300, 50, m_taille_mesure/4 + 300, 70);// barre de mesure
        painter.drawLine(2*m_taille_mesure/4 + 300, 50, 2*m_taille_mesure/4 + 300, 70);// barre de mesure
        painter.drawLine(3*m_taille_mesure/4 + 300, 50, 3*m_taille_mesure/4 + 300, 70);// barre de mesure
    }
    else
    {
        int i;
        for (i=0; i < 8; i++)
        {
            if(i == 4)
            {
                painter.setPen(QPen(Qt::black, 3));
                painter.drawLine(i*m_taille_mesure/4 + 50, 45, i*m_taille_mesure/4 + 50, 75);// barre de mesure
            }
            else
            {
                painter.setPen(QPen(Qt::black, 1));
                painter.drawLine(i*m_taille_mesure/4 + 50, 50, i*m_taille_mesure/4 + 50, 70);// barre de mesure
            }
        }
    }

    if(nbre_mesures > 2)
    {
        painter.setPen(QPen(Qt::black, 3));
        painter.drawLine(50, 110,(nbre_mesures == 4)? 50 + 2*m_taille_mesure : 50 + m_taille_mesure, 110); // barre horizontale
        painter.drawLine(50, 95, 50, 125); // barre début mesure
        painter.drawLine((nbre_mesures == 4)? 2*m_taille_mesure + 50 : m_taille_mesure + 50, 95,(nbre_mesures == 4 )? 2*m_taille_mesure + 50 : m_taille_mesure + 50, 125); // barre fin mesure
        painter.setPen(QPen(Qt::black, 1));
        int j;
        for (j=0; j < ((nbre_mesures - 2) * 4); j++)
        {
            if(j == 4) //barre séparation mesures
            {
                painter.setPen(QPen(Qt::black, 3));
                painter.drawLine(j*m_taille_mesure/4 + 50, 95, j*m_taille_mesure/4 + 50, 125);// barre de mesure
            }
            else
            {
                painter.setPen(QPen(Qt::black, 1));
                painter.drawLine(j*m_taille_mesure/4 + 50, 100, j*m_taille_mesure/4 + 50, 120);// barre de mesure
            }
        }
    }

    /*trait séparation*/
    painter.setPen(QPen(Qt::black, 1));
    painter.drawLine(0, 150, 1200, 150);


    /*Dessin des notes sur la mesure à jouer*/
    painter.setPen(QPen(Qt::black, 10));
    QRectF source(0, 0, 30, 58);

    int x = 53;
    if(nbre_mesures == 1)
        x = 303;
    int j;
    Measure* mesure_int = m_mesure;
    for(j=0; j<nbre_mesures; j++)
    {
        if (j == 2)
            x = 53;
        if(mesure_int->getNote() != NULL)
        {
            Note *note_int = mesure_int->getNote(); //note intermédiaire pour parcourir la liste de notes
            float valeur_prec = note_int->getValeur(); //retient en mémoire la valeur de la note d'avant
            while (note_int->estDerniere() != true)
            {
                note_int = note_int->getSuivante();
                painter.drawPixmap(QRectF(x, (j >= 2)? 58 : 8, 30, 58), ImageOfNote(note_int, 'n'), source);
                valeur_prec = note_int->getValeur();
                x += int(valeur_prec*m_taille_mesure);
            }
        }
        mesure_int = mesure_int->getSuivante();
    }

    /*barre défilante*/
    if(started)
    {
        if(!decompte && !preecoute)
        {
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine((nbre_mesures > 1) ? step : step + 300, (mesure_actuelle > 2)? 90 : 40, (nbre_mesures > 1) ? step : step + 300, (mesure_actuelle > 2)? 130 : 80); //mesure à jouer
        }
    }

    /*passage d'une mesure à l'autre*/
    if(time.elapsed() <= duree1Mesure)
        mesure_actuelle = 1;
    if(time.elapsed() >= duree1Mesure && time.elapsed() <= duree1Mesure*2)
        mesure_actuelle = 2;
    if(time.elapsed() >= duree1Mesure*2 && time.elapsed() <= duree1Mesure*3)
        mesure_actuelle = 3;
    if(time.elapsed() >= duree1Mesure*3 && time.elapsed() <= duree1Mesure*4)
        mesure_actuelle = 4;


    if(decompte && time.elapsed() >= duree1Mesure)
    {
        decompte = false;
        zone_coloree->setDecompte(false);
        time.restart();
    }

    /*pour revenir au début et commencer un nouvel essai*/
    if(time.elapsed() >= duree1Mesure*nbre_mesures && indice_essai < 10)
    {

        {
            time.restart();
            if(!decompte)
            {
                if(indice_essai < 10)
                {
                    indice_essai++;
                    zone_coloree->setIndice_essai(indice_essai);
                }
            }
            indice_j = 1;
        }
    }

    /*quand on a fini les 10 essais, ça s'arrête, et on remet tout à 0*/
    if((indice_essai >= 10) && (time.elapsed() > duree1Mesure*nbre_mesures))
    {
        started = false;
        step = 50 + 16;
        zone_coloree->setStarted(false);
        scrollArea->ensureVisible(0, 0);
    }

}

void Sheet::timerEvent(QTimerEvent *event) //event envoyé tous les vitesse ms
{
    if ((event->timerId() == timer.timerId()) && started)
    {
        step = (nbre_mesures > 1)? time.elapsed()*500/(duree1Mesure) + 50 + 16 : time.elapsed()*500/(duree1Mesure) + 16;
        if (nbre_mesures > 1 && step > 1050)
            step = step - 1000;
        if(nbre_mesures == 1 && step > 550)
            step = step - 500;

        update(); // pour que le widget s'update        
        scrollArea->ensureVisible(0, (nbre_mesures > 2)? 60+indice_essai*125 : 60 + indice_essai*75);
        zone_coloree->update();
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
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/ronde_n.png");
        if (i == 0.5)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/blanche_n.png");
        if (i == 0.25)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/noire_n.png");
        if (i == 0.125)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/croche_n.png");
        if (i == 0.0625)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/double_croche_n.png");
        if (i == 0.03125)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/triple_croche_n.png");
    }
    if(c == 'g')
    {
        if (i == 1.0)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/ronde_g.png");
        if (i == 0.5)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/blanche_g.png");
        if (i == 0.25)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/noire_g.png");
        if (i == 0.125)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/croche_g.png");
        if (i == 0.0625)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/double_croche_g.png");
        if (i == 0.03125)
            pix.load("C:/Users/PA/Documents/Drum Mastery/Images/Notes/triple_croche_g.png");
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
    int nbreTotal = 0;
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
        if(!liste_note->estDefaut())
        {
            nbreTotal++;
            if(liste_note->getCorrecte())
                nbreVert++;
        }
    }
    if (nbreTotal != 0)
        performance = nbreVert*100/nbreTotal;
    else performance = 0;

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
    else
        metronome_active = true;
}

void Sheet::start()
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

        indice_essai = 1;
        zone_coloree->setIndice_essai(1);
        indice_j = 1;
        timer.start(vitesse, this);
        time.start();
        if(decompte)
        {
            started = true;
            zone_coloree->setStarted(true);
        }
        decompte = true;
        zone_coloree->setDecompte(true);
    }
}

void Sheet::stop()
{
    if(started)
    {
        timer.stop();
        started = false;
        zone_coloree->setStarted(false);
        step = 50;
        decompte = false;
        scrollArea->ensureVisible(0, 0);
    }
}

void Sheet::keyPressEvent(QKeyEvent *event) //event envoyé quand une touche est pressée
{
    int temps_tape = time.elapsed();

    if (event->key() == Qt::Key_Space && !((indice_essai == 10) && (time.elapsed() + vitesse*16 >= duree1Mesure*nbre_mesures))) // quand on tape sur la touche espace
    {
        int a;
        Note_jugee* note_aff;
        for(a=0; a<indice_essai; a++)
        {
            note_aff = tab_liste_jugee[a];
            qDebug("essai : %d", a);
            while(!note_aff->estDerniere())
            {
                qDebug("%d", note_aff->getTemps());
                note_aff = note_aff->getSuivante();
            }
        }
        qDebug(" ");

        kick.play();

        /*si on est la première note mais qu'elle est déjà modifiée, on passe à la suivante*/
        if(indice_j == 1 && !tab_liste_jugee[indice_essai-1]->estDefaut())
            indice_j++;

        /*si on est pas à la première note, on demande à celle d'avant d'en créer une nouvelle*/
        if (!(indice_j == 1))
        {
            getNoteJugee(indice_j-1, tab_liste_jugee[indice_essai-1])->creer_suivante();
        }

        /*on sauvegarde le temps auquel on a tapé*/
        if((temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && started))
        {
            if(indice_essai == 1 && decompte)
                getNoteJugee(1, tab_liste_jugee[0])->setTemps(temps_tape);
            else if(indice_essai == 1 && !getNoteJugee(1, tab_liste_jugee[0])->estDefaut())
                getNoteJugee(1, tab_liste_jugee[1])->setTemps(temps_tape);
            else
                getNoteJugee(1, tab_liste_jugee[indice_essai])->setTemps(temps_tape);
        }
        else
            getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setTemps(temps_tape);

        Measure *mesure_int = m_mesure;
        Note *note_int = m_mesure->getNote()->getSuivante();
        float temps_cumule = 0;
        bool ok;
        while (temps_cumule + 30 <= (temps_tape % duree1Mesure*nbre_mesures))
        {
            if(abs((temps_tape % duree1Mesure) - temps_cumule) <= 30)
            {
                if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && !decompte)
                    getNoteJugee(1, tab_liste_jugee[indice_essai])->setCorrecte(true);
                else if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && decompte)
                    getNoteJugee(1, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
                else
                    getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
                ok = true;
            }
            temps_cumule += note_int->getValeur()* duree1Mesure;
            if(!note_int->estDerniere())
                note_int = note_int->getSuivante();
            if(note_int->estDerniere() && !mesure_int->getDerniere())
            {
                mesure_int = mesure_int->getSuivante();
                note_int = mesure_int->getNote();
            }
        }
        if(abs((temps_tape % duree1Mesure) - temps_cumule) <= 30)
        {
            if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && started && !decompte)
                getNoteJugee(1, tab_liste_jugee[indice_essai])->setCorrecte(true);
            else if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && started && decompte)
                getNoteJugee(1, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
            else
                getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(true);
            ok = true;
        }

        if(!ok)
        {
            if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && started && !decompte)
                getNoteJugee(1, tab_liste_jugee[indice_essai])->setCorrecte(false);
            else if(temps_tape + vitesse*16 >= duree1Mesure*nbre_mesures && started && decompte)
                getNoteJugee(1, tab_liste_jugee[indice_essai-1])->setCorrecte(false);
            else
                getNoteJugee(indice_j, tab_liste_jugee[indice_essai-1])->setCorrecte(false);
        }

        indice_j += 1;
        zone_coloree->setTabListesJugees(tab_liste_jugee);

        update(); //idem, update du widget

    }
    if(event->key() == Qt::Key_Alt)
    {
        if(!started)
        {
            start();
        }
        else
        {
            stop();
        }

    }
    if(event->key() == Qt::Key_P)
    {
        preecoute = true;
        note_preecoute = m_mesure->getNote();
        mesure_preecoute = m_mesure;
        cumul_preecoute = 0.;
        start();
    }
    if(event->key() == Qt::Key_A)
    {
        QFile file("simple1.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_Z)
    {
        QFile file("simple2.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_E)
    {
        QFile file("simple3.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_R)
    {
        QFile file("simple4.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_T)
    {
        QFile file("test2.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_Y)
    {
        QFile file("test3.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
}

void Sheet::save()
{
    QFile file("test.dm");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

    QTextStream out(&file);
    Note* liste;
    liste = m_mesure->getNote();
    out << m_mesure->getN() << ";";
    out << m_mesure->getU() << ";";
    out << nbre_mesures << ";";
    while(!liste->estDerniere())
    {
        if(liste->getValeur() == 1)
            out << "r";
        if(liste->getValeur() == 0.5)
            out << "b";
        if(liste->getValeur() == 0.25)
            out << "n";
        if(liste->getValeur() == 0.125)
            out << "c";
        if(liste->getValeur() == 0.0625)
            out << "d";
        if(liste->getValeur() == 0.03125)
            out << "t";
        liste=liste->getSuivante();
    }
    if(liste->getValeur() == 1)
        out << "r";
    if(liste->getValeur() == 0.5)
        out << "b";
    if(liste->getValeur() == 0.25)
        out << "n";
    if(liste->getValeur() == 0.125)
        out << "c";
    if(liste->getValeur() == 0.0625)
        out << "d";
    if(liste->getValeur() == 0.03125)
        out << "t";
    out << ";";
}

double Sheet::CharToInt(QChar c)
{
    if(c == 'r')
        return 1.0;
    if(c == 'b')
        return 0.5;
    if(c == 'n')
        return 0.25;
    if(c == 'c')
        return 0.125;
    if(c == 'd')
        return 0.0625;
    if(c == 't')
        return 0.03125;

    return 0;
}

void Sheet::load(QTextStream *text)
{
    QString contenu;
    contenu = text->readAll();

    m_mesure->setN((contenu.at(0).digitValue()));
    m_mesure->setU(contenu.at(2).digitValue());
    nbre_mesures = contenu.at(4).digitValue();
    zone_coloree->setNbMesure(contenu.at(4).digitValue());
    zone_coloree->update();
    Measure* mesure_int = m_mesure;

    int i = 6;
    int j;
    for(j=0; j<nbre_mesures; j++)
    {
        if(j > 0)
        {
            mesure_int->creerSuivante();
            mesure_int = mesure_int->getSuivante();
        }
        Note* note = new Note(1, CharToInt(contenu.at(i)));
        mesure_int->setNote(note);
        Note* note_int = mesure_int->getNote();
        while(contenu.at(i) != ';')
        {
            Note* note= new Note(1, CharToInt(contenu.at(i)));
            note_int->ajouter_suivante(note);
            i++;
            note_int = note_int->getSuivante();
        }
        i++;
    }
    update();
    zone_coloree->setMinimumSize(1100, (nbre_mesures > 2)? 1255 : 760);

    //chargement pour la préécoute
    /*mesure_preecoute = m_mesure;
    note_preecoute = m_mesure->getNote();
    cumul_preecoute = 0.;*/
}
