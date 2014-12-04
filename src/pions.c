#include <stdlib.h>
#include <stdio.h>

#include "../includes/pions.h"

Pions pions_creer()
{
    Pions liste = malloc(sizeof(ensemble_pions));

    liste->taille = 0;
    liste->tete = NULL;
    liste->courant = NULL;

    return liste;
}

void pions_detruire(Pions liste)
{
    element_pion* tmp;

    pions_tete(liste);

    if (!pions_vide(liste))
    {
        do
        {
            tmp = pions_courant(liste)->suivant;

            free(pions_courant(liste));

            liste->courant = tmp;
        } while (tmp != NULL);
    }

    free(liste);
}

int pions_vide(Pions liste)
{
    return liste->tete == NULL;
}

void pions_ajouter(Pion pion, Pions liste)
{
    element_pion* element = malloc(sizeof(element_pion));

    element->pion = pion;
    element->suivant = NULL;

    if (pions_vide(liste))
    {
        liste->tete = element;
        liste->courant = element;
    }
    else
    {
        while (pions_suivant(liste))
        {}

        pions_courant(liste)->suivant = element;
    }

    liste->taille++;
}

int pions_appartient(Pion pion, Pions liste)
{
    if (pions_vide(liste))
        return 0;

    pions_tete(liste);

    while (!(pions_courant(liste)->pion.position.x == pion.position.x && pions_courant(liste)->pion.position.y == pion.position.y && pions_courant(liste)->pion.couleur == pion.couleur) && pions_suivant(liste)) {}

    return pions_courant(liste)->pion.position.x == pion.position.x && pions_courant(liste)->pion.position.y == pion.position.y && pions_courant(liste)->pion.couleur == pion.couleur;
}

void pions_tete(Pions liste)
{
    if (!pions_vide(liste))
        liste->courant = liste->tete;
}

int pions_suivant(Pions liste)
{
    if (pions_vide(liste))
        return 0;

    if (pions_courant(liste)->suivant != NULL)
    {
        liste->courant = pions_courant(liste)->suivant;
        return 1;
    }

    return 0;
}

element_pion* pions_courant(Pions liste)
{
    return liste->courant;
}

