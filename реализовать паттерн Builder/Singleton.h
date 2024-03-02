#pragma once
using namespace std;

class Film {
private:
    string name;
    static Film* instance;
    Film(string name) {
        this->name = name;
    }
public:
    static Film* getInstance(string name) {
        if (instance == nullptr) {
            instance = new Film(name);
        }
        return instance;
    }
    void showInfo() {
        cout << this << " : " << name;
    }

};

Film* Film::instance = nullptr;