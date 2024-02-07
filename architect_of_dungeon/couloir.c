#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donjon.h"
#include "message.h"
#include "salle.h"
#include "couloir.h"
#include "constructeur.h"

Couloir *initialiser_couloir(int nb_deplacement, const char *sequence, int hauteur, int longueur) // Fonction qui permet d'initialiser un couloir
{
    Couloir *c = (Couloir *)malloc(sizeof(Couloir));
    c->nb_deplacement = nb_deplacement;
    c->sequence = strdup(sequence);
    c->H = hauteur;
    c->L = longueur;
    c->unCouloir = (char **)malloc(hauteur * sizeof(char *));
    for (int i = 0; i < hauteur; i++)
    {
        c->unCouloir[i] = (char *)malloc(longueur * sizeof(char));
    }
    return c;
}

Couloir *creer_couloir(int nb_deplacement, const char *sequence, int hauteur, int longueur) // Fonction qui permet de creer un couloir
{
    Couloir *c = initialiser_couloir(nb_deplacement, sequence, hauteur, longueur);
    for (int i = 0; i < c->H; i++)
    {
        for (int j = 0; j < c->L; j++)
        {
            c->unCouloir[i][j] = ' ';
        }
    }
    return c;
}

void liberer_couloir(Couloir *c) // Fonction qui permet de liberer un couloir
{
    for (int i = 0; i < c->H; i++)
    {
        free(c->unCouloir[i]);
    }
    free(c->unCouloir);
    free(c->sequence);
    free(c);
}

int calculer_longueur(const char *sequence) // Fonction qui permet de calculer la longueur necessaire au tableau pour contenir le couloir a sauvegarder dans un ficher
{
    int retour;
    int E = 0, O = 0;
    for (int i = 0; i < (int)strlen(sequence); i++)
    {
        if (sequence[i] == 'E')
        {
            E++;
        }
        else if (sequence[i] == 'O')
        {
            O++;
        }
    }
    if (O >= E)
    {
        retour = O + 3;
    }
    else
    {
        retour = E + 3;
    }
    if (retour < 3)
    {
        retour = 3;
    }
    return retour;
}

int calculer_hauteur(const char *sequence) // Fonction qui permet de calculer la hauteur necessaire au tableau pour contenur le couloir a sauvegarder
{
    int N = 0, S = 0;
    int retour = 0;
    for (int i = 0; i < (int)strlen(sequence); i++)
    {
        if (sequence[i] == 'N')
        {
            N++;
        }
        else if (sequence[i] == 'S')
        {
            S++;
        }
    }
    if (N >= S)
    {
        retour = N + 3;
    }
    else
    {
        retour = S + 3;
    }
    if (retour < 3)
    {
        retour = 3;
    }
    return retour;
}

int coordonnee_y(Couloir *c) // Fonction qui calcule le point de depart en Y du couloir qui sera sauvegarder
{
    int i, j;
    for (i = 1; i < c->H - 1; i++)
    {
        for (j = 1; j < c->L - 1; j++)
        {
            int y = i, x = j;
            int k;
            for (k = 0; k < (int)strlen(c->sequence); k++)
            {
                switch (c->sequence[k])
                {
                case 'S':
                    y++;
                    break;
                case 'N':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'O':
                    x--;
                    break;
                }
                if (y < 1 || y >= c->H - 1 || x < 1 || x >= c->L - 1)
                {
                    break;
                }
            }
            if (k == (int)strlen(c->sequence))
            {
                return i;
            }
        }
    }
    return -1;
}

int coordonnee_x(Couloir *c) // Fonction qui calcule le point de depart en X du couloir qui sera sauvegarder
{
    int i, j;
    for (i = 1; i < c->H - 1; i++)
    {
        for (j = 1; j < c->L - 1; j++)
        {
            int y = i, x = j;
            int k;
            for (k = 0; k < (int)strlen(c->sequence); k++)
            {
                switch (c->sequence[k])
                {
                case 'S':
                    y++;
                    break;
                case 'N':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'O':
                    x--;
                    break;
                }
                if (y < 1 || y >= c->H - 1 || x < 1 || x >= c->L - 1)
                {
                    break;
                }
            }
            if (k == (int)strlen(c->sequence))
            {
                return j;
            }
        }
    }
    return -1;
}

