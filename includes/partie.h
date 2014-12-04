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
  * @file partie.c
  *
  * Fichier d'en-tête du type abstrait Partie
  *
  */

#ifndef PARTIE_H
#define PARTIE_H

#include "plateau.h"

/**
  * @struct Joueur
  *
  * La structure implémentant un joueur
  *
  * @var Le nom du joueur
  * @var 1 s'il est humain, 0 si c'est une IA
  * @var Son score (conservé au fil de la partie)
  *
  */

typedef struct joueur
{
    char nom[8];
    int humain;
    float* score;
} Joueur;

/**
  * @struct Partie
  *
  * La structure permettant de gérer tout le déroulement d'une partie
  *
  * @var 1 si la partie est terminée, 0 sinon
  * @var 1 si au tour précédent, le joueur a passé
  * @var Le nombre de coups joués en tout
  * @var Le nombre de fois qu'un des joueurs a passé son tour
  * @var Le dernier coup joué (conservé au fil de la partie)
  * @var Le plateau actuel et tous les précédents
  * @var Un tableau contenant les deux joueurs
  * @var Le komi défini pour la partie
  *
  */

typedef struct partie
{
    int termine;
    int passe;
    int nbCoups;
    int nbPasse;
    char (*dernier)[4];
    Plateau* plateau;
    Joueur joueur[2];
    float komi;
} Partie;

/**
  * @typedef FonctionsQuestions
  *
  * Pointeur sur une fonction récupérant le paramétrage d'une partie par l'utilisateur
  *
  */

typedef void (*FonctionQuestions)(int numeroQuestion, Partie* p);

/**
  * Créé et initialise une partie selon le paramétrage de l'utilisateur
  *
  * @param Un pointeur sur la fonction communiquant avec l'utilisateur
  * @return La partie correctement intialisée
  *
  */

Partie partie_initialisation(FonctionQuestions fonctionQuestions);

/**
  * Pose les questions nécessaires à la création d'une partie à l'utilisateur en mode console
  *
  * @param Le numéro de la question
  * @param Un pointeur sur la partie à initialiser
  *
  */

void fonctionQuestions(int numeroQuestion, Partie* p);

/**
  * Sauvegarde une partie
  *
  * @param La partie à sauvegarder
  * @param Le fichier où sauvegarder
  * @return 1 si la sauvegarde a été réussie, 0 sinon
  *
  */

int partie_sauvegarde(Partie partie, FILE* fichier);

/**
  * Charge une partie
  *
  * @param Le fichier à partir duquel charger
  * @return La partie chargée
  *
  */

Partie partie_chargement(FILE* fichier);

/**
  * Calcule le score de chaque joueur en fin de partie
  *
  * @param La partie à traiter
  *
  */

void partie_score_joueurs(Partie* p);

#endif
