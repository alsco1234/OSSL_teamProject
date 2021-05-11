#include <iostream>
#include <cstring>
#include "class.h"

using namespace std;

int menu();

Clothes createClothes();

void readClothes(Clothes *c);

void listClothes(Clothes *c, int count);

int updateClothes(Clothes *c);

int deleteClothes(Product *p);

int category();