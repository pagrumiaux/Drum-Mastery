#ifndef FENENTRAINEMENT_H
#define FENENTRAINEMENT_H

#include <QWidget>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>


namespace Ui {
class FenEntrainement;
}

class FenEntrainement : public QWidget
{
    Q_OBJECT

public:
    explicit FenEntrainement(QWidget *parent = 0);
    ~FenEntrainement();

private slots:
    void on_boutonPlayPause_clicked();

    void on_boutonRetourMenu_clicked();

    void on_ouvrirExploreur_clicked();

    void on_nouveau_clicked();

    void on_boutonModeVue_clicked();

    void on_stop_clicked();

    void on_boutonMetronome_clicked();

    void on_boutonVolume_valueChanged(int position);

    void on_boutonSonOn_clicked();

    void on_boutonStop_clicked();

private:
    Ui::FenEntrainement *ui;
};

#endif // FENENTRAINEMENT_H
