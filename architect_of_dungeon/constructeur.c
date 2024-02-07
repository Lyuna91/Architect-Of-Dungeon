#include <stdio.h>
#include <stdlib.h>
#include "constructeur.h"
#include "salle.h"
#include "donjon.h"
#include "message.h"
#include "couloir.h"

void constructeur()
{
    char reponse;
    lancement();
    scanf(" %c", &reponse);
    if (reponse == 'O')
    {
        clear();
        Salle *donjon = creation_donjon();
        int nbSalles;
        nb_salles();
        scanf("%d", &nbSalles);
        while (nbSalles < 1 || nbSalles > 10)
        {
            erreur();
            nb_salles();
            scanf("%d", &nbSalles);
        }
        Salle *sallesPrecedentes[nbSalles];
        clear();
        for (int i = 0; i < nbSalles; i++)
        {
            Salle *s1 = creation_salle(i + 1);
            sallesPrecedentes[i] = s1;
        }
        clear();
        placement_salle();
        afficher_salle(donjon);
        placer_salles(donjon, sallesPrecedentes, nbSalles);
        afficher_salle(donjon);
        creation_couloir(donjon);
        modifier_donjon(donjon);
        enregister_donjon(donjon);
        clear();
        printf("Merci d'avoir utilise notre application !");
        liberer_salle(donjon);
        liberer_salles(sallesPrecedentes, nbSalles);
    }
    else
    {
        clear();
        printf(":[\n");
    }
}
