//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_ORDER_H
#define _ORDERING_FOOD_DISPLAY_ORDER_H
#include "input_from_customer.h"
#include "drinks.h"
#include "foods.h"
#define MAX_FOOD_NAME 30
#define MAX_DRINK_NAME 20
void displayOrderCustomerData(char username[]);
void displayOrderAdditionalItems(int getCutlery, char addInfo[]);
void displayOrderConfirm();
void calculateTotalAmount(double foodPrices, double drinkPrice, int drinkChoice);
void displayOrder(customer *c, type *foodType, drinks *drink, int drinkChoice,int cutleryChoice);
#endif //_ORDERING_FOOD_DISPLAY_ORDER_H
