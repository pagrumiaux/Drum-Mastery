#ifndef BOUM_H
#define BOUM_H


class Boum
{
public:
    Boum();
    int fonctionBoum(void);
};

static int recordCallback(const void *inputBuffer, void *outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData);

#endif // BOUM_H
