


#include <iostream>
#include <vector>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)

#include "Product.h"
#include "Milk.h"
#include "Fish.h"
#include "Meet.h"
#include "Shelf.h"
#include"Fridge.h"
string names[] = { "name1","name2","name3" };
string pos[] = { "milk","fish","meet", };
int pos1 = 1;
int main()
{
   // srand(time(NULL));
    Shelf shelf1(7);
    for (int i = 0; i < 7; i++) {
    


        shelf1.addProduct(new Milk(names[random(0, 2)]));
    }


    for (int i = 0; i < 3; i++) {
        shelf1.addProduct(new Meet(names[random(0, 2)]));
    }
    for (int i = 0; i < 2; i++) {
        shelf1.addProduct(new Fish(names[random(0, 2)]));
    }

    shelf1.showAllProducts();
    cout << endl;
    shelf1.getProductByIndex(2)->getInfo();
    cout << "after" << endl;
    shelf1.showAllProducts();
   shelf1.addProduct(new Fish(names[1]));
    cout << "after" << endl;
    shelf1.showAllProducts();

    cout << "after" << endl;
    Fridge fridge1(7);
    for (int i = 0; i < 7; i++) {



        fridge1.addShelfs(new Shelf(names[random(0, 2)],pos[random(0, 2)], pos1++));

    }
    fridge1.showAllShelfs();
    cout << "after" << endl;
   // fridge1.getShelfByIndex(2)->getInfoShelf();
    fridge1.getShelfByIndex(4);
    cout << "after" << endl;
    fridge1.showAllShelfs();
}

