#include <QWidget>
#include <QPainter>
#include <QPixmap>

#include "stdlib.h"
#include "note.h"
#include "measure.h"
#include "notes_jugees.h"
#include "math.h"
#include "colored.h"

Colored::Colored(QWidget *parent, int taille_mesure, Note_jugee* t_liste_jugee[10], Measure mesure, int vit)
    : QWidget(parent)
{
    vue = false;
    m_taille_mesure = taille_mesure;
    int i;
    for(i=0; i<10; i++)
        tab_liste_jugee[i] = t_liste_jugee[i];
    m_mesure = mesure;
    vitesse = vit;
    indice_essai = 1;
}


void Colored::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //qDebug("début : %d", time.elapsed());

    /*mesure d'essais*/
    int a;
    for (a=0; a < indice_essai; a++)
    {
        painter.setPen(QPen(QColor(80,80,80,255), 3));
        painter.drawLine(50, 60+a*75, m_taille_mesure + 50, 60+a*75); // barre horizontale
        painter.drawLine(50, 45+a*75, 50, 75+a*75); // barre début mesure
        painter.drawLine(m_taille_mesure + 50, 45+a*75, m_taille_mesure + 50, 75+a*75); // barre fin mesure
        painter.setPen(QPen(QColor(80,80,80,255), 1));
        painter.drawLine(m_taille_mesure/4 + 50, 50+a*75, m_taille_mesure/4 + 50, 70+a*75);// barre de mesure
        painter.drawLine(2*m_taille_mesure/4 + 50, 50+a*75, 2*m_taille_mesure/4 + 50, 70+a*75);// barre de mesure
        painter.drawLine(3*m_taille_mesure/4 + 50, 50+a*75, 3*m_taille_mesure/4 + 50, 70+a*75);// barre de mesure
    }

    /*Dessin sur la mesure d'essai*/
    QRectF source(0, 0, 30, 58);
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

    /*écriture et coloration des notes jouées sur la mesure d'essais*/
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
                yn = 13 + (c+1)*75;
            }
            else
            {
                xn = liste_note->getTemps()/vitesse+50;
                yn = 13 + c*75;
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
                yn = 13 + (c+1)*75;
            }
            else
            {
                xn = liste_note->getTemps()/vitesse+50;
                yn = 13 + c*75;
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

QPixmap Colored::ImageOfNote(Note *note, char c)
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

void Colored::setIndice_essai(int indice)
{
    indice_essai = indice;
}

int Colored::getIndice_essai()
{
    return indice_essai;
}

Note_jugee* Colored::getNoteJugee(int numero, Note_jugee* premiere_note)
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

void Colored::setTabListesJugees(Note_jugee* t_liste_jugee[])
{
    int i;
    for(i=0; i<indice_essai; i++)
        tab_liste_jugee[i] = t_liste_jugee[i];
}
