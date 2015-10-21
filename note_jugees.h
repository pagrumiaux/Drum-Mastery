#ifndef NOTES_JUGEES
#define NOTES_JUGEES

class Note_jugee
{
public:
    Note_jugee();

    void creer_suivante(); // ajoute une note a la liste
    void suppr_suivantes(); //supprime toutes les notes suivantes dans la liste (dans la mesure)
    Note_jugee* getSuivante();
    void setSuivante(Note_jugee* note);
    bool getCorrecte();
    void setCorrecte(bool valeur);
    bool estDerniere();
    void setDerniere(bool v);
    int getTemps();
    void setTemps(int temps);
    bool estDefaut();

private:
    float m_temps_joue;
    bool m_est_correcte;
    Note_jugee *m_note_suivante;
    bool m_derniere;
};

#endif // NOTES_JUGEES

