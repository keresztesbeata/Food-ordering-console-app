//
// Created by q on 11/6/2019.
//

#include "display_menu.h"
#include<stdio.h>

void displayFood(int noFoods, char **foods) {
    printf("Please choose the kind of food you'd like to eat today!\n");
    for (int i = 0; i < noFoods; i++) {
        putchar('a' + i);
        printf(") %s\n", foods[i]);
    }
    putchar('a' + noFoods);
    printf(") Go back\n");
    printf(">");
}

void displayFoodTypes(char *foods, int noTypes, char **types, double *prices) {
    printf("Please choose the type of %s!\n", foods);
    for (int i = 0; i < noTypes; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf\n", types[i], prices[i]);
    }
    putchar('a' + noTypes);
    printf(") Go back\n");
    printf(">");
}
void displayDrinks(char *foods, int noDrinks, char **drinks, double *drinkPrices) {
    printf("Please choose a drink to go with your %s.\n",foods);
    for(int i=0;i<noDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s: %.2lf\n", drinks[i], drinkPrices[i]);
    }
    putchar('a'+noDrinks);
    printf(") No, thanks!\n");
    putchar('a'+noDrinks+1);
    printf(") Go back\n");
    printf(">");
}
void displayCutlery() {
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No, thanks\n");
    printf("c) Go back\n");
    printf(">");
}