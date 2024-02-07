#include <stdio.h>
#include <stdlib.h>
#include "salle.h"
#include "couloir.h"
#include "message.h"

/* CREATION D'UNE SALLE */

Salle *initialiser_salle(int H, int L, int numero) // Permet d'initialiser une salle et d'allouer la mémoire
{
    Salle *s = (Salle *)malloc(sizeof(Salle));
    s->H = H;
    s->L = L;
    s->numero = numero;
    s->uneSalle = (char **)malloc(H * sizeof(char *));
    for (int i = 0; i < H; i++)
    {
        s->uneSalle[i] = (char *)malloc(L * sizeof(char));
    }
    return s;
}

Salle *creer_salle(int H, int L, int numero) // Permet de créer une salle (la remplir d'éléments vide et murs)
{
    Salle *s = initialiser_salle(H, L, numero);
    for (int i = 0; i < s->H; i++) // Remplir le tableau de caractères vide
    {
        for (int j = 0; j < s->L; j++)
        {
            s->uneSalle[i][j] = ' ';
        }
    }
    for (int i = 0; i < s->L; i++) // Dessiner les murs de la salle
    {
        s->uneSalle[0][i] = '#';        // Côté NORD
        s->uneSalle[s->H - 1][i] = '#'; // Côté SUD
    }
    for (int i = 0; i < s->H; i++)
    {
        s->uneSalle[i][0] = '#';        // Côté OUEST
        s->uneSalle[i][s->L - 1] = '#'; // Côté EST
    }
    return s;
}

Salle *dimensionner_salle(int numero) // Permet de créer une salle demandant les dimensions
{
    int hauteur, longueur;
    dimension_salle(numero); // Annonce pour les dimensions du donjon
    longueur_salle(numero);  //  Demande la longueur de la salle
    scanf("%d", &longueur);
    while (longueur > 15 || longueur < 5) // En cas d'erreur de saisie...
    {
        erreur();
        longueur_salle(numero);
        scanf("%d", &longueur);
    }
    hauteur_salle(numero); // Demande la hauteur de la salle
    scanf("%d", &hauteur);
    while (hauteur > 15 || hauteur < 5) // En cas d'erreur de saisie
    {
        erreur();
        hauteur_salle(numero);
        scanf("%d", &hauteur);
    }
    Salle *s = creer_salle(hauteur, longueur, numero);
    return s;
}

Salle *creation_salle(int numero) // Fonction qui permet de créer les salles avec les objets et portes
{
    Salle *s = dimensionner_salle(numero);
    system("cls");
    afficher_salle(s);
    insertion_objets(s);
    insertion_portes(s);
    enregister_salle(s);
    clear();
    return s;
}

void afficher_salle(Salle *s) // Permet d'afficher une salle
{
    espacement();
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            printf("%c ", s->uneSalle[i][j]);
        }
        printf("\n");
    }
    espacement();
}

void enregister_salle(Salle *s) // Fonction qui permet l'enregistrement dans un fichier.txt
{
    char reponse;
    enregistrement("SALLE");
    scanf(" %c", &reponse);
    if (reponse == 'O')
    {
        FILE *fichier = fopen("salle.txt", "w");
        afficher_fichier_salle(fichier, s);
        fclose(fichier);
    }
}

void afficher_fichier_salle(FILE *fichier, Salle *s) // Fonction qui ecris dans un fichier une salle
{
    fprintf(fichier, "Une salle de dimension %d sur %d \n", s->L, s->H);
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            fprintf(fichier, "%c ", s->uneSalle[i][j]);
        }
        fprintf(fichier, "\n");
    }
}

void liberer_salle(Salle *s) // Libère la mémoire d'une pièce
{
    for (int i = 0; i < s->H; i++)
    {
        free(s->uneSalle[i]);
    }
    free(s->uneSalle);
    free(s);
}

