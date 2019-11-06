//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_DISPLAY_ORDER_H
#define _ORDERING_FOOD_DISPLAY_ORDER_H

#define MAX_FOOD_NAME 30
#define MAX_DRINK_NAME 20

void displayOrderCustomerData(char username[]);
void displayOrderFood(char food[MAX_FOOD_NAME],int foodPrice,int *totalPrice);
void displayOrderDrink(char drink[MAX_DRINK_NAME],int drinkPrice,int drinkChoice,int*totalPrice);
void displayOrderAdditionalItems(int getCutlery, char addInfo[],int*totalPrice);

#endif //_ORDERING_FOOD_DISPLAY_ORDER_H