#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "config.h"
void enregistrer(Liste *liste);
void menu_personne(Liste *liste)
{ int wait;
  int l=99,i=99;
  Personne *p=malloc(sizeof(Personne));
  Element *element=malloc(sizeof(Element));
  liste=lire();
  do{
    system("clear");
   	printf("\n#############################################################################");
   	printf("\n**                                                                         **");
   	printf("\n**                          Gestionnaire d'actes                           **");
  	printf("\n**                                                                         **");
   	printf("\n**                                          By :  ISSAM ELMACHEHOUR        **");
    printf("\n**                                               & DARIF ELMEHDI           **");
    printf("\n#############################################################################");
    printf("\n**      1 : pour ajouter une nouvelle personne.                            **");
    printf("\n**      2 : pour modifier une personne.                                    **");
    printf("\n**      3 : pour supprimer une personne.                                   **");
    printf("\n**      4 : Afficher les personnes.                                        **");
    printf("\n**      5 : Retourner le nom de mère ou père d’une personne                **");
    printf("\n**      6 : Chercher une personne.                                         **");
    printf("\n**      7 : Retourner l’age d’une personne.                                **");
    printf("\n**      8 : Trier la liste des personnes (selon le nom et l’identifiant).  **");
    printf("\n**      9 : Imprimer données (Actes).                                      **");
    printf("\n**      0 : Quitter.                                                       **");
    printf("\n#############################################################################");
    printf("\n** Entrez votre choix :");
    scanf("%d",&l);
    switch(l){
      case 0 : {break;}
      case 1:{//ajouter des personnes
        system("clear");
      	ajouter(liste);
        enregistrer(liste);
        }break;
      case 2:{//modifier un personne
        system("clear");
      	modifier(liste);
        enregistrer(liste);
        }break;
      case 3:{ //supprimer un personne
        system("clear");
        printf("\n#############################################################################");
        printf("\n**                               ATTENTION                                 **");
        printf("\n**           Voulez-vous vraiment  effectuer cette  operation?             **");
        printf("\n#############################################################################");
        printf("\n**     1 : Confirmer                                                       **");
        printf("\n**     0 : Annuler                                                         **");
        printf("\n#############################################################################");
        printf("\n** Tapez votre choix :");
        scanf("%d",&i);
        system("clear");
        if(i==1){
                supprimer(liste);
          }
        enregistrer(liste);
        }break;
      case 4 :{//afficher des personnes
      	system("clear");
        printf("\n#############################################################################");
        consulter(liste);
        };break;
      case 5:{//chercher des parents
      	system("clear");
      	int f;
        printf("\n#############################################################################");
        printf("\n**                voulez-vous chercher  :                                 **");
        printf("\n**    1 : le pere                                                         **");
        printf("\n**    2 : la mere                                                         **");
        printf("\n############################################################################\n");
        printf("\n** Tapez votre choix :");      	
        scanf("%d",&f);
      	switch(f)
        {
          	case 1:
            {
                printf("** saisie l'identifiant de l'enfant : ");
                scanf("%d",&f);
                element=chercher_pere(liste, f);
            	break;
          	}
          	case 2:
          	{
                printf("** saisie l'identifiant de l'enfant : ");
                scanf("%d",&f);
            	  element=chercher_mere(liste, f);
                break;
            }
        }
          p=&element->personne;
          if(p!=NULL)
          {
              printf("\n** le nom est : %s",p->pr_nom);
              printf("\n** le prenom est : %s",p->pr_prenom);
              printf("\n** la date de naissance :");
              for (i = 0; i < 3; ++i)
              {
                  switch(i+1)
                  {
                      case 1:
                      {
                          printf("\n\t** le jour : %d",element->personne.date_de_naissance[i]);
                          break;
                      }
                      case 2:
                      {
                          printf("\n\t** le mois : %d",element->personne.date_de_naissance[i]);
                          break;
                      }
                      case 3:
                      {
                          printf("\n\t** l'année : %d",element->personne.date_de_naissance[i]);
                          break;
                      }
                  }
              }
              printf("\n** le sexe est : %u",p->sexe);
              printf("\n** le CIN est : %s",p->CIN);
              printf("\n** l'identifiant est : %d",p->identifiant);
              printf("\n** le nombre d'enfants est : %d",p->nbr_d_enfant);
              for (i = 0; i < p->nbr_d_enfant; i++)
              {
                  printf("\n** l'ide de l'enfant %d est : %d ",i+1,p->enfant_ide[i]);
              }
              printf("\nTapez un nombre pour terminer l'affichage ");
          scanf("%d",&wait);
          break ;
          }
          else
            printf("** Pere ou mere non trouver !!");
            printf("\nTapez un nombre pour terminer  ");
            scanf("%d",&wait);
          break;
          }
          printf("\nTapez un nombre pour terminer l'affichage ");
          scanf("%d",&wait);
      case 6://Chercher une personne.
        {
          system("clear");
          printf("\n#############################################################################");
          printf("\n**               voulez-vous recherche par:                                **");
          printf("\n**     1 : identifiant                                                     **");
          printf("\n**     2 : nom                                                             **");
          printf("\n**     3 : prenom                                                          **");
          printf("\n**     4 : CIN                                                             **");
          printf("\n**     0 : Annuler                                                         **");
          printf("\n#############################################################################");
          printf("\n** Tapez votre choix :");
          scanf("%d",&i);
          switch(i)
          {
            case 1:
            {
              chercher_ide(liste);
              break;
            }
            case 4:
            {
              chercher_CIN(liste);
              break;
            }
            case 2:{
              chercher_nom(liste);
              break;
            }
            case 3:{
          		chercher_prenom(liste);
          		break;
          	}
          	case 0:{break;}
          }
        break;
        }
      case 7://Retourner l’age d’une personne
      {
      	system("clear");
        element=chercher_ide(liste);
        if (element==NULL)
        {
        	printf("** la personne n'existe pas\n");
        }
        else
        {age(element->personne);}
        break;
      }
      case 8://Trier la liste des personnes
      {
      	system("clear");
      	int o;
        printf("\n#############################################################################");
        printf("\n**           voulez-vous Trier la liste selon:                             **");
        printf("\n**     1 : identifiant                                                     **");
        printf("\n**     2 : nom                                                             **");
        printf("\n**     0 : Annuler                                                         **");
        printf("\n#############################################################################");
        printf("\n** Affectez un choix : ");
        scanf("%d",&o);
        switch(o)
        {
        	case 0:break;
        	case 1:{
        		trie_ide(liste);
            liste=lire();
            consulter(liste);
        		break;
        	}
        	case 2:{
        		trie_nom(liste);
            liste=lire();
            consulter(liste);
        		break;
        	}
        }
        	break;
        }
      case 9://Imprimer données
        {
        	system("clear");
        	element=chercher_ide(liste);
        	remplir_acte(element,liste);
        	break;
        }
    }

  }while(l!=0);
}
void enregistrer(Liste *liste)
{
    int i;
    system("clear");
    printf("\n#############################################################################");
    printf("\n**        Voulez vous enregistrer les modifications saisie (1):            **");
    printf("\n**      1 : Oui                                                            **");
    printf("\n**      2 : non                                                            **");
    printf("\n#############################################################################");
    printf("\n** votre choix : ");
    scanf("%d",&i);
    if(i==1) Ecrire(liste);
    else liste=lire();
}