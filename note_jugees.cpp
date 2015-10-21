#include "notes_jugees.h"
#include <stddef.h>

Note_jugee::Note_jugee()
{
    m_temps_joue = 0;
    m_est_correcte = false;
    m_note_suivante = NULL;
    m_derniere = true;
}

bool Note_jugee::estDefaut()
{
    if((m_temps_joue == 0) && (m_est_correcte = false) && (m_note_suivante == NULL) && (m_derniere == true))
        return true;
    else
        return false;
}

void Note_jugee::creer_suivante()
{
    Note_jugee *note = new Note_jugee();
    m_derniere = false;
    m_note_suivante = note;
}

void Note_jugee::setSuivante(Note_jugee* note)
{
    m_note_suivante = note;
}

void Note_jugee::suppr_suivantes()
{

}

bool Note_jugee::getCorrecte()
{
    return m_est_correcte;
}

void Note_jugee::setCorrecte(bool valeur)
{
    m_est_correcte = valeur;
}

Note_jugee* Note_jugee::getSuivante()
{
    return m_note_suivante;
}

int Note_jugee::getTemps()
{
    return m_temps_joue;
}

void Note_jugee::setTemps(int temps)
{
    m_temps_joue = temps;
}

bool Note_jugee::estDerniere()
{
    return m_derniere;
}

void Note_jugee::setDerniere(bool v)
{
    m_derniere = v;
}

