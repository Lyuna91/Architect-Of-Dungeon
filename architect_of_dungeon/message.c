#include <stdlib.h>
#include <stdio.h>
#include "message.h"

/* ESTHETIQUE */

void espacement() // Purement esthétique, permet de créer de l'espacement dans le texte
{
    printf("\n");
}

void d_espacement() // Purement esthétique, permet de créer un double espacement dans le texte
{
    espacement();
    espacement();
}

void logo() // Purement esthétique, permet d'afficher un logo
{
    for (int i = 0; i < 60; i++)
    {
        printf("#");
        printf(" ");
    }
    d_espacement();
    for (int i = 0; i < 50; i++)
    {
        printf(" ");
    }
    printf("ARCHITECT OF DUNGEONS");
    d_espacement();
    for (int i = 0; i < 60; i++)
    {
        printf("#");
        printf(" ");
    }
}

void description() // Petite description de l'application
{
    d_espacement();
    printf("BIENVENUE dans ARCHITECT OF DUNGEONS! \n");
    printf("Nous sommes une application qui va vous permettre de creer votre propre donjon! \n");
    d_espacement();
    printf("Etes-vous pret? (O/N)\n");
    valeur();
}

void lancement() // Nettoie le terminal, affiche le logo puis la description
{
    clear();
    logo();
    description();
}

void erreur() // Message qui informe l'utilisateur d'une erreur de saisie
{
    espacement();
    printf("ATTENTION ! Il y a une ERREUR dans votre SAISIE.\n");
}

void valeur() // Purement esthétique, permet d'indiquer à l'utilisateur quand entrer une donnée
{
    printf("> ");
}

void clear() // Permet de vider le terminal pour qu'il ne soit pas surcharger
{
    system("cls");
}

/* DONJON */

void donjon() // PARTIE : CREATION DE DONJON
{
    printf("*** CREATION DU DONJON ***\n");
    espacement();
}

void dimension_donjon() // SOUS PARTIE : DIMENSION DU DONJON
{
    espacement();
    printf("-> CHOISISSEZ LA DIMENSION DE VOTRE DONJON <-\n");
}

void longueur_donjon() // Demander la longueur du donjon
{
    espacement();
    printf("CHOISISSEZ LA LONGUEUR DE VOTRE DONJON\n");
    printf("La longueur de votre donjon doit se situer entre 25 et 60 \n");
    valeur();
}

void hauteur_donjon() // Demander la hauteur du donjon
{
    espacement();
    printf("CHOISISSEZ LA HAUTEUR DE VOTRE DONJON\n");
    printf("La hauteur de votre donjon doit se situer entre 25 et 60 \n");
    valeur();
}

void entree_sortie() // SOUS PARTIE : ENTREE ET SORTIE
{
    espacement();
    printf("-> CHOISISSEZ LA POSITION DE L'ENTREE ET DE LA SORTIE <-\n");
}

void entree_donjon(int longueur) // Demander la position de l'entrée du donjon
{
    espacement();
    printf("CHOISISSEZ LA POSITION DE L'ENTREE DU DONJON\n");
    printf("Une entree de donjon se situe toujours au NORD du donjon\n");
    printf("Veuillez entrer un nombre entre 3 et %d\n", longueur);
    printf("3 etant une entree a GAUCHE et %d une entree a DROITE\n", longueur);
    valeur();
}

void sortie_donjon(int longueur) // Demander la position de la sortie
{
    espacement();
    printf("CHOISISSEZ LA POSITION DE LA SORTIE DU DONJON\n");
    printf("Une sortie de donjon se situe toujours au SUD du donjon\n");
    printf("Veuillez entrer un nombre entre 3 et %d\n", longueur);
    printf("3 etant une sortie a GAUCHE et %d une entree a DROITE\n", longueur);
    valeur();
}

/* SALLES */

void salle() // PARTIE : CREATION DES SALLES
{
    printf("*** CREATION DES SALLES ***");
    espacement();
}

void nb_salles() // Demander le nombre de salles DIFFERENTES
{
    espacement();
    printf("CHOISISSEZ LE NOMBRE DE SALLES DE VOTRE DONJON\n");
    printf("Veuillez choisir un nombre entre 1 et 10.\n");
    valeur();
}

void dimension_salle(int n_salle) // SOUS PARTIE : DIMENSION DE LA SALLE
{
    espacement();
    printf(" -> CHOISISSEZ LA DIMENSION DE VOTRE SALLE %d <-\n ", n_salle);
}

void longueur_salle(int n_salle) // Demander la longueur de la salle
{
    espacement();
    printf("CHOISISSEZ LA LONGUEUR DE VOTRE SALLE %d \n", n_salle);
    printf("La longueur de votre salle doit etre entre 5 et 15\n");
    valeur();
}

void hauteur_salle(int n_salle) // Demander la hauteur de la salle
{
    espacement();
    printf("CHOISISSEZ LA HAUTEUR DE VOTRE SALLE %d \n", n_salle);
    printf("La hauteur de votre salle doit etre entre 5 et 15\n");
    valeur();
}

