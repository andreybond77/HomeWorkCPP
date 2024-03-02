
#include <iostream>
#include "Singleton.h"
#include "Builder.h"
#define random(a,b) a+rand()%(b+1-a)

#define SINGLETON
#define BUILDER
using namespace std;


int main()
{
    srand(time(NULL));

#ifdef SINGLETON

    Film* p1 = Film::getInstance("Bruce Willis");
    Film* p2 = Film::getInstance("Sylvester Stallone");
    p1->showInfo();
    cout << endl;
    p2->showInfo();
    cout << endl;
#endif // SINGLETON

#ifdef BUILDER
    HouseBuilder country_houseBuilder;
    HouseBuilder villaBuilder;
  

    HouseBuilder** builder = new HouseBuilder * [3] {new HouseBuilder, new HouseBuilder, new HouseBuilder};
    builder[0]->setType_of_building("Villa");
    builder[0]->setGarden("Park");
    builder[0]->setSwimming_pool("10000.l");
    builder[0]->setGarage("100. car");
    builder[0]->setBarbecue("Barbecue");

    builder[1]->setType_of_building("Country_house");
    builder[1]->setGarden("Garden");
    builder[1]->setBarbecue("Barbecue");

    builder[2]->setType_of_building("Flat");
    builder[2]->setGarage("1. car");
    House* houses = new House[10];
    for (int i = 0; i < 10; i++) {
        houses[i] = builder[random(0, 2)]->getResult();
    }

    for (int i = 0; i < 10; i++) {
        houses[i].show();
    }



    



#endif // BUILDER





}

