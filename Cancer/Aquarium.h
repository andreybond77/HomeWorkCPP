#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cancer.h"
#include "FileManager.h"
using namespace std;
class Aquarium
{
	static int id;
	int uniqId;
	int maxCountCancers=1000;
	int CountCancers;
	vector<Cancer> cancers;
public:
	Aquarium(int CountCancers);
	void updateCancers();
	void addCancer(Cancer cancer);
	void delCancers(int id);
	void showInfo();
	void save();
};

