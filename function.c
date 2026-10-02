#include <stdio.h>
#include "function.h"

void displayMenu(){
    printf("\n");

       printf("*********\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("*********\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    
    printf("*********");
}
int validateChoice(int choice){

    if(choice>=1 && choice <=6){
        return 1;
    }
    else{
        return 0;
    }

    
}
int validateAmount(double amount){

    if(amount >=0){
        return 1;
    }
    else{
        return 0;
    }
    
}
int validateName(char name[]){
    if(name[0] != '\0'){
        return 1;
    }
    else{
        return 0;
    }
}
void exitProgram(){
    printf(" Goodbye!\n");
}