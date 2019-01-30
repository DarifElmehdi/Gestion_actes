#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "config.h"

void menu(Liste *liste)
{
    int k;
    do
    {   system("clear");
   	    printf("\n#############################################################################");
   	    printf("\n**                                                                         **");
   	    printf("\n**                          Gestionnaire d'actes                           **");
  	    printf("\n**                                                                         **");
   	    printf("\n**                                          By :  ISSAM ELMACHEHOUR        **");
        printf("\n**                                               & DARIF ELMEHDI           **");
        printf("\n#############################################################################");
        printf("\n**                       Les Choix disponibles:                            **");
        printf("\n**              1 : Gestion des Personnes.                                 **");
        printf("\n**              2 : Gestion des enfants d'une personne.                    **");
        printf("\n**              3 : Quitter.                                               **");
        printf("\n#############################################################################\n");
		printf("** tapez votre choix :");
        scanf("%d",&k);
        switch(k)
        {
            case 3 :
            {
                break;
            }
            case 2 :
            {
                menu_enfants(liste);
                break;
            }
            case 1 :
            {
                menu_personne(liste);
                break;
            }
        }
    } while (k!=3);
}

