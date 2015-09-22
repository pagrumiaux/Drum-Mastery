#ifndef SHEET
#define SHEET

#endif // SHEET

#include <QBasicTimer>
#include <QWidget>
#include <QPointF>
#include <QTime>
#include <QMediaPlayer>

#include "measure.h"
#include "notes_jugees.h"

class Sheet : public QWidget
{
    Q_OBJECT

public:
    Sheet(QWidget *parent = 0);
    Note_jugee* getNoteJugee(int numero, Note_jugee* premiere_note);

public slots:
    //  void setPos(const int pos) { position = pos; }

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

    Note_jugee *liste_notes_jugees;
    int indice_liste_notes_jugees;
};

