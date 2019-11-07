//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_ORDER_H
#define _ORDERING_FOOD_DISPLAY_ORDER_H

#define MAX_FOOD_NAME 30
#define MAX_DRINK_NAME 20

void displayOrderCustomerData(char username[]);
void displayOrderFood(char food[MAX_FOOD_NAME], int foodPrice);
void displayOrderDrink(char drink[MAX_DRINK_NAME], int drinkPrice, int drinkChoice);
void displayOrderAdditionalItems(int getCutlery, char addInfo[]);
void displayOrderConfirm();
void calculateTotalAmount(int foodPrice, int drinkPrice, int drinkChoice);
void displayOrder(char username[], char food[MAX_FOOD_NAME], int foodPrice, char drink[MAX_DRINK_NAME], int drinkPrice, int drinkChoice,int getCutlery, char addInfo[]);
#endif //_ORDERING_FOOD_DISPLAY_ORDER_H
