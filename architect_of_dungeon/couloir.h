#ifndef COULOIR_H
#define COULOIR_H
#include "salle.h"

typedef struct
{
    int nb_deplacement;
    char *sequence;
    int H;
    int L;
    char **unCouloir;
} Couloir;

Couloir *initialiser_couloir(int nb_deplacement, const char *sequence, int hauteur, int longueur); // Fonction qui permet d'initialiser un couloir
Couloir *creer_couloir(int nb_deplacement, const char *sequence, int hauteur, int longueur);       // Fonction qui permet de creer un couloir
void liberer_couloir(Couloir *c);                                                                  // Fonction qui permet de liberer un couloir
int calculer_longueur(const char *sequence);                                                       // Fonction qui permet de calculer la longueur necessaire au tableau pour contenir le couloir a sauvegarder dans un ficher
int calculer_hauteur(const char *sequence);                                                        // Fonction qui permet de calculer la hauteur necessaire au tableau pour contenur le couloir a sauvegarder
int coordonnee_y(Couloir *c);                                                                      // Fonction qui calcule le point de depart en Y du couloir qui sera sauvegarder
int coordonnee_x(Couloir *c);                                                                      // Fonction qui calcule le point de depart en X du couloir qui sera sauvegarder
void dessiner_chemin(Couloir *c);                                                                  // Fonction qui dessine le chemin du couloir qui sera sauvegarder
void dessiner_couloir(Couloir *c);                                                                 // Fonction qui dessine le couloir
void enregistrer_couloir(Couloir *c);                                                              // Sauvegarder le couloir dans un fichier
void afficher_fichier_couloir(FILE *fichier, Couloir *c);                                          // Afficher le couloir dans un fichier
void afficher_couloir(Couloir *c);                                                                 // Fonction qui affiche le couloir a sauvegarder
void nettoyer_couloir(Couloir *c);                                                                 // Fonction qui nettoie le couloir qui sera sauvegarder
void nettoyer_couloir_donjon(Salle *s);                                                            // Fonction qui nettoie le couloir dans le donjon
void placer_couloir(Salle *s);                                                                     // Fonction qui trace le couloir sur le donjon en fonction du chemin
void creation_couloir(Salle *s);                                                                   // Fonction qui creer le couloir en temps reel sur le donjon

#endif /* COULOIR_H */
