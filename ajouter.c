
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "config.h"


void ajouter(Liste *liste)
{
    int i ,test=1;
    do
    {
        int ide;
        test=0;
        Personne nv_personne;
        Element *nv_element=malloc(sizeof(*nv_element));
        printf("\nentrer le nom :  ");
        scanf("%s",nv_personne.pr_nom);
        printf("\nentrer le prenom :  ");
        scanf("%s",nv_personne.pr_prenom);
        printf("\nchoisis ton sexe (0)Homme (1)Femme :  ");
        scanf("%u",&nv_personne.sexe);
        if (liste->premier==NULL) ide=1;
        else
            ide=liste->premier->personne.identifiant+1;
        nv_personne.identifiant=ide;
        printf("\nla date de naissance :");
        for (i = 0; i < 3; ++i)
        {
            switch(i)
            {
                case 0:
                {
                    printf("\n\tEntrer le jour :  ");
                    break;
                }
                case 1:
                {
                    printf("\n\tEntrer le mois :  ");
                    break;
                }
                case 2:
                {
                    printf("\n\tEnter l'année  :  ");
                    break;
                }
            }
            scanf("%d",&nv_personne.date_de_naissance[i]);
        }
        printf("\nEntrer votre CIN :  ");
        scanf("%s",nv_personne.CIN );
        nv_personne.identifiant=ide;
        printf("\nEntrer le nombre d'enfant :");
        scanf("%u",&nv_personne.nbr_d_enfant);

        if (nv_personne.nbr_d_enfant!=0)
        {
            printf("\nentrer l'ide des enfant :");
        }
        for (i = 0;i < nv_personne.nbr_d_enfant; i++)
        {   printf("\t") ;
            scanf("%d",&ide);
            if (verification_ide(liste,ide,nv_personne.sexe)==1)
            {
                nv_personne.enfant_ide[i]=ide;
        
            }
            else
                i--;
        }
        nv_element->personne=nv_personne;
        nv_element->suivant=liste->premier;
        liste->premier=nv_element;
        
        printf("\nSi vous voulez ajouter autre Personne appui sur (1) :");
        scanf("%d",&test);
    } while (test==1);
}


int verification_ide(Liste *liste,int ide,int sexe)
{
    int i;

    Element *element = malloc(sizeof(Element));
    element = liste->premier;

    while((element!=NULL))
    {
        if(element->personne.sexe==sexe)
        {
            for(i=0 ; i<element->personne.nbr_d_enfant ; i++)
            {
                if(ide == element->personne.enfant_ide[i])
                    return 0;
                    
            }
        }

        element = element->suivant;
    }

    return 1;
}
