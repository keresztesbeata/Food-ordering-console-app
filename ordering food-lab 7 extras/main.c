#include <stdio.h>
#include <stdbool.h>
#include "input_from_customer.h"
#include "display_menu.h"
#include "display_order.h"
#include "loading_data.h"
// maximum memory
#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20
#define LOAD_DATA "Please load the data"
enum statesOfOrder {LOADING_DATA, LOGIN, FOOD, FOOD_TYPE, DRINK, CUTLERY, INFO, ORDER}; // states of the order
int main() {
    //food data
    int noFoods,*noFoodTypes,noDrinks;
    char **foods,***foodTypes,**drinks;
    double **foodPrices,*drinkPrices;
    //user input data
    char username[30], password[30], addInfo[100];
    int foodChoice, typeChoice, drinkChoice, getCutlery;
    //loop
    int state=LOADING_DATA;
    bool confirm=false;
    while(!confirm) {
        switch(state) {
            case LOADING_DATA:{
                loadData(&noFoods,&foods,&noFoodTypes,&foodTypes,&foodPrices,&noDrinks,&drinks,&drinkPrices,&state);
                break;
                }
            case LOGIN: {
                login(username, password, &state);
                break;
            }
            case FOOD:{
                displayFood(noFoods, foods);
                foodChoice=getChoiceIndex(noFoods, &state);
                break;
            }
            case FOOD_TYPE:{
                displayFoodTypes(foods[foodChoice], noFoodTypes[foodChoice], foodTypes[foodChoice], foodPrices[foodChoice]);
                typeChoice=getChoiceIndex(noFoodTypes[foodChoice], &state);
                break;
            }
            case DRINK:{
                displayDrinks(foods[foodChoice], noDrinks, drinks, drinkPrices);
                drinkChoice=getOptionalChoiceIndex(noDrinks, &state);// return null value for no drinks
                break;
            }
            case CUTLERY:{
                displayCutlery();
                getCutlery=chooseCutlery(&state);
                break;
            }
            case INFO:{
              getAdditionalInfo(addInfo, &state);
                break;
            }
            case ORDER:{
                    displayOrder(username, foodTypes[foodChoice][typeChoice], foodPrices[foodChoice][typeChoice], drinks[drinkChoice], drinkPrices[drinkChoice], drinkChoice, getCutlery, addInfo);
                    placeOrder(&confirm, username, &state);
            }
            default:break;
        }
    }
    freeMemory(noFoods,noFoodTypes,foods,foodTypes,foodPrices,noDrinks,drinks,drinkPrices);
    return 0;
}