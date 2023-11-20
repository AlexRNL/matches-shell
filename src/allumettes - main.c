//       BIBLIOTHEQUES STANDARD

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//       DEFINE

#define NB_ALLUMETTES 0 //0 pour un nombre d'alumettes al�atoires.

//       BIBLIOTHEQUES PERSONNELLES

#include "allumettes - affichage.h"
#include "allumettes - jeu.h"

/*Jeu des alumettes : un nombre (al�atoire ou pas) d'alumettes est disponible, le joueur peut prendre
entre 1 et 3 alumettes par tours. Celui qui prend la derni�re perd !!*/

int main(void)
{
    //      DECLARATION DES CONSTANTES
    const char e = '\x82', ee = '\x8A', a = '\x85' ; //�, � et �.

    //      DECLARATION DES VARIABLES
    int nb_joueurs, nb_Allumettes, nb_tours, nb_Allumettes_a_enlever, difficulte ;


    //      DEBUT DU JEU
    srand((unsigned int) time(NULL)) ;
    do
    {
        system("CLS") ;
        printf("\t\t\t\tALLUMETTES\n\n\n") ;
        printf("\tCelui qui prend la derni%cre allumette perd !!\n\n", ee) ;
        printf("\tCombien de joueur(s) (1 ou 2) ? ") ;
        scanf("%d", &nb_joueurs) ;
    } while (nb_joueurs != 1 && nb_joueurs != 2) ;
    if (nb_joueurs == 1) 
    {
                   do
                   {
                         system("CLS") ;
                         printf("\t\t\t\tALLUMETTES\n\n\n") ;
                         printf("\tCelui qui prend la derni%cre allumette perd !!\n\n", ee) ;
                         printf("\tCombien de joueur(s) (1 ou 2) ? %d", nb_joueurs) ;
                         printf("\n\n\tQuel niveau de difficult%c (de 0 %c 3) ? ", e, a) ;
                         scanf("%d", &difficulte) ;
                   } while (difficulte < 0 || difficulte > 3) ;
    }
    if (NB_ALLUMETTES) {nb_Allumettes = NB_ALLUMETTES ;}
    else {nb_Allumettes = rand()%(11) + 16 ;} //Nombre d'allumette al�atoire entre 15 et 40.
    nb_tours = 0 ;
    while (nb_Allumettes != 1)
    {
        do
        {
                         afficher_jeu(nb_Allumettes, nb_joueurs, nb_tours) ;
                         demander(&nb_Allumettes_a_enlever, nb_Allumettes, nb_tours, nb_joueurs, difficulte) ;
        } while ((nb_Allumettes_a_enlever < 1 || nb_Allumettes_a_enlever > 3) || (nb_Allumettes_a_enlever >= nb_Allumettes)) ;
        nb_Allumettes -= nb_Allumettes_a_enlever ;
        nb_tours++ ;
    }
    afficher_fin(nb_tours, nb_joueurs) ;
    printf("\n\n") ;
    system("PAUSE");
    return 0;
}
