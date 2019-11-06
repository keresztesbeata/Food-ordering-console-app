//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_MENU_H
#define _ORDERING_FOOD_DISPLAY_MENU_H

#include<stdbool.h>

#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20

void displayFood(int nrFood,char food[][MAX_FOOD_NAME]);
void displayFoodTypes(char foods[MAX_FOOD_NAME],int nrType, char type[][MAX_FOOD_TYPE_NAME], int prices[]);
void displayDrinks(char foods[MAX_FOOD_TYPE_NAME],int nrDrinks,char drink[][MAX_DRINK_NAME],int drinkPrices[]);



#endif //_ORDERING_FOOD_DISPLAY_MENU_H
