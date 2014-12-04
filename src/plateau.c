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
  * @file plateau.c
  *
  * Fonctions utiles à la gestion du plateau de jeu
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/plateau.h"

/**
  * Fonction récursive intermédiaire utile à la détermination de chaines
  *
  * @param Le plateau courant
  * @param La chaine à déterminer entièrement
  * @param L'abscisse de la position de laquelle partir
  * @param L'ordonée de la position de laquelle partir
  *
  */

void chaine_ajouter_pions_adjacents(Plateau plateau, Chaine chaine, int x, int y);

Plateau plateau_creer(int taille)
{
    int i;

    Plateau plateau = malloc(sizeof(structure_plateau));

    plateau->taille = taille;

    plateau->couleur = malloc(taille*taille*sizeof(Couleur));

    for (i = 0; i < taille*taille; ++i)
        plateau->couleur[i] = VIDE;

    return plateau;
}

void plateau_detruire(Plateau plateau)
{
    free(plateau->couleur);
    free(plateau);
}

Couleur plateau_get(Plateau plateau, int i, int j)
{
    return plateau->couleur[j*plateau->taille+i];
}

void plateau_set(Plateau plateau, int i, int j, Couleur couleur)
{
    plateau->couleur[j*plateau->taille+i] = couleur;
}

Chaine plateau_determiner_chaine(Plateau plateau, Position pos)
{
    if (plateau_get(plateau, pos.x, pos.y) == VIDE)
        return NULL;

    Chaine chaine = chaine_creer(plateau_get(plateau, pos.x, pos.y));
    chaine_ajouter(pos, chaine);
    chaine_ajouter_pions_adjacents(plateau, chaine, pos.x, pos.y);
    return chaine;
}

void chaine_ajouter_pions_adjacents(Plateau plateau, Chaine chaine, int x, int y)
{
    int i, j;
    Position position;

    for (j = y-1; j <= y+1; ++j)
        for (i = x-1; i <= x+1; ++i)
            if (i >= 0 && j >= 0 && i < plateau->taille && j < plateau->taille && (i+j == x+y+1 || i+j == x+y-1))
            {
                position.x = i;
                position.y = j;

                if (plateau_get(plateau, i, j) == chaine->couleur && !chaine_appartient(position, chaine))
                {
                    chaine_ajouter(position, chaine);
                    chaine_ajouter_pions_adjacents(plateau, chaine, i, j);
                }
            }
}

void plateau_realiser_capture(Plateau plateau, Chaine chaine)
{
    chaine_tete(chaine);

    do
    {
        plateau_set(plateau, chaine_courant(chaine)->position.x, chaine_courant(chaine)->position.y, VIDE);
    } while (chaine_suivant(chaine));
}

int plateau_est_identique(Plateau plateau1, Plateau plateau2)
{
    int i, k;

    if (plateau1->taille == plateau2->taille)
    {
        k = 0;

        for (i = 0; i < plateau1->taille*plateau1->taille; i++)
            if (plateau1->couleur[i] == plateau2->couleur[i])
                ++k;

        if (k == plateau1->taille*plateau1->taille)
            return 1;
    }

    return 0;
}

int plateau_copie(Plateau from, Plateau to)
{
    int i;

    if (from->taille == to->taille)
    {
        for (i = 0; i < to->taille*to->taille; ++i)
            to->couleur[i] = from->couleur[i];

        if (plateau_est_identique(from, to))
            return 1;
    }

    return 0;
}

Chaines plateau_entoure_un_territoire(Territoire territoire, Plateau plateau)
{
    int i, j;
    Chaine chaine;
    Position position;

    Chaines liste = chaines_creer();

    territoire_tete(territoire);

    do
    {
        for (j = territoire_courant(territoire)->position.y-1; j <= territoire_courant(territoire)->position.y+1; ++j)
            for (i = territoire_courant(territoire)->position.x-1; i <= territoire_courant(territoire)->position.x+1; ++i)
                if (i >= 0 && j >= 0 && i < plateau->taille && j < plateau->taille && (i+j == territoire_courant(territoire)->position.x+territoire_courant(territoire)->position.y+1 || i+j == territoire_courant(territoire)->position.x+territoire_courant(territoire)->position.y-1))
                    if (plateau_get(plateau, i, j) != VIDE)
                    {
                        position.x = i;
                        position.y = j;

                        chaine = plateau_determiner_chaine(plateau, position);

                        if (!chaines_appartient(chaine, liste))
                            chaines_ajouter(chaine, liste);
                    }
    } while (territoire_suivant(territoire));

    return liste;
}

int plateau_sauvegarde(Plateau plateau, FILE* fichier)
{
    int i;

    if (fichier != NULL)
    {
        fprintf(fichier, "%d\n", plateau->taille);

        for (i = 0; i < plateau->taille*plateau->taille; ++i)
            fprintf(fichier, "%d\n", plateau->couleur[i]);

        return 1;
    }

    return 0;
}

Plateau plateau_chargement(FILE* fichier)
{
    int i, taille;

    if (fichier != NULL)
    {
        fscanf(fichier, "%d\n", &taille);

        Plateau plateau = plateau_creer(taille);

        for (i = 0; i < taille*taille; ++i)
            fscanf(fichier, "%d\n", &plateau->couleur[i]);

        return plateau;
    }

    return NULL;
}
/*
Chaines capture_chaines(Plateau plateau, Pion pion, int* valide)
{
    int i, j;
    Plateau pl;
    Position position;
    Chaine chaine;
    Libertes libertes;

    Chaines liste = chaines_creer();

    pl = plateau_creer(plateau->taille);

    plateau_copie(plateau, pl);

    plateau_set(pl, pion.position.x, pion.position.y, pion.couleur);

    for (j = pion.position.y-1; j <= pion.position.y+1; j++)
            for (i = pion.position.x-1; i <= pion.position.x+1; i++)
                if (i >= 0 && j >= 0 && i < pl->taille && j < pl->taille && (i+j == pion.position.x+pion.position.y+1 || i+j == pion.position.x+pion.position.y-1))
                    if (plateau_get(pl, i, j) != VIDE && plateau_get(pl, i, j) != pion.couleur)
                    {
                        position.x = i;
                        position.y = j;

                        chaine = plateau_determiner_chaine(pl, position);

                        libertes = determine_liberte(pl, chaine);

                        if (libertes->taille == 0)
                            if (!chaines_appartient(chaine, liste))
                            {
                                chaines_ajouter(chaine, liste);

                                plateau_realiser_capture(pl, chaine);
                            }
                    }

    if (liste->taille == 0)
    {
        chaine = plateau_determiner_chaine(pl, pion.position);

        libertes = determine_liberte(pl, chaine);

        if (libertes->taille == 0)
        {
            *valide = 0;

            libertes_detruire(libertes);
            chaine_detruire(chaine);
            chaines_detruire(liste);

            return NULL;
        }

        *valide = 1;

        return NULL;
    }

    *valide = 1;

    return liste;
}*/
