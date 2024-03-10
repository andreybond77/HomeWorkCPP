#include "Shelf.h"
#include "Product.h"
#include "Fish.h"
using namespace std;
Shelf::Shelf(int maxCount)
{
	this->maxCount = maxCount;
}

void Shelf::addProduct(Product* product) {
	if (countProducts < maxCount) {
		int count = 0;
		bool flag = true;
		for (auto el : products) {
			if (el == nullptr) {
				flag = false;
				products[count] = product;
				break;
			}
			count++;
		}
		if (flag) products.push_back(product);
		countProducts++;
	}

}

void Shelf::showAllProducts()
{
	for (auto el : products) {
		if (el != nullptr) {
			el->getInfo();
		}
		else cout << "----" << endl;
	}
}

Product* Shelf::getProductByIndex(int index)
{
	Product* buf = *(products.begin() + index);
	products[index] = nullptr;
	countProducts--;
	return buf;
}

Shelf::Shelf(std::string name, std::string pos, int pos1)
{
	this->name = name;
	this->pos = pos;
	this->pos1 = pos1;
}
void Shelf::getInfoShelf()
{
	
	std::cout <<"shelf :" << pos1 << " : " << pos << " : " << name << std::endl;
}