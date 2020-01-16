//
// Created by q on 12/18/2019.
//

#ifndef _ORDERING_FOOD_FOODS_H
#define _ORDERING_FOOD_FOODS_H
#include "types.h"
#include <stdio.h>

typedef struct _food {
    char *name;
    int noTypes;
    type *types;
}food;

void freeFoods(int noFoods, food *foods);
void loadFoodsData(FILE *file, char *inputLine, int *noFoods, food **foodsAddr);
void readFood(char * inputLine, char **ptrFoods,int *ptrNoTypes);
void displayFood(int noFoods, food *foods);

#endif //_ORDERING_FOOD_FOODS_H
