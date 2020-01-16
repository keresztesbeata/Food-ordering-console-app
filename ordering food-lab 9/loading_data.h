//
// Created by q on 11/27/2019.
//

#ifndef _ORDERING_FOOD_LOADING_DATA_H
#define _ORDERING_FOOD_LOADING_DATA_H

#endif //_ORDERING_FOOD_LOADING_DATA_H
#include<stdio.h>
#include "drinks.h"
#include "foods.h"
#include "types.h"

#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20
#define MAX_PRICE 50
#define MAX_NO_ELEMENTS 20
#define MAX_LINE 100
#define LOAD_DATA "Please load the data"
//loading data
void loadData(FILE *file, int *ptrNoFoods, food **foodsAddr, int *ptrNoDrinks, drinks **drinksAddr);
void readNoCategory(FILE* file, int *noCategories);
//process strings functions
void separateTwo(char * line, char * type, char *delim);
void splitLineIntoElements(char *line, char **elements, char *delim, int MAX_NAME);
double convertToDouble(char *string);
void deleteUnnecessarySpaces (char * string);
