#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LOGIN 0
#define FOOD (LOGIN+1)
#define FOOD_TYPE (FOOD+1)
#define DRINK (FOOD_TYPE+1)
#define CUTLERY (DRINK+1)
#define INFO (CUTLERY+1)
#define ORDER (INFO+1)

int main()
{

    //food data
    int nrFood=3;
    char food[][30]={"Pizza","Pasta","Salad"};
    int nrType[]={3,2,4};
    char foodtype[3][4][30]={{"Pizza Carbonara","Pizza Margherita","Pizza Diavola"},
                             {"Chicken Alfredo","Mac&Cheese"},
                             {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}};
    int foodPrices[3][4]={{21,23,19},{23,21},{23,22,19,21}};
    int nrDrinks=4;
    char drink[][30]={"Cola","Fanta","Lipton","Water"};
    int drinkPrices[4]={5,5,5,4};
    int TotalPrice=0;
    //user input data
    char username[30];
    char password[30];
    char choice;
    int FoodChoice;
    int TypeChoice;
    int DrinkChoice;
    int GetDrink;
    int GetCutlery;
    char addInfo[100];
    //loop
    int state=LOGIN;
    bool confirm=false;
    while(!confirm)
    {
        switch(state)
        {
            case LOGIN: {
                printf("Welcome to Noblesse!\n");
                printf("Please sign in to continue!\n");
                printf("->Username:\n>");
                gets(username);
                printf("->Password:\n>");
                gets(password);
                state++;
                break;
            }
            case FOOD:{
                printf("Please choose the kind of food you'd like to eat today!\n");
                for(int i=0;i<nrFood;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                }
                putchar('a'+nrFood);
                printf(") Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a'+nrFood) {state--;break;}
                state++;
                FoodChoice=choice-'a';
                break;
            }
            case FOOD_TYPE:{
                printf("Please choose the type of %s!\n",food[FoodChoice]);
                for(int i=0;i<nrType[FoodChoice];i++)
                {
                    putchar('a'+i);
                    printf(") %s: %d\n",foodtype[FoodChoice][i],foodPrices[FoodChoice][i]);
                }
                putchar('a'+nrType[FoodChoice]);
                printf(") Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a'+nrType[FoodChoice]) {state--;break;}
                state++;
                TypeChoice=choice-'a';
                break;
            }
            case DRINK:{
                printf("Please choose a drink to go with your %s.\n",food[FoodChoice]);
                GetDrink=1;
                for(int i=0;i<nrDrinks;i++)
                {
                    putchar('a'+i);
                    printf(") %s: %d\n",drink[i],drinkPrices[i]);
                }
                putchar('a'+nrDrinks);
                printf(") No, thanks!\n");
                putchar('a'+nrDrinks+1);
                printf(") Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a'+nrDrinks+1) {state--;break;}
                else if(choice=='a'+nrDrinks) {GetDrink=0;}
                else DrinkChoice=choice-'a';
                state++;
                break;
            }
            case CUTLERY:{
                printf("Do you want cutlery?\n");
                GetCutlery=1;
                printf("a) Yes\n");
                printf("b) No, thanks\n");
                printf("c) Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='b') GetCutlery=0;
                if(choice=='c') {state--;break;}
                state++;
                break;
            }
            case INFO:{
                printf("Any additional info?\n>");
                gets(addInfo);
            }
            case ORDER:{
                printf("This is your order:\n");
                printf("------------\n");
                printf("Name: %s\n",username);
                printf("Food items:\n");
                printf("---%s: %d\n",foodtype[FoodChoice][TypeChoice],foodPrices[FoodChoice][TypeChoice]);
                TotalPrice+=foodPrices[FoodChoice][TypeChoice];
                if(GetDrink) {
                    printf("---%s: %d\n",drink[DrinkChoice],drinkPrices[DrinkChoice]);
                    TotalPrice+=drinkPrices[DrinkChoice];
                }
                printf("Cutlery: ");
                if(GetCutlery) printf("yes\n");
                else printf("no\n");
                printf("Additional info: %s\n",addInfo);
                printf("Payment amount: %d\n",TotalPrice);
                printf("-----------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a') {
                    printf("You order has been registered. Thank you for buying from us, %s!\n",username);
                    confirm=true;
                }
                if(choice=='b') {state--;break;}
                getchar();
            }
            default:break;
        }
    }
    return 0;
}