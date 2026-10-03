#ifndef FUNCTION_H
#define FUNCTION_H

#define MAX_SUPPLIERS 100

extern char supplierID[MAX_SUPPLIERS][30];
extern char supplierName[MAX_SUPPLIERS][100];
extern char email[MAX_SUPPLIERS][100];
extern char telephoneNumber[MAX_SUPPLIERS][20];
extern char town[MAX_SUPPLIERS][50];

extern int supplierCount;

void supplierMenu();
void addSupplier();
void displaySuppliers();
void searchSupplierID();
void searchSupplierName();

#endif