#include "measure.h"
#include "note.h"
#include <stddef.h>

Measure::Measure()
{
    m_n = 4;
    m_u = 4;
    m_note_1 = NULL;
    estDerniere = true;
}

Measure::Measure(int n, int u)
{
    m_n = n;
    m_u = u;
    m_note_1 = NULL;
    estDerniere = true;
}

Measure::Measure(int n, int u, Note *note)
{
    m_n = n;
    m_u = u;
    m_note_1 = note;
    estDerniere = true;
}

void Measure::setN(int n)
{
    m_n = n;
}

int Measure::getN()
{
    return m_n;
}

void Measure::setU(int u)
{
    m_u = u;
}

int Measure::getU()
{
    return m_u;
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
    double somme = .0;
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

void Measure::creerSuivante()
{
    Measure *mesure = new Measure(m_n, m_u);
    mesure_suivante = mesure;
    estDerniere = false;
}

Measure *Measure::getSuivante()
{
    return mesure_suivante;
}

bool Measure::getDerniere()
{
    return estDerniere;
}
