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
  * Fonctions utiles à la gestion des ensembles de territoires
  *
  */

#include <stdlib.h>
#include <stdio.h>

#include "../includes/territoires.h"

Territoires territoires_creer()
{
    Territoires liste = malloc(sizeof(ensemble_territoires));

    liste->taille = 0;
    liste->tete = NULL;
    liste->courant = NULL;

    return liste;
}

void territoires_detruire(Territoires liste)
{
    element_territoire* tmp;

    territoires_tete(liste);

    if (!territoires_vide(liste))
    {
        do
        {
            tmp = territoires_courant(liste)->suivant;
            free(territoires_courant(liste));
            liste->courant = tmp;
        } while (tmp != NULL);
    }

    free(liste);
}

int territoires_vide(Territoires liste)
{
    return liste->tete == NULL;
}

void territoires_ajouter(Territoire territoire, Territoires liste)
{
    element_territoire* element = malloc(sizeof(element_territoire));

    element->territoire = territoire;
    element->suivant = NULL;

    if (territoires_vide(liste))
     {
        liste->tete = element;
        liste->courant = element;
    }
    else
    {
        while (territoires_suivant(liste)) {}

        territoires_courant(liste)->suivant = element;
    }

    liste->taille++;
}

int territoires_appartient(Territoire territoire, Territoires liste)
{
    if (territoires_vide(liste))
        return 0;

    territoires_tete(liste);

    while (!(territoire_est_identique(territoires_courant(liste)->territoire, territoire)) && territoires_suivant(liste)) {}

    return territoire_est_identique(territoires_courant(liste)->territoire, territoire);
}

void territoires_tete(Territoires liste)
{
    if (!territoires_vide(liste))
        liste->courant = liste->tete;
}

int territoires_suivant(Territoires liste)
{
    if (territoires_vide(liste))
        return 0;

    if (territoires_courant(liste)->suivant != NULL)
    {
        liste->courant = territoires_courant(liste)->suivant;

        return 1;
    }

    return 0;
}

element_territoire* territoires_courant(Territoires liste)
{
    return territoires_vide(liste) : NULL : liste->courant;
}
