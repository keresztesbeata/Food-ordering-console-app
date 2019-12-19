//
// Created by q on 12/17/2019.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "drinks.h"
#include "loading_data.h"
#define MAX_DRINK_NAME 20
drinks createDrink() {
    drinks d;
    d.name=(char*)malloc(MAX_DRINK_NAME*sizeof(char));
    d.price=0.0;
    return d;
}
void loadDrinksData(FILE *file, char *inputLine, int *noDrinks, drinks **ptrDrinksArr) {
    readNoCategory(file,noDrinks);//read nr of drinks
    fgets(inputLine,MAX_LINE,file);
    deleteUnnecessarySpaces(inputLine);
    drinks* drinksArray=(drinks*)malloc((*noDrinks)*sizeof(drinks));
    char **elements=(char**)malloc(MAX_NO_ELEMENTS*sizeof(char*));
    readDrinks(inputLine,"(),",noDrinks,elements,drinksArray);
    *ptrDrinksArr=drinksArray;
    for(int i=0;i<*noDrinks;i++)
        free(elements[i]);
    free(elements);
}
void readDrinks(char *inputLine, char *delim, int *noDrinks, char **elements, drinks *drinksArray) {
    splitLineIntoElements(inputLine, elements, delim,MAX_DRINK_NAME);
    for (int i = 0; i < *noDrinks; i++) {
        drinksArray[i] = createDrink();
        separateTwo(elements[i], drinksArray[i].name, "-");
        drinksArray[i].price = convertToDouble(elements[i]);
    }
}
void displayDrinks(char *foods, int noDrinks, drinks *drinksArr) {
    printf("Please choose a drink to go with your %s.\n",foods);
    for(int i=0;i<noDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s: %.2lf\n", drinksArr[i].name, drinksArr[i].price);
    }
    putchar('a'+noDrinks);
    printf(") No, thanks!\n");
    putchar('a'+noDrinks+1);
    printf(") Go back\n");
    printf(">");
}
void displayOrderDrink(drinks *drink, int drinkChoice) {
    if (drinkChoice>=0) {
        printf("---%s: %.2lf\n", drink->name, drink->price);
    }
}
void freeDrinks(int noDrinks, drinks *drinksArr) {
    for(int i=0;i<noDrinks;i++) {
        free(drinksArr[i].name);
    }
    free(drinksArr);
}
