//
// Created by q on 11/6/2019.
//

#include "display_order.h"
#include<stdio.h>
#include<string.h>

#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20

void displayOrderCustomerData(char username[]) {
    printf("This is your order:\n");
    printf("------------\n");
    printf("Name: %s\n", username);
}
void displayOrderFood(char *foods, double foodPrices) {
    printf("Food items:\n");
    printf("---%s: %.2lf\n", foods, foodPrices);
}
void displayOrderDrink(char *drinks, double drinkPrices, int drinkChoice) {
    if (drinkChoice>=0) {
        printf("---%s: %.2lf\n", drinks, drinkPrices);
    }
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
void calculateTotalAmount(double foodPrices, double drinkPrices, int drinkChoice) {
    double totalPrice=0;
    totalPrice+=foodPrices;
    if(drinkChoice>=0)
        totalPrice+=drinkPrices;
    printf("Payment amount: %.2lf\n", totalPrice);
    printf("------------\n");
}
void displayOrder(char username[], char *foods, double foodPrices, char *drinks, double drinkPrices, int drinkChoice,int getCutlery, char addInfo[]) {
    displayOrderCustomerData(username);
    displayOrderFood(foods, foodPrices);
    displayOrderDrink(drinks, drinkPrices, drinkChoice);
    displayOrderAdditionalItems(getCutlery, addInfo);
    calculateTotalAmount(foodPrices, drinkPrices, drinkChoice);
}