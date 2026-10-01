#include <stdio.h>
#include <string.h>

int main()
{
    char supplierID[30];
    char supplierName[100];
    char email[100];
    char telephoneNumber[20];
    char town[50];

    char searchName[100];
    char backupName[100];

    int choice;
    int supplierAdded = 0;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("\nEnter supplier ID: ");
                fgets(supplierID, sizeof(supplierID), stdin);
                supplierID[strcspn(supplierID, "\n")] = '\0';

                printf("Enter supplier name: ");
                fgets(supplierName, sizeof(supplierName), stdin);
                supplierName[strcspn(supplierName, "\n")] = '\0';

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';

                printf("Enter telephone number: ");
                fgets(telephoneNumber, sizeof(telephoneNumber), stdin);
                telephoneNumber[strcspn(telephoneNumber, "\n")] = '\0';

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = '\0';

                supplierAdded = 1;

                printf("\nSupplier added successfully.\n");
                break;

            case 2:
                if(supplierAdded == 1)
                {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    printf("Supplier ID : %s\n", supplierID);
                    printf("Name        : %s\n", supplierName);
                    printf("Email       : %s\n", email);
                    printf("Phone       : %s\n", telephoneNumber);
                    printf("Town        : %s\n", town);
                }
                else
                {
                    printf("\nNo supplier has been added.\n");
                }
                break;

            case 3:
                if(supplierAdded == 1)
                {
                    printf("\nEnter supplier name to search: ");
                    fgets(searchName, sizeof(searchName), stdin);
                    searchName[strcspn(searchName, "\n")] = '\0';

                    if(strcmp(searchName, supplierName) == 0)
                    {
                        printf("Supplier found.\n");
                    }
                    else
                    {
                        printf("Supplier not found.\n");
                    }
                }
                else
                {
                    printf("\nNo supplier has been added.\n");
                }
                break;

            case 4:
                if(supplierAdded == 1)
                {
                    printf("\nEnter another supplier name to compare: ");
                    fgets(backupName, sizeof(backupName), stdin);
                    backupName[strcspn(backupName, "\n")] = '\0';

                    if(strcmp(supplierName, backupName) == 0)
                    {
                        printf("The suppliers are the same.\n");
                    }
                    else
                    {
                        printf("The suppliers are different.\n");
                    }
                }
                else
                {
                    printf("\nNo supplier has been added.\n");
                }
                break;

            case 5:
                printf("\nExiting program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

