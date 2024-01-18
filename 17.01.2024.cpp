
#include <iostream>
#include <string>
using namespace std;

class Drob {
private:
    int chisl;
    int znamen;
    
    int NOD(int x, int y)
    {
        if (y == 0) return x;
        return NOD(y, x % y);
    }
public:
    
    void input(int c, int z)
    {
        chisl = c;
        znamen = z;
    }
    void mult(int x)
    {
        chisl *= x;
        cout << "дробь:  " << chisl << '/' << znamen << endl;
    }
    void div(int x)
    {
        znamen *= x;
        cout << "дробь:  " << chisl << '/' << znamen << endl;

    }
    
    void sum(int x)
    {
        chisl += (x * znamen);
        cout << "дробь:  " << chisl << '/' << znamen << endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        cout << "дробь:  " << chisl << '/' << znamen << endl;

    }
    void show()
    {
        cout << "Текущее значение:  " << chisl << '/' << znamen << endl;
    }
    void show_1()
    {
        cout << "Текущее значение:  " << 1 << '/' << 1 << endl;
    }
    
    int peredacha()
    {
        return NOD(chisl, znamen);
    }
    void reduct(int x)
    {
        chisl /= x;
        znamen /= x;
    }

};



    int main() {
        setlocale(LC_ALL, "ru");
        int a, b, m;
        char c = 'y';
        cout << "Введите числитель:" << endl;
        cin >> a;
        cout << "Введите знаменатель:" << endl;
        cin >> b;
        if (b == 0) {
            cout << "На 0 делить нельзя" << endl;
            goto enter;
        }
        



        Drob st;

        st.input(a, b);
        do {
            st.reduct(st.peredacha());
            st.show();
            cout << "Выберите действие" << endl;
            cout << "1:Прибавить к дроби число" << endl;
            cout << "2:Отнять от дроби число" << endl;
            cout << "3:Умножить дробь на число" << endl;
            cout << "4:Разделить дробь на число" << endl;

            cin >> m;


            switch (m)
            {
            case 1:
                cout << "Введите слогаемое " << endl;
                cin >> a;
                st.sum(a);
                break;
            case 2:
                cout << "Введите вычитаемое" << endl;
                cin >> a;
                st.sub(a);
                break;
            case 3:
                cout << "Введите множитель" << endl;
                cin >> a;
                st.mult(a);
                break;
            case 4:
                cout << "Введите делитель" << endl;
                cin >> a;
                st.div(a);
                break;
            default:
                cout << "Некорректный ввод" << endl;
            }
            cout << "Продолжить действие?(y/n)" << endl;
            cin >> c;
        } while (c != 'n');
    enter: cout << "" << endl;
        return 0;
    
}