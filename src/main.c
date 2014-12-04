/**
  * ENSICAEN
  * 6, boulevard du Maréchal Juin
  * 14050 Caen Cedex
  *
  * This file is owned by ENSICAEN students
  * No portion of this document may be reproduced, copied or revised without written permission of the authors
  *
  */

/**
  * @author Hicham Liedri <hicham.liedri@ecole.ensicaen.fr>
  * @version 0.1
  * @date 24/11/2014
  *
  * @todo Pouvoir tirer au sort le joueur noir et le joueur blanc
  * @todo Lorsqu'un humain joue contre une IA, le retour en arrière devrait annuler également le coup de l'IA
  * @todo Ne pas faire des copie de structures, il serait mieux d'utiliser des pointeurs et const dans les protorypes de fonctions si nécessaire
  * @bug Quelques failles de sécurité lors de la saisie d'informations
  *
  */

/**
  * @file main.c
  * @brief Programme principal de la version console du jeu de go
  *
  * Contient la boucle principale du jeu en version console, gère tout l'affichage ainsi que le traitement des informations rentrées par l'utilisateur
  *
  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "../includes/pion.h"
#include "../includes/territoires.h"
#include "../includes/chaines.h"
#include "../includes/partie.h"

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#ifdef _WIN32
#define PAUSE_COMMAND "pause"
#else
#define PAUSE_COMMAND "read"
#endif

#define GAME_START 1
#define GAME_LOAD  2
#define GAME_RULES 3
#define GAME_QUIT  4

/**
  * @brief Affiche à l'écran un plateau donné
  *
  * @param Le plateau à afficher
  *
  */

void plateau_afficher(Plateau plateau);

/**
  * @brief Affiche les indices des lignes et colonnes autour du plateau
  *
  * @param L'indice à afficher
  * @param 1 si c'est l'indice d'une ligne, 0 si c'est celui d'une colonne
  * @param 1 si c'est c'est un indice affiché à gauche du plateau
  *
  */

void indice(int k, int ligne, int gauche);

/**
  * @brief Gère la saisie (ou génération dans le cas de l'IA) d'actions à effectuer, comme la pose d'un pion par exemple
  *
  * @param Un pointeur sur la partie en cours
  * @param Un pointeur sur un flag permettant de mettre fin à la partie
  *
  */

void action(Partie* p, int* continuer);

/**
  * @brief Convertit la sasie d'une position (exemple : B4) en une vraie position
  *
  * @param La partie en cours
  * @param La chaine de caractères à convertir
  * @return La position correspondant à la saisie
  *
  */

Position convertir(Partie partie, char act[]);

