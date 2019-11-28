//
// Created by q on 11/6/2019.
//

#include "input_from_customer.h"

#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include "display_order.h"

void displaySignOptions () {
    printf("Welcome to Food Thingies!\n");
    printf("%s\n",SIGN_IN_UP);
    printf("a) %s\n",SIGN_IN);
    printf("b) %s\n",SIGN_UP);
}

void signIn(char username[], char password[], int *state, int *goOn ) {
    printf("%s\n",SIGNING_IN);
    printf("---Username:\n>");
    gets(username);
    int conditionUsername=validateUsername(username);
    if(conditionUsername) {
        printf("---Password:\n>");
        gets(password);
        int conditionPassword = validatePassword(password, username);
        if(conditionPassword) {
            (*state)++;*goOn=0;
        }
        else
            printf("%s\n",INCORRECT_PASSWORD);
    }
    else {
        printf("%s\n",USER_NOT_FOUND);
        *goOn=0;
    }
}

void signUp(char username[], char password[], int *state, int *goOn ) {
    printf("%s\n",SIGNING_UP);
    printf("---Username:\n>");
    gets(username);
    int conditionUsername=validateUsername(username);
    if(!conditionUsername) {
        printf("---Password:\n>");
        gets(password);
        int conditionPassword = validatePassword(password, username);
        if(conditionPassword) {
            (*state)++;*goOn=0;
        }
        else
            incorrectNewPassword(password,username);
    }
    else
        printf("%s\n",DUPLICATE_USER);
}

void login(char username[], char password[], int *state) {
    displaySignOptions();
    char signChoice=getchar();
    getchar();//new line
    switch (signChoice) {
        case 'a': {
            int goOn = 1;
            while (goOn)
                signIn(username, password, state, &goOn);
            break;
        }
        case 'b':{
            int goOn = 1;
            while (goOn)
                signUp(username, password, state, &goOn);
            break;
        }
        default: break;
    }
}
int validateUsername(char username[]) {
    if(strcmp(username,"admin")==0)
        return 1;
    return 0;
}
/*
the password must be at least 7 chars long
the password must not contain the username
the password must contain one of the following characters: .,_,!
the password must contain digits
*/
int validatePassword(char password[], char username[]) {
    if(isLongEnough(password) && notContainUsername(password,username) && containSpecialCharacters(password) && containDigits(password))
        return 1;
    return 0;
}
int isLongEnough(char password[]) {
    if(strlen(password) >= 7)
        return 1;
    return 0;
}
int notContainUsername(char password[],char username[]) {
    if(!strstr(password,username))
        return 1;
    return 0;
}
int containSpecialCharacters(char password[]) {
    if(strpbrk(password,".,_!"))
        return 1;
    return 0;
}
int containDigits(char password[]) {
    if(strpbrk(password,"01234556789"))
        return 1;
    return 0;
}

void incorrectNewPassword(char password[], char username[]) {
    if(!isLongEnough(password)) printf("%s\n",ERROR_PASSWORD_LONG);
    if(!notContainUsername(password, username)) printf("%s\n",ERROR_PASSWORD_NOT_USERNAME);
    if(!containSpecialCharacters(password)) printf("%s\n",ERROR_PASSWORD_SPECIAL_CHAR);
    if(!containDigits(password)) printf("%s\n",ERROR_PASSWORD_DIGITS);
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
            getchar();  //reads new line
    }
}
