#include <stdio.h>
#include <stdbool.h>
#include "input_from_customer.h"
#include "display_menu.h"
#include "display_order.h"
// maximum memory
#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20
enum statesOfOrder {LOGIN, FOOD, FOOD_TYPE, DRINK, CUTLERY, INFO, ORDER}; // states of the order
int main() {
    //food data
    int nrFood=3;
    char food[][MAX_FOOD_NAME]={"Pizza","Pasta","Salad"};
    int nrType[]={3,2,4}, foodPrices[3][4]={{21,23,19},{23,21},{23,22,19,21}};
    char foodType[3][4][MAX_FOOD_TYPE_NAME]={{"Pizza Carbonara","Pizza Margherita","Pizza Diavola"},
                                             {"Chicken Alfredo","Mac&Cheese"},
                                             {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}};
    int nrDrinks=4, drinkPrices[4]={5,5,5,4};
    char drink[][MAX_DRINK_NAME]={"Cola","Fanta","Lipton","Water"};
    //user input data
    char username[30], password[30], addInfo[100];
    int foodChoice, typeChoice, drinkChoice, getCutlery;
    //loop
    int state=LOGIN;
    bool confirm=false;
    while(!confirm) {
        switch(state) {
            case LOGIN: {
                login(username, password, &state);
                break;
            }
            case FOOD:{
                displayFood(nrFood, food);
                foodChoice=getChoiceIndex(nrFood, &state);
                break;
            }
            case FOOD_TYPE:{
                displayFoodTypes(food[foodChoice], nrType[foodChoice], foodType[foodChoice], foodPrices[foodChoice]);
                typeChoice=getChoiceIndex(nrType[foodChoice], &state);
                break;
            }
            case DRINK:{
                displayDrinks(food[foodChoice], nrDrinks, drink, drinkPrices);
                drinkChoice=getOptionalChoiceIndex(nrDrinks, &state);// return null value for no drink
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
                    displayOrder(username, foodType[foodChoice][typeChoice], foodPrices[foodChoice][typeChoice], drink[drinkChoice], drinkPrices[drinkChoice], drinkChoice, getCutlery, addInfo);
                    placeOrder(&confirm, username, &state);
            }
            default:break;
        }
    }
    return 0;
}