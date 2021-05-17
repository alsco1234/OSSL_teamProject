#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include "class.h"

vector<string> split(string str, char delimiter);

void saveData(Clothes *c); //데이터 저장
int loadData(Clothes *c); //데이터 읽어오기

int searchName(Clothes *c, int count);
int searchPrice(Clothes *c, int count);
int searchSize(Clothes *c, int count);
int searchNum_stars(Clothes *c, int count);
