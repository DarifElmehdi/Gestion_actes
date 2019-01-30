#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "structs.h"

char _login[]="admin";
char _pass[]="admin";
int main()
{ int flag=0 ;
  char login[10];
  char pass[10];
  do {
    system("clear");
    printf("\n#############################################################################");
    printf("\n**                                                                         **");
    printf("\n**                          Gestionnaire d'actes                           **");
    printf("\n**                                                                         **");
    printf("\n**                                          By :  ISSAM ELMACHEHOUR        **");
    printf("\n**                                               & DARIF ELMEHDI           **");
    printf("\n#############################################################################\n");
    if(flag!=0){
      printf("** Donnees incorrectes ressayer !");
    }
    printf("\n** Tapez votre login :");
    scanf("%s",login);
    printf("\n** Tapez votre pass  :");
    scanf("%s",pass);
    flag=1;
  }while(strcmp(login,_login)!=0||strcmp(pass,_pass)!=0);
  Liste *liste=malloc(sizeof(Liste));
  lire(liste);      
	menu(liste);
	return 0;
}