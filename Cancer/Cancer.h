#pragma once
#include <iostream>
#include <vector>
#include "FileManager.h"
using namespace std;

class Cancer
{
	int id;
	int weight;
	int price;
public:
	Cancer(int id, int weight,int price);
	Cancer(string str);
	string toString();
};

