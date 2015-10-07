#ifndef FENEDITION_H
#define FENEDITION_H

#include <QWidget>

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

private:
    Ui::FenEdition *ui;
};

#endif // FENEDITION_H
