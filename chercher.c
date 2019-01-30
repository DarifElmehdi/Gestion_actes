#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Element* chercher_ide(Liste *liste)
{
	Element *element = malloc(sizeof(Element));
	int ide,test,i;
	printf("** entrer l'identifiant de la personne rechercher :");
	scanf("%d",&ide);
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
		printf("** l'element rechercher existe pour afficher ses info taper (1) :");
        scanf("%d",&test);
		if (test==1)
		{
			printf("\nle nom est : %s  ",element->personne.pr_nom);
			printf("\nle prenom est : %s ",element->personne.pr_prenom);
			printf("\nla date de naissance :   ");
			for (i = 0; i < 3; ++i)
			{
			switch(i+1)
			{
				case 1:
				{
					printf("\n\tle jour : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("\n\tle mois : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("\n\tl'année : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("\nle sexe est : ");
			if (element->personne.sexe == 0 )
			{
				printf("Homme");
			}
			else
			{
				printf("\nFemme");
			}
			printf("\nle CIN est : %s  ",element->personne.CIN);
			printf("\nl'identifiant est : %d  ",element->personne.identifiant);
			printf("\nle nombre d'enfants est : %d  ",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("\nles identifiant des enfants sont :  ");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("\n\tl'ide de l'enfant %d est : %d   ",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_CIN(Liste *liste)
{
	int test,i;
    char C[_MAX];
	printf("** entrer le CIN de la personne rechercher :");
	scanf("%s",C);

    Element *element = malloc(sizeof(Element));
    element = liste->premier;

	while(element != NULL && (strcmp(C,element->personne.CIN))!=0)
	{
		element=element->suivant;
	}
	if (element==NULL || (strcmp(C,element->personne.CIN))!=0)
	{
        return NULL;
	}
	else
	{
		printf("** l'element rechercher existe pour afficher ses info taper (1) :\n");
        scanf("%d",&test);
		if (test==1)
		{
			printf("\nle nom est : %s  ",element->personne.pr_nom);
			printf("\nle prenom est : %s  ",element->personne.pr_prenom);
			printf("\nla date de naissance : \n");
			for (i = 0; i < 3; ++i)
			{
			switch(i+1)
			{
				case 1:
				{
					printf("\tle jour : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("\tle mois : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("\tl'année : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("\nle sexe est :");
			if (element->personne.sexe == 0)
			{
				printf("\n\tHomme");
			}
			else
			{
				printf("\n\tFemme");
			}

			printf("\nl'identifiant de la personne est : %d ",element->personne.identifiant);
			printf("\nl'identifiant est : %d ",element->personne.identifiant);
			printf("\nle nombre d'enfants est : %d ",element->personne.nbr_d_enfant);

			if (element->personne.nbr_d_enfant != 0)
			{
				printf("\nles identifiant des enfant sont :  ");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("\tl'ide de l'enfant %d est : %d ",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_nom(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int test,i;
	char re_nom[_MAX];
	printf("\n** entrer le nom de la personne a rechercher :  ");
	scanf("%s",re_nom);
	element=liste->premier;

	do
	{
		while((element!=NULL) && strcmp(re_nom,element->personne.pr_nom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_nom,element->personne.pr_nom)!=0)
		{
            return NULL;
		}
		else
		{
			printf("\nla personne avec le nom rechercher est trouver ses info sont les suivants:");
			printf("\nle prenom est : %s  ",element->personne.pr_prenom);
			printf("\nla date de naissance :   ");
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
					printf("\n\tl'année : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("\nle sexe est : ");
			if (element->personne.sexe == 0)
			{
				printf("\tHomme");
			}
			else
			{
				printf("\tFemme");
			}

			printf("\nl'identifiant de la personne est : %d  ",element->personne.identifiant);
			printf("\nl'identifiant est : %d  ",element->personne.identifiant);
			printf("\nle nombre d'enfants est : %d  ",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant != 0)
			{
				printf("\nles identifiant des enfant sont :");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("\n\tl'ide de l'enfant %d est : %d ",(i+1),element->personne.enfant_ide[i]);
			}
        }
		printf("\nsi la personne ne correspond pas a ce que vous voulez veuillez appuiez sur (1) :");
		scanf("%d",&test);
	} while (test==1);
	return element;
}

Element* chercher_prenom(Liste *liste)
{
	Element *element = malloc(sizeof(Element));
	int test,i;
	char re_prenom[_MAX];
	printf("\nentrer le prenom de la personne rechercher :  ");
    fflush(stdin);
    scanf("%s",re_prenom);
    element=liste->premier;
	do
	{
		while(element!=NULL && strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			return NULL;
		}
		else
		{
			printf("\nla personne avec le prenom rechercher est trouver ses info sont les suivants: ");
			printf("\nle nom est : %s ",element->personne.pr_nom);
			printf("\nla date de naissance :  ");
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
					printf("\n\tl'année : %d  ",element->personne.date_de_naissance[i]);
					break;
				}
			}
			}
			printf("\nle sexe est : ");
			if (element->personne.sexe == 0)
			{
				printf("\tHomme");
			}
			else
			{
				printf("\tFemme");
			}
			printf("\nl'identifiant de la personne est : %d  ",element->personne.identifiant);
			printf("\nl'identifiant est : %d  ",element->personne.identifiant);
			printf("\nle nombre d'enfants est : %d  ",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("\nles identifiant des enfant sont :");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("\n\tl'ide de l'enfant %d est : %d ",(i+1),element->personne.enfant_ide[i]);
			}
            
        }
		printf("** Si la personne ne correspond pas a ce que vous voulez veuillez appuiez sur (1) :\n");
		scanf("%d",&test);
	}while (test==1);
	return element;
}
