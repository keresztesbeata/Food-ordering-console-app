//
// Created by q on 12/18/2019.
//

#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loading_data.h"
#define MAX_FOOD_TYPE_NAME 30

void freeType(type *types) {
    free(types->name);
}

void readFoodTypes(char *inputLine, char *delim, int noTypes, char **elements, type **typesAddr) {
    type *types=(type*)malloc(noTypes*sizeof(type));
    char **names=(char**)malloc(noTypes*sizeof(char*));
    double *prices=(double*)malloc(noTypes*sizeof(double));
    splitLineIntoElements(inputLine, elements, delim,MAX_FOOD_TYPE_NAME);
    for (int i = 0; i < noTypes; i++) {
        names[i] = (char *) malloc(MAX_FOOD_TYPE_NAME * sizeof(char));
        separateTwo(elements[i], names[i], "-");
        prices[i] = convertToDouble(elements[i]);
    }
    for(int i=0;i<noTypes;i++){
        types[i].name=names[i];
        types[i].price=prices[i];
    }
    for(int i=0;i<noTypes;i++)
        free(names[i]);
    free(names);
    free(prices);
    *typesAddr=types;
}


void displayOrderFood(type *foodType) {
    printf("Food items:\n");
    printf("---%s: %.2lf\n", foodType->name, foodType->price);
}
void displayFoodTypes(char *foods,int noTypes,type *types) {
    printf("Please choose the type of %s!\n", foods);
    for (int i = 0; i <noTypes; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf\n",types[i].name, types[i].price);
    }
    putchar('a' + noTypes);
    printf(") Go back\n");
    printf(">");
}
