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
  * @file pion.c
  *
  * Fichier d'en-tête du type abstrait Pion
  *
  */

#ifndef PION_H
#define PION_H

#include "couleur.h"

/**
  * @struct Pion
  *
  * La structure implémentant un pion
  *
  * @var La couleur du pion
  * @var La position du pion
  *
  */

typedef struct pion
{
    Couleur couleur;
    Position position;
} Pion;

#endif
