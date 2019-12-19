//
// Created by q on 12/17/2019.
//

#ifndef _ORDERING_FOOD_DRINKS_H
#define _ORDERING_FOOD_DRINKS_H
typedef struct _drinks{
    char *name;
    double price;
}drinks;
drinks createDrink();
void readDrinks(char *inputLine, char *delim, int *noDrinks, char **elements, drinks *drinksArray);
void loadDrinksData(FILE *file, char *inputLine, int *noDrinks, drinks **ptrDrinksArr);
void displayDrinks(char *foods, int noDrinks, drinks *drinksArr);
void displayOrderDrink(drinks *drink, int drinkChoice);
void freeDrinks(int noDrinks, drinks *drinksArr);
#endif //_ORDERING_FOOD_DRINKS_H
