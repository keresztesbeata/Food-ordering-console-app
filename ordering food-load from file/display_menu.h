//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_MENU_H
#define _ORDERING_FOOD_DISPLAY_MENU_H

#include<stdbool.h>

#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20

void displayFood(int noFoods, char **foods);
void displayFoodTypes(char *foods, int noTypes, char **types, double *prices);
void displayDrinks(char *foods, int noDrinks, char **drinks, double *drinkPrices);
void displayCutlery();

#endif //_ORDERING_FOOD_DISPLAY_MENU_H
