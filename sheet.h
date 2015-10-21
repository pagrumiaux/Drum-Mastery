#ifndef SHEET
#define SHEET

#endif // SHEET

#include <QBasicTimer>
#include <QWidget>
#include <QPointF>
#include <QTime>
#include <QMediaPlayer>
#include <QScrollArea>

#include "measure.h"
#include "notes_jugees.h"

class Sheet : public QWidget
{
    Q_OBJECT

public:
    Sheet(QWidget *parent = 0);
    Note_jugee* getNoteJugee(int numero, Note_jugee* premiere_note);
    void resetListeJ(Note_jugee* premiere_note);
    int getIndice_essai();

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    QBasicTimer timer;
    int position;
    int step;
    QTime time;
    int vitesse;
    int bpm; // battement par minute (tempo)
    bool vue;
    bool started;
    QMediaPlayer kick;
    QMediaPlayer metronome;

    int m_taille_mesure; // taille d'une mesure en pixel
    Measure m_mesure;

    Note_jugee* tab_liste_jugee[10];
    int indice_j;
    int indice_essai;
};

