#ifndef BOUM_H
#define BOUM_H

#include <QObject>
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

    signals :
        void resultReady ();
    };

static int recordCallback(const void *inputBuffer, void *outputBuffer,
      unsigned long framesPerBuffer,
      const PaStreamCallbackTimeInfo* timeInfo,
      PaStreamCallbackFlags statusFlags,
      void *userData);

#endif // BOUM_H

