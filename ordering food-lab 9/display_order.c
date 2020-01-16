//
// Created by q on 11/6/2019.
//

#include "display_order.h"
#include<stdio.h>
#include<string.h>
#include "drinks.h"
#include "foods.h"

#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20

void displayOrderCustomerData(char username[]) {
    printf("This is your order:\n");
    printf("------------\n");
    printf("Name: %s\n", username);
}
void displayOrderAdditionalItems(int getCutlery, char addInfo[]) {
    printf("Cutlery: ");
    if (getCutlery) printf("yes\n");
    else printf("no\n");
    if (strlen(addInfo)!=0)
        printf("Additional info: %s\n", addInfo); //if there's no additional info it won't print anything
}
void displayOrderConfirm() {
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    printf(">");
}
void calculateTotalAmount(double foodPrice, double drinkPrice, int drinkChoice) {
    double totalPrice=0;
    totalPrice+=foodPrice;
    if(drinkChoice>=0)
        totalPrice+=drinkPrice;
    printf("Payment amount: %.2lf\n", totalPrice);
    printf("------------\n");
}
void displayOrder(customer *c, type* foodType, drinks *drink, int drinkChoice,int cutleryChoice) {
    displayOrderCustomerData(c->username);
    displayOrderFood(foodType);
    displayOrderDrink(drink, drinkChoice);
    displayOrderAdditionalItems(cutleryChoice, c->addInfo);
    calculateTotalAmount(foodType->price, drink->price, drinkChoice);
}