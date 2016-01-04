/* Fichier cpp lié à la classe fenetreBoum et au fichier Gui avec un bouton push qui lance le programme BOUM dans la console Qt */

#include "fenetreboum.h"
#include "ui_fenetreboum.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QtConcurrent>
#include "portaudio.h"
#include "pa_asio.h"
#include "boum.h"
#include "fenetreboum.h"

FenetreBoum::FenetreBoum(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FenetreBoum)
{
    ui->setupUi(this);
}

FenetreBoum::~FenetreBoum()
{
    delete ui;
}

void FenetreBoum::on_boutonBoum_clicked()
{
    Boum cake;
    cake.fonctionBoum();
    //QFuture<int> future = QtConcurrent::run(cake, &Boum::fonctionBoum);
}
