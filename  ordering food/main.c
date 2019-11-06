#include <stdio.h>
#include <stdbool.h>
#include "input_from_customer.h"
#include "display_menu.h"
#include "display_order.h"
// states of the order
#define LOGIN 0
#define FOOD (LOGIN+1)
#define FOOD_TYPE (FOOD+1)
#define DRINK (FOOD_TYPE+1)
#define CUTLERY (DRINK+1)
#define INFO (CUTLERY+1)
#define ORDER (INFO+1)
// maximum memory
#define MAX_FOOD_NAME 30
#define MAX_FOOD_TYPE_NAME 30
#define MAX_DRINK_NAME 20

int main()
{    //food data
    int nrFood=3;
    char food[][MAX_FOOD_NAME]={"Pizza","Pasta","Salad"};
    int nrType[]={3,2,4};
    char foodType[3][4][MAX_FOOD_TYPE_NAME]={{"Pizza Carbonara","Pizza Margherita","Pizza Diavola"},
                             {"Chicken Alfredo","Mac&Cheese"},
                             {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}};
    int foodPrices[3][4]={{21,23,19},{23,21},{23,22,19,21}};
    int nrDrinks=4;
    char drink[][MAX_DRINK_NAME]={"Cola","Fanta","Lipton","Water"};
    int drinkPrices[4]={5,5,5,4};
    int totalPrice;
    //user input data
    char username[30];
    char password[30];
    int foodChoice;
    int typeChoice;
    int drinkChoice;
    int getCutlery;
    char addInfo[100];
    //loop
    int state=LOGIN;
    bool confirm=false;
    while(!confirm)
    {
        switch(state)
        {
            case LOGIN: {
                login(username,password,&state);
                break;
            }
            case FOOD:{
                displayFood(nrFood,food);
                foodChoice=getChoiceIndex(nrFood,&state);
                break;
            }
            case FOOD_TYPE:{
                displayFoodTypes(food[foodChoice],nrType[foodChoice], foodType[foodChoice],foodPrices[foodChoice]);
                typeChoice=getChoiceIndex(nrType[foodChoice],&state);
                break;
            }
            case DRINK:{
                displayDrinks(food[foodChoice],nrDrinks,drink,drinkPrices);
                drinkChoice=getOptionalChoiceIndex(nrDrinks,&state);
                break;
            }
            case CUTLERY:{
                getCutlery=chooseCutlery(&state);
                break;
            }
            case INFO:{
              getAdditionalInfo(addInfo,&state);
                break;
            }
            case ORDER:{
                displayOrderCustomerData(username);
                totalPrice = 0;
                displayOrderFood(foodType[foodChoice][typeChoice],foodPrices[foodChoice][typeChoice],&totalPrice);
                displayOrderDrink(drink[drinkChoice],drinkPrices[drinkChoice],drinkChoice,&totalPrice);
                displayOrderAdditionalItems(getCutlery,addInfo,&totalPrice);
                placeOrder(&confirm,&state,username);
            }
            default:break;
        }
    }
    return 0;
}