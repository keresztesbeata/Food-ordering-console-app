//
// Created by q on 12/1/2019.
//

#include "loading_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//allocating memory must be done inside the function, because the size is not known
void allocateMemoryFoods(int *noFoods, int **ptrNoTypes, char ***ptrFoods, char ****ptrFoodTypes, double ***ptrFoodPrices) {
    *ptrFoods=(char **)malloc(*noFoods*sizeof(char*));
    *ptrNoTypes=(int *)malloc(*noFoods*sizeof(int));
    *ptrFoodTypes=(char ***)malloc(*noFoods*sizeof(char **));
    *ptrFoodPrices=(double**)malloc(*noFoods*sizeof(double*));
}
void allocateMemoryDrinks(int *noDrinks, char ***ptrDrinks, double **ptrDrinkPrices) {
    *ptrDrinks=(char **)malloc(*noDrinks*sizeof(char*));
    *ptrDrinkPrices=(double*)malloc(*noDrinks*sizeof(double));
}
void loadData(int *ptrNoFoods,char ***ptrFoods,int **ptrNoFoodTypes,char ****ptrFoodTypes,double ***ptrFoodPrices,int *ptrNoDrinks,char ***ptrDrinks,double **ptrDrinkPrices,int *state) {
    char *inputLine=(char*)malloc(MAX_LINE*sizeof(char));
    loadFoodsData(inputLine,ptrNoFoods,ptrFoods,ptrNoFoodTypes,ptrFoodTypes,ptrFoodPrices);
    loadDrinksData(inputLine,ptrNoDrinks,ptrDrinks,ptrDrinkPrices);
    (*state)++;
}
void loadFoodsData(char *inputLine, int *noFoods, char ***ptrFoods, int **ptrNoTypes, char ****ptrFoodTypes, double ***ptrFoodPrices) {
    readNoCategory(noFoods);//ptrNoFood
    char **foods;
    char ***foodTypes;
    double **foodPrices;
    int *noTypes;
    allocateMemoryFoods(noFoods,&noTypes,&foods,&foodTypes,&foodPrices);
    char **elements=(char**)malloc(MAX_NO_ELEMENTS*sizeof(char*));
    for(int i=0;i<*noFoods;i++) {
        gets(inputLine);
        deleteUnnecessarySpaces(inputLine);
        readFoodType(inputLine,&foods[i],&noTypes[i]);
        processDataLine(inputLine,"()",&noTypes[i],elements,&foodTypes[i],&foodPrices[i],MAX_FOOD_TYPE_NAME);
    }
    *ptrFoods=foods;
    *ptrNoTypes=noTypes;
    *ptrFoodTypes=foodTypes;
    *ptrFoodPrices=foodPrices;
}

void loadDrinksData(char *inputLine, int *noDrinks, char ***ptrDrinks, double **ptrDrinkPrices) {
    readNoCategory(noDrinks);
    gets(inputLine);
    deleteUnnecessarySpaces(inputLine);
    char **drinks;
    double *drinkPrices;
    allocateMemoryDrinks(noDrinks,&drinks,&drinkPrices);
    char **elements=(char**)malloc(MAX_NO_ELEMENTS*sizeof(char*));
    processDataLine(inputLine,"(),",noDrinks,elements,&drinks,&drinkPrices,MAX_DRINK_NAME);
    *ptrDrinks=drinks;
    *ptrDrinkPrices=drinkPrices;
}
void readNoCategory(int *noCategories) {
    scanf("%d %*c",noCategories);
    getchar();//new line
}
//process data
void processDataLine(char *inputLine, char *delim, int *noTypes, char **elements, char ***ptrTypes, double **ptrPrices, int MAX_NAME) {
    char **types=(char**)malloc(*noTypes*sizeof(char*));
    double *prices=(double*)malloc(*noTypes*sizeof(double));
    splitLineIntoElements(inputLine, elements, delim,MAX_NAME);
    for (int i = 0; i < *noTypes; i++) {
        types[i] = (char *) malloc(MAX_NAME * sizeof(char));
        separateTwo(elements[i], types[i], "-");
        prices[i] = convertToDouble(elements[i]);
    }
    *ptrTypes=types;
    *ptrPrices=prices;
}

void readFoodType(char * inputLine, char **ptrFoods, int *noTypes) {
    char *foods=(char*)malloc(MAX_FOOD_NAME*sizeof(char));
    char *noString=(char*)malloc(6*sizeof(char));
    separateTwo(inputLine,noString,":");
    separateTwo(noString,foods," ");
    char *endPtr;
    *noTypes=strtol(noString,&endPtr,10);
    *ptrFoods=foods;
}

void separateTwo(char * line, char * type, char *delim) {
    char *ptr;
    ptr = strtok(line, delim);
    strcpy(type, ptr);
    ptr = strtok(NULL, delim);
    strcpy(line, ptr);
}

void splitLineIntoElements(char *line, char **elements, char *delim, int MAX_NAME) {
    char *ptr;
    int i=0;
    ptr=strtok(line,delim);
    while(ptr) {
        elements[i]=(char *)malloc((MAX_NAME+MAX_PRICE)*sizeof(char));
        strcpy(elements[i],ptr);
        ptr=strtok(NULL,delim);
        i++;
    }
}

double convertToDouble(char *string) {
    char *endPtr;
    return strtod(string,&endPtr);
}

void deleteUnnecessarySpaces (char * string) {
    int n=strlen(string);
    for(int i=0;i<n;i++) {
        if (string[i] == ' ')
            if (string[i-1]==':'||(string[i - 1] == ')' && string[i + 1] == '(' )|| (string[i - 1] == '-' || string[i + 1] == '-')||(string[i-1]==','&&string[i+1]=='('))
            {strcpy(string+i,string+i+1);
                n--;
            }
    }
}

void freeMemory(int noFood, int *noTypes, char **foods, char ***foodTypes, double ** foodPrices, int noDrinks, char **drinks, double *drinkPrices) {
//free memory
    for(int i=0;i<noFood;i++) {
        for(int j=0;j<noTypes[i];j++) {
            free(foodTypes[i][j]);
            free(foods[i]);
        }
        free(foodTypes[i]);
        free(foodPrices[i]);
    }
    free(foods);
    free(foodTypes);
    free(foodPrices);
    free(noTypes);
    for(int i=0;i<noDrinks;i++)
        free(drinks[i]);
    free(drinks);
}