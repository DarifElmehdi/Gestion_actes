all :   				prog 


prog : 					main.o actegenerat.o afficher_enfants.o age.o ajouter_enfant.o ajouter.o chercher.o consulter.o liste_fichier.o menu_enfants.o menu_personne.o menu_principal.o modifier.o pere_mere.o supprimer.o 
						gcc *.o -o prog


main.o :				main.c
						gcc -c main.c

actegenerat.o :			actegenerat.c
						gcc -c actegenerat.c

afficher_enfants.o : 	afficher_enfants.c
						gcc -c afficher_enfants.c

age.o  :				age.c
						gcc -c age.c

ajouter_enfant.o :      ajouter.c
						gcc -c ajouter_enfant.c
					
ajouter.o :     		ajouter.c
						gcc -c ajouter.c

chercher.o  : 			chercher.c
						gcc -c chercher.c

consulter.o :       	consulter.c
						gcc -c consulter.c 
					
liste_fichier.o :		liste_fichier.c trie.o
						gcc -c liste_fichier.c
					
menu_enfants.o :		menu_enfants.c
						gcc -c menu_enfants.c
					
menu_personne.o :		menu_personne.c trie.o
						gcc -c menu_personne.c

menu_principal.o :    	menu_principal.c
						gcc -c menu_principal.c

modifier.o : 			modifier.c
						gcc -c modifier.c

pere_mere.o :			pere_mere.c
						gcc -c pere_mere.c

supprimer.o :			supprimer.c
						gcc -c supprimer.c

trie.o :				trie.c
						gcc -c trie.c

clean :					
						rm -rf *.o

run :  
						./prog