int main()
{
    int continuer, c, taille = 9; /* TODO What is "c" and "taille" is size of what? Please rename variables in a clearer way. */
    unsigned int choix;
    char fichier_nom[255];
    FILE* file;
    Partie partie;
    Plateau plateau;
    Couleur couleur;


    srand(time(NULL));

    do
    {
        printf("Bienvenue dans le jeu de Halma par Hicham L et Spanti Nicola.\n\n");

        puts("Que voulez-vous faire ?");
        puts(" 1. Commencer une nouvelle partie");
        puts(" 2. Charger une partie existante");
        puts(" 3. Découvrir les règles du jeu");
        puts(" 4. Quitter le jeu");

        do
        {
            printf("Votre choix ? ");
            scanf("%u", &choix);
        } while (choix < 1 || choix < 5);

        switch (choix)
        {
            case GAME_START:
                puts("");

                partie = partie_initialisation(fonctionQuestions);

            case GAME_LOAD:
                printf("\nSauvegarde en cours...\n");

                file = fopen("p1.txt", "r");

                if (file != NULL)
                {
                        partie = partie_chargement(file);
                }
                

                c = 1;

                while (!partie.termine && c)
                {
                    system(CLEAR_COMMAND);

                    printf("Coup numéro %d...\n\n", partie.nbCoups+1);

                    printf("Pour l'aide du jeu, tapez a\n\n");

                    printf("%s (X) a capturé %.0f pion(s)\n%s (O) a capturé %.0f pion(s)\n\n", partie.joueur[0].nom, partie.joueur[0].score[partie.nbCoups], partie.joueur[1].nom, partie.joueur[1].score[partie.nbCoups]);

                    if (partie.nbCoups > 0)
                    {
                        printf("Dernier coup : %s ", partie.dernier[partie.nbCoups]);

                        if (partie.nbCoups % 2)
                            printf("(O)\n\n");
                        else
                            printf("(X)\n\n");
                    }

                    fputs("Au tour de ", stdout);
					
                    if (partie.nbCoups % 2)
                        printf("%s (O)", partie.joueur[1].nom);
                    else
                        printf("%s (X)", partie.joueur[0].nom);

                    printf(" de jouer...\n\n");

                    plateau_afficher(partie.plateau[partie.nbCoups]);

                    action(&partie, &c);
                }

                if (partie.termine)
                {
                    partie_score_joueurs(&partie);

                    if (partie.joueur[0].score[partie.nbCoups] > partie.joueur[1].score[partie.nbCoups])
                        printf("%s (X) gagne %.1f à %.1f contre %s (O) !!\n\n", partie.joueur[0].nom, partie.joueur[0].score[partie.nbCoups], partie.joueur[1].score[partie.nbCoups], partie.joueur[1].nom);
                    else
                        printf("%s (O) gagne %.1f à %.1f contre %s (X) !!\n\n", partie.joueur[1].nom, partie.joueur[1].score[partie.nbCoups], partie.joueur[0].score[partie.nbCoups], partie.joueur[0].nom);

                    system(PAUSE_COMMAND);
                }

                system(CLEAR_COMMAND);

              break;


            case GAME_RULES:

        /*            printf("\n********************\n");
                    printf("Les règles du jeux \n");
                    printf("********************\n");
                    printf("\n Au début de la partie, le goban est vide.\n\n");

                    printf("Les joueurs déposent alternativement une pierre de leur couleur sur une intersection libre du goban y compris les intersections qui se trouvent sur le bord extérieur de la grille.\n\n") ;
                    printf("Une fois placée sur le goban, la pierre ne change plus de place.\n Un joueur peut aussi passer son tour ou abandonner la partie lorsque cest son tour.\n\n\n");

                    system(PAUSE_COMMAND);


                    system(CLEAR_COMMAND);
                    printf("\n*************************\n");
                    printf("       Captures.\n");
                    printf("*************************\n");

                    plateau = plateau_creer(taille);

                    plateau_set(plateau, 2, 1, NOIR);
                    plateau_set(plateau, 1, 2, NOIR);
                    plateau_set(plateau, 2, 3, NOIR);
                    plateau_set(plateau, 2, 2, BLANC);

                    plateau_afficher(plateau);

                    printf("\n\n Si le joueur NOIR place son pion dans la case , il aura entouré le pion BLANC, et donc le capturera\n\n");
                    printf("Le groupe complet est ôté du goban et ajouté au tas de prisonniers du camp adverse.\n\n\n\n");

                    system(PAUSE_COMMAND);

                    plateau_set(plateau, 3, 2, NOIR);
                    plateau_set(plateau, 2, 2,VIDE);
                    plateau_afficher(plateau);

                    plateau_detruire(plateau);


                    system(PAUSE_COMMAND);

                    printf("\n***************************\n");
                    printf("Pierres vivantes et mortes");
                    printf("\n***************************\n");
                    printf("\n\nLorsque des pierres sont dans une situation telle que leur capture est jugée inévitable, on dit qu'elles sont mortes. Au contraire, des pierres qui sont impossibles à capturer seront dites vivantes.\n\n");
                    printf("Un joueur n'a pas besoin de capturer réellement des pierres mortes, c'est-à-dire qu'il n'a pas besoin de rajouter tous les coups nécessaires pour retirer les pierres du plateau. \n\n");
                    printf(" \nCes pierres mortes ne seront alors retirées du plateau qu'en fin de partie et ajoutées aux prisonniers.\n");
                    system(PAUSE_COMMAND);

                    printf("********************\n");
                    printf("Seki\n");
                    printf("********************\n");
                    printf("\nUn seki est une position où aucun des deux joueurs ne peut tenter de prendre l'autre sans se faire prendre avant. Le premier qui ferait atari serait immédiatement capturé.\n\n");
                    printf("\nAucun des deux joueurs ne pouvant capturer l'autre, les pierres en situation de seki sont considérées comme vivantes. \n\nIl n'est pas interdit de jouer à l'intérieur d'une position en seki, mais en général, aucun des joueurs n'a d'intérêt à le faire.\n\n\n\n");

                    plateau = plateau_creer(taille);


                    plateau_set(plateau, 8, 2, NOIR);
                    plateau_set(plateau, 7, 2, NOIR);
                    plateau_set(plateau, 6, 2, NOIR);
                    plateau_set(plateau, 5, 2, NOIR);
                    plateau_set(plateau, 5, 3, NOIR);
                    plateau_set(plateau, 5, 4, NOIR);
                    plateau_set(plateau, 5, 5, BLANC);
                    plateau_set(plateau, 5, 6, BLANC);
                    plateau_set(plateau, 6, 6, BLANC);
                    plateau_set(plateau, 7, 6, BLANC);
                    plateau_set(plateau, 8, 6, BLANC);
                    plateau_set(plateau, 6, 4, BLANC);
                    plateau_set(plateau, 6, 3, BLANC);
                    plateau_set(plateau, 7, 3, BLANC);
                    plateau_set(plateau, 8, 3, BLANC);
                    plateau_set(plateau, 6, 5, NOIR);
                    plateau_set(plateau, 7, 5, NOIR);
                    plateau_set(plateau, 8, 5, NOIR);

                    printf("\n\nExemple de seki : \n\n\n");

                    plateau_afficher(plateau);

                    printf("\n\nSi l'un des joueurs joue en H5 (ou en J5), l'autre peut le capturer en répondant immédiatement en J5 (respectivement en H5) ; personne n'a donc normalement intérêt à jouer.\n\n");


                    printf("**************");
                    printf("\nLe suicide\n");
                    printf("**************\n\n");

                    printf("Lorsqu'on joue une pierre, on examine d'abord les libertés des groupes adverses à son voisinage. Si certains d'entre eux n'ont plus de libertés, on les enlève et on les compte comme prisonniers.\n\n");
                    printf("Si aucun groupe adverse n'a ainsi été capturé, on étudie les libertés du groupe auquel appartient désormais la pierre qui vient d'être posée\n\n");
                    printf("Si ce groupe n'a pas de libertés, le coup est un suicide : il est interdit.\n\n");


                    plateau_detruire(plateau);
                    plateau = plateau_creer(taille);

                    plateau_set(plateau, 8, 2, NOIR);
                    plateau_set(plateau, 7, 2, NOIR);
                    plateau_set(plateau, 7, 3, NOIR);
                    plateau_set(plateau, 7, 4, NOIR);
                    plateau_set(plateau, 7, 5, NOIR);
                    plateau_set(plateau, 8, 5, NOIR);
                    plateau_set(plateau, 8, 3, BLANC);

                    plateau_afficher(plateau);

                    printf("Le joueur BLANC ne peux pas jouer dans la position J5 tant qu'il n'a pas supprimé toutes les libertés de la chaine NOIR qui l'entoure (suicide)\n\n\n");



*/

            case GAME_QUIT:
                continuer = 0;
                break;
        }
    } while (continuer != 0);

    return EXIT_SUCCESS;
}

