//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_INPUT_FROM_CUSTOMER_H
#define _ORDERING_FOOD_INPUT_FROM_CUSTOMER_H

#include <stdbool.h>

void login(char username[], char password[], int *state);
int getChoiceIndex(int nrChoices, int *state);
int getOptionalChoiceIndex(int nrChoices, int *state);
int chooseCutlery(int *state);
void getAdditionalInfo(char addInfo[], int *state);
void placeOrder(bool *confirm, char username[], int *state);

#endif //_ORDERING_FOOD_INPUT_FROM_CUSTOMER_H
