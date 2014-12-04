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
  * Fichier d'en-tête du type abstrait Libertés
  *
  */

#ifndef LIBERTES_H
#define LIBERTES_H

#include "position.h"

/**
  * @typedef Libertés
  *
  * Libertés est un pointeur sur ensemble_positions
  *
  */

typedef ensemble_positions* Libertes;

#include "chaines.h"
#include "plateau.h"

/**
  * Création et intialisation d'un ensemble de libertés
  *
  * @return L'ensemble de libertés correctement alloué
  *
  */

Libertes libertes_creer();

 /**
  * Destruction d'un ensemble de libertés
  *
  * @param L'ensemble de libertés à détruire
  *
  */

void libertes_detruire(Libertes liste);

/**
  * Teste si un ensemble de libertés est vide
  *
  * @param L'ensemble à tester
  * @return 1 si l'ensemble est vide, 0 si elle ne l'est pas
  *
  */

int libertes_vide(Libertes liste);

/**
  * Ajoute une liberté à l'ensemble
  *
  * @param La position à ajouter
  * @param L'ensemble auquel on veut ajouter une position
  *
  */

void libertes_ajouter(Position position, Libertes liste);

/**
  * Teste si une position appartient à l'ensemble de libertés
  *
  * @param La position à tester
  * @param L'ensemble à tester
  * @return 1 si la position appartient à l'ensemble, 0 sinon
  *
  */

int libertes_appartient(Position position, Libertes liste);

/**
  * Se placer en tête d'un ensemble de libertés
  *
  * @param L'ensemble à traiter
  *
  */

void libertes_tete(Libertes liste);

/**
  * Passer à l'élément suivant d'un ensemble de libertés
  *
  * @param L'ensemble à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int libertes_suivant(Libertes liste);

/**
  * L'élément courant d'un ensemble de libertés
  *
  * @param L'ensemble à traiter
  * @return Un pointeur sur l'élément courant de l'ensemble
  *
  */

element_position* libertes_courant(Libertes liste);

/**
  * Détermine les libertés d'une chaine sur le plateau
  *
  * @param Le plateau courant
  * @param La chaine à traiter
  * @return L'ensemble des libertés de la chaine
  *
  */

Libertes determine_liberte(Plateau plateau, Chaine chaine);

#endif
