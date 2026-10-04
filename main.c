#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_SUPPLIERS 100
#define MAX_ASSETS 100
#define MAX_BUDGETS 100

char employeeID[MAX_EMPLOYEES][20];
char employeeName[MAX_EMPLOYEES][50];
char employeeDepartment[MAX_EMPLOYEES][50];

float basicSalary[MAX_EMPLOYEES];
float housingAllowance[MAX_EMPLOYEES];
float transportAllowance[MAX_EMPLOYEES];
float otherAllowance[MAX_EMPLOYEES];

int employeeCount = 0;

char supplierID[MAX_SUPPLIERS][30];
char supplierName[MAX_SUPPLIERS][100];
char email[MAX_SUPPLIERS][100];
char telephoneNumber[MAX_SUPPLIERS][20];
char town[MAX_SUPPLIERS][50];

int supplierCount = 0;

int assetID[MAX_ASSETS];
char assetName[MAX_ASSETS][50];
char assetType[MAX_ASSETS][50];
float assetPurchaseValue[MAX_ASSETS];
char assetDepartment[MAX_ASSETS][50];
char assetCondition[MAX_ASSETS][50];

int assetCount = 0;

char budgetDepartment[MAX_BUDGETS][50];
float allocatedBudget[MAX_BUDGETS];
float expenditure[MAX_BUDGETS];

int budgetCount = 0;

void displayMenu();
int validateChoice(int choice);
int validateAmount(double amount);
int validateName(char name[]);

void employeeManagement();
void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateEmployeeSalary();
void employeeReport();

void budgetManagement();
void addBudget();
void displayBudgets();
void budgetReport();

void supplierManagement();
void addSupplier();
void displaySuppliers();
void searchSupplierID();
void searchSupplierName();
void supplierReport();

void assetManagement();
void addAsset();
void displayAssets();
void searchAsset();
void searchDepartment();
void assetReport();

void reportManagement();
void fullSystemReport();

void exitProgram();

void displayMenu()
{
    printf("\n");
    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

int validateChoice(int choice)
{
    if(choice >= 1 && choice <= 6)
        return 1;
    else
        return 0;
}

int validateAmount(double amount)
{
    if(amount >= 0)
        return 1;
    else
        return 0;
}

int validateName(char name[])
{
    if(name[0] != '\0' && name[0] != '\n')
        return 1;
    else
        return 0;
}

void employeeManagement()
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Employee Report\n");
        printf("6. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            addEmployee();
        else if(choice == 2)
            displayEmployees();
        else if(choice == 3)
            searchEmployee();
        else if(choice == 4)
            calculateEmployeeSalary();
        else if(choice == 5)
            employeeReport();
        else if(choice == 6)
            printf("\nReturning to main menu...\n");
        else
            printf("\nInvalid choice. Please try again.\n");

    } while(choice != 6);
}

