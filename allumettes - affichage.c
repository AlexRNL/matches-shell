//       BIBLIOTHEQUES STANDARD

#include <stdio.h>
#include <stdlib.h>

//       DEFINE

#define NB_ALLUMETTES 0 //0 pour un nombre d'alumettes aléatoires.

//       BIBLIOTHEQUES PERSONNELLES

#include "allumettes - affichage.h"
#include "allumettes - jeu.h"

/*Contient le fonctions qui gèrent l'affichage*/

//Fonction qui gère l'affichage du jeu en cours :
void afficher_jeu (int nb_Allumettes, int nb_joueurs, int nb_tours)
{
    const char e = '\x82', ee = '\x8A', eee = '\x88', a = '\x85' ; //é, è, ê et à.
    int i, j = 0 ;
    system("CLS") ;
    printf("\t\t\t\tALLUMETTES\n\n\n") ;
    printf("\tCelui qui prend la derni%cre allumette perd !!\n\n\tIl y a %d allumettes.\n\n", ee, nb_Allumettes) ;
    do
    {
        j++ ;
        for (i=0 ; i<nb_Allumettes ; i++) {printf(" | ") ;}
        printf("\n") ;
    } while (j<5) ;
    printf("\n\n\n\t\x10 ") ;
    switch (nb_tours%2)
    {
        case 0 : printf("Joueur 1") ;
                 break ;
        case 1 : if (nb_joueurs == 1) {printf("Ordinateur") ;}
                 else {printf("Joueur 2") ;}
                 break ;
    }
    printf(" : ") ;
}

void afficher_fin (int tours, int joueurs)
{
    const char e = '\x82', ee = '\x8A', eee = '\x88', a = '\x85' ; //é, è, ê et à.
    int i = 0 ;
    system("CLS") ;
    printf("\t\t\t\tALLUMETTES\n\n\n") ;
    printf("\tCelui qui prend la derni%cre allumette perd !!\n\n\n\n", ee) ;
    do
    {
        i++ ;
        printf(" | ") ;
        printf("\n") ;
    } while (i<5) ;
    printf("\n\n\n\tLe gagnant est ") ;
    if (tours%2 == 1) {printf("le joueur 1.") ;}
    else if (joueurs == 1) {printf("l'ordinateur.") ;}
    else {printf("le joueur 2.") ;}
    printf("\n\n\n\n\n\n\tJeu cr%c%c par Alex Barf%cty le 28/11/2007.", e, e, e) ;
}
