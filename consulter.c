#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>
void consulter(Liste *liste)
{   int wite ;
    int i;
    Personne personne;
    Element *element = malloc(sizeof(*element));
    element = liste->premier;
    while(element!=NULL)
    {
        personne=element->personne;
        printf("\nle nom est : %s  ",personne.pr_nom);
        printf("\nle prenom est : %s ",personne.pr_prenom);
        printf("\nla date de naissance : ");
		for (i = 0; i < 3; ++i)
		{
			switch(i+1)
			{
				case 1:
				{
					printf("\n\tle jour : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("\n\tle mois : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("\n\tl'année : %d \n ",element->personne.date_de_naissance[i]);
					break;
				}
			}
		}
        printf("\nle sexe est :");
        if (personne.sexe == 0)
        {
        	printf("\tHomme");
        }
        else
        {
        	printf("\tFemme");
        }
        printf("\nle CIN est : %s  ",personne.CIN);
        printf("\nl'identifiant est : %d ",personne.identifiant);
        printf("\nle nombre d'enfants est : %d  ",personne.nbr_d_enfant);
        for (i = 0; i < personne.nbr_d_enfant; i++)
        {
            printf("\nl'ide de l'enfant %d est : %d  \n",i+1,personne.enfant_ide[i]);
        }
        printf("\n");
        
        element=element->suivant;
    } 
    printf("Entrez un nombre pour terminer l'affichageé");
    scanf("%d",&wite);
}