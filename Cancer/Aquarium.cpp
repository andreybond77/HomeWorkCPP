#include "Aquarium.h"
#include"Cancer.h"

Aquarium::Aquarium(int CountCancers)
{
	this->uniqId = uniqId;
	this->CountCancers = CountCancers;
	
}

void Aquarium::updateCancers()
{
	string fileName = to_string(uniqId) + ".csv";
	vector<string> cancersString = FileManager::readFile(fileName);
	cancers.clear();
	for (auto el : cancersString) {
		cancers.push_back(Cancer(el));
	}
}

void Aquarium::addCancer(Cancer cancer)
{
	if (cancers.size() < maxCountCancers)
		cancers.push_back(cancer);
}

void Aquarium::delCancers(int id)
{
}

void Aquarium::showInfo()
{
	cout  << CountCancers<<" pieces"<< endl;
	for (auto el : cancers) {
		cout << el.toString()<< endl;
	}
}

void Aquarium::save()
{
	 vector<string> strings;
	for (auto el : cancers) {
		 strings.push_back(el.toString());
	}
	 string fileName = to_string(uniqId) + ".csv";
	 FileManager::writeFile(fileName, strings);
}
int Aquarium::id = 1;