/* Jeu du morpion TP1
 * crée le 14/10/2011 par Baptiste G.
 */

#include <stdio.h>
#include <conio.h> // pour le getch
#include <myconio.h> // Gotoxy
#include <stdlib.h> // cls

int main() {
	
	bool g = true ;
	int c , l , j , tab[3][3] , nbre = 0 ; // j numéro du joueur et nbre pour le nonbre de tour
	
		
	// affichage de la grille
	gotoxy (10,1);
	printf(" -----------\n");
	gotoxy (10,2);
	printf("|   |   |   |\n");
	gotoxy (10,3);
	printf(" -----------\n");
	gotoxy (10,4);
	printf("|   |   |   |\n");
	gotoxy (10,5);
	printf(" -----------\n");
	gotoxy (10,6);
	printf("|   |   |   |\n");
	gotoxy (10,7);
	printf(" -----------\n");
		
	do {
	// boucle tanque personne a gagné
		
		for (j = 1 ; j <= 2 ; j++) { // boucle pour tour des joueur
			do{  // test si cases est prises
					gotoxy (10, 10);
					printf("C'est au tour du joueur %d", j);
				do{ // test  l = 1 2 ou 3
					gotoxy (11,11);
					printf("Ligne =   ");
					gotoxy (18,11);
					scanf ("%d", &l); // taper le n° de ligne
				}while (l != 1 && l != 2 && l !=3 );
				do{ // test y = 1 2 ou 3
					gotoxy (11,12);
					printf("Colonne =   ");
					gotoxy (20,12);
					scanf ("%d", &c);
				}while ( c != 1 && c != 2 && c != 3 );
				
				if ( (tab[c-1][l-1] == 1)  || (tab[c-1][l-1] == 2) ){ // pour dit au joueur que la cases est occuper
					gotoxy (1, 14);
					printf("La cases n'est pas libre ");
				}else{
					gotoxy (1, 14);
					printf("                         ");
				}
			}while ( ( tab[c-1][l-1] == 1 ) || ( tab[c-1][l-1] == 2 ) );
				nbre++; // conte le nombre de tour
				gotoxy (((c*c)+11),(2*l));
			if (j==1){ // si  O pour jour 1 et x pour joueur 2
					printf ("O");
					tab[c-1][l-1] = 1 ;
			}else{
					printf ("x");
					tab[c-1][l-1] = 2 ;
			}
			// test pour savoir s'il a gagné
								
			if ( tab[0][0]==j && tab[1][0]==j && tab[2][0]==j){				
						g = false;					
			}
			if ( tab[0][1]==j && tab[1][1]==j && tab[2][1]==j){				
									g = false;					
						}
			if ( tab[0][2]==j && tab[1][2]==j && tab[2][3]==j){				
									g = false;					
						}
			if ( tab[0][0]==j && tab[0][1]==j && tab[0][2]==j){				
									g = false;					
						}
			if ( tab[1][0]==j && tab[1][1]==j && tab[1][2]==j){				
									g = false;					
						}
			if ( tab[2][0]==j && tab[2][1]==j && tab[2][2]==j){				
									g = false;					
						}
			if ( tab[0][0]==j && tab[1][1]==j && tab[2][2]==j){				
									g = false;					
						}
			if ( tab[0][2]==j && tab[1][1]==j && tab[2][0]==j){				
									g = false;					
						}
			if (g == false){ // si une joueur gagner
				gotoxy (20,14);
				printf("Le joureur %d \x85 GAGNER", j);
			}
			if ( nbre == 9 && g == true ){ // si les 9 cases sous rempli
				gotoxy (20,14);
				printf("vous avez perdu");
			}
		}
		
	
	} while ( g==true || nbre == 9 );
	 
	
	getch();
	return 0;
}
