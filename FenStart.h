#ifndef FENSTART_H
#define FENSTART_H

#include <QWidget>

namespace Ui {
class FenStart;
}

class FenStart : public QWidget
{
    Q_OBJECT

public:
    explicit FenStart(QWidget *parent = 0);
    ~FenStart();

private slots:

    void on_BoutonModePartition_clicked();

    void on_boutonModeEntrainement_clicked();

private:
    Ui::FenStart *ui;
};

#endif // FENSTART_H
