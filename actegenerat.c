#include <stdio.h>
#include "structs.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "config.h"

int numero_acte();
void remplir_acte(Element *element,Liste *liste)
{  
    char etat[_MAX*_MAX] , service[_MAX*_MAX] ,enonciations[_MAX*_MAX],nomacte[_MAX*_MAX];
    int numero = numero_acte();
    unsigned long longueur;
    Element *element_mere=NULL;
    Element *element_pere=NULL;

    if(element!=NULL)
    {
        element_mere = chercher_mere(liste, element->personne.identifiant);
        element_pere = chercher_pere(liste, element->personne.identifiant);
    
    FILE* fichier = NULL;
    fichier = fopen("acte.html", "w");
    if (element_pere==NULL)
    {
        element_pere = malloc(sizeof(Element));
        element_pere->personne.pr_nom[0] = '\0';
        element_pere->personne.pr_prenom[0] = '\0';
    }
    if (element_mere==NULL)
    {
        element_mere=malloc(sizeof(Element));
        element_mere->personne.pr_nom[0]='\0';
        element_mere->personne.pr_prenom[0]='\0';
    }
    char sexe[6];
    if (element->personne.sexe == 0)
    {
    	sexe[0]='H';
    	sexe[1]='o';
    	sexe[2]='m';
    	sexe[3]='m';
    	sexe[4]='e';
    	sexe[5]='\0';
    }
    else
    {
    	sexe[0]='F';
    	sexe[1]='e';
    	sexe[2]='m';
    	sexe[3]='m';
    	sexe[4]='e';
    	sexe[5]='\0';
    }

    //pour la date acctuelle
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant = *localtime(&secondes);


    printf("\n\n\nEntez votre Etat :");
    scanf("%s",etat);
    printf("\nENtrez le service d'etat civil 'ville' :");
    scanf("%s",service);
    printf("\nVoulez-vous entrez autres enonciations de l'acte veuillez l'entrer :");
    scanf("%s",enonciations);
    printf("\nEntrez le nom sous le quel l'acte sera enregistrer :");
    scanf("%s",nomacte);


    fprintf(fichier,"<h3>&nbsp;</h3><h3>&nbsp;</h3><h3>1&nbsp; &nbsp;&Eacute;TAT :&nbsp; &nbsp; &nbsp; &nbsp; %s &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;</h3>",etat);

    fprintf(fichier,"<h3>2&nbsp; SERVICE DE L&rsquo;&Eacute;TAT CIVIL DE&nbsp;:&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; %s </h3><table style='height: 63px;' border='black' width='683'><tbody><tr style='height: 67.875px;'><td style='width: 673px; height: 67.875px; text-align: left;'><h3>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 3&nbsp; &nbsp;ETRAIT DE L&rsquo;",service);

    fprintf(fichier,"ACTE DE NAISSANCE N&deg; : %d &nbsp;</h3></td></tr></tbody></table><table style='height: 20px; width: 683px;' border='black'><tbody><tr style='height: 102px;'><td style='width: 44px; height: 102px;'><h3 style='text-align: center;'>&nbsp;4</h3></td><td style='width: 624px; height: 102px;'><h3>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; DATE ET LIEU DE NAISSANCE&nbsp; :&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;",numero);

    fprintf(fichier,"%d/%d/%d</h3></td></tr><tr style='height: 77.875px;'><td style='width: 44px; height: 77.875px; text-align: center;'><h3>5&nbsp;</h3></td><td style='width: 624px; height: 77.875px;'><h3>&nbsp; &nbsp; &nbsp; NOM :&nbsp; &nbsp; &nbsp; &nbsp;",element->personne.date_de_naissance[0],element->personne.date_de_naissance[1],element->personne.date_de_naissance[2] );

    fprintf(fichier,"%s</h3></td></tr><tr style='height: 81px;'><td style='width: 44px; height: 81px;'><h3 style='text-align: center;'>&nbsp;6</h3></td><td style='width: 624px; height: 81px;'><h3>&nbsp; &nbsp; &nbsp; PRENOM :&nbsp; &nbsp; &nbsp; ",element->personne.pr_nom);

    fprintf(fichier,"%s</h3></td></tr></tbody></table><table style='height: 27px; width: 683px;' border='black'><tbody><tr style='height: 44px;'><td style='width: 42px; height: 44px; text-align: center;'><h3>&nbsp;7</h3></td><td style='width: 220px; height: 44px;'><h3>&nbsp;SEXE :&nbsp; &nbsp; ",element->personne.pr_prenom);

    fprintf(fichier,"%s </h3></td><td style='width: 218px; height: 44px;'><h3>&nbsp;8&nbsp; &nbsp;&nbsp;P&Egrave;RE</h3></td><td style='width: 197px; height: 44px;'><h3>&nbsp;9&nbsp; &nbsp;M&Egrave;RE</h3></td></tr><tr style='height: 44px;'><td style='width: 42px; height: 37px; text-align: center;'><h3>&nbsp;5</h3></td><td style='width: 220px; height: 37px;'><h3>&nbsp;NOM</h3></td><td style='width: 218px; height: 37px;'><h3>&nbsp;",sexe);

    fprintf(fichier,"%s</h3></td><td style='width: 197px; height: 37px;'><h3>&nbsp;%s</h3></td></tr><tr style='height: 44px;'><td style='width: 42px; height: 45px;'><h3 style='text-align: center;'>&nbsp;6</h3></td><td style='width: 220px; height: 45px;'><h3>PRENOM&nbsp;</h3></td><td style='width: 218px; height: 45px;'><h3>&nbsp;",element_pere->personne.pr_nom,element_mere->personne.pr_nom);

    fprintf(fichier,"%s</h3></td><td style='width: 197px; height: 45px;'><h3>&nbsp;%s</h3></td></tr></tbody></table><div><table style='height: 105px; width: 683px;' border='black'><tbody><tr style='height: 79px;'><td style='width: 42px; height: 79px;'><h3 style='text-align: center;'>&nbsp;10</h3></td><td style='width: 624px; height: 79px;'><h3>&nbsp; AUTRES &Eacute;NONCIATIONS DE L&rsquo;ACTE :</h3><h3>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;",element_pere->personne.pr_prenom,element_mere->personne.pr_prenom); 

    fprintf(fichier,"%s </h3></td></tr><tr style='height: 161.875px;'><td style='width: 42px; height: 161.875px;'><h3 style='text-align: center;'>&nbsp;11</h3></td><td style='width: 624px; height: 161.875px;'><h3>&nbsp; &nbsp; DATE DE D&Eacute;LIVRANCE :&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;",enonciations);

    fprintf(fichier,"%d/%d/%d</h3><h3>&nbsp; &nbsp; SIGNATURE, SCEAU&nbsp; &nbsp;</h3><p>&nbsp;</p></td></tr></tbody></table></div>",instant.tm_mday, instant.tm_mon+1,instant.tm_year+1900);

    longueur=strlen(nomacte);
    nomacte[longueur]='.';
    nomacte[longueur+1]='h';
    nomacte[longueur+2]='t';
    nomacte[longueur+3]='m';
    nomacte[longueur+4]='l';
    nomacte[longueur+5]='\0';
    
    rename("acte.html",nomacte);
    fclose(fichier);
    }
    else
        printf("\nCe identifant ne correspond a aucune personne\n");
}

int numero_acte()
{   
    int numero;
    FILE* fichier=fopen("Numero", "r");
    if(fichier==NULL)numero=1;
    else {
    fscanf(fichier,"%d",&numero);
        numero+=1;
    }

    fichier=fopen("Numero", "w");
    fprintf(fichier,"%d",numero);
    
    fclose(fichier);
    return numero;
}
