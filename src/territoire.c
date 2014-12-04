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
  * Fonctions utiles à la gestion des territoires
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/territoire.h"

/**
  * Fonction récursive intermédiaire utile à la détermination de territoires
  *
  * @param Le plateau courant
  * @param Le territoire à déterminer entièrement
  * @param La position de laquelle partir
  *
  */

void territoire_ajouter_pions_adjacents(Plateau plateau, Territoire territoire, int x, int y);

Territoire territoire_creer(Couleur couleur)
{
    Territoire liste = malloc(sizeof(ensemble_colore));

    liste->taille = 0;
    liste->tete = NULL;
    liste->courant = NULL;
    liste->couleur = couleur;

    return liste;
}

void territoire_detruire(Territoire liste)
{
    element_position* tmp;

    territoire_tete(liste);

    if (!territoire_vide(liste))
    {
        do
        {
            tmp = territoire_courant(liste)->suivant;

            free(territoire_courant(liste));

            liste->courant = tmp;
        } while (tmp != NULL);
    }

    free(liste);
}

int territoire_vide(Territoire liste)
{
    return liste->tete == NULL;
}

void territoire_ajouter(Position position, Territoire liste)
{
    element_position* element = malloc(sizeof(element_position));

    element->position = position;
    element->suivant = NULL;

    if (territoire_vide(liste))
    {
        liste->tete = element;
        liste->courant = element;
    }
    else
    {
        while (territoire_suivant(liste))
        {}

        territoire_courant(liste)->suivant = element;
    }

    liste->taille++;
}

int territoire_appartient(Position position, Territoire liste)
{
    if (territoire_vide(liste))
        return 0;

    territoire_tete(liste);

    while (!(territoire_courant(liste)->position.x == position.x && territoire_courant(liste)->position.y == position.y) && territoire_suivant(liste)) {}

    return territoire_courant(liste)->position.x == position.x && territoire_courant(liste)->position.y == position.y;
}

int territoire_est_identique(Territoire territoire1, Territoire territoire2)
{
    if (territoire_vide(territoire1) && territoire_vide(territoire2))
        return 1;

    if (territoire_vide(territoire1) || territoire_vide(territoire2))
        return 0;

    int k = 0;

    if (territoire1->couleur == territoire2->couleur && territoire1->taille == territoire2->taille)
    {
        territoire_tete(territoire1);

        do
        {
            if (territoire_appartient(territoire_courant(territoire1)->position, territoire2))
                ++k;
        } while (territoire_suivant(territoire1));

        if (k == territoire1->taille)
            return 1;
    }

    return 0;
}

void territoire_tete(Territoire liste)
{
    if (!territoire_vide(liste))
        liste->courant = liste->tete;
}

int territoire_suivant(Territoire liste)
{
    if (territoire_vide(liste))
        return 0;

    if (territoire_courant(liste)->suivant != NULL)
    {
        liste->courant = territoire_courant(liste)->suivant;

        return 1;
    }

    return 0;
}

element_position* territoire_courant(Territoire liste)
{
    return territoire_vide(liste)) ? NULL : liste->courant;
}

Territoire determine_territoire(Plateau plateau, Position pos)
{
    if (plateau_get(plateau, pos.x, pos.y) != VIDE)
        return NULL;

    int k = 0;

    Territoire territoire = territoire_creer(VIDE);

    territoire_ajouter(pos, territoire);

    territoire_ajouter_pions_adjacents(plateau, territoire, pos.x, pos.y);

    Chaines liste = plateau_entoure_un_territoire(territoire, plateau);

    if (!chaines_vide(liste))
    {
        chaines_tete(liste);

        Couleur coul = chaines_courant(liste)->chaine->couleur;

        do
        {
            if (chaines_courant(liste)->chaine->couleur == coul)
                ++k;
        } while (chaines_suivant(liste));

        if (k == liste->taille)
            territoire->couleur = coul;
    }

    return territoire;
}

void territoire_ajouter_pions_adjacents(Plateau plateau, Territoire territoire, int x, int y)
{
    int i, j;
    Position position;

    for (j = y-1; j <= y+1; ++j)
        for (i = x-1; i <= x+1; ++i)
            if (i >= 0 && j >= 0 && i < plateau->taille && j < plateau->taille && (i+j == x+y+1 || i+j == x+y-1))
            {
                position.x = i;
                position.y = j;

                if (plateau_get(plateau, i, j) == VIDE && !territoire_appartient(position, territoire))
                {
                    territoire_ajouter(position, territoire);
                    territoire_ajouter_pions_adjacents(plateau, territoire, i, j);
                }
            }
}
