# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "structs.h"
#include "config.h"
void menu_enfants(Liste *liste)
{
	int i,ide ,wait;
    liste=lire();
  	Element *element=malloc(sizeof(Element));
  	do
  	{	system("clear");
    	printf("\n#############################################################################");
    	printf("\n**                                                                         **");
    	printf("\n**                          Gestionnaire d'actes                           **");
    	printf("\n**                                                                         **");
    	printf("\n**                                          By :  ISSAM ELMACHEHOUR        **");
   	    printf("\n**                                               & DARIF ELMEHDI           **");
      	printf("\n#############################################################################");
        printf("\n**            voulez-vous :                                                **");
        printf("\n**  1 : Afficher les informations sur les enfants d’une personne           **");
        printf("\n**  2 : Ajouter les enfants d’une personne                                 **");
        printf("\n**  0 : sortir                                                             **");
        printf("\n#############################################################################");
        printf("\n** Entrez votre choix :");
        scanf("%d",&i);
        switch(i)
        {
        	case 0:
        	{
        		enregistrer(liste);
        		break;
        	}
        	case 1:
        	{
                printf("** Donnez l'id du parent :");
                scanf("%d",&ide);
        		afficher_enfants(ide,liste);
				scanf("%d",&wait);
        		break;
        	}
        	case 2:
        	{
        		element=chercher_ide(liste);
                if (element==NULL)
                {
                    printf("** La personne n'existe pas\n");
                }
                else
        		{modifier_enfants(&(element->personne));}
        		break;
        	}
        }
  	} while (i!=0);
}
