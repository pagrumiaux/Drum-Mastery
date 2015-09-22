#ifndef MEASURE
#define MEASURE

#include "note.h"
#include "stdlib.h"

class Measure
{
public:
    Measure();
    Measure(int n, int u);
    Measure(int n, int u, Note *note);
    void setN(int n);
    void setU(int u);
    void setNote(Note *note);
    Note* getNote();
    bool est_valable() const;

private:
    int m_n;
    int m_u;
    Note *m_note_1;

};

#endif // MEASURE