void elements() // SOUS PARTIE : CHOIX ET PLACEMENT DES ELEMENTS
{
    espacement();
    printf("-> CHOISISSEZ LES ELEMENTS ET PLACEZ LES <-");
}

void nb_elements(int n_salle, int n_max_element) // Demander le nombre d'element
{
    printf("CHOISISSEZ LE NOMBRE D'ELEMENTS DE VOTRE SALLE %d\n", n_salle);
    printf("Vous pouvez en choisir au maximum %d \n", n_max_element);
    valeur();
}

void type_element(int n_element, int n_salle) // Demander type de l'element
{
    espacement();
    printf("CHOISISSEZ LE TYPE DE L'ELEMENT %d DE VOTRE SALLE %d PARMIS CETTE LISTE\n", n_element, n_salle);
    liste_elements();
    valeur();
}

void liste_elements() // Liste des elements
{
    printf("C : Un coffre\n");
    printf("M : Un monstre\n");
    printf("W : Une depouille\n");
    printf("A : Un autel\n");
    printf("P : Un piege\n");
    printf("B : Un champion\n");
    printf("# : Un mur\n");
}

void position_x_element(int min, int max, int n_element) // Demander la position en X (longueur) de l'élement
{
    espacement();
    printf("CHOISISSEZ LA POSITION X DE VOTRE ELEMENT %d \n", n_element);
    printf("Veuillez choisir un nombre entre %d et %d\n", min, max);
    printf("%d etant a GAUCHE et %d etant a DROITE\n", min, max);
    valeur();
}

void position_y_element(int min, int max, int n_element) // Demander la position en Y (hauteur) de l'élement
{
    espacement();
    printf("CHOISISSEZ LA POSITION Y DE VOTRE ELEMENT %d \n", n_element);
    printf("Veuillez choisir un nombre entre %d et %d\n", min, max);
    printf("%d etant en HAUT et %d etant en BAS\n", min, max);
    valeur();
}

void porte() // SOUS PARTIE : CHOIX DU TYPE ET EMPLACEMENT PORTES
{
    espacement();
    printf("-> CHOISISSEZ LE TYPE DE PORTE ET L'EMPLACEMENT<-");
}

void nb_portes(int n_salle, int n_max_porte) // Demander le nombre de porte
{
    espacement();
    printf("CHOISISSEZ LE NOMBRE DE PORTES DE VOTRE SALLE %d\n", n_salle);
    printf("Vous pouvez en choisir au maximum %d \n", n_max_porte);
    valeur();
}

void type_porte(int n_porte, int n_salle) // Demander le type de porte
{
    espacement();
    printf("CHOISISSEZ LE TYPE DE LA PORTE %d DE VOTRE SALLE %d \n", n_porte, n_salle);
    printf("O : Porte OUVERTE\n");
    printf("F : Porte FERME\n");
    valeur();
}

void direction_porte(int n_porte) // Demander la direction de la porte (exemple: E signifie porte à l'EST donc à DROITE)
{
    espacement();
    printf("CHOISISSEZ LA DIRECTION DE LA PORTE %d \n", n_porte);
    printf("N pour NORD\n");
    printf("S pour SUD\n");
    printf("O pour OUEST\n");
    printf("E pour EST\n");
    valeur();
}

void position_porte_NS(int n_porte, int min, int max) // Demander la position de la porte au NORD et SUD (en longueur)
{
    espacement();
    printf("CHOISISSEZ la POSITION de votre PORTE %d \n", n_porte);
    printf("Veuillez choisir un nombre entre %d et %d \n", min, max);
    printf("%d etant a GAUCHE et %d a DROITE \n", min, max);
    valeur();
}

void position_porte_EO(int n_porte, int min, int max) // Demander la position de la porte EST et OUEST (en hauteur)
{
    espacement();
    printf("CHOISISSEZ la POSITION de votre PORTE %d \n", n_porte);
    printf("Veuillez choisir un nombre entre %d et %d\n", min, max);
    printf("%d etant en HAUT et %d en BAS \n", min, max);
    valeur();
}

void afficher_salles(int nb_salles) // Annonce de l'affichage de la ou les salles
{
    if (nb_salles == 1)
    {
        printf("Voici votre salle terminee. \n");
        espacement();
    }
    else
    {
        printf("Voici vos %d salles terminees ", nb_salles);
        espacement();
    }
}

/* SALLES ET DONJONS */

void placement_salle() // PARTIE : PLACEMENT DES SALLES DANS LE DONJON
{
    printf("*** PLACEMENT DES SALLES DANS LE DONJON ***\n");
    espacement();
}

void choix_salle(int nb_salle) // Demander le numéro de la salle a placer
{
    espacement();
    printf("CHOISISSEZ LA SALLE A PLACER.\n");
    printf("Choisissez un nombre entre 1 et %d pour placer une salle\n", nb_salle);
    printf("Tapez 0 si vous voulez arreter de placer des salle.\n");
    valeur();
}

