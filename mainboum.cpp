/* Fonction main du programme qui écrit BOUM dans la console quand on tape sur la pad
Pour le faire marcher, il faut inclure la bibliothèque Portaudio au projet */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include "pa_asio.h"
#include "fenetreBoum.h"

#include <QApplication>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    FenetreBoum* fenetreun = new FenetreBoum();
    fenetreun->show();
    return app.exec();
}


