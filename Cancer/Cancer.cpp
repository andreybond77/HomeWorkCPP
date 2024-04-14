#include "Cancer.h"

Cancer::Cancer(int id, int weight,int price)
{
	this->id = id;
	this->weight = weight;
	this->price = price;
}

Cancer::Cancer(string str)
{
	vector<string> buf = FileManager::split(str, ';');
	this->id = stoi(buf[0]);
	this->weight = stoi (buf[1]);
	this->price = stoi( buf[2]);
}

string Cancer::toString()
{
	return  to_string(id) + ";" + to_string(weight) + "gr  :" + to_string(price) + "rub  ;";;
}
