#include "assets.h"

int assetID[MAX_ASSETS];
char name[MAX_ASSETS][50];
char type[MAX_ASSETS][50];
float purchaseValue[MAX_ASSETS];
char department[MAX_ASSETS][50];
char condition[MAX_ASSETS][50];
int count = 0;

int main()
{
    int choice;

    do
    {
        printf("\n===== MUNICIPAL ASSET REGISTER =====\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Search Department\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            addAsset();
        }
        else if(choice == 2)
        {
            displayAssets();
        }
        else if(choice == 3)
        {
            searchAsset();
        }
        else if(choice == 4)
        {
            searchDepartment();
        }
        else if(choice == 5)
        {
            printf("\nProgram ended.\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}

void addAsset()
{
    int i;

    printf("\n===== ADD ASSET =====\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assetID[count]);

    getchar();

    printf("Enter Name: ");
    fgets(name[count], 50, stdin);

    for(i = 0; name[count][i] != '\0'; i++)
    {
        if(name[count][i] == '\n')
        {
            name[count][i] = '\0';
            break;
        }
    }

    printf("Enter Type (Vehicles, Computers, Buildings, Equipment, Office furniture): ");
    fgets(type[count], 50, stdin);

    for(i = 0; type[count][i] != '\0'; i++)
    {
        if(type[count][i] == '\n')
        {
            type[count][i] = '\0';
            break;
        }
    }

    printf("Enter Purchase Value: ");
    scanf("%f", &purchaseValue[count]);

    getchar();

    printf("Enter Department: ");
    fgets(department[count], 50, stdin);

    for(i = 0; department[count][i] != '\0'; i++)
    {
        if(department[count][i] == '\n')
        {
            department[count][i] = '\0';
            break;
        }
    }

    printf("Enter Condition: ");
    fgets(condition[count], 50, stdin);

    for(i = 0; condition[count][i] != '\0'; i++)
    {
        if(condition[count][i] == '\n')
        {
            condition[count][i] = '\0';
            break;
        }
    }

    count = count + 1;

    printf("\nAsset added successfully!\n");
}

void displayAssets()
{
    int i;

    if(count == 0)
    {
        printf("\nNo assets available.\n");
    }
    else
    {
        printf("\n===== ALL ASSETS =====\n");

        for(i = 0; i < count; i++)
        {
            printf("\nAsset %d\n", i + 1);
            printf("Asset ID: %d\n", assetID[i]);
            printf("Name: %s\n", name[i]);
            printf("Type: %s\n", type[i]);
            printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
            printf("Department: %s\n", department[i]);
            printf("Condition: %s\n", condition[i]);
        }
    }
}

void searchAsset()
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter Asset ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(assetID[i] == id)
        {
            printf("\nAsset found!\n");
            printf("Asset ID: %d\n", assetID[i]);
            printf("Name: %s\n", name[i]);
            printf("Type: %s\n", type[i]);
            printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
            printf("Department: %s\n", department[i]);
            printf("Condition: %s\n", condition[i]);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nAsset not found.\n");
    }
}

void searchDepartment()
{
    char searchDept[50];
    int i, j;
    int found = 0;

    getchar();

    printf("\nEnter Department to search: ");
    fgets(searchDept, 50, stdin);

    for(i = 0; searchDept[i] != '\0'; i++)
    {
        if(searchDept[i] == '\n')
        {
            searchDept[i] = '\0';
            break;
        }
    }

    for(i = 0; i < count; i++)
    {
        int match = 1;

        for(j = 0; searchDept[j] != '\0' || department[i][j] != '\0'; j++)
        {
            if(searchDept[j] != department[i][j])
            {
                match = 0;
                break;
            }
        }

        if(match == 1)
        {
            if(found == 0)
            {
                printf("\n===== ASSETS IN DEPARTMENT =====\n");
            }

            printf("\nAsset ID: %d\n", assetID[i]);
            printf("Name: %s\n", name[i]);
            printf("Type: %s\n", type[i]);
            printf("Purchase Value: N$%.2f\n", purchaseValue[i]);
            printf("Department: %s\n", department[i]);
            printf("Condition: %s\n", condition[i]);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nNo assets found for this department.\n");
    }
}