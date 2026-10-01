#include <stdio.h>

char employeeID[100][20];
char name[100][50];
char department[100][50];
float basicSalary[100];
float housingAllowance[100];
float transportAllowance[100];
float otherAllowance[100];
int count = 0;

void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateEmployeeSalary();
void employeeReport();

int main()
{
    int choice;

    do
    {
        printf("\n===== EMPLOYEE MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Employee Salary\n");
        printf("5. Employee Report\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            addEmployee();
        }
        else if(choice == 2)
        {
            displayEmployees();
        }
        else if(choice == 3)
        {
            searchEmployee();
        }
        else if(choice == 4)
        {
            calculateEmployeeSalary();
        }
        else if(choice == 5)
        {
            employeeReport();
        }
        else if(choice == 6)
        {
            printf("\nProgram ended.\n");
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }

    } while(choice != 6);

    return 0;
}

void addEmployee()
{
    int i;

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%19s", employeeID[count]);

    getchar();

    printf("Enter Name: ");
    fgets(name[count], 50, stdin);

    i = 0;

    while(name[count][i] != '\0')
    {
        if(name[count][i] == '\n')
        {
            name[count][i] = '\0';
            break;
        }

        i++;
    }

    printf("Enter Department: ");
    fgets(department[count], 50, stdin);

    i = 0;

    while(department[count][i] != '\0')
    {
        if(department[count][i] == '\n')
        {
            department[count][i] = '\0';
            break;
        }

        i++;
    }

    printf("Enter Basic Salary: ");
    scanf("%f", &basicSalary[count]);

    printf("Enter Housing Allowance: ");
    scanf("%f", &housingAllowance[count]);

    printf("Enter Transport Allowance: ");
    scanf("%f", &transportAllowance[count]);

    printf("Enter Other Allowance: ");
    scanf("%f", &otherAllowance[count]);

    count = count + 1;

    printf("\nEmployee added successfully!\n");
}

void displayEmployees()
{
    int i;

    if(count == 0)
    {
        printf("\nNo employees available.\n");
    }
    else
    {
        printf("\n===== ALL EMPLOYEES =====\n");

        for(i = 0; i < count; i++)
        {
            printf("\nEmployee %d\n", i + 1);
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Name: %s\n", name[i]);
            printf("Department: %s\n", department[i]);

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
    int i;
    int found = 0;

    printf("\nEnter Employee ID to search: ");
    scanf("%19s", id);

    for(i = 0; i < count; i++)
    {
        int j = 0;
        int same = 1;

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
            printf("Name: %s\n", name[i]);
            printf("Department: %s\n", department[i]);
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
    {
        printf("\nEmployee not found.\n");
    }
}

void calculateEmployeeSalary()
{
    char id[20];
    int i;
    int found = 0;
    float grossSalary;

    printf("\nEnter Employee ID: ");
    scanf("%19s", id);

    for(i = 0; i < count; i++)
    {
        int j = 0;
        int same = 1;

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
            grossSalary = basicSalary[i]
                        + housingAllowance[i]
                        + transportAllowance[i]
                        + otherAllowance[i];

            printf("\n===== SALARY INFORMATION =====\n");
            printf("Employee ID: %s\n", employeeID[i]);
            printf("Name: %s\n", name[i]);
            printf("Basic Salary: N$%.2f\n", basicSalary[i]);
            printf("Housing Allowance: N$%.2f\n", housingAllowance[i]);
            printf("Transport Allowance: N$%.2f\n", transportAllowance[i]);
            printf("Other Allowance: N$%.2f\n", otherAllowance[i]);
            printf("Gross Salary: N$%.2f\n", grossSalary);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nEmployee not found.\n");
    }
}

void employeeReport()
{
    int i;
    float totalSalary = 0;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    if(count == 0)
    {
        printf("\nNo employees available.\n");
    }
    else
    {
        highestSalary = basicSalary[0]
                      + housingAllowance[0]
                      + transportAllowance[0]
                      + otherAllowance[0];

        lowestSalary = highestSalary;

        for(i = 0; i < count; i++)
        {
            float salary;

            salary = basicSalary[i]
                   + housingAllowance[i]
                   + transportAllowance[i]
                   + otherAllowance[i];

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

        averageSalary = totalSalary / count;

        printf("\n===== EMPLOYEE REPORT =====\n");
        printf("Total Employees: %d\n", count);
        printf("Average Salary: N$%.2f\n", averageSalary);
        printf("Highest Salary: N$%.2f\n", highestSalary);
        printf("Lowest Salary: N$%.2f\n", lowestSalary);
    }
}
