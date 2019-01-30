#ifndef struct_c
#define struct_c
#define _MAX 15
#define nbrMAX 10

typedef struct Personne
{
    char pr_nom[_MAX];
    char pr_prenom[_MAX];
    int sexe;
    int date_de_naissance[3];
    char CIN[_MAX];
    int identifiant;
    int nbr_d_enfant;
    int enfant_ide[nbrMAX];

}Personne;

typedef struct Element Element;
struct Element
{
    Personne personne;
    Element *suivant;

};

typedef struct Liste
{
    Element *premier;
}Liste;

/*
 typede struct Fin Fin
 {
	Personne *dernier;
 };
 */
/*
typedef struct Arbre_famille
{
    int arb_ide_prs;
    struct Arbre_famille *droit;
    struct Arbre_famille *gauche;
}Arbre_famille;
*/


#endif 