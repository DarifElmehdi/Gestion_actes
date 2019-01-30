
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
void modifier_enfants(Personne *personne)
{
	int nv_nbr;
	printf("\n** Entrez l'identifiant de l'enfant que tu veux ajouter :");
	scanf("%d",&nv_nbr);
    personne->enfant_ide[personne->nbr_d_enfant]=nv_nbr;
    personne->nbr_d_enfant+=1;
    
}
