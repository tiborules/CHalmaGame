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
  * @file partie.c
  *
  * Fonctions utiles à la gestion de parties
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/partie.h"

Partie partie_initialisation(FonctionQuestions fonctionQuestions)
{
    int i;
    Partie partie;

    partie.termine = 0;

    //partie.passe = 0;

    partie.nbCoups = 0;

    partie.nbPasse = 0;

    partie.dernier = malloc(4*sizeof(char*));

    partie.plateau = malloc(sizeof(structure_plateau));

    for (i = 0; i < 6; ++i)
        (*fonctionQuestions)(i, &partie);

    for (i = 0; i < 2; ++i)
    {
        partie.joueur[i].score = malloc(sizeof(float));
        partie.joueur[i].score[0] = 0;
    }

    return partie;
}

void fonctionQuestions(int numeroQuestion, Partie* p)
{
    int taille = 0;

    switch(numeroQuestion)
    {
        case 0:
            printf("Nom du joueur ROUGE (<8 caractères) :");

            scanf("%s", p->joueur[0].nom);

            break;

        case 1:
            printf("Nom du joueur blanc (< 8 caractères) ? ");

            scanf("%s", p->joueur[1].nom);

            break;

        case 3:
            printf("Taille du plateau est 16X16. ");

            taille = 16;

            p->plateau[0] = plateau_creer(taille);

            break;
    }
}


int partie_sauvegarde(Partie partie, FILE* fichier)
{
    int i, j;

    if (fichier != NULL)
    {
        fprintf(fichier, "%d\n", partie.termine);

        fprintf(fichier, "%d\n", partie.passe);

        fprintf(fichier, "%d\n", partie.nbCoups);

        fprintf(fichier, "%d\n", partie.nbPasse);

        for (i = 1; i <= partie.nbCoups; ++i)
            fprintf(fichier, "%s\n", partie.dernier[i]);

        for (i = 0; i < 2; i++)
        {
            fprintf(fichier, "%s\n", partie.joueur[i].nom);
            fprintf(fichier, "%d\n", partie.joueur[i].humain);

            for (j = 0; j <= partie.nbCoups; ++j)
                fprintf(fichier, "%f\n", partie.joueur[i].score[j]);
        }

        fprintf(fichier, "%f\n", partie.komi);

        for (i = 0; i <= partie.nbCoups; ++i)
            plateau_sauvegarde(partie.plateau[i], fichier);

        return 1;
    }

    return 0;
}

Partie partie_chargement(FILE* fichier)
{
    int i, j;

    Partie partie;

    fscanf(fichier, "%d\n", &partie.termine);

    fscanf(fichier, "%d\n", &partie.passe);

    fscanf(fichier, "%d\n", &partie.nbCoups);

    fscanf(fichier, "%d\n", &partie.nbPasse);

    for (i = 1; i <= partie.nbCoups; ++i)
        fscanf(fichier, "%s\n", partie.dernier[i]);

    for (i = 0; i < 2; ++i)
    {
        fscanf(fichier, "%s\n", partie.joueur[i].nom);
        fscanf(fichier, "%d\n", &partie.joueur[i].humain);

        for (j = 0; j <= partie.nbCoups; ++j)
            fscanf(fichier, "%f\n", &partie.joueur[i].score[j]);
    }

    fscanf(fichier, "%f\n", &partie.komi);

    partie.plateau = malloc((partie.nbCoups+1)*sizeof(structure_plateau));

    for (i = 0; i <= partie.nbCoups; ++i)
        partie.plateau[i] = plateau_chargement(fichier);

    return partie;
}

void partie_score_joueurs(Partie* p)
{
    int i, j;
    Territoire territoire;
    Position pos;

    Territoires liste = territoires_creer();

    for (j = 0; j < p->plateau[p->nbCoups]->taille; ++j)
        for (i = 0; i < p->plateau[p->nbCoups]->taille; ++i)
            if (plateau_get(p->plateau[p->nbCoups], i, j) == VIDE)
            {
                pos.x = i;
                pos.y = j;

                territoire = determine_territoire(p->plateau[p->nbCoups], pos);

                if (!territoires_appartient(territoire, liste))
                    territoires_ajouter(territoire, liste);
            }

    territoires_tete(liste);

    do
    {
        if (territoires_courant(liste)->territoire->couleur == NOIR)
            p->joueur[0].score[p->nbCoups] += (float)territoires_courant(liste)->territoire->taille;
        else if (territoires_courant(liste)->territoire->couleur == BLANC)
            p->joueur[1].score[p->nbCoups] += (float)territoires_courant(liste)->territoire->taille;
    } while (territoires_suivant(liste));

    p->joueur[1].score[p->nbCoups] += p->komi;
}
