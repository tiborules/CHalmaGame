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
  * @file libertes.c
  *
  * Fonctions utiles à la gestion des libertés
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/libertes.h"

Libertes libertes_creer()
{
    Libertes liste = malloc(sizeof(ensemble_positions));

    liste->taille = 0;
    liste->tete = NULL;
    liste->courant = NULL;

    return liste;
}

void libertes_detruire(Libertes liste)
{
    element_position* tmp;

    libertes_tete(liste);

    if (!libertes_vide(liste))
    {
        do
        {
            tmp = libertes_courant(liste)->suivant;

            free(libertes_courant(liste));

            liste->courant = tmp;
        } while (tmp != NULL);
    }

    free(liste);
}

int libertes_vide(Libertes liste)
{
    return liste->tete == NULL;
}

void libertes_ajouter(Position position, Libertes liste)
{
    element_position* element = malloc(sizeof(element_position));

    element->position = position;
    element->suivant = NULL;

    if (libertes_vide(liste))
    {
        liste->tete = element;
        liste->courant = element;
    }
    else
    {
        while (libertes_suivant(liste))
        {}

        libertes_courant(liste)->suivant = element;
    }

    ++liste->taille;
}

int libertes_appartient(Position position, Libertes liste)
{
    if (libertes_vide(liste))
        return 0;

    libertes_tete(liste);

    while (!(libertes_courant(liste)->position.x == position.x && libertes_courant(liste)->position.y == position.y) && libertes_suivant(liste))
    {}

    return libertes_courant(liste)->position.x == position.x && libertes_courant(liste)->position.y == position.y;
}

void libertes_tete(Libertes liste)
{
    if (!libertes_vide(liste))
        liste->courant = liste->tete;
}

int libertes_suivant(Libertes liste)
{
    if (libertes_vide(liste))
        return 0;

    if (libertes_courant(liste)->suivant != NULL)
    {
        liste->courant = libertes_courant(liste)->suivant;

        return 1;
    }

    return 0;
}

element_position* libertes_courant(Libertes liste)
{
    return libertes_vide(liste)) ? NULL : liste->courant;
}

Libertes determine_liberte(Plateau plateau, Chaine chaine)
{
    int i, j;
    Position position;

    Libertes libertes = libertes_creer();

    chaine_tete(chaine);

    do
    {
        for (j = chaine_courant(chaine)->position.y-1; j <= chaine_courant(chaine)->position.y+1; ++j)
            for (i = chaine_courant(chaine)->position.x-1; i <= chaine_courant(chaine)->position.x+1; ++i)
                if (i >= 0 && j >= 0 && i < plateau->taille && j < plateau->taille && (i+j == chaine_courant(chaine)->position.x+chaine_courant(chaine)->position.y+1 || i+j == chaine_courant(chaine)->position.x+chaine_courant(chaine)->position.y-1))
                    if (plateau_get(plateau, i, j) == VIDE)
                    {
                        position.x = i;
                        position.y = j;

                        if (!libertes_appartient(position, libertes))
                            libertes_ajouter(position, libertes);
                    }
    } while (chaine_suivant(chaine));

    return libertes;
}
