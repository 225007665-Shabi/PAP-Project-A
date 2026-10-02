#include <stdio.h>
#include "function.h"



int main()
{
    int choice;

    do
    {
        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(validateChoice(choice)==0){
            printf("Invalid choice. Please enter a numberbetween 1 and 6. \n");
        }
        else
        {

            switch(choice)
            {
                 case 1:
                      printf("Employee Management selected.\n");
                     break;

                case 2:
                     printf("Budget Management selected.\n");
                      break;

                case 3:
                    printf("Supplier Management selected.\n");
                     break;

                case 4:
                     printf("Asset Management selected.\n");
                     break;

                case 5:
                     printf("Reports selected.\n");
                     break;

                case 6:
                     exitProgram();
                      break;

                default:
                     printf("Invalid choice. Try again.\n");
            }
        }
    } while(choice != 6);

    return 0;
}