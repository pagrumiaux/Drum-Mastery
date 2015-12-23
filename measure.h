#ifndef MEASURE
#define MEASURE

#include "note.h"
#include "stdlib.h"
#include "measure.h"

class Measure
{
public:
    Measure();
    Measure(int n, int u);
    Measure(int n, int u, Note *note);
    void setN(int n);
    int getN();
    void setU(int u);
    int getU();
    void setNote(Note *note);
    Note* getNote();
    bool est_valable() const;
    void creerSuivante();
    Measure* getSuivante();
    bool getDerniere();

private:
    int m_n;
    int m_u;
    Note *m_note_1;
    Measure *mesure_suivante;
    bool estDerniere;

};

#endif // MEASURE
