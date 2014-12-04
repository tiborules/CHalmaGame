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
  * @file territoire.c
  *
  * Fichier d'en-tête du type abstrait Territoire
  *
  */

#ifndef TERRITOIRE_H
#define TERRITOIRE_H

#include "couleur.h"

/**
  * @typedef Territoire
  *
  * Territoire est un pointeur sur ensemble_colore
  *
  */

typedef ensemble_colore* Territoire;

#include "plateau.h"

/**
  * Création et intialisation d'un territoire
  *
  * @param La couleur du territoire
  * @return Le territoire correctement alloué
  *
  */

Territoire territoire_creer(Couleur couleur);

/**
  * Destruction d'un territoire
  *
  * @param Le territoire à détruire
  *
  */

void territoire_detruire(Territoire liste);

/**
  * Teste si un territoire est vide
  *
  * @param Le territoire à tester
  * @return 1 si le territoire est vide, 0 s'il ne l'est pas
  *
  */

int territoire_vide(Territoire liste);

/**
  * Ajoute une position à un territoire
  *
  * @param La position à ajouter
  * @param Le territoire auquel on veut ajouter une position
  *
  */

void territoire_ajouter(Position position, Territoire liste);

/**
  * Teste si une position appartient à un territoire
  *
  * @param La position à tester
  * @param Le territoire à tester
  * @return 1 si la position appartient au territoire, 0 sinon
  *
  */

int territoire_appartient(Position position, Territoire liste);

/**
  * Teste si deux territoires sont identiques
  *
  * @param Le premier territoire à tester
  * @param Le second territoire à tester
  * @return 1 si les territoires sont identiques, 0 sinon
  *
  */

int territoire_est_identique(Territoire territoire1, Territoire territoire2);

/**
  * Se placer en tête d'un territoire
  *
  * @param Le territoire à traiter
  *
  */

void territoire_tete(Territoire liste);

/**
  * Passer à l'élément suivant d'un territoire
  *
  * @param Le territoire à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int territoire_suivant(Territoire liste);

/**
  * L'élément courant d'un territoire
  *
  * @param Le territoire à traiter
  * @return Un pointeur sur l'élément courant du territoire
  *
  */

element_position* territoire_courant(Territoire liste);

/**
  * Détermine le territoire auquel appartient une case vide du plateau
  *
  * @param Le plateau courant
  * @param La position de la case
  * @return Le territoire auquel appartient la position
  *
  */

Territoire determine_territoire(Plateau plateau, Position pos);

#endif
