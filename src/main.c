#include "fonctionsSujet1.h"

int main() {
    srand( time( NULL ) );
    int choix;
    char n[256] = "";

    printf("Veuillez choisir : \n ");
    printf(" 1 - Airbnb \n  2 - Ordonnanceur\n");
    scanf("%s", n);
    choix = saisieEntier(n);
    logement* tab;

    switch(choix){
        case 1:
            tab = openCsv();
            logement logementComp = inputlog();
            distance(tab, logementComp);
            randomize(tab);
            quickSort(tab, 0, lenghTab-1);
            Price(tab);

            free(tab);
            break;
        case 2:
            printf("choix nbr two");
            break; 
        default :
            printf("saisie incorrecte.\n");
            break;
    }


}