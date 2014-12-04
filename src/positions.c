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
  * @file positions.c
  *
  * Fonctions utiles à la gestion d'ensembles de positions
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/positions.h"

Positions positions_creer()
{
    Positions liste = malloc(sizeof(ensemble_positions));

    liste->taille = 0;
    liste->tete = NULL;
    liste->courant = NULL;

    return liste;
}

void positions_detruire(Positions liste)
{
    element_position* tmp;

    positions_tete(liste);

    if (!positions_vide(liste))
    {
        do
        {
            tmp = positions_courant(liste)->suivant;

            free(positions_courant(liste));

            liste->courant = tmp;
        } while (tmp != NULL);
    }

    free(liste);
}

int positions_vide(Positions liste)
{
    return liste->tete == NULL;
}

void positions_ajouter(Position position, Positions liste)
{
    element_position* element = malloc(sizeof(element_position));

    element->position = position;
    element->suivant = NULL;

    if (positions_vide(liste))
    {
        liste->tete = element;
        liste->courant = element;
    }
    else
    {
        while (positions_suivant(liste)) {}

        positions_courant(liste)->suivant = element;
    }

    liste->taille++;
}

int positions_appartient(Position position, Positions liste)
{
    if (positions_vide(liste))
        return 0;

    positions_tete(liste);

    while (!(positions_courant(liste)->position.x == position.x && positions_courant(liste)->position.y == position.y) && positions_suivant(liste))
    {}

    return positions_courant(liste)->position.x == position.x && positions_courant(liste)->position.y == position.y;
}

void positions_tete(Positions liste)
{
    if (!positions_vide(liste))
        liste->courant = liste->tete;
}

int positions_suivant(Positions liste)
{
    if (positions_vide(liste))
        return 0;

    if (positions_courant(liste)->suivant != NULL)
    {
        liste->courant = positions_courant(liste)->suivant;

        return 1;
    }

    return 0;
}

element_position* positions_courant(Positions liste)
{
    return positions_vide(liste) ? NULL : liste->courant;
}
