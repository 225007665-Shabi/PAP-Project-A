#ifndef ASSETS_H
#define ASSETS_H

#include <stdio.h>

#define MAX_ASSETS 100

extern int assetID[MAX_ASSETS];
extern char name[MAX_ASSETS][50];
extern char type[MAX_ASSETS][50];
extern float purchaseValue[MAX_ASSETS];
extern char department[MAX_ASSETS][50];
extern char condition[MAX_ASSETS][50];
extern int count;

void addAsset();
void displayAssets();
void searchAsset();
void searchDepartment();

#endif