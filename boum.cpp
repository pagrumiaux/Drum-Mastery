/*Cette page contient le code qui permet de faire une boucle d'enregistrement et d'écoute des signaux en entrée de l'entrée ligne de l'ordinateur.
Attention, inputParameters.device correspond à l'entrée ligne de mon ordinateur, et vaut 7 ici, mais ce chiffre dépend de l'ordinateur */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "portaudio.h"
#include "pa_asio.h"
#include <QApplication>
#include "boum.h"

#define SAMPLE_RATE  (44100)//(44100)
#define FRAMES_PER_BUFFER (103)//(512)
#define NUM_SECONDS     (0.08)// Le temps de traitement de l'enregistrement et de réinitialisation est de 0,08s
#define NUM_CHANNELS    (2)

#define DITHER_FLAG     (0)
#define WRITE_TO_FILE   (0)

#if 1
#define PA_SAMPLE_TYPE  paFloat32
typedef float SAMPLE;
#define SAMPLE_SILENCE  (0.0f)
#define PRINTF_S_FORMAT "%.8f"
#elif 1
#define PA_SAMPLE_TYPE  paInt16
typedef short SAMPLE;
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%d"
#elif 0
#define PA_SAMPLE_TYPE  paInt8
typedef char SAMPLE;
#define SAMPLE_SILENCE  (0)
#define PRINTF_S_FORMAT "%d"
#else
#define PA_SAMPLE_TYPE  paUInt8
typedef unsigned char SAMPLE;
#define SAMPLE_SILENCE  (128)
#define PRINTF_S_FORMAT "%d"
#endif

using namespace std;

typedef struct
{
    int          frameIndex;  /* Index into sample array. */
    int          maxFrameIndex;
    SAMPLE      *recordedSamples;
}
paTestData;

// Callback

static int recordCallback(const void *inputBuffer, void *outputBuffer,
    unsigned long framesPerBuffer,
    const PaStreamCallbackTimeInfo* timeInfo,
    PaStreamCallbackFlags statusFlags,
    void *userData)
{
    paTestData *data = (paTestData*)userData;
    const SAMPLE *rptr = (const SAMPLE*)inputBuffer;
    SAMPLE *wptr = &data->recordedSamples[data->frameIndex * NUM_CHANNELS];
    long framesToCalc;
    long i;
    int finished;
    unsigned long framesLeft = data->maxFrameIndex - data->frameIndex;

    (void)outputBuffer; /* Prevent unused variable warnings. */
    (void)timeInfo;
    (void)statusFlags;
    (void)userData;

    if (framesLeft < framesPerBuffer)
    {
        framesToCalc = framesLeft;
        finished = paComplete;
    }
    else
    {
        framesToCalc = framesPerBuffer;
        finished = paContinue;
    }

    if (inputBuffer == NULL)
    {
        for (i = 0; i<framesToCalc; i++)
        {
            *wptr++ = SAMPLE_SILENCE;  /* left */
            if (NUM_CHANNELS == 2) *wptr++ = SAMPLE_SILENCE;  /* right */
        }
    }
    else
    {
        for (i = 0; i<framesToCalc; i++)
        {
            *wptr++ = *rptr++;  /* left */
            if (NUM_CHANNELS == 2) *wptr++ = *rptr++;  /* right */
        }
    }
    data->frameIndex += framesToCalc;
    return finished;
}

Boum::Boum() //constructeur
{};

// fonction qui permet de lancer le debug qui affiche boum si on tape sur le pad

int Boum::fonctionBoum(void)
{
    PaStreamParameters  inputParameters,
        outputParameters;
    PaStream*           stream;
    PaError             err = paNoError;
    paTestData          data;
    int                 i, a = 0, b = 1; // M est le seuil de detection
    float				M = 0.0009;
    int                 totalFrames;
    int                 numSamples;
    int                 numBytes;
    SAMPLE              max, val;
    double              average;
    //Etude des peripheriques
    int numDevices;
    const PaDeviceInfo *deviceInfo;
    /*
    for(i=0; i<numDevices; i++)
    {
    deviceInfo = Pa_GetDeviceInfo(i);
    system("pause");
    }
    */

    //Debut de la boucle

    a = 0; // parametre determinant au bout de cbn de notes arreter le programme
    while (a<30)
    {
        val = 0.; // maximum d'amplitude des pics mesures
        a = a + 1;
        while (val<M)
        {
            //    qDebug() <<"patest_record.c"<< endl;
            fflush(stdout);

            data.maxFrameIndex = totalFrames = NUM_SECONDS * SAMPLE_RATE; /* Record for a few seconds. */
            data.frameIndex = 0;
            numSamples = totalFrames * NUM_CHANNELS;
            numBytes = numSamples * sizeof(SAMPLE);
            data.recordedSamples = (SAMPLE *)malloc(numBytes); /* From now on, recordedSamples is initialised. */
            if (data.recordedSamples == NULL)
            {
                //qDebug() << "Could not allocate record array." << endl;
                goto done;
            }
            for (i = 0; i < numSamples; i++)
            {
                data.recordedSamples[i] = 0;
            }

            err = Pa_Initialize();
            if (err != paNoError) goto done;
            //qDebug() << Pa_GetDeviceCount() << Pa_GetDefaultInputDevice();
            inputParameters.device = /*PaDeviceIndex(4)*/7 ;
            // 0 correspond a l'entree micro
            if (inputParameters.device == paNoDevice)
            {
                //qDebug() << "Error : No default input device" << endl;
                goto done;
            }
            inputParameters.channelCount = 2; //stereo input
            inputParameters.sampleFormat = PA_SAMPLE_TYPE;
            inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
            inputParameters.hostApiSpecificStreamInfo = NULL;

            // Ouverture du Stream puis ecoute

            //qDebug() << ".";

            err = Pa_OpenStream(
                &stream,
                &inputParameters,
                NULL,
                SAMPLE_RATE,
                FRAMES_PER_BUFFER,
                paClipOff,
                recordCallback,
                &data);
            if(err!=paNoError) goto done;

            err = Pa_StartStream(stream);
            if(err!=paNoError) goto done;
            //qDebug() << "Now recording"<< endl;
            fflush(stdout);

            while ((err = Pa_IsStreamActive(stream)) == 1)
            {
                    Pa_Sleep(50);
                    //qDebug() << "Now stream active" << endl;
                    //qDebug() << "index "<< data.frameIndex << endl;
                fflush(stdout);
            }
            //if(err < 0) goto done;

            err = Pa_CloseStream(stream);
            if(err!=paNoError) goto done;

            /*MAXIMUM PEAK AMPLITUDE*/
            i = 0;
            max = 0;
            while (i<numSamples-1 && val<M)
            {
                i++;
                val = data.recordedSamples[i];
                //	if(data.recordedSamples[i] > 0.5)
                //qDebug() << data.recordedSamples[i] << endl ;
                if(val<0) val=-val;
                if (val>max) max = val;
            }
            //qDebug() << " /";
            //qDebug() << "valeur du pic" << max << endl;
            if (val>M)
            {
                qDebug("BOUM %d %f",b,val);
                //Pa_Sleep(80);

            }
        }
    }

done:
    Pa_Terminate();
    if (data.recordedSamples)
        free(data.recordedSamples);
    if (err != paNoError)
        //qDebug() << "Error" << endl;
    return 0;
}

