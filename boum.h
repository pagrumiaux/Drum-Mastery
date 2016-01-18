#ifndef BOUM_H
#define BOUM_H

#include<QTime>
#include <QObject>
#include <QMediaPlayer>
#include "portaudio.h"
#include "fenentrainement.h"

class Boum : public QObject
       {
    Q_OBJECT

    public:
        Boum();
        int fonctionBoum(void);

    public slots :
        void doWork ();
        void lancerTimer();

    signals :
        void resultReady ();

   private :
        QTime time;
    };

static int recordCallback(const void *inputBuffer, void *outputBuffer,
      unsigned long framesPerBuffer,
      const PaStreamCallbackTimeInfo* timeInfo,
      PaStreamCallbackFlags statusFlags,
      void *userData);

#endif // BOUM_H