void dessiner_chemin(Couloir *c) // Fonction qui dessine le chemin du couloir qui sera sauvegarder
{
    int y = coordonnee_y(c);
    int x = coordonnee_x(c);
    int sauvegarde_y = y;
    int sauvegarde_x = x;
    for (int i = 1; i <= (int)strlen(c->sequence); i++)
    {
        switch (c->sequence[i])
        {
        case 'S':
            y++;
            c->unCouloir[y][x] = 'x';
            break;
        case 'N':
            y--;
            c->unCouloir[y][x] = 'x';
            break;
        case 'E':
            x++;
            c->unCouloir[y][x] = 'x';
            break;
        case 'O':
            x--;
            c->unCouloir[y][x] = 'x';
            break;
        default:
            break;
        }
    }
    c->unCouloir[sauvegarde_y][sauvegarde_x] = '&';
    c->unCouloir[y][x] = '&';
}

void dessiner_couloir(Couloir *c) // Fonction qui dessine le couloir en fonction du chemin.
{
    for (int i = 0; i < c->H; i++)
    {
        for (int j = 0; j < c->L; j++)
        {
            if (c->unCouloir[i][j] == 'x' || (strlen(c->sequence) == 1 && c->unCouloir[i][j] == '&'))
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int new_i = i + dy;
                        int new_j = j + dx;

                        if (new_i >= 0 && new_i < c->H && new_j >= 0 && new_j < c->L &&
                            (c->unCouloir[new_i][new_j] == ' '))
                        {
                            c->unCouloir[new_i][new_j] = '#';
                        }
                    }
                }
            }
        }
    }
}

void enregistrer_couloir(Couloir *c) // Sauvegarder le couloir dans un fichier
{
    char reponse;
    enregistrement("COULOIR");
    scanf(" %c", &reponse);
    if (reponse == 'O')
    {
        FILE *fichier = fopen("couloir.txt", "w");
        afficher_fichier_couloir(fichier, c);
        fclose(fichier);
    }
}

void afficher_fichier_couloir(FILE *fichier, Couloir *c) // Afficher le couloir dans un fichier
{
    fprintf(fichier, "Sequence des deplacements : %s \n", c->sequence);
    fprintf(fichier, "Nombre de deplacement pour le traverver : %d \n", (int)strlen(c->sequence));
    fprintf(fichier, "\n");
    for (int i = 0; i < c->H; i++)
    {
        for (int j = 0; j < c->L; j++)
        {
            fprintf(fichier, "%c ", c->unCouloir[i][j]);
        }
        fprintf(fichier, "\n");
    }
}

void nettoyer_couloir(Couloir *c) // Fonction qui permet de nettoyer le couloir (enlever le chemin et les repères)
{
    for (int i = 0; i < c->H; i++)
    {
        for (int j = 0; j < c->L; j++)
        {
            if (c->unCouloir[i][j] == 'x' || c->unCouloir[i][j] == '&')
            {
                c->unCouloir[i][j] = ' ';
            }
        }
    }
}

void nettoyer_couloir_donjon(Salle *s) // Fonction qui permet de nettoyer les couloirs du donjon (enlever le chemin et les repères)
{
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            if (s->uneSalle[i][j] == 'x')
            {
                s->uneSalle[i][j] = ' ';
            }
        }
    }
}

void afficher_couloir(Couloir *c) // Fonction qui sert à afficher un couloir
{
    espacement();
    for (int i = 0; i < c->H; i++)
    {
        for (int j = 0; j < c->L; j++)
        {
            printf("%c ", c->unCouloir[i][j]);
        }
        printf("\n");
    }
    espacement();
}

void placer_couloir(Salle *s) // Fonction qui trace le couloir sur le donjon en fonction du chemin
{
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            if (s->uneSalle[i][j] == 'x')
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        int new_i = i + dy;
                        int new_j = j + dx;

                        if (new_i >= 0 && new_i < s->H && new_j >= 0 && new_j < s->L &&
                            (s->uneSalle[new_i][new_j] == ' '))
                        {
                            s->uneSalle[new_i][new_j] = '#';
                        }
                    }
                }
            }
        }
    }
}

