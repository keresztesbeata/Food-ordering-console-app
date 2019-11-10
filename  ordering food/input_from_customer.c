//
// Created by q on 11/6/2019.
//

#include "input_from_customer.h"

#include <stdio.h>
#include <stdbool.h>
#include "display_order.h"

void login(char username[], char password[], int *state) {
    printf("Welcome to Noblesse!\n");
    printf("Please sign in to continue!\n");
    printf("->Username:\n>");
    gets(username);
    printf("->Password:\n>");
    gets(password);
    (*state)++;
}

int getChoiceIndex(int nrChoices, int *state) {
    int customerChoice;
    char choice=getchar();
    getchar();
    if(choice=='a'+nrChoices)
        (*state)--;
    else{
        customerChoice=choice-'a';
        (*state)++;
    }
    return customerChoice;
}

int getOptionalChoiceIndex(int nrChoices, int *state) {
    int chosenElement;
    int choice=getchar();
    getchar();
    if(choice=='a'+nrChoices+1)
        (*state)--;
    else {
        if (choice =='a'+nrChoices)
            chosenElement=-1;  //if the customer chose nothing the function returns negative value
        else
            chosenElement=choice - 'a';
        (*state)++;
    }
    return chosenElement;
}

int chooseCutlery (int *state) {
    int wantCutlery;
    int choice=getchar();
    getchar();
    if(choice=='c') {
        (*state)--;
        wantCutlery = -1;
    }
    else {
        if(choice=='b') wantCutlery=0;
        if(choice=='a') wantCutlery=1;
        (*state)++;
    }
    return wantCutlery;
}

void getAdditionalInfo(char addInfo[], int *state) {
    printf("Any additional info?\n>");
    gets(addInfo);
    (*state)++;
}

void placeOrder(bool *confirm, char username[], int *state) {
    displayOrderConfirm();
    int choice=getchar();
    getchar();
    if(choice=='a') {
        printf("You order has been registered. Thank you for buying from us, %s!\n", username);
        *confirm=true;
    }
    else {
        if (choice=='b')
            (*state)-=2;     //it brings us back to the cutlery option
        else
            getchar();
    }
}
