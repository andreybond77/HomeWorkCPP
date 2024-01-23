#include <iostream>
#include <string>
using namespace std;


class Car {
private:
    int price;
    string model;
    string colour;
    int engine_volume;

public:
    Car(int price, string model, string colour, int engine_volume) {
        this->price = price;
        this->model = model;
        this->colour = colour;
        this->engine_volume = engine_volume;

    }

    void setPrice(int price) {
        this->price = price;
    }
    void setModel(string model) {
        this->model = model;
    }
    void setColor(string colour) {
        this->colour = colour;
    }
    void setEngine_volume(int engine_volume) {
        this->engine_volume = engine_volume;
    }

    int getPrice() {
        return price;
    }
    string getModel() {
        return model;
    }
    string getColor() {
        return colour;
    }
    int getEngine_volume() {
        return engine_volume;
    }

    void show() {
        cout << price << ":" << model << ":" << colour << ":" << engine_volume << endl;
    }
};




int main() {
    setlocale(LC_ALL, "ru");
    int m;
    char c = 'y';
    Car* car = new Car[4]{ Car(3750000, "Toyota_Camry","Black", 2500),
    Car(3950000, "Mitsubishi_L200","White", 2400),
    Car(1050000, "Nissan_Almera","Gray", 2500),
    Car(820000, "Subaru_Legacy","Blue", 2000) };

    do {

        cout << "Выберите действие" << endl;
        cout << "1: Выбрать автомобиль по цене." << endl;
        cout << "2: Выбрать автомобиль по модели." << endl;
        cout << "3: Выбрать автомобиль по цвету." << endl;
        cout << "4: Выбрать автомобиль по объему двигателя." << endl;

        cin >> m;
        int my_budget = 0;
        string my_model;
        string my_colour;
        int my_volume = 0;
        switch (m)
        {
        case 1:

            cout << "Ваш бюджет: ";
            cin >> my_budget;
            for (int i = 0;i < 4;i++) {
                if (my_budget >= car[i].getPrice()) {
                    car[i].show();
                }
            }
            break;
        case 2:


            cout << "Модель авто: ";
            cin >> my_model;
            for (int i = 0;i < 4;i++) {

                if (my_model == car[i].getModel()) {
                    car[i].show();
                }

            }
            break;
        case 3:
            cout << "Цвет авто: ";
            cin >> my_colour;
            for (int i = 0;i < 4;i++) {

                if (my_colour == car[i].getColor()) {
                    car[i].show();
                }

            
            }
            break;
        case 4:

            
            cout << "Ваш объем двигателя: ";
            cin >> my_volume;
            for (int i = 0;i < 4;i++) {
                if (my_volume >= car[i].getEngine_volume()) {
                    car[i].show();
                }
            }
             break;
        default:
            cout << "Некорректный ввод" << endl;
        }
        cout << "Продолжить действие?(y/n)" << endl;
        cin >> c;
    } while (c != 'n');
enter: cout << "" << endl;



    system("pause");
    return 0;
}