void creation_couloir(Salle *s) // Fonction qui creer le couloir en temps reel sur le donjon
{
    clear();
    couloir();
    char reponse;
    for (int i = 0; i < s->H; i++)
    {
        for (int j = 0; j < s->L; j++)
        {
            if (s->uneSalle[i][j] == 'E' || s->uneSalle[i][j] == 'S' || s->uneSalle[i][j] == 'O' || s->uneSalle[i][j] == 'F')
            {
                int sauvegarde_i = i;
                int sauvegarde_j = j;
                char porte = s->uneSalle[i][j];
                if (s->uneSalle[i][j] != ' ')
                {
                    s->uneSalle[i][j] = '!';
                }
                afficher_salle(s);
                depart_couloir();
                scanf(" %c", &reponse);
                int terminer = 0;
                s->uneSalle[i][j] = porte;
                char sequence[100] = "";
                if (reponse == 'O')
                {
                    while (terminer != 1)
                    {
                        char direction_couloir;
                        tracer_couloir();
                        scanf(" %c", &direction_couloir);
                        if (direction_couloir == 'N')
                        {
                            if (s->uneSalle[i - 1][j] == '#') // En cas d'erreur de saisie...
                            {
                                erreur();
                            }
                            else
                            {
                                i--;
                                s->uneSalle[i][j] = 'x';
                                strcat(sequence, "N");
                                clear();
                                afficher_salle(s);
                                if (s->uneSalle[i - 1][j] == 'O' || s->uneSalle[i - 1][j] == 'F' || s->uneSalle[i - 1][j] == 'E' || s->uneSalle[i - 1][j] == 'S')
                                {
                                    terminer = 1;
                                }
                            }
                        }
                        else if (direction_couloir == 'S')
                        {
                            if (s->uneSalle[i + 1][j] == '#') // En cas d'erreur de saisie...
                            {
                                erreur();
                            }
                            else
                            {
                                i++;
                                s->uneSalle[i][j] = 'x';
                                strcat(sequence, "S");
                                clear();
                                afficher_salle(s);
                                if (s->uneSalle[i + 1][j] == 'O' || s->uneSalle[i + 1][j] == 'F' || s->uneSalle[i + 1][j] == 'E' || s->uneSalle[i + 1][j] == 'S')
                                {
                                    terminer = 1;
                                }
                            }
                        }
                        else if (direction_couloir == 'E')
                        {
                            if (s->uneSalle[i][j + 1] == '#') // En cas d'erreur de saisie...
                            {
                                erreur();
                            }
                            else
                            {
                                j++;
                                s->uneSalle[i][j] = 'x';
                                strcat(sequence, "E");
                                clear();
                                afficher_salle(s);
                                if (s->uneSalle[i][j + 1] == 'O' || s->uneSalle[i][j + 1] == 'F' || s->uneSalle[i][j + 1] == 'E' || s->uneSalle[i][j + 1] == 'S')
                                {
                                    terminer = 1;
                                }
                            }
                        }
                        else if (direction_couloir == 'O')
                        {
                            if (s->uneSalle[i][j - 1] == '#') // En cas d'erreur de saisie...
                            {
                                erreur();
                            }
                            else
                            {
                                j--;
                                s->uneSalle[i][j] = 'x';
                                clear();
                                strcat(sequence, "O");
                                afficher_salle(s);
                                if (s->uneSalle[i][j - 1] == 'O' || s->uneSalle[i][j - 1] == 'F' || s->uneSalle[i][j - 1] == 'E' || s->uneSalle[i][j - 1] == 'S')
                                {
                                    terminer = 1;
                                }
                            }
                        }
                        else
                        {
                            erreur();
                        }
                    }
                    i = sauvegarde_i;
                    j = sauvegarde_j;
                }
                Couloir *c = creer_couloir((int)strlen(sequence), sequence, calculer_hauteur(sequence), calculer_longueur(sequence));
                dessiner_chemin(c);
                dessiner_couloir(c);
                nettoyer_couloir(c);
                placer_couloir(s);
                nettoyer_couloir_donjon(s);
                if ((int)(strlen(c->sequence) != 0))
                {
                    enregistrer_couloir(c);
                }
                liberer_couloir(c);
            }
        }
    }
}
