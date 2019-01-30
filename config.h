#include "structs.h"
#ifndef config_h
#define config_h
//FONCTIONS DE MENU
void menu(Liste *liste);
void menu_enfants(Liste *liste);
void menu_personne(Liste *liste);

//FONCTION DE GESTION DES PERSONNE
void afficher_enfants(int ide,Liste *liste);
void modifier_enfants(Personne *personne);
void ajouter(Liste *liste);
int verification_ide(Liste *liste,int ide,int sexe);
void consulter(Liste *liste);
void age(Personne p);


//FONCTION DE RECHERCHE 
Element* chercher_ide(Liste *liste);
Element* chercher_CIN(Liste *liste);
Element* chercher_nom(Liste *liste);
Element* chercher_prenom(Liste *liste);
Element* chercher_enfants(Liste *liste,int ide);
Element* chercher_mere(Liste *liste,int ide);
Element* chercher_pere(Liste *liste,int ide);





//FONCTION DE LECTURE ET ECRITURE SUR REGISTRE 
Liste* lire();
void Ecrire(Liste *liste);
void enregistrer(Liste *liste);
void supprimer(Liste *liste);
void modifier(Liste *liste);
void remplir_acte(Element *element,Liste *liste);



//FONCTION DE TRIE 
void trie_ide(Liste *liste);
void trie_nom(Liste *liste);
//Fonction du permutation
void cha(char a[],char b[]);
void in(int *a, int *b);


#endif