void addEmployee()
{
    int i;
    float basic, housing, transport, other;

    if(employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%19s", employeeID[employeeCount]);
    getchar();

    do
    {
        printf("Enter Name: ");
        fgets(employeeName[employeeCount], 50, stdin);

        if(validateName(employeeName[employeeCount]) == 0)
            printf("Name cannot be empty. Please try again.\n");

    } while(validateName(employeeName[employeeCount]) == 0);

    i = 0;

    while(employeeName[employeeCount][i] != '\0')
    {
        if(employeeName[employeeCount][i] == '\n')
        {
            employeeName[employeeCount][i] = '\0';
            break;
        }

        i++;
    }

    printf("Enter Department: ");
    fgets(employeeDepartment[employeeCount], 50, stdin);

    i = 0;

    while(employeeDepartment[employeeCount][i] != '\0')
    {
        if(employeeDepartment[employeeCount][i] == '\n')
        {
            employeeDepartment[employeeCount][i] = '\0';
            break;
        }

        i++;
    }

    do
    {
        printf("Enter Basic Salary: ");
        scanf("%f", &basic);

        if(validateAmount(basic) == 0)
            printf("Salary cannot be negative.\n");

    } while(validateAmount(basic) == 0);

    do
    {
        printf("Enter Housing Allowance: ");
        scanf("%f", &housing);

        if(validateAmount(housing) == 0)
            printf("Allowance cannot be negative.\n");

    } while(validateAmount(housing) == 0);

    do
    {
        printf("Enter Transport Allowance: ");
        scanf("%f", &transport);

        if(validateAmount(transport) == 0)
            printf("Allowance cannot be negative.\n");

    } while(validateAmount(transport) == 0);

    do
    {
        printf("Enter Other Allowance: ");
        scanf("%f", &other);

        if(validateAmount(other) == 0)
            printf("Allowance cannot be negative.\n");

    } while(validateAmount(other) == 0);

    basicSalary[employeeCount] = basic;
    housingAllowance[employeeCount] = housing;
    transportAllowance[employeeCount] = transport;
    otherAllowance[employeeCount] = other;

    employeeCount++;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees()
{
    int i;

    if(employeeCount == 0)
    {
        printf("\nNo employees available.\n");
    }
    else
    {
        printf("\n===== ALL EMPLOYEES =====\n");

        for(i = 0; i < employeeCount; i++)
        {
            printf("\nEmployee %d\n", i + 1);
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Department: %s\n", employeeDepartment[i]);
            printf("Basic Salary: N$%.2f\n", basicSalary[i]);
            printf("Housing Allowance: N$%.2f\n", housingAllowance[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowance[i]);
            printf("Other Allowance: N$%.2f\n", otherAllowance[i]);
            printf("Gross Salary: N$%.2f\n",
                   basicSalary[i] +
                   housingAllowance[i] +
                   transportAllowance[i] +
                   otherAllowance[i]);
        }
    }
}

void searchEmployee()
{
    char id[20];
    int i, j, found = 0, same;

    printf("\nEnter Employee ID to search: ");
    scanf("%19s", id);

    for(i = 0; i < employeeCount; i++)
    {
        j = 0;
        same = 1;

        while(id[j] != '\0' || employeeID[i][j] != '\0')
        {
            if(id[j] != employeeID[i][j])
            {
                same = 0;
                break;
            }

            j++;
        }

        if(same == 1)
        {
            printf("\nEmployee found!\n");
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Department: %s\n", employeeDepartment[i]);
            printf("Basic Salary: N$%.2f\n", basicSalary[i]);
            printf("Gross Salary: N$%.2f\n",
                   basicSalary[i] +
                   housingAllowance[i] +
                   transportAllowance[i] +
                   otherAllowance[i]);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nEmployee not found.\n");
}

void calculateEmployeeSalary()
{
    char id[20];
    int i, j, found = 0, same;
    float grossSalary;

    printf("\nEnter Employee ID: ");
    scanf("%19s", id);

    for(i = 0; i < employeeCount; i++)
    {
        j = 0;
        same = 1;

        while(id[j] != '\0' || employeeID[i][j] != '\0')
        {
            if(id[j] != employeeID[i][j])
            {
                same = 0;
                break;
            }

            j++;
        }

        if(same == 1)
        {
            grossSalary = basicSalary[i] +
                          housingAllowance[i] +
                          transportAllowance[i] +
                          otherAllowance[i];

            printf("\n===== SALARY INFORMATION =====\n");
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Name: %s\n", employeeName[i]);
            printf("Basic Salary: N$%.2f\n", basicSalary[i]);
            printf("Housing Allowance: N$%.2f\n", housingAllowance[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowance[i]);
            printf("Other Allowance: N$%.2f\n", otherAllowance[i]);
            printf("Gross Salary: N$%.2f\n", grossSalary);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nEmployee not found.\n");
}

void employeeReport()
{
    int i;
    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    if(employeeCount == 0)
    {
        printf("\nNo employees available.\n");
    }
    else
    {
        highestSalary = basicSalary[0] +
                        housingAllowance[0] +
                        transportAllowance[0] +
                        otherAllowance[0];

        lowestSalary = highestSalary;

        for(i = 0; i < employeeCount; i++)
        {
            float salary = basicSalary[i] +
                           housingAllowance[i] +
                           transportAllowance[i] +
                           otherAllowance[i];

            totalSalary = totalSalary + salary;

            if(salary > highestSalary)
                highestSalary = salary;

            if(salary < lowestSalary)
                lowestSalary = salary;
        }

        averageSalary = totalSalary / employeeCount;

        printf("\n===== EMPLOYEE REPORT =====\n");
        printf("Total Employees: %d\n", employeeCount);
        printf("Average Salary: N$%.2f\n", averageSalary);
        printf("Highest Salary: N$%.2f\n", highestSalary);
        printf("Lowest Salary: N$%.2f\n", lowestSalary);
    }
}

void budgetManagement()
{
    int choice;

    do
    {
        printf("\n===== BUDGET MANAGEMENT =====\n");
        printf("1. Add Budget\n");
        printf("2. Display Budgets\n");
        printf("3. Budget Report\n");
        printf("4. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            addBudget();
        else if(choice == 2)
            displayBudgets();
        else if(choice == 3)
            budgetReport();
        else if(choice == 4)
            printf("\nReturning to main menu...\n");
        else
            printf("\nInvalid choice. Please try again.\n");

    } while(choice != 4);
}

void addBudget()
{
    float budget;
    float expense;

    if(budgetCount >= MAX_BUDGETS)
    {
        printf("\nBudget storage is full.\n");
        return;
    }

    printf("\n===== ADD BUDGET =====\n");

    printf("Enter name of Department: ");
    scanf(" %49[^\n]", budgetDepartment[budgetCount]);

    do
    {
        printf("Enter Allocated Department Budget: ");
        scanf("%f", &budget);

        if(validateAmount(budget) == 0)
            printf("Budget cannot be negative.\n");

    } while(validateAmount(budget) == 0);

    do
    {
        printf("Enter Total Expenditure: ");
        scanf("%f", &expense);

        if(validateAmount(expense) == 0)
            printf("Expenditure cannot be negative.\n");

    } while(validateAmount(expense) == 0);

    allocatedBudget[budgetCount] = budget;
    expenditure[budgetCount] = expense;

    budgetCount++;

    printf("\nBudget added successfully!\n");
}

void displayBudgets()
{
    int i;
    float balance;

    if(budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    printf("\n===== ALL BUDGETS =====\n");

    for(i = 0; i < budgetCount; i++)
    {
        balance = allocatedBudget[i] - expenditure[i];

        printf("\nBudget %d\n", i + 1);
        printf("Department: %s\n", budgetDepartment[i]);
        printf("Allocated Budget: N$%.2f\n", allocatedBudget[i]);
        printf("Total Expenditure: N$%.2f\n", expenditure[i]);
        printf("Balance: N$%.2f\n", balance);

        if(expenditure[i] <= allocatedBudget[i])
            printf("Status: Within Budget\n");
        else
            printf("Status: NOT Within Budget\n");
    }
}

void budgetReport()
{
    int i;
    int withinBudget = 0;
    int overBudget = 0;

    float totalBudget = 0;
    float totalExpenditure = 0;
    float totalBalance;

    if(budgetCount == 0)
    {
        printf("\nNo budgets available.\n");
        return;
    }

    for(i = 0; i < budgetCount; i++)
    {
        totalBudget = totalBudget + allocatedBudget[i];
        totalExpenditure = totalExpenditure + expenditure[i];

        if(expenditure[i] <= allocatedBudget[i])
            withinBudget++;
        else
            overBudget++;
    }

    totalBalance = totalBudget - totalExpenditure;

    printf("\n===== BUDGET REPORT =====\n");
    printf("Total Departments: %d\n", budgetCount);
    printf("Total Allocated Budget: N$%.2f\n", totalBudget);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Balance: N$%.2f\n", totalBalance);
    printf("Departments Within Budget: %d\n", withinBudget);
    printf("Departments Over Budget: %d\n", overBudget);
}

void supplierManagement()
{
    int choice;

    do
    {
        printf("\n===== SUPPLIER MANAGEMENT =====\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Search Supplier by Name\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySuppliers();
                break;

            case 3:
                searchSupplierID();
                break;

            case 4:
                searchSupplierName();
                break;

            case 5:
                printf("\nReturning to main menu...\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 5);
}

void addSupplier()
{
    if(supplierCount >= MAX_SUPPLIERS)
    {
        printf("\nSupplier storage is full.\n");
        return;
    }

    printf("\n===== ADD SUPPLIER =====\n");

    printf("Enter Supplier ID: ");
    scanf("%29s", supplierID[supplierCount]);

    printf("Enter Supplier Name: ");
    scanf(" %99[^\n]", supplierName[supplierCount]);

    printf("Enter Email: ");
    scanf("%99s", email[supplierCount]);

    printf("Enter Telephone Number: ");
    scanf("%19s", telephoneNumber[supplierCount]);

    printf("Enter Town: ");
    scanf(" %49[^\n]", town[supplierCount]);

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers()
{
    int i;

    if(supplierCount == 0)
    {
        printf("\nNo suppliers have been added yet.\n");
        return;
    }

    printf("\n===== ALL SUPPLIERS =====\n");

    for(i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("-------------------------\n");
        printf("Supplier ID: %s\n", supplierID[i]);
        printf("Supplier Name: %s\n", supplierName[i]);
        printf("Email: %s\n", email[i]);
        printf("Telephone Number: %s\n", telephoneNumber[i]);
        printf("Town: %s\n", town[i]);
    }
}

void searchSupplierID()
{
    char searchID[30];
    int found = 0;
    int i;

    printf("\nEnter Supplier ID: ");
    scanf("%29s", searchID);

    for(i = 0; i < supplierCount; i++)
    {
        if(strcmp(supplierID[i], searchID) == 0)
        {
            printf("\nSupplier found!\n");
            printf("Supplier ID: %s\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone Number: %s\n", telephoneNumber[i]);
            printf("Town: %s\n", town[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nSupplier not found.\n");
}

void searchSupplierName()
{
    char searchName[100];
    int found = 0;
    int i;

    printf("\nEnter Supplier Name: ");
    scanf(" %99[^\n]", searchName);

    for(i = 0; i < supplierCount; i++)
    {
        if(strcmp(supplierName[i], searchName) == 0)
        {
            printf("\nSupplier found!\n");
            printf("Supplier ID: %s\n", supplierID[i]);
            printf("Supplier Name: %s\n", supplierName[i]);
            printf("Email: %s\n", email[i]);
            printf("Telephone Number: %s\n", telephoneNumber[i]);
            printf("Town: %s\n", town[i]);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nSupplier not found.\n");
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
        printf("%d. %s - %s\n",
               i + 1,
               supplierName[i],
               town[i]);
    }
}

void assetManagement()
{
    int choice;

    do
    {
        printf("\n===== MUNICIPAL ASSET REGISTER =====\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        printf("3. Search Asset\n");
        printf("4. Search Department\n");
        printf("5. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            addAsset();
        else if(choice == 2)
            displayAssets();
        else if(choice == 3)
            searchAsset();
        else if(choice == 4)
            searchDepartment();
        else if(choice == 5)
            printf("\nReturning to main menu...\n");
        else
            printf("\nInvalid choice. Please try again.\n");

    } while(choice != 5);
}

void addAsset()
{
    int i;
    float purchase;

    if(assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full.\n");
        return;
    }

    printf("\n===== ADD ASSET =====\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assetID[assetCount]);
    getchar();

    do
    {
        printf("Enter Name: ");
        fgets(assetName[assetCount], 50, stdin);

        if(validateName(assetName[assetCount]) == 0)
            printf("Name cannot be empty. Please try again.\n");

    } while(validateName(assetName[assetCount]) == 0);

    i = 0;

    while(assetName[assetCount][i] != '\0')
    {
        if(assetName[assetCount][i] == '\n')
        {
            assetName[assetCount][i] = '\0';
            break;
        }

        i++;
    }

    printf("Enter Type (Vehicles, Computers, Buildings, Equipment, Office furniture): ");
    fgets(assetType[assetCount], 50, stdin);

    i = 0;

    while(assetType[assetCount][i] != '\0')
    {
        if(assetType[assetCount][i] == '\n')
        {
            assetType[assetCount][i] = '\0';
            break;
        }

        i++;
    }

    do
    {
        printf("Enter Purchase Value: ");
        scanf("%f", &purchase);

        if(validateAmount(purchase) == 0)
            printf("Purchase value cannot be negative.\n");

    } while(validateAmount(purchase) == 0);

    assetPurchaseValue[assetCount] = purchase;

    getchar();

    printf("Enter Department: ");
    fgets(assetDepartment[assetCount], 50, stdin);

    i = 0;

    while(assetDepartment[assetCount][i] != '\0')
    {
        if(assetDepartment[assetCount][i] == '\n')
        {
            assetDepartment[assetCount][i] = '\0';
            break;
        }

        i++;
    }

    printf("Enter Condition: ");
    fgets(assetCondition[assetCount], 50, stdin);

    i = 0;

    while(assetCondition[assetCount][i] != '\0')
    {
        if(assetCondition[assetCount][i] == '\n')
        {
            assetCondition[assetCount][i] = '\0';
            break;
        }

        i++;
    }

    assetCount++;

    printf("\nAsset added successfully!\n");
}

void displayAssets()
{
    int i;

    if(assetCount == 0)
    {
        printf("\nNo assets available.\n");
    }
    else
    {
        printf("\n===== ALL ASSETS =====\n");

        for(i = 0; i < assetCount; i++)
        {
            printf("\nAsset %d\n", i + 1);
            printf("Asset ID: %d\n", assetID[i]);
            printf("Name: %s\n", assetName[i]);
            printf("Type: %s\n", assetType[i]);
            printf("Purchase Value: N$%.2f\n", assetPurchaseValue[i]);
            printf("Department: %s\n", assetDepartment[i]);
            printf("Condition: %s\n", assetCondition[i]);
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

    for(i = 0; i < assetCount; i++)
    {
        if(assetID[i] == id)
        {
            printf("\nAsset found!\n");
            printf("Asset ID: %d\n", assetID[i]);
            printf("Name: %s\n", assetName[i]);
            printf("Type: %s\n", assetType[i]);
            printf("Purchase Value: N$%.2f\n", assetPurchaseValue[i]);
            printf("Department: %s\n", assetDepartment[i]);
            printf("Condition: %s\n", assetCondition[i]);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nAsset not found.\n");
}

void searchDepartment()
{
    char searchDept[50];
    int i, j;
    int found = 0;
    int match;

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

    for(i = 0; i < assetCount; i++)
    {
        match = 1;

        for(j = 0;
             searchDept[j] != '\0' || assetDepartment[i][j] != '\0';
             j++)
        {
            if(searchDept[j] != assetDepartment[i][j])
            {
                match = 0;
                break;
            }
        }

        if(match == 1)
        {
            if(found == 0)
                printf("\n===== ASSETS IN DEPARTMENT =====\n");

            printf("\nAsset ID: %d\n", assetID[i]);
            printf("Name: %s\n", assetName[i]);
            printf("Type: %s\n", assetType[i]);
            printf("Purchase Value: N$%.2f\n", assetPurchaseValue[i]);
            printf("Department: %s\n", assetDepartment[i]);
            printf("Condition: %s\n", assetCondition[i]);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo assets found in that department.\n");
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
        printf("%d. %s - N$%.2f\n",
               i + 1,
               assetName[i],
               assetPurchaseValue[i]);
    }
}

void reportManagement()
{
    int choice;

    do
    {
        printf("\n===== REPORTS =====\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Full System Report\n");
        printf("6. Back to Main Menu\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            employeeReport();
        else if(choice == 2)
            budgetReport();
        else if(choice == 3)
            supplierReport();
        else if(choice == 4)
            assetReport();
        else if(choice == 5)
            fullSystemReport();
        else if(choice == 6)
            printf("\nReturning to main menu...\n");
        else
            printf("\nInvalid choice. Please try again.\n");

    } while(choice != 6);
}

void fullSystemReport()
{
    float totalBudget = 0;
    float totalExpenditure = 0;
    float totalAssetValue = 0;
    float totalSalary = 0;

    int i;

    for(i = 0; i < budgetCount; i++)
    {
        totalBudget = totalBudget + allocatedBudget[i];
        totalExpenditure = totalExpenditure + expenditure[i];
    }

    for(i = 0; i < assetCount; i++)
    {
        totalAssetValue = totalAssetValue + assetPurchaseValue[i];
    }

    for(i = 0; i < employeeCount; i++)
    {
        totalSalary = totalSalary +
                      basicSalary[i] +
                      housingAllowance[i] +
                      transportAllowance[i] +
                      otherAllowance[i];
    }

    printf("\n===== FULL SYSTEM REPORT =====\n");

    printf("\nEMPLOYEES\n");
    printf("Total Employees: %d\n", employeeCount);
    printf("Total Gross Salaries: N$%.2f\n", totalSalary);

    printf("\nBUDGETS\n");
    printf("Total Budgets: %d\n", budgetCount);
    printf("Total Allocated Budget: N$%.2f\n", totalBudget);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Total Budget Balance: N$%.2f\n",
           totalBudget - totalExpenditure);

    printf("\nSUPPLIERS\n");
    printf("Total Suppliers: %d\n", supplierCount);

    printf("\nASSETS\n");
    printf("Total Assets: %d\n", assetCount);
    printf("Total Asset Value: N$%.2f\n", totalAssetValue);

    printf("\n===== END OF REPORT =====\n");
}

void exitProgram()
{
    printf("\nGoodbye!\n");
}

int main()
{
    int choice;

    do
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(validateChoice(choice) == 0)
        {
            printf("\nInvalid choice. Please enter 1-6.\n");
        }
        else
        {
            switch(choice)
            {
                case 1:
                    employeeManagement();
                    break;

                case 2:
                    budgetManagement();
                    break;

                case 3:
                    supplierManagement();
                    break;

                case 4:
                    assetManagement();
                    break;

                case 5:
                    reportManagement();
                    break;

                case 6:
                    exitProgram();
                    break;
            }
        }

    } while(choice != 6);

    return 0;
}
