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
void displayOrderFood(char food[MAX_FOOD_NAME], int foodPrice) {
    printf("Food items:\n");
    printf("---%s: %d\n", food, foodPrice);
}
void displayOrderDrink(char drink[MAX_DRINK_NAME], int drinkPrice, int drinkChoice) {
    if (drinkChoice>=0) {
        printf("---%s: %d\n", drink, drinkPrice);
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
void calculateTotalAmount(int foodPrice, int drinkPrice, int drinkChoice) {
    int totalPrice=0;
    totalPrice+=foodPrice;
    if(drinkChoice>=0)
        totalPrice+=drinkPrice;
    printf("Payment amount: %d\n", totalPrice);
    printf("------------\n");
}
