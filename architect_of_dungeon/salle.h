#ifndef SALLE_H
#define SALLE_H

/* Cette bibliothèque contient tout ce qu'il faut pour créer une salle. De la dimension jusqu'au placement des objets
et des portes.*/

/* TYPEDEF */

typedef struct s
{
    int numero;      // Numéro de la salle
    int H;           // Hauteur de la salle
    int L;           // Longeur de la salle
    char **uneSalle; // Tableau dynamique de la salle
} Salle;

typedef enum
{
    COFFRE = 'C',
    MONSTRE = 'M',
    DEPOUILLE = 'W',
    AUTEL = 'A',
    PIEGE = 'P',
    CHAMPION = 'B',
    MUR = '#',

    ENTREE = 'E',
    SORTIE = 'S',
    PORTEF = 'F',
    PORTEO = 'O',
} Element;

/* CREATION D'UNE SALLE */

Salle *creer_salle(int H, int L, int numero);         // Permet d'initialiser une salle et d'allouer la mémoire
Salle *initialiser_salle(int H, int L, int numero);   // Permet de créer une salle (la remplir d'éléments)
Salle *dimensionner_salle(int n_salle);               // Permet de créer une salle avec des dimensions choisis
Salle *creation_salle(int n_salle);                   // Fonction qui permet de créer les salles avec les objets et portes
void afficher_salle(Salle *s);                        // Permet d'afficher une salle
void enregister_salle(Salle *s);                      // Permet d'enregistrer une salle dans un fichier.txt
void afficher_fichier_salle(FILE *fichier, Salle *s); // Permet d'afficher dans un fichier
void liberer_salle(Salle *s);                         // Libère la mémoire d'une pièce
void liberer_salles(Salle **salles, int nb_salles);   // Liberer la mémoire pour toutes les salles

/* AJOUT D'OBJETS/PORTES */

/* Objets */
void ajouter_objet(Salle *s, char objet, int X, int Y); // Permet de placer un objet à l'intérieur d'une salle
void insertion_objets(Salle *s);                        // Permet de placer un nombre d'objets qui sera choisis

/* Portes */
void ajouter_porte(Salle *s, char porte, int X, int Y);         // Permet de placer une porte sur les murs d'une salle
void ajouter_porte_position(Salle *s, char porte, int n_porte); // Permet de placer une porte à une position plus simple à comprendre
void insertion_portes(Salle *s);                                // Permet de placer un nombre de portes choisis

/* PLACEMENT DES SALLES */

void placer_salles(Salle *donjon, Salle **sallesPrecedentes, int nbSalles); // Fonction qui permet d'ajouter des salles dans un donjon
void ajouter_salle(Salle *d, Salle *s, int X, int Y);                       // Fonction qui permet de placer des salles dans un donjon

#endif