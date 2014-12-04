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
  * @file couleur.c
  *
  * Fichier d'en-tête du type abstrait Couleur
  *
  */

#ifndef COULEUR_H
#define COULEUR_H

#include "position.h"

/**
  * @enum Couleur
  *
  * Une couleur peut être noire, blanche ou vide
  *
  */

typedef enum couleur {VIDE, ROUGE, BLEU, JAUNE, VERT, MARQUEUR} Couleur;

/**
  * @struct ensemble_colore
  *
  * Une structure incluant une couleur permettant de gérer une liste simplement chainée de positions
  *
  * @var La taille de la liste
  * @var Un pointeur sur la tête de la liste
  * @var Un pointeur sur l'élément courant de la liste
  * @var La couleur de la liste
  *
  */

typedef struct ensemble_colore
{
    int taille;
    element_position* tete;
    element_position* courant;
    Couleur couleur;
} ensemble_colore;

#endif
