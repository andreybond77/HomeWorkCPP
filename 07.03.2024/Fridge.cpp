#include "Fridge.h"
#include "Product.h"
#include "Shelf.h"
#include <vector>
using namespace std;
Fridge::Fridge(int maxCount)
{
	this->maxCount = maxCount;
	


}
void Fridge::addShelfs(Shelf* shelf)
{
	if (countShelfs < maxCount) {
		int count = 0;
		bool flag = true;
		for (auto el : shelfs) {
			if (el == nullptr) {
				flag = false;
				shelfs[count] = shelf;
				break;
			}
			count++;
		}
		if (flag) shelfs.push_back(shelf);
		countShelfs++;
	}
}
void Fridge::showAllShelfs()
{
	cout << "Fridge" << endl;
	for (auto el : shelfs) {
		if (el != nullptr) {
			el->getInfoShelf();
		}
		else cout << "----" << endl;
	}

}
Shelf* Fridge::getShelfByIndex(int index)
{
	Shelf* buf = *(shelfs.begin() + index);
	shelfs[index] = nullptr;
	countShelfs--;
	return buf;
}

