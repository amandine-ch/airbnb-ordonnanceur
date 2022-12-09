#ifndef FONCTIONSSUJET1_H
#define FONCTIONSSUJET1_H

// Including necessary libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define lenghTab 7917

typedef struct logement logement;
struct logement{
    int accomodate;
    float bedroom;
    float bathroom;
    float bed;
    float price;
    int min_night;
    int max_night;
    int reviews;
    float distance;
};

logement * openCsv();
int saisieEntier(char * n);
logement inputlog();
void distance(logement * tab, logement logementTest);
void randomize (logement * tableau);
void swap(logement *a, logement *b);
int partition(logement * tab, int left, int right);
void quickSort(logement * tab, int left, int right);
int nbLogement ();
float priceCalculation (logement * tab, int nbComp);
void Price (logement * tab, logement logementComp);

#endif
