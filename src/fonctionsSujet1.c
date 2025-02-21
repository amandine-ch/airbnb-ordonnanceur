#include "fonctionsSujet1.h"

//Ouvre le fichier csv et rempli le tableau de structure correspondant
logement * openCsv(){
  // logement tabLogement[lenghTab];
  logement * tabLogement = (logement*) malloc(lenghTab*sizeof(logement));

	// Declaration des variables
	FILE* file;
	char* line;
    char* buff;
    char** bp;
    size_t len;
    size_t nbCharligne;
    char* strToken;
    int n;

  	//ouverture the csv
	file = fopen("data/airbnb_donnees_propre.csv", "r");
	if (file==NULL){
		printf("Ouverture fichier impossible !\n");
		exit(0);
	}

	//Lecture du fichier csv
  	nbCharligne = getline(&line, &len, file);
  	if(nbCharligne != -1){
    	while((nbCharligne = getline(&line, &len, file)) != -1){
            
      		buff = strdup(line);

        	if(buff == NULL){
          		printf("ERROR BUFF\n");
          		exit(0);
        	}
    		bp = &buff;

        	strsep(bp,",");
          // complete the array of structures with data

        	strToken=strsep(bp,",");
        	tabLogement[n].accomodate=strtof(strToken,NULL);

        	strToken=strsep(bp,",");
            tabLogement[n].bedroom=strtof(strToken,NULL);

            strToken=strsep(bp,",");
            tabLogement[n].bathroom=strtof(strToken,NULL);

            strToken=strsep(bp,",");
            tabLogement[n].bed=strtof(strToken,NULL);

            strToken=strsep(bp,",");
            float pricetest = strtof(strToken, NULL);
            tabLogement[n].price = pricetest;

            strToken=strsep(bp,",");
            tabLogement[n].min_night=strtof(strToken,NULL);

            strToken=strsep(bp,",");
            tabLogement[n].max_night=strtof(strToken,NULL);

            strToken=strsep(bp,",");
            tabLogement[n].reviews=strtof(strToken,NULL);

            n++;
        }
    }

    fclose(file);
    return tabLogement;
}

void emptyBuff(){
  int c =0;
  while(c != '\n'){
    c = getchar();
  }
}

//check if the char sent is an int or no
int saisieEntier(char * n){
    int length,i, num; 
    char input[10];

    length = strlen (n);
    if (n[length -1 ] != '\n'){
          emptyBuff();
          printf("saisie incorrecte \n");
          printf("Veuillez saisir une nouvelle valeur : \n");
          fgets(input, 10, stdin);
          saisieEntier(input);
        }
        
    for (i = 0 ; i < length-1 ; i++){
        if (!isdigit(n[i]) || length > 10){
          printf("saisie incorrecte : valeur entrée n'est pas un entier\n");
          printf("Veuillez saisir une nouvelle valeur : \n");
          fgets(input, 10, stdin);
          saisieEntier(input);
        }
        
    }
    num = atoi(n);
    
    return num;
}

// create logement x we have to compare
// ask user to complete the informations of logement x and verify if the input is correct
logement inputlog(){
        logement logementx;
        char n[10];

        printf("\n\nVeuillez entrer les informations du bien a évaluer: \n");
        printf("nombre de personnes logées :\n");
        fgets(n, 10, stdin);
        logementx.accomodate = saisieEntier(n);

        printf("nombre de chambres :\n");
        fgets(n, 10, stdin);
        logementx.bedroom = saisieEntier(n);

        printf("nombre de salle de bain :\n");
        fgets(n, 10, stdin);
        logementx.bathroom = saisieEntier(n);

        printf("nombre de lits :\n");
        fgets(n, 10, stdin);
        logementx.bed = saisieEntier(n);

        logementx.price = -1;

        printf("nombre minimum de nuits:\n");
        fgets(n, 10, stdin);
        logementx.min_night = saisieEntier(n);

        printf("nombre maximum de nuits :\n");
        fgets(n, 10, stdin);
        logementx.max_night = saisieEntier(n);

        logementx.reviews = -1;
        
        logementx.distance = -1;
        
        return logementx;
}

//verify if the choosen attribute is not already in tabAttr
int  verifdouble (int * tabAttr, int i){
  for(int t = 0; t < i; t++){
    if(tabAttr[i] == tabAttr[t]){
      return 1;
    }
    
  }
  return 0;
}

// create the array containing the number representative of the attributes
int * createTabAttr(int nbAttr){
  int * tabAttr = (int*) malloc(nbAttr * sizeof(int));
  char n[10];
  int numAttr;

  //if we ask for 6 attributes we won't need to ask which ones exactly
  if (nbAttr == 6) {
    for(int i = 0; i < 6; i++){
      tabAttr[i] = i + 1;
    }
  }
	// print the possible attributes
	// ask the user to enter the number corresponding to the attribute
	// verify this number then put it in the array tabAttr
  else {
    printf("\n1 - Loge\n2 - chambre\n3 - salle de bain\n4 - lit\n5 - nombre de nuits minimums\n6 - nombre de nuits maximum\n");
    printf("Veuillez indiquer les éléments a comparer : \n\n");
    for (int i = 0; i < nbAttr; i++){
      printf("attribut n° %d : \n", i+1);
      fgets(n, 10, stdin);
      numAttr = saisieEntier(n);

      while (numAttr > 6 || verifdouble(tabAttr, i)){
        printf("Erreur !\n Valeur entrée supérieure au nombre d'attributs ou a déja été entrée.\nVeuillez en entrer un nouveau : \n");
        fgets(n, 10, stdin);
        numAttr = saisieEntier(n);
      }
      tabAttr[i] = numAttr;
    }
  }

  return tabAttr;
}