void position_salle(int n_salle) // SOUS PARTIE : DEMANDER LA POSITION DE LA SALLE
{
    espacement();
    printf("-> VOUS ALLEZ CHOISIR LA POSITION DE VOTRE SALLE %d <-\n", n_salle);
}

void placer_salle_x(int n_salle, int x_max) // Demander la position de la salle en X (longueur)
{
    espacement();
    printf("CHOISISSEZ LA POSITION EN X DE VOTRE SALLE %d\n", n_salle);
    printf("La position en X est defini par rapport au coin superieur gauche de votre salle\n");
    printf("Veuillez choisir un nombre entre 2 et %d\n", x_max);
    printf("2 etant a GAUCHE et %d a DROITE\n", x_max);
    valeur();
}

void placer_salle_y(int n_salle, int y_max) // Demander la position de la salle en Y (hauteur)
{
    espacement();
    printf("CHOISISSEZ LA POSITION EN Y DE VOTRE SALLE %d\n", n_salle);
    printf("La position en Y est defini par rapport au coin superieur gauche de votre salle\n");
    printf("Veuillez choisir un nombre entre 2 et %d\n", y_max);
    printf("2 etant en HAUT GAUCHE et %d en BAS\n", y_max);
    valeur();
}

/* COULOIR */

void couloir() // PARTIE : CREATION DES COULOIRS
{
    espacement();
    printf("*** CREATION DES COULOIRS ***\n");
}

void depart_couloir() // Demander la confirmation pour le depart d'un couloir
{
    espacement();
    printf("VOUS ALLEZ CHOISIR LE DEPART D'UN COULOIR\n");
    printf("Un '!' est apparu sur votre donjon\n");
    printf("Voulez-vous commencer un couloir ici? (O/N)\n");
    valeur();
}

void tracer_couloir() // Demander la direction du couloir
{
    espacement();
    printf("DESSINONS UN COULOIR\n");
    printf("Utilisez les directions NORD, SUD, OUEST et EST pour dessiner votre couloir\n");
    printf("Votre couloir s'arretera quand il aura rencontrer une autre porte.`\n");
    printf("Quel est la direction de votre couloir ? (N/S/E/O)\n");
    valeur();
}

/* DONJON, SALLES et COULOIRS*/

void enregistrement(char *nom) // Demander l'enregistrement dans un fichier.txt
{
    espacement();
    printf("ENREGISTREMENT %s DANS UN FICHIER\n", nom);
    printf("Voulez vous l'enregistrer dans un fichier.txt ? (O/N)\n");
    valeur();
}

void modification() // PARTE : DERNIERES MODIFICATION
{
    espacement();
    printf("*** LES DERNIERES MODIFICATION ***");
    d_espacement();
}

void demande_modification() // Demande si il y a des modification a faire
{
    espacement();
    printf("VOUS POUVEZ EFFECTUER DES MODIFICATIONS\n");
    printf("Voulez-vous effectuer des modification ? (O/N)\n");
    valeur();
}

void modification_position() // SOUS PARTIE : POSITION DE LA MODIFICATION
{
    espacement();
    printf("-> CHOIX POSITION DE LA MODIFICATION <-\n");
}

void modification_pos_x(Salle *s) // Demande position en X
{
    espacement();
    printf("CHOISISSEZ L'EMPLACEMENT X DE VOTRE MODIFICATION\n");
    printf("Choisissez un nombre entre %d et %d\n", 1, s->L);
    valeur();
}

void modification_pos_y(Salle *s) // Demande position en Y
{
    espacement();
    printf("CHOISISSEZ L'EMPLACEMENT Y DE VOTRE MODIFICATION\n");
    printf("Choisissez un nombre entre %d et %d\n", 0, s->H - 1);
    valeur();
}

void validation_position() // Demande validation de la position d ela modification
{
    espacement();
    printf("Etes-vous sure de vouloir placer un element ici? (O/N)\n");
    valeur();
}

void type_modification()
{
    espacement();
    printf("-> CHOISISSEZ LE TYPE DE VOTRE MODIFICATION <-");
}

void liste_elements_portes() // Liste des elements que l'on peux modifier
{
    printf("C : Un coffre\n");
    printf("M : Un monstre\n");
    printf("W : Une depouille\n");
    printf("A : Un autel\n");
    printf("P : Un piege\n");
    printf("B : Un champion\n");
    printf("# : Un mur\n");
    printf("E : Une entree\n");
    printf("S : Une sortie\n");
    printf("O : Une porte ouverte\n");
    printf("F : Une porte fermee\n");
    printf("V : Une case vide\n");
}

void choix_modification() // Demande le type de la modification
{
    espacement();
    printf("Quel element voulez-vous placer ici?\n");
    printf("Choisissez un element a partir de cette liste\n");
    liste_elements_portes();
    printf("- Si vous voulez supprimer un element, tapez V \n");
    valeur();
}

void fin_modification() // Demande la fin des modifications
{
    espacement();
    printf("Avez-vous finis les modifications? (O/N)\n");
    valeur();
}