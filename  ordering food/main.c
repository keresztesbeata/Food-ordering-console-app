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
    int totalPrice=0;
    //user input data
    char username[30];
    char password[30];
    char choice;
    int foodChoice;
    int typeChoice;
    int drinkChoice;
    int getDrink;
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
                if(choice=='a'+nrFood)
                {state--;break;}
                state++;
                foodChoice=choice-'a';
                break;
            }
            case FOOD_TYPE:{
                printf("Please choose the type of %s!\n",food[foodChoice]);
                for(int i=0;i<nrType[foodChoice];i++)
                {
                    putchar('a'+i);
                    printf(") %s: %d\n",foodtype[foodChoice][i],foodPrices[foodChoice][i]);
                }
                putchar('a'+nrType[foodChoice]);
                printf(") Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a'+nrType[foodChoice])
                   {state--;break;}
                state++;
                typeChoice=choice-'a';
                break;
            }
            case DRINK:{
                printf("Please choose a drink to go with your %s.\n",food[foodChoice]);
                getDrink=1;
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
                else if(choice=='a'+nrDrinks) {getDrink=0;}
                else drinkChoice=choice-'a';
                state++;
                break;
            }
            case CUTLERY:{
                printf("Do you want cutlery?\n");
                getCutlery=1;
                printf("a) Yes\n");
                printf("b) No, thanks\n");
                printf("c) Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='b')
                    getCutlery=0;
                if(choice=='c')
                    {state--;break;}
                state++;
                break;
            }
            case INFO:{
                printf("Any additional info?\n>");
                gets(addInfo);
                state++;
                break;
            }
            case ORDER:{
                totalPrice=0;
                printf("This is your order:\n");
                printf("------------\n");
                printf("Name: %s\n",username);
                printf("Food items:\n");
                printf("---%s: %d\n",foodtype[foodChoice][typeChoice],foodPrices[foodChoice][typeChoice]);
                totalPrice+=foodPrices[foodChoice][typeChoice];
                if(getDrink) {
                    printf("---%s: %d\n",drink[drinkChoice],drinkPrices[drinkChoice]);
                    totalPrice+=drinkPrices[drinkChoice];
                }
                printf("Cutlery: ");
                if(getCutlery) printf("yes\n");
                else printf("no\n");
                if(addInfo[0]=='\n')
                    printf("Additional info: %s\n",addInfo); //if there's no additional info it won't print anything
                printf("Payment amount: %d\n",totalPrice);
                printf("------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                printf(">");
                choice=getchar();
                getchar();
                if(choice=='a') {
                    printf("You order has been registered. Thank you for buying from us, %s!\n",username);
                    confirm=true;
                }
                if(choice=='b')
                {state-=2;break;} //it brings us back to the cutlary option
                getchar();
            }
            default:break;
        }
    }
    return 0;
}