// calcul de la distance
// for each attributes contained in tabAttr enter the switch case
// sum everything together for each attributes than sqrt the total to get the result
float calcDist (int * tabAttr, int nbAttr, logement positionI, logement logementTest){
  float sum = 0;
  float x;
  for (int i = 0; i < nbAttr; i++){
    switch (tabAttr[i]){
      case 1:
         x = (logementTest.accomodate - positionI.accomodate);
        sum += x*x;
        break;

      case 2:
         x = (logementTest.bedroom - positionI.bedroom);
        sum += x*x;
        break;

      case 3:
         x = (logementTest.bathroom - positionI.bathroom);
        sum += x*x;
        break;

      case 4:
         x = (logementTest.bed - positionI.bed);
        sum += x*x;
        break; 

      case 5:
         x = (logementTest.min_night - positionI.min_night);
        sum += x*x;
        break;

      case 6:
         x = (logementTest.max_night - positionI.max_night);
        sum += x*x;
        break;

      default:
        printf("erreur dans le numero d'attributs");
        exit(0);
        break;
    }
  }
  return sqrtf(sum);
}

// function which permit to choose how many attributes we want to compare and call necessary function.
void distance (logement * tab, logement  logementTest){
  int nbAttr;
  char n[10];

  printf("\nVeuillez entre le nombre d'attributs que vous voulez comparer (6 maximum) : \n");
  fgets(n, 10, stdin);
  nbAttr = saisieEntier(n);

  // verify if the user ask for more attributes than the ones existing
  while (nbAttr > 6 ){
    printf("Erreur !\n Valeur entrée supérieure au nombre d'attributs, veuillez en entrer un nouveau : \n");
    fgets(n, 10, stdin);
    nbAttr = saisieEntier(n);
  }

  int * tabAttr = createTabAttr(nbAttr);

  // calculation of the distance for each housing from the data and the logement x
  for (int i = 0; i < lenghTab; i++){
    tab[i].distance = calcDist(tabAttr, nbAttr, tab[i], logementTest);
  }
}

// swap randomly elements of the array 
void randomize (logement * tableau){
    int j = 0;

    for (int i = 0; i < lenghTab; i++){
        j = i + rand()/(RAND_MAX/(lenghTab-i)+1);
        logement tmp = tableau[j];
        tableau[j] = tableau[i];
        tableau[i] = tmp;
    }
}

// function to swap element of the array during the quicksort
void swap(logement *a, logement *b) {
  logement t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(logement * tab, int left, int right) {
  // select the rightmost element as pivot
  int pivot = tab[right].distance;
  int i = (left - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = left; j < right; j++) {
    if (tab[j].distance <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      swap(&tab[i], &tab[j]);
    }
  }
  swap(&tab[i + 1], &tab[right]);
  return (i + 1);
}

void quickSort(logement * tab, int left, int right) {
  if (left < right) {
    int piv = partition(tab, left, right);
    quickSort(tab, left, piv - 1);
    quickSort(tab, piv + 1, right);
  }
}

// allows to know how many accomodations the user want to compare 
int nbLogement (){
    int nbcomp = 0;
    char n[10];

    printf("\nveuillez entrer le nombre de logement(s) a comparer pour trouver le prix:\n");
    fgets(n, 10, stdin);
    nbcomp = saisieEntier(n);
    return nbcomp;
}

// calculation of the price
// sum the price of each lodging from 0 to nbComp in tab then return the average
float priceCalculation (logement * tab, int nbComp){
    float price = 0;

    for (int i = 0; i < nbComp; i++){
        price += tab[i].price;
    }
    return price/nbComp;
}

// display the lodging the user want to compare
void displayArray (logement logementComp) {
  printf("-------------------------------------------------\n\nPour un bien avec ces informations :\n");
  printf("capacité de logement : %d\n", logementComp.accomodate);
  printf("chambres : %d \n", logementComp.bedroom);
  printf("salle de bain : %d \n", logementComp.bathroom);
  printf("lits : %d \n", logementComp.bed);
  printf("nombre minimum de nuits : %d \n", logementComp.min_night);
  printf("nombre maximum de nuits : %d \n\n", logementComp.max_night);
}

//call the necessary functions to get the price.
void Price (logement * tab, logement  logementComp){
    int nbcomp = nbLogement ();
    float price = priceCalculation (tab, nbcomp);
    displayArray(logementComp);
    printf("le prix prédit est de : %f €\n", price);
}


