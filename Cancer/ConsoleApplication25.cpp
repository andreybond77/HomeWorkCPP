

#include <iostream>
using namespace std;
#include "Aquarium.h"
#include "FileManager.h"
#include"Cancer.h"
/*
Напишите программу для раковой фермы
Для данной фермы предусмотрите возможность
создания аквариумов, обновление
данных из файла и сохранение.
В каждом аквариуме будут находиться раки
по фиксированной цене за кг.
Информация об аквариумах и цене находится
в файле price.csv
уник id;макс кол-во раков;цена за кг;

В аквариуме находятся раки.
Информация о раках находится в файле .csv
Название файла формируется исходя из номера
аквариума.
Реализовать возможность добавление раков
в аквариум, удаление и перенос раков
из одного аквариума
в другой.
информация о раках выглядит так:
id рака; вес;
*/

int main()
{
    Cancer st1( 3, 500 ,450);
    Cancer st2(2, 600, 750);
    vector<string> cancers;
    cancers.push_back(st1.toString());
    cancers.push_back(st2.toString());
    FileManager::writeFile("group1.txt", cancers);
    vector<string> read = FileManager::readFile("group1.txt");
    vector<string> buf = FileManager::split(cancers[0], ';');
    for (auto el : buf) {
        cout << el << " : ";
    }
     Aquarium aquarium(300);
     aquarium.updateCancers();
     aquarium.showInfo();
     aquarium.addCancer(Cancer (st2));
     aquarium.showInfo();

}


