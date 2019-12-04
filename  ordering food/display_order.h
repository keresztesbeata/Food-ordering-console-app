//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_ORDER_H
#define _ORDERING_FOOD_DISPLAY_ORDER_H

#define MAX_FOOD_NAME 30
#define MAX_DRINK_NAME 20

void displayOrderCustomerData(char username[]);
void displayOrderFood(char *foods, double foodPrices);
void displayOrderDrink(char *drinks, double drinkPrices, int drinkChoice);
void displayOrderAdditionalItems(int getCutlery, char addInfo[]);
void displayOrderConfirm();
void calculateTotalAmount(double foodPrices, double drinkPrices, int drinkChoice);
void displayOrder(char username[], char *foods, double foodPrices, char *drinks, double drinkPrices, int drinkChoice,int getCutlery, char addInfo[]);
#endif //_ORDERING_FOOD_DISPLAY_ORDER_H
