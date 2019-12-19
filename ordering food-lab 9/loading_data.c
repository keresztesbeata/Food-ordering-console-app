//
// Created by q on 11/27/2019.
//

#include "loading_data.h"
#include "drinks.h"
#include "foods.h"
#include "types.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

void loadData(FILE *file, int *ptrNoFoods, food **foodsAddr, int *ptrNoDrinks, drinks **drinksAddr) {
    char *inputLine=(char*)malloc(MAX_LINE*sizeof(char));
    loadFoodsData(file, inputLine, ptrNoFoods, foodsAddr);
    loadDrinksData(file, inputLine, ptrNoDrinks, drinksAddr);
    free(inputLine);
}

void readNoCategory(FILE *file, int *noCategories) {
    fscanf(file,"%d %*c",noCategories);
    fgetc(file);//new line
}

void separateTwo(char * line, char * type, char *delim) {
        char *ptr;
        ptr = strtok(line, delim);
        strcpy(type, ptr);
        ptr = strtok(NULL, delim);
        strcpy(line, ptr);
}

void splitLineIntoElements(char *line, char **elements, char *delim, int MAX_NAME) {
    char *ptr;
    int i=0;
    ptr=strtok(line,delim);
    while(ptr) {
        elements[i]=(char *)malloc((MAX_NAME+MAX_PRICE)*sizeof(char));
        strcpy(elements[i],ptr);
        ptr=strtok(NULL,delim);
        i++;
    }
}

double convertToDouble(char *string) {
    char *endPtr;
    return strtod(string,&endPtr);
}

void deleteUnnecessarySpaces (char * string) {
    int n=strlen(string);
    for(int i=0;i<n;i++) {
        if (string[i] == ' ')
            if (string[i-1]==':'||(string[i - 1] == ')' && string[i + 1] == '(' )|| (string[i - 1] == '-' || string[i + 1] == '-')||(string[i-1]==','&&string[i+1]=='('))
            {strcpy(string+i,string+i+1);
                n--;
            }
    }
}

