#ifndef SHEET
#define SHEET

#endif // SHEET

#include <QBasicTimer>
#include <QWidget>
#include <QTime>
#include <QMediaPlayer>
#include <QScrollArea>
#include <QPixmap>
#include <QHBoxLayout>
#include <QFile>

#include "measure.h"
#include "notes_jugees.h"
#include "colored.h"

class Sheet : public QWidget
{
    Q_OBJECT

public:
    Sheet(QWidget *parent = 0);
    Note_jugee* getNoteJugee(int numero, Note_jugee* premiere_note);
    void resetListeJ(Note_jugee* premiere_note);
    int getIndice_essai();
    int getPerformance();
    QPixmap ImageOfNote(Note *note, char c);
    void setMetronome();
    void start();
    void stop();
    void save();
    void load(QTextStream *text);
    double CharToInt(QChar c);

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QBasicTimer timer; // timer
    QTime time; // timer
    int step;
    int vitesse; //vitesse de l'update
    int bpm; // battement par minute (tempo)

    bool vue; //vrai si on veut avoir la vue
    bool started; //vrai si on est en train de jouer
    bool decompte; //vrai pour le décompte, faux une fois le décompte effectué
    bool metronome_active;
    bool preecoute;

    QMediaPlayer kick;
    QMediaPlayer metronome;

    int performance; //indice de performance

    int m_taille_mesure; // taille d'une mesure en pixel
    int nbre_mesures;
    Measure *m_mesure;
    int mesure_actuelle;
    int duree1Temps;
    int duree1Mesure;

    Note_jugee* tab_liste_jugee[10]; //tableau qui retient les notes jouées (jusqu'à 10 essais)
    int indice_j; //indice pour parcourir une liste de notes jugées
    int indice_essai; //indice pour parcourir le tableau des listes de notes jugées

    Colored *zone_coloree;
    QScrollArea *scrollArea;
    QVBoxLayout *layoutV;

    Measure* mesure_preecoute;
    Note* note_preecoute; //variables utiles à la préécoute
    float cumul_preecoute;
};

