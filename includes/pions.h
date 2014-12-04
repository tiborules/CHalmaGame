#ifndef PIONS_H
#define PIONS_H

#include "pion.h"

typedef struct element_pion
{
    Pion pion;
    struct element_pion* suivant;
} element_pion;

typedef struct ensemble_pions
{
    int taille;
    element_pion* tete;
    element_pion* courant;
} ensemble_pions;

typedef ensemble_pions* Pions;

Pions pions_creer();

void pions_detruire(Pions liste);

int pions_vide(Pions liste);

void pions_ajouter(Pion pion, Pions liste);

int pions_appartient(Pion pion, Pions liste);

void pions_tete(Pions liste);

int pions_suivant(Pions liste);

element_pion* pions_courant(Pions liste);

#endif
