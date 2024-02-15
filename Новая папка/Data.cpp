#include "Data.h"


Data::Data(Lines line) {
	string* array = line.getArray();
	year = array[0];

	month = array[1];
	day = array[2];
	hour = array[3];
	minute = array[4];
	second = array[5];
	Lines marksLine(array[5], ',');
	marks = new int[marksLine.getCountString()];
	string* marksStr = marksLine.getArray();
	for (int i = 0; i < marksLine.getCountString(); i++) {
		marks[i] = stoi(marksStr[i]);
	}
	countMarks = marksLine.getCountString();

}

void Data::showInfo()
{
	cout << year << " : " <<
		month << " " <<
		day << " " <<
		hour << " : " <<
		minute << " " <<
		second << " "  ;
		
	for (int i = 0; i < countMarks; i++) {
		cout << marks[i] << " ";
	}
	cout << endl;
}