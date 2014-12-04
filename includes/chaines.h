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
  * @file chaines.c
  *
  * Fichier d'en-tête du type abstrait Chaines
  *
  */

#ifndef CHAINES_H
#define CHAINES_H

#include "chaine.h"

/**
  * @struct element_chaine
  *
  * L'élément d'une liste simplement chainée de chaines
  *
  * @var Une chaine
  * @var Un pointeur sur l'élément suivant
  *
  */

typedef struct element_chaine
{
    Chaine chaine;
    struct element_chaine* suivant;
} element_chaine;

/**
  * @struct ensemble_chaines
  *
  * La structure permettant de gérer une liste simplement chainée de chaines
  *
  * @var La taille de la liste
  * @var Un pointeur sur la tête de la liste
  * @var Un pointeur sur l'élément courant de la liste
  *
  */

typedef struct ensemble_chaines
{
    int taille;
    element_chaine* tete;
    element_chaine* courant;
} ensemble_chaines;

/**
  * @typedef Chaines
  *
  * Chaines est un pointeur sur ensemble_chaines
  *
  */

typedef ensemble_chaines* Chaines;

/**
  * Création et intialisation d'une liste simplement chainée de chaines
  *
  * @return La liste correctement allouée
  *
  */

Chaines chaines_creer();

/**
  * Destruction d'une liste de chaines
  *
  * @param La liste à détruire
  *
  */

void chaines_detruire(Chaines liste);

/**
  * Teste si une liste de chaines est vide
  *
  * @param La liste à tester
  * @return 1 si la liste est vide, 0 si elle ne l'est pas
  *
  */

int chaines_vide(Chaines liste);

/**
  * Ajoute une chaine à une liste de chaines
  *
  * @param La chaine à ajouter
  * @param La liste à laquelle on veut ajouter une chaine
  *
  */

void chaines_ajouter(Chaine chaine, Chaines liste);

/**
  * Teste si une chaine appartient à une liste de chaines
  *
  * @param La chaine à tester
  * @param La liste à tester
  * @return 1 si la chaine appartient à la liste, 0 sinon
  *
  */

int chaines_appartient(Chaine chaine, Chaines liste);

/**
  * Se placer en tête d'une liste de chaines
  *
  * @param La liste à traiter
  *
  */

void chaines_tete(Chaines liste);

/**
  * Passer à l'élément suivant d'une liste de chaines
  *
  * @param La liste à traiter
  * @return 1 s'il y'a bien un suivant, 0 sinon
  *
  */

int chaines_suivant(Chaines liste);

/**
  * L'élément courant d'une liste de chaines
  *
  * @param La liste à traiter
  * @return Un pointeur sur l'élément courant de la liste
  *
  */

element_chaine* chaines_courant(Chaines liste);

#endif
