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
  * @file position.c
  *
  * Fichier d'en-tête du type abstrait Positions
  *
  */

#ifndef POSITION_H
#define POSITION_H

/**
  * @struct position
  *
  * La structure implémentant une position
  *
  * @var L'abscisse
  * @var L'ordonnée
  *
  */

typedef struct position
{
    int x;
    int y;
} Position;

/**
  * @struct element_position
  *
  * L'élément d'une liste simplement chainée de positions
  *
  * @var La position
  * @var Un pointeur sur l'élement suivant
  *
  */

typedef struct element_position
{
    Position position;
    struct element_position* suivant;
} element_position;

/**
  * @struct ensemble_position
  *
  * Une structure permettant de gérer une liste simplement chainée de positions
  *
  * @var La taille de la liste
  * @var Un pointeur sur la tête de la liste
  * @var Un pointeur sur l'élément courant de la liste
  *
  */

typedef struct ensemble_positions
{
    int taille;
    element_position* tete;
    element_position* courant;
} ensemble_positions;

#endif
