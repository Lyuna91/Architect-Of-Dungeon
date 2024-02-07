#ifndef MESSAGE_H
#define MESSAGE_H
#include "salle.h"

/* Cette bibliothèque va permettre de stocker tout les messages. Ces messages serviront à une
meilleure compréhension de notre application et à l'esthétisme*/

/* ESTHETIQUE */

void espacement();   // Purement esthétique, permet de créer de l'espacement dans le texte
void d_espacement(); // Purement esthétique, permet de créer un double espacement dans le texte
void logo();         // Purement esthétique, permet d'afficher un logo
void description();  // Petite description de l'application
void lancement();    // Nettoie le terminal, affiche le logo puis la description
void erreur();       // Message qui informe l'utilisateur d'une erreur de saisie
void valeur();       // Purement esthétique, permet d'indiquer à l'utilisateur quand entrer une donnée
void clear();        // Permet de vider le terminal pour qu'il ne soit pas surcharger

/* DONJON */

void donjon();                    // PARTIE : CREATION DE DONJON
void dimension_donjon();          // SOUS PARTIE : DIMENSION DU DONJON
void longueur_donjon();           // Demander la longueur du donjon
void hauteur_donjon();            // Demander la hauteur du donjon
void entree_sortie();             // SOUS PARTIE : ENTREE ET SORTIE
void entree_donjon(int longueur); // Demander la position de l'entrée du donjon
void sortie_donjon(int longueur); // Demander la position de la sortie

/* SALLES */

void salle();                                             // PARTIE : CREATION DES SALLES
void nb_salles();                                         // Demander le nombre de salles DIFFERENTES
void dimension_salle(int n_salle);                        // SOUS PARTIE : DIMENSION DE LA SALLE
void longueur_salle(int n_salle);                         // Demander la longueur de la salle
void hauteur_salle(int n_salle);                          // Demander la hauteur de la salle
void elements();                                          // SOUS PARTIE : CHOIX ET PLACEMENT DES ELEMENTS
void nb_elements(int n_salle, int n_max_element);         // Demander le nombre d'element
void type_element(int n_element, int n_salle);            // Demander type de l'element
void liste_elements();                                    // Liste des elements
void position_x_element(int min, int max, int n_element); // Demander la position en X (longueur) de l'élement
void position_y_element(int min, int max, int n_element); // Demander la position en Y (hauteur) de l'élement
void porte();                                             // SOUS PARTIE : CHOIX DU TYPE ET EMPLACEMENT PORTES
void nb_portes(int n_salle, int n_max_porte);             // Demander le nombre de porte
void type_porte(int n_porte, int n_salle);                // Demander le type de porte
void direction_porte(int n_porte);                        // Demander la direction de la porte (exemple: E signifie porte à l'EST donc à DROITE)
void position_porte_NS(int n_porte, int min, int max);    // Demander la position de la porte au NORD et SUD (en longueur)
void position_porte_EO(int n_porte, int min, int max);    // Demander la position de la porte EST et OUEST (en hauteur)
void afficher_salles(int nb_salles);                      // Annonce de l'affichage de la ou les salles

/* SALLES ET DONJONS */

void placement_salle();                      // PARTIE : PLACEMENT DES SALLES DANS LE DONJON
void choix_salle(int nb_salle);              // Demander le numéro de la salle a placer
void position_salle(int n_salle);            // SOUS PARTIE : DEMANDER LA POSITION DE LA SALLE
void placer_salle_x(int n_salle, int x_max); // Demander la position de la salle en X (longueur)
void placer_salle_y(int n_salle, int y_max); // Demander la position de la salle en Y (hauteur)

/* COULOIR */

void couloir();        // PARTIE : CREATION DES COULOIRS
void depart_couloir(); // Demander la confirmation pour le depart d'un couloir
void tracer_couloir(); // Demander la direction du couloir

/* DONJON, SALLES et COULOIRS */

void enregistrement();             // Demander l'enregistrement dans un fichier.txt
void modification();               // PARTE : DERNIERES MODIFICATION
void demande_modification();       // Demande si il y a des modification a faire
void modification_position();      // SOUS PARTIE : POSITION DE LA MODIFICATION
void modification_pos_x(Salle *s); // Demande position en X
void modification_pos_y(Salle *s); // Demande position en Y
void validation_position();        // Demande validation de la position d ela modification
void type_modification();          // SOUS PARTIE : TYPE DE LA MODIFICATION
void liste_elements_portes();      // Liste des elements que l'on peux modifier
void choix_modification();         // Demande le type de la modification
void fin_modification();           // Demande la fin de la modification
#endif