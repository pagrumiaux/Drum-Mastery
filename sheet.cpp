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
    const QString filePath = "C:/Users/P-A/Documents/Drum Mastery/kick2.wav";
    kick.setMedia(QUrl::fromLocalFile(filePath));
    const QString filePath2 = "C:/Users/P-A/Documents/Drum Mastery/metronome2.wav";
    metronome.setMedia(QUrl::fromLocalFile(filePath2));

    bpm = 120; //on travaille en 4/4 pour l'instant
    vitesse = (4*60*1000)/(m_taille_mesure*bpm); //calcul de la vitesse de déplacement du curseur (nbre de msec entre chaque pixel)
    qDebug("vitesse : %d", vitesse);

    //création des mesures à jouer
    nbre_mesures = 1;
    mesure_actuelle = 1;
    m_mesure = new Measure();

    /*mise en place de la zone coloree*/
    zone_coloree = new Colored(0, m_taille_mesure, tab_liste_jugee, m_mesure, vitesse, nbre_mesures);
    zone_coloree->setMinimumSize(1100, (nbre_mesures > 2)? 1255 : 760);
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
    QString p, q;
    p.append(QString("%1%").arg(getPerformance()));
    q.append(QString("essai : %1").arg(getIndice_essai()));
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    painter.drawText(10, 25, p);
    font.setPointSize(10);
    painter.setFont(font);
    painter.drawText(55, 20, q);

    /*affichage du décompte*/
    QString n_compte;
    font.setPointSize(60);
    painter.setPen(QPen(Qt::blue, 3));
    painter.setFont(font);
    if((decompte && started) && !preecoute)
    {
        if(0 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse/4)
            n_compte.append(QString("%1").arg(4));
        if(m_taille_mesure*vitesse/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*2/4)
            n_compte.append(QString("%1").arg(3));
        if(m_taille_mesure*vitesse*2/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*3/4)
            n_compte.append(QString("%1").arg(2));
        if(m_taille_mesure*vitesse*3/4 <=time.elapsed() && time.elapsed() <= m_taille_mesure*vitesse*4/4)
            n_compte.append(QString("%1").arg(1));
        painter.drawText(525,70, n_compte);
    }

    /*lecture du metronome*/
    if(metronome_active)
    {
        if(started)
        {
            if(((time.elapsed() % 500) <= 8) || ((time.elapsed() % 500) >= 492))
            {
                metronome.play();
                //qDebug("m %d", time.elapsed());
            }
        }
    }

    /*préécoute*/
    if(preecoute)
    {
        Note* liste_note_pre;
        liste_note_pre = m_mesure->getNote();
        int cumul = liste_note_pre->getValeur();
        kick.play();
        while(!liste_note_pre->estDerniere())
        {
            if(time.elapsed() >= vitesse * m_taille_mesure * cumul - 10 && time.elapsed() <= vitesse * m_taille_mesure * cumul - 10)
            {
                kick.play();
                liste_note_pre = liste_note_pre->getSuivante();
                cumul += liste_note_pre->getValeur();
            }
        }
    }


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
        if(!decompte)
        {
            painter.setPen(QPen(Qt::black, 3));
            painter.drawLine((nbre_mesures > 1) ? step : step + 300, (mesure_actuelle > 2)? 90 : 40, (nbre_mesures > 1) ? step : step + 300, (mesure_actuelle > 2)? 130 : 80); //mesure à jouer
        }
    }

    /*passage d'une mesure à l'autre*/
    if(time.elapsed() <= vitesse*m_taille_mesure)
        mesure_actuelle = 1;
    if(time.elapsed() >= vitesse*m_taille_mesure && time.elapsed() <= vitesse*m_taille_mesure*2)
        mesure_actuelle = 2;
    if(time.elapsed() >= vitesse*m_taille_mesure*2 && time.elapsed() <= vitesse*m_taille_mesure*3)
        mesure_actuelle = 3;
    if(time.elapsed() >= vitesse*m_taille_mesure*3 && time.elapsed() <= vitesse*m_taille_mesure*4)
        mesure_actuelle = 4;


    if(decompte && time.elapsed() >= vitesse*m_taille_mesure)
    {
        decompte = false;
        time.restart();
    }

    /*pour revenir au début et commencer un nouvel essai*/
    if(time.elapsed() >= vitesse*m_taille_mesure*nbre_mesures && indice_essai < 10)
    {
        if(preecoute)
            stop();
        else
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
    if((indice_essai >= 10) && (time.elapsed() > vitesse*m_taille_mesure*nbre_mesures))
    {
        timer.stop();
        started = false;
        zone_coloree->setStarted(false);
        step = 50 + 16;
        scrollArea->ensureVisible(0, 0);
    }

    preecoute = false;
}