void liberer_salles(Salle **s, int nb_salles) // Liberer la mémoire pour toutes les salles
{
    for (int i = 0; i < nb_salles; i++)
    {
        liberer_salle(s[i]);
    }
    free(s);
}

/* AJOUT D'OBJETS/PORTES */

/* Objets */

void ajouter_objet(Salle *s, char objet, int X, int Y) // Permet de placer un objet à l'intérieur d'une salle
{
    if ((X < ((s->L) - 1) && X >= 1) && (Y < ((s->H) - 1) && Y >= 1))
    {
        s->uneSalle[Y][X] = objet;
    }
}

void insertion_objets(Salle *s) // Permet de placer un nombre d'objets qui sera choisis
{
    int nb_objets, pos_x, pos_y;
    int nb_objets_max = ((s->L - 2) * (s->H - 2));

    nb_elements(s->numero, nb_objets_max);
    scanf("%d", &nb_objets);

    while (nb_objets > nb_objets_max)
    {
        erreur();
        nb_elements(s->numero, nb_objets_max);
        scanf("%d", &nb_objets);
    }
    clear();
    afficher_salle(s);
    for (int i = 0; i < nb_objets; i++)
    {
        type_element(i + 1, s->numero);

        char element;
        scanf(" %c", &element);
        Element objet = (Element)element;

        while (objet != COFFRE && objet != MONSTRE && objet != DEPOUILLE &&
               objet != AUTEL && objet != PIEGE && objet != CHAMPION &&
               objet != MUR)
        {
            erreur();
            type_element(i + 1, s->numero);
            scanf(" %c", &element);
            objet = (Element)element;
        }

        position_x_element(1, s->L - 2, i + 1);
        scanf("%d", &pos_x);

        while (pos_x > s->L - 2 || pos_x < 1)
        {
            erreur();
            position_x_element(1, s->L - 2, i + 1);
            scanf("%d", &pos_x);
        }

        position_y_element(1, s->H - 2, i + 1);
        scanf("%d", &pos_y);

        while (pos_y > s->H - 2 || pos_y < 1)
        {
            erreur();
            position_y_element(1, s->H - 2, i + 1);
            scanf("%d", &pos_y);
        }

        ajouter_objet(s, objet, pos_x, pos_y);
        clear();
        afficher_salle(s);
    }
}

/* Portes */

void ajouter_porte(Salle *s, char porte, int X, int Y) // Permet de placer une porte sur les murs d'une salle
{
    s->uneSalle[Y][X] = porte;
}

void ajouter_porte_position(Salle *s, char porte, int n_porte) // Permet de placer une porte à une position plus simple à comprendre
{
    char position;
    int pos_X = s->L;
    int pos_Y = s->H;
    direction_porte(n_porte);
    scanf(" %c", &position);
    while (position != 'N' && position != 'E' && position != 'S' && position != 'O')
    {
        erreur();
        direction_porte(n_porte);
        scanf(" %c", &position);
    }

    if (position == 'N')
    {
        int position_n;
        position_porte_NS(n_porte, 1, pos_X - 2);
        scanf("%d", &position_n);
        if (position_n < 1 || position_n > pos_X - 2)
        {
            erreur();
            position_porte_NS(n_porte, 1, pos_X - 2);
            scanf("%d", &position_n);
        }
        ajouter_porte(s, porte, position_n, 0);
    }
    else if (position == 'S')
    {
        int position_s;
        position_porte_NS(n_porte, 1, pos_X - 2);
        scanf("%d", &position_s);
        if (position_s == 0 || position_s > pos_X - 2)
        {
            erreur();
            position_porte_NS(n_porte, 1, pos_X - 2);
            scanf("%d", &position_s);
        }
        ajouter_porte(s, porte, position_s, pos_Y - 1);
    }
    else if (position == 'E')
    {
        int position_e;
        position_porte_EO(n_porte, 1, pos_Y - 2);
        scanf("%d", &position_e);
        if (position_e == 0 || position_e > pos_Y - 2)
        {
            erreur();
            position_porte_EO(n_porte, 1, pos_Y - 2);
            scanf("%d", &position_e);
        }
        ajouter_porte(s, porte, pos_X - 1, position_e);
    }
    else if (position == 'O')
    {
        int position_o;
        position_porte_EO(n_porte, 1, pos_Y - 2);
        scanf("%d", &position_o);
        if (position_o == 0 || position_o > pos_Y - 2)
        {
            erreur();
            position_porte_EO(n_porte, 1, pos_Y - 2);
            scanf("%d", &position_o);
        }
        ajouter_porte(s, porte, 0, position_o);
    }
}

