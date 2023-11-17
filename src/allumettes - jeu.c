//       BIBLIOTHEQUES STANDARD

#include <stdio.h>
#include <stdlib.h>

//       BIBLIOTHEQUES PERSONNELLES

#include "allumettes - affichage.h"
#include "allumettes - jeu.h"

/*Fonctions qui gère les commandes du jeu*/

//Fonction qui demande un nombre d'allumettes à enlever :
void demander(int *nb_Allumettes_a_enlever, int allumettes, int nb_tours, int nb_joueurs, int difficulte)
{
     //On regarde si c'est l'ordinateur qui doit jouer ou pas.
     if ((nb_joueurs == 1) && (nb_tours%2 == 1))
     {
                     *nb_Allumettes_a_enlever = intelligence_artificielle(allumettes, difficulte) ;
                     printf("%d\n\n", *nb_Allumettes_a_enlever) ;
                     system("PAUSE") ;
     }
     else {scanf("%d",nb_Allumettes_a_enlever) ;}
}

//Fonction qui gère l'intelligence artificielle du jeu :
int intelligence_artificielle (int allumettes, int difficulte)
{
    int res ;
    do
    {
        switch (difficulte)
        {
               case 0 : res = rand()%(3) + 1 ;
                        break ;
               case 1 : if (allumettes > 8) {res = rand()%(3) + 1 ;}
                        else {res = ia_parfaite (allumettes) ;}
                        break ;
               case 2 : if (allumettes > 12) {res = rand()%(3) + 1 ;}
                        else {res = ia_parfaite (allumettes) ;}
                        break ;
               case 3 : res = ia_parfaite (allumettes) ;
                        break ;
        }
    } while (res>allumettes) ;
    return res ;
}

int ia_parfaite (int allumettes)
{
    int res ;
    switch (allumettes%4)
    {
           case 0 : res = 3 ;
                    break ;
           case 1 : res = rand()%(3) + 1 ;
                    break ;
           case 2 : res = 1 ;
                    break ;
           case 3 : res = 2 ;
                    break ;
    }
    return res ;
}
