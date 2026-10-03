
#include <stdio.h>
int main() {
char department[50];
float budget;
float expenditure;
float balance;

printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
printf("***** MUNICIPAL BUDGET MANAGEMENT *****\n");
printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");

printf("Enter name of Department: ");
scanf("%49s", department);

printf("Enter Allocated Department Budget: ");
scanf("%f", &budget);

printf("Enter Total Expenditure: ");
scanf("%f", &expenditure);

balance = budget - expenditure;
printf("\nBalance: %.2f\n", balance);


printf("\n^^^^^ DEPARTMENT BUDGET STATUS ^^^^^\n");

printf("Name of Department: %s\n", department);
printf("Allocated Department Budget: %.2f\n", budget);
printf("Total Expenditure: %.2f\n", expenditure);
printf("Balance: %.2f\n", balance);

if (expenditure <= budget) {
printf("Department is within Budget\n");
}
else
{
printf("Department is NOT within Budget!!\n");
}
return 0;
}

