#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_from_customer.h"
#include "display_order.h"
#include "loading_data.h"
#include "foods.h"
#include "types.h"
// maximum memory
#define LOAD_DATA "Please load the data"
#define FILE_PATH "../data.txt"
enum statesOfOrder {LOGIN, FOOD, FOOD_TYPE, DRINK, CUTLERY, INFO, ORDER}; // states of the order
int main() {
    FILE *dataFile, *stream;
    //food data
    int noFoods, noDrinks;
    food *myFoods;
    drinks *myDrinks;
    //open file
    dataFile = fopen(FILE_PATH, "r");
    //check if file was opened successfully
    if (dataFile == NULL) {
        printf("%s\n", LOAD_DATA);
        stream=stdin;
    } else
    stream = dataFile;
    loadData(stream, &noFoods, &myFoods, &noDrinks, &myDrinks);
    fclose(dataFile);//close file
    //user input data
    customer myCustomer;
    int foodChoice, typeChoice, drinkChoice, cutleryChoice;
    int state=LOGIN;
    bool confirm=false;
    while(!confirm) {
        switch (state) {
                case LOGIN: {
                    login(&myCustomer, &state);
                    break;
                }
                case FOOD: {
                    displayFood(noFoods, myFoods);
                    foodChoice = getChoiceIndex(noFoods, &state);
                    break;
                }
                case FOOD_TYPE: {
                    displayFoodTypes(myFoods[foodChoice].name,myFoods[foodChoice].noTypes,myFoods[foodChoice].types);
                    typeChoice = getChoiceIndex(myFoods[foodChoice].noTypes, &state);
                    break;
                }
                case DRINK: {
                    displayDrinks(myFoods[foodChoice].name, noDrinks, myDrinks);
                    drinkChoice = getOptionalChoiceIndex(noDrinks, &state);// return null value for no drinks
                    break;
                }
                case CUTLERY: {
                    cutleryChoice = chooseCutlery(&state);
                    break;
                }
                case INFO: {
                    getAdditionalInfo(myCustomer.addInfo, &state);
                    break;
                }
                case ORDER:{
                    displayOrder(&myCustomer, &(myFoods[foodChoice].types[typeChoice]),&myDrinks[drinkChoice], drinkChoice, cutleryChoice);
                    placeOrder(&confirm, myCustomer.username, &state);
                }
                default: break;
            }
        }
    //free memory
    freeFoods(noFoods,myFoods);
    freeDrinks(noDrinks,myDrinks);
    return 0;
    }