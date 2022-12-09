#include "fonctionsSujet1.h"

int main() {
    srand( time( NULL ) );

    logement* tab;

    tab = openCsv();
    logement logementComp = inputlog();
    distance(tab, logementComp);
    randomize(tab);
    quickSort(tab, 0, lenghTab-1);
    Price(tab, logementComp);

    free(tab);
}
