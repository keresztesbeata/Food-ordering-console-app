//
// Created by q on 11/6/2019.
//

#include "display_menu.h"
#include<stdio.h>

void displayFood(int nrFood,char food[][MAX_FOOD_NAME]) {
    printf("Please choose the kind of food you'd like to eat today!\n");
    for (int i = 0; i < nrFood; i++) {
        putchar('a' + i);
        printf(") %s\n", food[i]);
    }
    putchar('a' + nrFood);
    printf(") Go back\n");
    printf(">");
}


void displayFoodTypes(char foods[MAX_FOOD_NAME],int nrType, char type[][MAX_FOOD_TYPE_NAME],int prices[]) {
    printf("Please choose the type of %s!\n", foods);
    for (int i = 0; i < nrType; i++) {
        putchar('a' + i);
        printf(") %s: %d\n", type[i], prices[i]);
    }
    putchar('a' + nrType);
    printf(") Go back\n");
    printf(">");
}

void displayDrinks(char foods[MAX_FOOD_TYPE_NAME],int nrDrinks,char drink[][MAX_DRINK_NAME],int drinkPrices[])
{
    printf("Please choose a drink to go with your %s.\n",foods);
    for(int i=0;i<nrDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s: %d\n",drink[i],drinkPrices[i]);
    }
    putchar('a'+nrDrinks);
    printf(") No, thanks!\n");
    putchar('a'+nrDrinks+1);
    printf(") Go back\n");
    printf(">");

}
