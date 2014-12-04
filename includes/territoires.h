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
  * @file territoires.c
  *
  * Fichier d'en-tête du type abstrait Territoires
  *
  */

#ifndef TERRITOIRES_H
#define TERRITOIRES_H

#include "territoire.h"

/**
  * @struct element_territoire
  *
  * L'élément d'une liste simplement chainée de territoires
  *
  * @var Un territoire
  * @var Un pointeur sur l'élément suivant
  *
  */

typedef struct element_territoire
{
    Territoire territoire;
    struct element_territoire* suivant;
} element_territoire;

/**
  * @struct ensemble_territoires
  *
  * La structure permettant de gérer une liste simplement chainée de territoires
  *
  * @var La taille de la liste
  * @var Un pointeur sur la tête de la liste
  * @var Un pointeur sur l'élément courant de la liste
  *
  */

typedef struct ensemble_territoires
{
    int taille;
    element_territoire* tete;
    element_territoire* courant;
} ensemble_territoires;

/**
  * @typedef Territoires
  *
  * Territoires est un pointeur sur ensemble_territoires
  *
  */

typedef ensemble_territoires* Territoires;

/**
  * Création et intialisation d'une liste simplement chainée de territoires
  *
  * @return La liste correctement allouée
  *
  */

Territoires territoires_creer();

/**
  * Destruction d'une liste de territoires
  *
  * @param La liste à détruire
  *
  */

void territoires_detruire(Territoires liste);

/**
  * Teste si une liste de territoires est vide
  *
  * @param La liste à tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  */

int territoires_vide(Territoires liste);

/**
  * Ajoute un territoire à une liste de territoires
  *
  * @param Le territoires à ajouter
  * @param La liste à laquelle on veut ajouter un territoire
  *
  */

void territoires_ajouter(Territoire territoire, Territoires liste);

/**
  * Teste si un territoire appartient à une liste de territoires
  *
  * @param Le territoire à tester
  * @param La liste à tester
  * @return 1 si le territoire appartient à la liste, 0 sinon
  *
  */

int territoires_appartient(Territoire territoire, Territoires liste);

/**
  * Se placer en tête d'une liste de territoires
  *
  * @param La liste à traiter
  *
  */

void territoires_tete(Territoires liste);

/**
  * Passer à l'élément suivant d'une liste de territoires
  *
  * @param La liste à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int territoires_suivant(Territoires liste);

/**
  * L'élément courant d'une liste de territoires
  *
  * @param La liste à traiter
  * @return Un pointeur sur l'élément courant de la liste
  *
  */

element_territoire* territoires_courant(Territoires liste);

#endif
