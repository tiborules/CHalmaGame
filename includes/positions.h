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
  * Fichier d'en-tête du type abstrait Positions
  *
  */

#ifndef POSITIONS_H
#define POSITIONS_H

#include "position.h"

/**
  * @typedef Positions
  *
  * Positions est un pointeur sur ensemble_positions
  *
  */

typedef ensemble_positions* Positions;

/**
  * Création et intialisation d'une liste de positions
  *
  * @return La liste correctement allouée
  *
  */

Positions positions_creer();

/**
  * Destruction d'une liste de positions
  *
  * @param La liste à détruire
  *
  */

void positions_detruire(Positions liste);

/**
  * Teste si une liste de positions est vide
  *
  * @param La liste à tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  */

int positions_vide(Positions liste);

/**
  * Ajoute une chaine à une liste de positions
  *
  * @param La position à ajouter
  * @param La liste à laquelle on veut ajouter une chaine
  *
  */

void positions_ajouter(Position position, Positions liste);

/**
  * Teste si une position appartient à une liste de positions
  *
  * @param La position à tester
  * @param La liste à tester
  * @return 1 si la position appartient à la liste, 0 sinon
  *
  */

int positions_appartient(Position position, Positions liste);

/**
  * Se placer en tête d'une liste de positions
  *
  * @param La liste à traiter
  *
  */

void positions_tete(Positions liste);

/**
  * Passer à l'élément suivant d'une liste de positions
  *
  * @param La liste à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int positions_suivant(Positions liste);

/**
  * L'élément courant d'une liste de positions
  *
  * @param La liste à traiter
  * @return Un pointeur sur l'élément courant de la liste
  *
  */

element_position* positions_courant(Positions liste);

#endif
