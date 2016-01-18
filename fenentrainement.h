#ifndef FENENTRAINEMENT_H
#define FENENTRAINEMENT_H

#include <QWidget>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>
#include "portaudio.h"


namespace Ui {
class FenEntrainement;
}

class FenEntrainement : public QWidget
{
    Q_OBJECT
    QThread threadBoum;


public:
    explicit FenEntrainement(QWidget *parent = 0);
    ~FenEntrainement();

public slots:
void handleResults ();
//void changerPerformance();

private slots:
    void on_boutonPlayPause_clicked();
    void on_boutonRetourMenu_clicked();
    void on_ouvrirExploreur_clicked();
    void on_boutonMetronome_clicked();
    void on_boutonVolume_valueChanged(int position);
    void on_boutonSonOn_clicked();
    void on_boutonBpm_valueChanged(int bpm);

signals :
    void operate ();
    void timerLance ();

private:
    Ui::FenEntrainement *ui;
};

void simulationEspace ();

#endif // FENENTRAINEMENT_H