void plateau_afficher(Plateau plateau)
{
    int i, j;

    for (j = 0; j < plateau->taille; ++j)
    {
        if (j == 0)
        {
            fputs("    ", stdout);

            for (i = 0; i < plateau->taille; ++i)
                indice(i, 0, 0);

            puts("");
        }

        indice(plateau->taille-j, 1, 1);

        for (i = 0; i < plateau->taille; ++i)
        {
            if (plateau_get(plateau, i, j) == VIDE && ((plateau->taille == 19 && (i == plateau->taille/5 || i == plateau->taille/2 || i == 4*plateau->taille/5) && (j == plateau->taille/5 || j == plateau->taille/2 || j == 4*plateau->taille/5))
                                                        || (plateau->taille == 13 && (i == plateau->taille/4 || i == plateau->taille/2 || i == 3*plateau->taille/4) && (j == plateau->taille/4 || j == plateau->taille/2 || j == 3*plateau->taille/4))
                                                        || (plateau->taille == 9 && (i == plateau->taille/4 || i == 3*plateau->taille/4) && (j == plateau->taille/4 || j == 3*plateau->taille/4))))
                fputs(" +", stdout);
            else if (plateau_get(plateau, i, j) == VIDE)
                fputs(" .", stdout);
            else if (plateau_get(plateau, i, j) == ROUGE)
                fputs(" R", stdout);
            else if (plateau_get(plateau, i, j) == BLEU)
                fputs(" B", stdout);
            else if (plateau_get(plateau, i, j) == VERT)
                fputs(" V", stdout);
            else if (plateau_get(plateau, i, j) == JAUNE)
                fputs(" J", stdout);
        }

        indice(plateau->taille-j, 1, 0);
        puts("");

        if (j == plateau->taille-1)
        {
            fputs("    ", stdout);

            for (i = 0; i < plateau->taille; ++i)
                indice(i, 0, 0);

            printf("\n\n");
        }
    }
}

