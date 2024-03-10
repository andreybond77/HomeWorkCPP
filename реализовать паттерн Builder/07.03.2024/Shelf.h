#pragma once
#include "Product.h"
#include <vector>
using namespace std;
class Shelf
{
	vector<Product*> products;
	int maxCount;
	int countProducts = 0;
protected:
	std::string name;
	std::string pos;
	int pos1;
public:
	Shelf(int maxCount);
	void addProduct(Product* product);
	void showAllProducts();
	Product* getProductByIndex(int index);
	Shelf(std::string name, std::string pos, int pos1);
	void getInfoShelf();
};