void insertion_portes(Salle *s) // Permet de placer un nombre de portes choisis
{
    char type;
    int nb;
    int n_max_portes = (((s->L * s->H) - 4) / 2);
    nb_portes(s->numero, n_max_portes);
    scanf("%d", &nb);
    while (nb > n_max_portes)
    {
        erreur();
        nb_portes(s->numero, n_max_portes);
        scanf("%d", &nb);
    }
    clear();
    afficher_salle(s);
    for (int i = 0; i < nb; i++)
    {
        type_porte(s->numero, i + 1);
        scanf(" %c", &type);
        while (type != 'F' && type != 'O')
        {
            erreur();
            type_porte(s->numero, i + 1);
            scanf(" %c", &type);
        }
        ajouter_porte_position(s, type, i + 1);
        clear();
        afficher_salle(s);
    }
    clear();
    afficher_salle(s);
}

/* PLACEMENT DES SALLES */

void ajouter_salle(Salle *d, Salle *s, int pos_X, int pos_Y) // Fonction qui permet d'ajouter des salles dans un donjon
{
    if (pos_X >= 1 && pos_X + s->L <= d->L && pos_Y >= 1 && pos_Y + s->H <= d->H)
    {
        for (int i = 0; i < s->H; i++)
        {
            for (int j = 0; j < s->L; j++)
            {
                d->uneSalle[pos_Y + i][pos_X + j] = s->uneSalle[i][j];
            }
        }
    }
    else
    {
        erreur();
    }
}

void placer_salles(Salle *donjon, Salle **sallesPrecedentes, int nbSalles) // Fonction qui permet de placer des salles dans un donjon
{
    int nSalle = 1;
    int x, y;

    while (nSalle != 0)
    {
        for (int j = 0; j < nbSalles; j++)
        {
            printf("SALLE %d \n", j + 1);
            afficher_salle(sallesPrecedentes[j]);
        }

        choix_salle(nbSalles);
        scanf("%d", &nSalle);
        if (nSalle == 0)
        {
            break;
        }

        while (nSalle > nbSalles)
        {
            erreur();
            choix_salle(nbSalles);
            scanf("%d", &nSalle);
        }

        placer_salle_x(nSalle, donjon->L - (sallesPrecedentes[nSalle - 1]->L + 2));
        scanf("%d", &x);
        while (x < 2 || x > donjon->L - (sallesPrecedentes[nSalle - 1]->L + 2))
        {
            erreur();
            placer_salle_x(nSalle, donjon->L - (sallesPrecedentes[nSalle - 1]->L + 2));
            scanf("%d", &x);
        }

        placer_salle_y(nSalle, donjon->H - (sallesPrecedentes[nSalle - 1]->H + 2));
        scanf("%d", &y);
        while (y < 2 || y > donjon->H - (sallesPrecedentes[nSalle - 1]->H + 2))
        {
            erreur();
            placer_salle_y(nSalle, donjon->H - (sallesPrecedentes[nSalle - 1]->H + 2));
            scanf("%d", &y);
        }

        ajouter_salle(donjon, sallesPrecedentes[nSalle - 1], x, y);
        clear();
        afficher_salle(donjon);
    }
}