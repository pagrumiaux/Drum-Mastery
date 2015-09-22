#ifndef NOTE
#define NOTE

class Note
{
public:
    Note();
    Note(int type, float valeur);
    Note(int type, float valeur, Note *suivante);

    void ajouter_suivante(Note *suivante); // ajoute une note a la liste
    void suppr_suivantes(); //supprime toutes les notes suivantes dans la liste (dans la mesure)

    float getValeur(); //renvoie la valeur de la note (dépend du chiffrage)
    int getType(); //renvoie le type de note
    Note* getSuivante(); //renvoie un pointeur vers la note suivante dans la liste chainee
    bool estDerniere(); //renvoie true ou false si elle est derniere ou pas dans la liste chainee

private:
    Note *m_suivante; //pointeur vers la prochaine note dans la liste chainée
    int m_type; //0 pour un soupir, 1 pour une note
    float m_valeur; //valeur de la note
    int m_numero; //numero de la note
    bool derniere; //derniere note ou pas

};

#endif // NOTE
