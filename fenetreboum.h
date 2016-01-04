#ifndef FENETREBOUM_H
#define FENETREBOUM_H

#include <QWidget>

namespace Ui {
class FenetreBoum;
}

class FenetreBoum : public QWidget
{
    Q_OBJECT

public:
    explicit FenetreBoum(QWidget *parent = 0);
    ~FenetreBoum();

private slots:
    void on_boutonBoum_clicked();

private:
    Ui::FenetreBoum *ui;
};

#endif // FENETREBOUM_H
