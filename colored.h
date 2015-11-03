#ifndef COLORED
#define COLORED

#include <QWidget>
#include <QScrollArea>
#include <QPixmap>

#include "measure.h"
#include "notes_jugees.h"

class Colored : public QWidget
{
    Q_OBJECT

public:
    Colored(QWidget *parent, int taille_mesure, Note_jugee* tab_liste_jugee[10], Measure mesure, int vit);
    Note_jugee* getNoteJugee(int numero, Note_jugee* premiere_note);
    QPixmap ImageOfNote(Note *note, char c);

    void setIndice_essai(int indice);
    int getIndice_essai();

    void setTabListesJugees(Note_jugee* t_liste_jugee[]);
    Note_jugee* getTabListesJugees();

public slots:

protected:
    void paintEvent(QPaintEvent *event);

private:

    bool vue; //vrai si on veut avoir la vue

    int m_taille_mesure; // taille d'une mesure en pixel
    int vitesse;
    Measure m_mesure;

    Note_jugee* tab_liste_jugee[10]; //tableau qui retient les notes jouées (jusqu'à 10 essais)
    int indice_j; //indice pour parcourir une liste de notes jugées
    int indice_essai; //indice pour parcourir le tableau des listes de notes jugées
};

#endif // COLORED
