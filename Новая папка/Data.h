#pragma once
#include <iostream>
#include "Lines.h"
#include <string>
using namespace std;
class Data
{
private:
	string year;
	string month;
	string day;
	string hour;
	string minute;
	string second;
	int* marks;
	int countMarks;
	
public:
	Data(Lines line);
	void showInfo();
	
	

};

