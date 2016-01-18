#ifndef FENEDITION_H
#define FENEDITION_H

#include <QWidget>
#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class FenEdition;
}

class FenEdition : public QWidget
{
    Q_OBJECT

public:
    explicit FenEdition(QWidget *parent = 0);
    ~FenEdition();

private slots:
    void on_boutonPlayPause_clicked();

    void on_boutonSonOn_clicked();

    void on_boutonRetourArriere_clicked();

    void on_ouvrirExploreur_clicked();

    void on_nouveau_clicked();

private:
    Ui::FenEdition *ui;
};

#endif // FENEDITION_H
