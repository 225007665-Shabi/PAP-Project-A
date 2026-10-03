#ifndef FUNCTION_H
#define FUNCTION_H

extern char employeeID[100][20];
extern char name[100][50];
extern char department[100][50];
extern float basicSalary[100];
extern float housingAllowance[100];
extern float transportAllowance[100];
extern float otherAllowance[100];
extern int count;

void addEmployee();
void displayEmployees();
void searchEmployee();
void calculateEmployeeSalary();
void employeeReport();

#endif