//
// Created by q on 12/18/2019.
//

#include "foods.h"
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include "loading_data.h"
#define MAX_FOOD_TYPE_NAME 30

food createFood() {
    food f;
    f.name=(char*)malloc(MAX_FOOD_NAME*sizeof(char));
    f.types=NULL;
}

void freeFoods(int noFoods, food * foods) {
    for(int i=0;i<noFoods;i++) {
        for (int j = 0; j < foods[i].noTypes; j++) {
            freeType(&(foods[i].types[j]));
        }
        free(foods[i].types);
        free(foods[i].name);
    }
    free(foods);
}

void readFood(char * inputLine, char **ptrFoods,int *ptrNoTypes) {
    char *foods=(char*)malloc(MAX_FOOD_NAME*sizeof(char));
    char *string=(char*)malloc(10*sizeof(char));
    separateTwo(inputLine,string,":");
    sscanf(string,"%s %d",foods,ptrNoTypes);
    free(string);
    *ptrFoods=foods;
    free(foods);
}
void loadFoodsData(FILE *file, char *inputLine, int *noFoods, food **foodsAddr) {
    food*foods=(food*)malloc(*noFoods*sizeof(food));
    readNoCategory(file, noFoods);
    char **elements=(char**)malloc(MAX_NO_ELEMENTS*sizeof(char*));
    for(int i=0;i<*noFoods;i++) {
        fgets(inputLine,MAX_LINE,file);
        deleteUnnecessarySpaces(inputLine);
        foods[i]=createFood();
        readFood(inputLine,&(foods[i].name),&(foods[i].noTypes));
        readFoodTypes(inputLine,"()",foods[i].noTypes,elements,&(foods[i].types));
    }
    *foodsAddr=foods;
    free(elements);
}
void displayFood(int noFoods, food *foods) {
    printf("Please choose the kind of food you'd like to eat today!\n");
    for (int i = 0; i < noFoods; i++) {
        putchar('a' + i);
        printf(") %s\n", foods[i].name);
    }
    putchar('a' + noFoods);
    printf(") Go back\n");
    printf(">");
}