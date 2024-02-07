#include <stdio.h>
#include <stdlib.h>
#include "donjon.h"
#include "salle.h"
#include "couloir.h"
#include "message.h"

Salle *creer_donjon() // Fonction qui permet de créer un donjon. (Un donjon est juste une grande salle, avec une entrée et sortie)
{
    int longueur, hauteur;
    donjon();           // Annonce de la création du donjon
    dimension_donjon(); // Partie dimension donjon
    longueur_donjon();  // Demander la longueur du donjon
    scanf("%d", &longueur);
    while (longueur < 25 || longueur > 60) // En cas d'erreur de saisie...
    {
        erreur();
        longueur_donjon();
        scanf("%d", &longueur);
    }
    hauteur_donjon(); // Demander la hauteur du donjon
    scanf("%d", &hauteur);
    while (hauteur < 25 || hauteur > 60) // En cas d'erreur de saisie...
    {
        erreur();
        hauteur_donjon();
        scanf("%d", &hauteur);
    }
    Salle *d = creer_salle(hauteur, longueur, 0);
    clear();
    afficher_salle(d);
    return d;
}

void placer_entrer(Salle *s) // Fonction qui permet de placer une entrée 'E' au NORD.
{
    int entree;
    entree_donjon(s->L - 4); // Pour empêcher que l'entrée soit coller aux murs verticaux (esthétisme)
    scanf("%d", &entree);
    while (entree < 3 || entree > s->L - 4) // En cas d'erreur de saisie...
    {
        erreur();
        entree_donjon(s->L - 4);
        scanf("%d", &entree);
    }
    ajouter_porte(s, 'E', entree, 0);
    clear();
    afficher_salle(s);
}

void placer_sortie(Salle *s) // Fonction qui permet de placer une sortie 'S' au SUD
{
    int sortie;
    sortie_donjon(s->L - 4); // Pour empêcher que la sortie soit coller aux murs verticaux (esthétisme)
    scanf("%d", &sortie);
    while (sortie < 3 || sortie > s->L - 4) // En cas d'erreur de saisie...
    {
        erreur();
        sortie_donjon(s->L - 4);
        scanf("%d", &sortie);
    }
    ajouter_porte(s, 'S', sortie, s->H - 1);
    afficher_salle(s);
}

Salle *creation_donjon() // Fonction qui permet de créer un donjon avec une entrée et sortie
{
    Salle *donjon = creer_donjon();
    placer_entrer(donjon);
    placer_sortie(donjon);
    clear();
    afficher_salle(donjon);
    return donjon;
}

void afficher_fichier_donjon(FILE *fichier, Salle *s) // Afficher le donjon dans le fichier.txt
{
    fprintf(fichier, "Un donjon de dimension %d sur %d \n", s->L, s->H);
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            fprintf(fichier, "%c ", s->uneSalle[i][j]);
        }
        fprintf(fichier, "\n");
    }
}

void enregister_donjon(Salle *s) // Fonction qui permet l'enregistrement dans un fichier.txt
{
    char reponse;
    enregistrement("DONJON");
    scanf(" %c", &reponse);
    if (reponse == 'O')
    {
        FILE *fichier = fopen("donjon.txt", "w");
        afficher_fichier_donjon(fichier, s);
        fclose(fichier);
    }
}

void modifier_donjon(Salle *s)
{
    clear();
    afficher_salle(s);
    char reponse;
    printf("Voulez-vous effectuer des modifications ? (O/N): ");
    scanf(" %c", &reponse);
    if (reponse == 'O')
    {
        char fin = 'N';
        while (fin == 'N')
        {
            int x, y;
            clear();
            afficher_salle(s);
            modification_position();
            modification_pos_x(s);
            scanf("%d", &x);
            while (x < 0 || x > s->L - 1)
            {
                erreur();
                modification_pos_x(s);
                scanf("%d", &x);
            }
            modification_pos_y(s);
            scanf("%d", &y);
            while (y < 0 || y > s->H - 1)
            {
                erreur();
                modification_pos_y(s);
                scanf("%d", &y);
            }

            char sauvegarde = s->uneSalle[y][x];
            char validation;
            s->uneSalle[y][x] = '!';
            clear();
            afficher_salle(s);
            validation_position();
            scanf(" %c", &validation);

            if (validation == 'O')
            {
                char modification;
                type_modification();
                choix_modification();
                scanf(" %c", &modification);
                if (modification == 'V')
                {
                    s->uneSalle[y][x] = ' ';
                }
                else
                {
                    Element element = (Element)modification;
                    while (element != COFFRE && element != MONSTRE && element != DEPOUILLE &&
                           element != AUTEL && element != PIEGE && element != CHAMPION &&
                           element != MUR && element != ENTREE && element != SORTIE &&
                           element != PORTEF)
                    {
                        erreur();
                        choix_modification();
                        scanf(" %c", &modification);
                        element = (Element)modification;
                    }
                    s->uneSalle[y][x] = element;
                }
                clear();
                afficher_salle(s);
            }
            else
            {
                s->uneSalle[y][x] = sauvegarde;
            }
            fin_modification();
            scanf(" %c", &fin);
        }
    }
}