void Sheet::timerEvent(QTimerEvent *event) //event envoyé tous les vitesse ms
{
    if ((event->timerId() == timer.timerId()) && started)
    {
        step = (nbre_mesures > 1)? time.elapsed()*500/2000 + 50 + 16 : time.elapsed()*500/2000 + 16;
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
    }
}

void Sheet::stop()
{
    if(started)
    {
        timer.stop();
        started = false;
        step = 50;
        decompte = false;
    }
}

void Sheet::keyPressEvent(QKeyEvent *event) //event envoyé quand une touche est pressée
{
    int temps_tape = time.elapsed();

    if (event->key() == Qt::Key_Space) // quand on tape sur la touche espace
    {
if(started) {
        kick.play();
        qDebug("%d", temps_tape);

        if(indice_j == 1 && !tab_liste_jugee[indice_essai-1]->estDefaut())
            indice_j++;

        if (!(indice_j == 1))
            getNoteJugee((temps_tape + vitesse*16 > 2000*nbre_mesures && started) ? 1 : indice_j-1, tab_liste_jugee[(temps_tape + vitesse*16 > 2000*nbre_mesures) ? indice_essai : indice_essai-1])->creer_suivante();

        getNoteJugee((temps_tape + vitesse*16 > 2000*nbre_mesures && started) ? 1 : indice_j, tab_liste_jugee[(temps_tape + vitesse*16 > 2000*nbre_mesures) ? indice_essai : indice_essai-1])->setTemps(temps_tape);

        Measure *mesure_int = m_mesure;
        Note *note_int = m_mesure->getNote()->getSuivante();
        float temps_cumule = 0;
        bool ok;
        while (temps_cumule + 20 < temps_tape)
        {
            qDebug("temps cumule : %f", temps_cumule);
            if(abs(temps_tape - temps_cumule) < 30)
            {
                getNoteJugee((temps_tape + vitesse*16 > 2000*nbre_mesures && started) ? 1 : indice_j, tab_liste_jugee[(temps_tape + vitesse*16 > 2000*nbre_mesures) ? indice_essai : indice_essai-1])->setCorrecte(true);
                ok = true;
            }
            temps_cumule += note_int->getValeur()*m_taille_mesure*float(vitesse);
            if(!note_int->estDerniere())
                note_int = note_int->getSuivante();
            else
            {
                mesure_int = mesure_int->getSuivante();
                note_int = mesure_int->getNote();
            }
        }
        if(abs(temps_tape - temps_cumule) < 30)
        {
            getNoteJugee((temps_tape + vitesse*16 > 2000*nbre_mesures && started) ? 1 : indice_j, tab_liste_jugee[(temps_tape + vitesse*16 > 2000*nbre_mesures) ? indice_essai : indice_essai-1])->setCorrecte(true);
            ok = true;
        }

        if(!ok)
        {
            getNoteJugee((temps_tape + vitesse*16 > 2000*nbre_mesures && indice_essai != 1) ? 1 : indice_j, tab_liste_jugee[(temps_tape + vitesse*16 > 2000*nbre_mesures) ? indice_essai : indice_essai-1])->setCorrecte(false);
        }

        indice_j += 1;
        zone_coloree->setTabListesJugees(tab_liste_jugee);

        update(); //idem, update du widget

    }
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
        start();
    }
    if(event->key() == Qt::Key_S)
        save();
    if(event->key() == Qt::Key_1)
    {
        QFile file("simple1.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_2)
    {
        QFile file("simple2.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_3)
    {
        QFile file("simple3.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_4)
    {
        QFile file("simple4.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_5)
    {
        QFile file("test2.dm");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        QTextStream text(&file);
        load(&text);
    }
    if(event->key() == Qt::Key_6)
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
        mesure_int->creerSuivante();
        mesure_int = mesure_int->getSuivante();
    }
    update();
}
