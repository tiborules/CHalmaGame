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
  * @file chaine.c
  *
  * Fichier d'en-tête du type abstrait Chaine
  *
  */

#ifndef CHAINE_H
#define CHAINE_H

#include "couleur.h"

/**
  * @typedef Chaine
  *
  * Chaine est un pointeur sur ensemble_colore
  *
  */

typedef ensemble_colore* Chaine;

/**
  * Création et intialisation d'une chaine
  *
  * @param La couleur de la chaine
  * @return La chaine correctement allouée
  *
  */

Chaine chaine_creer(Couleur couleur);

/**
  * Destruction d'une chaine
  *
  * @param La chaine à détruire
  *
  */

void chaine_detruire(Chaine liste);

/**
  * Teste si une chaine est vide
  *
  * @param La chaine à tester
  * @return 1 si la chaine est vide, 0 si elle ne l'est pas
  *
  */

int chaine_vide(Chaine liste);

/**
  * Ajoute une position à une chaine
  *
  * @param La position à ajouter
  * @param La chaine à laquelle on veut ajouter une position
  *
  */

void chaine_ajouter(Position position, Chaine liste);

/**
  * Teste si une position appartient à une chaine
  *
  * @param La position à tester
  * @param La chaine à tester
  * @return 1 si la position appartient à la chaine, 0 sinon
  *
  */

int chaine_appartient(Position position, Chaine liste);

/**
  * Teste si deux chaines sont identiques
  *
  * @param La première chaine à tester
  * @param La seconde chaine à tester
  * @return 1 si les chaines sont identiques, 0 sinon
  *
  */

int chaine_est_identique(Chaine chaine1, Chaine chaine2);

/**
  * Se placer en tête d'une chaine
  *
  * @param La chaine à traiter
  *
  */

void chaine_tete(Chaine liste);

/**
  * Passer à l'élément suivant d'une chaine
  *
  * @param La chaine à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int chaine_suivant(Chaine liste);

/**
  * L'élément courant d'une chaine
  *
  * @param La chaine à traiter
  * @return Un pointeur sur l'élément courant de la chaine
  *
  */

element_position* chaine_courant(Chaine liste);

#endif
