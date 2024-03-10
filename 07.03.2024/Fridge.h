#pragma once
#include "Shelf.h"
#include "Product.h"
#include <vector>
class Fridge
{
	vector<Shelf*> shelfs;
	int maxCount;
	int countShelfs = 0;
public:
	Fridge(int maxCount);
	void addShelfs(Shelf* shelf);
	void showAllShelfs();
	Shelf* getShelfByIndex(int index);
};




	
	