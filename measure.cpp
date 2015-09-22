#include "measure.h"
#include "note.h"
#include <stddef.h>

Measure::Measure()
{
    m_n = 4;
    m_u = 4;
    m_note_1 = NULL;
}

Measure::Measure(int n, int u)
{
    m_n = n;
    m_u = u;
    m_note_1 = NULL;
}

Measure::Measure(int n, int u, Note *note)
{
    m_n = n;
    m_u = u;
    m_note_1 = note;
}

void Measure::setN(int n)
{
    m_n = n;
}

void Measure::setU(int u)
{
    m_u = u;
}

void Measure::setNote(Note *note)
{
    m_note_1 = note;
}

Note* Measure::getNote()
{
    return m_note_1;
}

bool Measure::est_valable() const
{
    Note *note_int = m_note_1;
    float somme = .0;
    while (note_int->estDerniere() != true)
    {
        somme += note_int->getValeur();
        note_int = note_int->getSuivante();
    }
    somme += note_int->getValeur();

    if (somme == 1)
        return true;
    else
        return false;
}
