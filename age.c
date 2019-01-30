#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
void age(Personne p)
{   int wite ;
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    printf("\n** La date d'aujourd'huit est : %d/%d/%d\n", instant.tm_mday, instant.tm_mon+1,instant.tm_year+1900);
    int age,jour,mois,annee;
    jour=p.date_de_naissance[0];
    mois=p.date_de_naissance[1];
    annee=p.date_de_naissance[2];
    age=instant.tm_year+1900;
    printf("votre age est :");
    if (mois>instant.tm_mon+1)
    {
    	age=age-annee-1;
    	printf("%d",age);
        printf("\nEntrez un nombre pour terminer l'affichage :");
        scanf("%d",&wite);
    }
    else if (mois<instant.tm_mon+1)
    {
    	age=age-annee;
    	printf("%d",age);
        printf("\nEntrez un nombre pour terminer l'affichage :");
        scanf("%d",&wite);
    }
    else
    {
    	if (jour<instant.tm_mday)
    	{
    		age=age-annee;
    		printf("%d",age);
            printf("\nEntrez un nombre pour terminer l'affichage :");
            scanf("%d",&wite);
    	}
    	else if (jour>instant.tm_mday)
    	{
    		age=age-annee-1;
    		printf("%d",age);
            printf("\nEntrez un nombre pour terminer l'affichage :");
            scanf("%d",&wite);
    	}
    	else
    	{
      		age=age-annee;
    		printf("%d",age);
    		printf("joyeux anniversaire\n");
            printf("\nEntrez un nombre pour terminer l'affichage :");
            scanf("%d",&wite);

    	}   
    }
}
