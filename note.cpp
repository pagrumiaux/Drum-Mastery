#include "Note.h"
#include <stddef.h>

Note::Note()
{
    m_type = 0;
    m_valeur = 0;
    m_suivante = NULL;
}

Note::Note(int type, float valeur)
{
    if ((type == 0) || (type = 1))
        m_type = type;
    if (valeur <= 1)
        m_valeur = valeur;

    m_suivante = NULL;
    derniere = true;
}

Note::Note(int type, float valeur, Note *suivante)
{
    if ((type == 0) || (type = 1))
        m_type = type;
    if (valeur <= 1)
        m_valeur = valeur;

    m_suivante = suivante;
    derniere = false;
}

void Note::ajouter_suivante(Note *suivante)
{
    derniere = false;
    m_suivante = suivante;
}

void Note::suppr_suivantes()
{
    if (m_suivante != 0)
    {
        m_suivante->suppr_suivantes();
        delete m_suivante;
    }
    derniere = true;
}

float Note::getValeur()
{
    return m_valeur;
}

Note* Note::getSuivante()
{
    return m_suivante;
}

int Note::getType()
{
    return m_type;
}

bool Note::estDerniere()
{
    return derniere;
}
