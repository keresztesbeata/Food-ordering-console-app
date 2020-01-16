//
// Created by q on 12/18/2019.
//

#ifndef _ORDERING_FOOD_TYPES_H
#define _ORDERING_FOOD_TYPES_H
#include <stdio.h>
typedef struct _type {
char *name;
double price;
}type;

void freeType(type *types);
void readFoodTypes(char *inputLine, char *delim, int noTypes, char **elements, type **typeAddr);
void displayOrderFood(type *types);
void displayFoodTypes(char *foods,int noTypes,type *types);
#endif //_ORDERING_FOOD_TYPES_H