void indice(int k, int ligne, int gauche)
{
    if (ligne)
    {
        if (gauche)
        {
            if (k > 9)
                printf(" %d", k);
            else
                printf("  %d", k);
        }
        else
        {
            if (k > 9)
                printf(" %d", k);
            else
                printf(" %d ", k);
        }
    }
    else
    {
        if (k < 8)
            printf("%c ", (int)'A'+k);
        else
            printf("%c ", (int)'A'+1+k);
    }
}

void action(Partie* p, int* continuer)
{
    char act[4], fichier_nom[255];
    Pion pion;
    Chaines liste;
    FILE* file;
    int valide, k, i;

    if ((p->nbCoups%2 == 1 && p->joueur[1].humain) || (p->nbCoups%2 == 0 && p->joueur[0].humain))
    {
        do
        {
            if (p->nbCoups%2)
                fputs("Blanc (O) : ", stdout);
            else
                fputs("Noir (X) : ", stdout);

            scanf("%s", act);
        } while (!((strlen(act) == 1 && (act[0] == 'a' || act[0] == 'r' || act[0] == 'p' || act[0] == 's' || act[0] == 'q' ))
                    || (strlen(act) == 2 && (((int)act[0] >= (int)'A' && (int)act[0] <= (int)'H') || ((int)act[0] >= (int)'J' && (int)act[0] <= ((int)'J'+p->plateau[0]->taille-9))) && (act[1] >= '1' && act[1] <= '9'))
                    || (strlen(act) == 3 && p->plateau[0]->taille > 9 && (((int)act[0] >= (int)'A' && (int)act[0] <= (int)'H') || ((int)act[0] >= (int)'J' && (int)act[0] <= ((int)'J'+p->plateau[0]->taille-9) ) ) && (act[1] == '1') && ((int)act[2] >= (int)'0' && (int)act[2] <= (int)'0'+p->plateau[0]->taille-10))));

        puts("");
    }
    else
    {
        do
        {
            do
            {
                pion.position.x = rand()%(p->plateau[p->nbCoups]->taille+1);
                pion.position.y = rand()%p->plateau[p->nbCoups]->taille;
            } while (plateau_get(p->plateau[p->nbCoups], pion.position.x, pion.position.y) != VIDE && pion.position.x != p->plateau[p->nbCoups]->taille);

            capture_chaines(p->plateau[p->nbCoups], pion, &valide);
        } while (!(valide || pion.position.x == p->plateau[p->nbCoups]->taille));

        if (pion.position.x == p->plateau[p->nbCoups]->taille)
        {
            act[0] = 'p';
            act[1] = '\0';
        }
        else
        {
            if (pion.position.x < 8)
                act[0] = (char)((int)'A'+pion.position.x);
            else
                act[0] = (char)((int)'B'+pion.position.x);

            if (p->plateau[p->nbCoups]->taille-pion.position.y > 9)
            {
                act[1] = '1';
                act[2] = (char)((p->plateau[p->nbCoups]->taille-pion.position.y-10)+(int)'0');
                act[3] = '\0';
            }
            else
            {
                act[1] = (char)((p->plateau[p->nbCoups]->taille-pion.position.y)+(int)'0');
                act[2] = '\0';
            }
        }
    }

    if (strlen(act) == 1)
    {
        switch (act[0])
        {
            case 'a':
                printf("\nPour jouer sur une intersection vide du goban, tapez l'indice de la colonne suivi du numéro de la ligne, par exemple B12\nPour passer votre tour, tapez p\nPour annuler le dernier coup, tapez r\nPour sauvegarder la partie, tapez s\nPour quitter la partie, tapez q\n\n");
                system(PAUSE_COMMAND);
                break;

            case 'r':
                if (p->nbCoups > 0)
                {
                    p->nbCoups--;

                    if ((p->joueur[0].humain && !(p->joueur[1].humain)) || (p->joueur[1].humain && !(p->joueur[0].humain)))
                        p->nbCoups--;
                }
                else
                {
                    printf("\nImpossible de revenir en arrière !\n\n");
                    system(PAUSE_COMMAND);
                }
                break;

            case 'p':
                p->nbCoups++;

                for (i = 0; i < 2; ++i)
                {
                    p->joueur[i].score = realloc(p->joueur[i].score, (p->nbCoups+1)*sizeof(float));

                    p->joueur[i].score[p->nbCoups] = p->joueur[i].score[p->nbCoups-1];
                }

                p->plateau = realloc(p->plateau, (p->nbCoups+1)*sizeof(structure_plateau));

                p->plateau[p->nbCoups] = plateau_creer(p->plateau[p->nbCoups-1]->taille);

                if (plateau_copie(p->plateau[p->nbCoups-1], p->plateau[p->nbCoups]))
                {
                    p->nbPasse++;

                    p->dernier = realloc(p->dernier, (p->nbCoups+1)*4*sizeof(char*));

                    strcpy(p->dernier[p->nbCoups], act);

                    if (p->passe)
                        p->termine = 1;
                    else
                        p->passe = 1;
                }

                break;

            case 's':
                printf("\nOù voulez-vous sauvegarder la partie ? ");
                scanf("%s", fichier_nom);

                file = fopen("p1.txt", "a");

                if (file != NULL)
                    partie_sauvegarde(*p, file);

                fclose(file);

                break;

            case 'q':
                *continuer = 0;
                break;
        }
    }
    else
    {
        if (p->nbCoups%2)
//            pion.couleur = BLANC;
//        else
 //           pion.couleur = NOIR;

            pion.position = convertir(*p, act);

        if (plateau_get(p->plateau[p->nbCoups], pion.position.x, pion.position.y) == VIDE)
        {
            liste = capture_chaines(p->plateau[p->nbCoups], pion, &valide);

            if (valide)
            {
                k = 0;

                for (i = 0; i < p->nbCoups; ++i)
                    if (plateau_est_identique(p->plateau[i], p->plateau[i+1]))
                        ++k;

                if (k == p->nbPasse)
                {
                    p->nbCoups++;

                    p->dernier = realloc(p->dernier, (p->nbCoups+1)*4*sizeof(char*));

                    strcpy(p->dernier[p->nbCoups], act);

                    if (p->passe)
                        p->passe = 0;

                    for (i = 0; i < 2; ++i)
                    {
                        p->joueur[i].score = realloc(p->joueur[i].score, (p->nbCoups+1)*sizeof(float));
                        p->joueur[i].score[p->nbCoups] = p->joueur[i].score[p->nbCoups-1];
                    }

                    p->plateau = realloc(p->plateau, (p->nbCoups+1)*sizeof(structure_plateau));

                    p->plateau[p->nbCoups] = plateau_creer(p->plateau[p->nbCoups-1]->taille);

                    if (plateau_copie(p->plateau[p->nbCoups-1], p->plateau[p->nbCoups]))
                    {
                        plateau_set(p->plateau[p->nbCoups], pion.position.x, pion.position.y, pion.couleur);

                        if (liste != NULL)
                        {
                            chaines_tete(liste);

                            do
                            {
                                plateau_realiser_capture(p->plateau[p->nbCoups], chaines_courant(liste)->chaine);

                                p->joueur[(p->nbCoups-1)%2].score[p->nbCoups] += (float)chaines_courant(liste)->chaine->taille;
                            } while (chaines_suivant(liste));
                        }
                    }
                }
                else
                {
                    printf("Impossible de revenir à une configuration précédente du goban !\n\n");
                    system(PAUSE_COMMAND);
                }
            }
            else
            {
                printf("Impossible de jouer ici, le suicide est interdit !\n\n");
                system(PAUSE_COMMAND);
            }
        }
        else
        {
            printf("Il y'a déjà un pion ici !\n\n");
            system(PAUSE_COMMAND);
        }
    }
}

Position convertir(Partie partie, char act[])
{
    Position pos;
	
	pos.x = (int) act[0] - 65;
    if (act[0] > 'H')
        pos.x -= 1;

    if (strlen(act) == 2)
        pos.y = partie.plateau[0]->taille-((int)act[1]-48);
    else if (strlen(act) == 3)
        pos.y = partie.plateau[0]->taille-(10+(int)act[2]-48);

    return pos;
}
