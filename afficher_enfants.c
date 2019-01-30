#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
Element* chercher_enfants(Liste *liste,int ide);
void afficher_enfants(int ide,Liste *liste)
{
    int j;
    if (chercher_enfants(liste,ide)==NULL)
    {
        printf("\n** la personne n'existe pas !!");
        exit(0);
    }
    else
    {   Personne p=chercher_enfants(liste,ide)->personne;
        system("clear");
        for(j=0;j<p.nbr_d_enfant;j++)
        {   
            printf("\nL'enfant %d :",j);
            chercher_enfants(liste,p.enfant_ide[j]);
        }
    }
}

Element* chercher_enfants(Liste *liste,int ide)
{
    Element *element=malloc(sizeof(Element));
    int test,i=0;
    element=liste->premier;
    while(element!=NULL&&(ide!=element->personne.identifiant) )
    {
        element=element->suivant;
    }
    if (element==NULL || ide!=element->personne.identifiant)
    {
        return NULL;
    }
    else
    {
        test=1;
        if (test==1)
        {
            printf("\nle nom est : %s",element->personne.pr_nom);
            printf("\nle prenom est : %s",element->personne.pr_prenom);
            printf("\nla date de naissance : ");
            for (i = 0; i < 3; ++i)
            {
                switch(i+1)
                {
                    case 1:
                    {
                        printf("    le jour : %d\n",element->personne.date_de_naissance[i]);
                        break;
                    }
                    case 2:
                    {
                        printf("    le mois : %d\n",element->personne.date_de_naissance[i]);
                        break;
                    }
                    case 3:
                    {
                        printf("    l'année : %d\n",element->personne.date_de_naissance[i]);
                        break;
                    }
                }
            }
            printf("\nle sexe est : ");
            if (element->personne.sexe==0)
            {
                printf("\tHomme");
            }
            else
            {
                printf("\tFemme");
            }
            printf("\nle CIN est : %s",element->personne.CIN);
            printf("\nl'identifiant est : %d",element->personne.identifiant);
            printf("\nle nombre d'enfants est : %d",element->personne.nbr_d_enfant);
            if (element->personne.nbr_d_enfant!=0)
            {
                printf("\nles identifiant des enfants sont :");
            }
            for (i = 0; i < element->personne.nbr_d_enfant; ++i)
            {
                printf("\n\tl'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
            }
        }
    }
    return element;
}