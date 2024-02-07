#ifndef DONJON_H
#define DONJON_H
#include "salle.h"

/* Cette bibliothèque stocke les quelques fonctions qui concerne uniquement le donjon.*/

/* DONJON */

Salle *creer_donjon();                                 // Fonction qui permet de créer un donjon. (Un donjon est juste une grande salle, avec une entrée et sortie)
void placer_entrer(Salle *s);                          // Fonction qui permet de placer une entrée 'E' au NORD.
void placer_sortie(Salle *s);                          // Fonction qui permet de placer une sortie 'S' au SUD
Salle *creation_donjon();                              // Fonction qui permet de créer un donjon avec une entrée et sortie
void afficher_fichier_donjon(FILE *fichier, Salle *s); // Afficher une salle dans un fichier
void enregister_donjon(Salle *s);                      // Fonction qui permet l'enregistrement dans un fichier.txt
void modifier_donjon(Salle *s);                        // Fonction qui lance la modification du donjon

#endif