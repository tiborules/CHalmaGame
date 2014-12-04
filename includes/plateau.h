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
  * Fichier d'en-tête du type abstrait Plateau
  *
  */

#ifndef PLATEAU_H
#define PLATEAU_H

#include "couleur.h"

/**
  * @struct structure_plateau
  *
  * La structure implémentant un plateau de jeu
  *
  * @var La taille du plateau
  * @var Un tableau d'une dimension stockant la couleur de chaque case du plateau
  *
  */

typedef struct structure_plateau
{
    int taille;
    Couleur* couleur;
} structure_plateau;

/**
  * @typedef Plateau
  *
  * Plateau est un pointeur sur structure_plateau
  *
  */

typedef structure_plateau* Plateau;

#include "pion.h"
#include "libertes.h"
#include "chaines.h"
#include "territoires.h"

/**
  * Création et intialisation d'un plateau de jeu
  *
  * @param La taille du plateau
  * @return Le plateau correctement initialisé
  *
  */

Plateau plateau_creer(int taille);

/**
  * Destruction d'un plateau de jeu
  *
  * @param Le plateau à détruire
  *
  */

void plateau_detruire(Plateau plateau);

/**
  * Récupère la couleur d'une case sur le plateau
  *
  * @param Le plateau
  * @param L'abscisse de la position
  * @param L'ordonnée de la position
  * @return La couleur à la position voulue
  *
  */

Couleur plateau_get(Plateau plateau, int i, int j);

/**
  * Modifier la couleur d'une case sur le plateau
  *
  * @param Le plateau
  * @param L'abscisse de la position
  * @param L'ordonnée de la position
  * @param La couleur à mettre sur la case
  *
  */

void plateau_set(Plateau plateau, int i, int j, Couleur couleur);

/**
  * Déterminer la chaine à laquelle appartient un pion
  *
  * @param Le plateau courant
  * @param La position du pion
  * @return La chaine complète
  *
  */

Chaine plateau_determiner_chaine(Plateau plateau, Position pos);

/**
  * Réaliser la capture d'une chaine sur le plateau
  *
  * @param Le plateau à modifier
  * @param La chaine à capturer
  *
  */

void plateau_realiser_capture(Plateau plateau, Chaine chaine);

/**
  * Teste si deux plateaux sont indentiques
  *
  * @param Le premier plateau à tester
  * @param Le second plateau à tester
  * @return 1 si les plateaux sont identiques, 0 sinon
  *
  */

int plateau_est_identique(Plateau plateau1, Plateau plateau2);

/**
  * Copier un plateau vers un autres, les deux étant correctement alloués
  *
  * @param Le plateau source
  * @param Le plateau destination
  * @return 1 si la copie est réussie, 0 sinon
  *
  */

int plateau_copie(Plateau from, Plateau to);

/**
  * Déterminer les chaines qui entourent un territoire sur le plateau
  *
  * @param Le territoire
  * @param Le plateau courant
  * @return La liste des chaines entourant le territoire
  *
  */

Chaines plateau_entoure_un_territoire(Territoire territoire, Plateau plateau);

/**
  * Sauvegarder un pleteau
  *
  * @param Le plateau à sauvegarder
  * @param Le fichier où sauvegarder
  * @return 1 si la sauvegarde est réussie, 0 sinon
  *
  */

int plateau_sauvegarde(Plateau plateau, FILE* fichier);

/**
  * Charger un pleteau
  *
  * @param Le fichier à partir duquel charger
  * @return Le plateau chargé
  *
  */

Plateau plateau_chargement(FILE* fichier);

/**
  * Détermine les chaines capturées par la pose d'un pion, et si le coup est valide ou non
  *
  * @param Le plateau courant
  * @param Le pion à poser
  * @param Un pointeur sur le booléen à mettre à 1 si le coup est valide, 0 sinon
  * @return La liste des chaines capturées
  *
  */

Chaines capture_chaines(Plateau plateau, Pion pion, int* valide);

#endif
