#include <stdio.h>
#include "reports.h"

void employeeReport()
{
    int i;
    float totalSalary = 0;
    float salary;
    float highestSalary;
    float lowestSalary;

    if(employeeCount == 0)
    {
        printf("\nNo employees available.\n");
        return;
    }

    salary = basicSalary[0] + housingAllowance[0] + transportAllowance[0] + otherAllowance[0];

    highestSalary = salary;
    lowestSalary = salary;

    for(i = 0; i < employeeCount; i++)
    {
        salary = basicSalary[i] + housingAllowance[i] + transportAllowance[i] + otherAllowance[i];

        totalSalary = totalSalary + salary;

        if(salary > highestSalary)
        {
            highestSalary = salary;
        }

        if(salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }

    printf("\n===== EMPLOYEE REPORT =====\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Total Salary: N$%.2f\n", totalSalary);
    printf("Average Salary: N$%.2f\n", totalSalary / employeeCount);
    printf("Highest Salary: N$%.2f\n", highestSalary);
    printf("Lowest Salary: N$%.2f\n", lowestSalary);
}

void supplierReport()
{
    int i;

    if(supplierCount == 0)
    {
        printf("\nNo suppliers available.\n");
        return;
    }

    printf("\n===== SUPPLIER REPORT =====\n");
    printf("Total Suppliers: %d\n", supplierCount);

    for(i = 0; i < supplierCount; i++)
    {
        printf("%d. %s - %s\n", i + 1, supplierName[i], town[i]);
    }
}

void assetReport()
{
    int i;
    float totalValue = 0;

    if(assetCount == 0)
    {
        printf("\nNo assets available.\n");
        return;
    }

    for(i = 0; i < assetCount; i++)
    {
        totalValue = totalValue + assetPurchaseValue[i];
    }

    printf("\n===== ASSET REPORT =====\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Asset Value: N$%.2f\n", totalValue);

    for(i = 0; i < assetCount; i++)
    {
        printf("%d. %s - N$%.2f\n", i + 1, assetName[i], assetPurchaseValue[i]);
    }
}

void fullSystemReport()
{
    int i;
    float totalSalary = 0;
    float totalAssetValue = 0;
    float salary;

    for(i = 0; i < employeeCount; i++)
    {
        salary = basicSalary[i] +
                 housingAllowance[i] +
                 transportAllowance[i] +
                 otherAllowance[i];

        totalSalary = totalSalary + salary;
    }

    for(i = 0; i < assetCount; i++)
    {
        totalAssetValue = totalAssetValue + assetPurchaseValue[i];
    }

    printf("\n===== FULL SYSTEM REPORT =====\n");

    printf("\nEMPLOYEE INFORMATION\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Total Salaries: N$%.2f\n", totalSalary);

    printf("\nSUPPLIER INFORMATION\n");
    printf("Total Suppliers: %d\n", supplierCount);

    printf("\nASSET INFORMATION\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Asset Value: N$%.2f\n", totalAssetValue);

    printf("\n===== END OF REPORT =====\n");
}

void reportManagement()
{
    int choice;

    do
    {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n");
        printf("2. Supplier Report\n");
        printf("3. Asset Report\n");
        printf("4. Full System Report\n");
        printf("5. Back to Main Menu\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            employeeReport();
        }
        else if(choice == 2)
        {
            supplierReport();
        }
        else if(choice == 3)
        {
            assetReport();
        }
        else if(choice == 4)
        {
            fullSystemReport();
        }
        else if(choice == 5)
        {
            printf("\nReturning to main menu...\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 5);
}