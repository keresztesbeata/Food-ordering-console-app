//
// Created by q on 11/6/2019.
//

#ifndef _ORDERING_FOOD_INPUT_FROM_CUSTOMER_H
#define _ORDERING_FOOD_INPUT_FROM_CUSTOMER_H

#define ERROR_PASSWORD_LONG "The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS "The password must contain digits"
#define SIGN_IN_UP  "Do you want to sign in or sign up?"
#define SIGN_IN "Sign in"
#define SIGN_UP "Sign up"
#define SIGNING_IN "Signing in!"
#define SIGNING_UP "Signing up!"
#define USER_NOT_FOUND "Username doesn't exist"
#define DUPLICATE_USER "Please choose another username!"
#define INCORRECT_PASSWORD "Incorrect password"
#define MAX_NAME_LENGHT 20
#define MAX_PASSWD_LENGHT 20
#include <stdbool.h>
#include<stdio.h>

//login
void login(char username[], char password[], int *state);
void signIn(FILE *loginFile, char username[], char password[], int *state, int *goOn );
void signUp(FILE *loginFile, char username[], char password[], int *state, int *goOn );
//validate username and password
void decrypt_pass(int key, char password[]);
void encrypt_pass(int key, char password[]);
int validateUsername(FILE *loginFile, int noOfUsers, char username[], char matchingPassword[]);
int validatePassword(char password[], char matchingPassword[], char username[]);
int isLongEnough(char password[]);
int notContainUsername(char password[],char username[]);
int containSpecialCharacters(char password[]);
int containDigits(char password[]);
void incorrectNewPassword(char password[], char username[]);
//user choices
int getChoiceIndex(int nrChoices, int *state);
int getOptionalChoiceIndex(int nrChoices, int *state);
int chooseCutlery(int *state);
void getAdditionalInfo(char addInfo[], int *state);
void placeOrder(bool *confirm, char username[], int *state);

#endif //_ORDERING_FOOD_INPUT_FROM_CUSTOMER_H
