
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
        cout << "�����:  " << chisl << '/' << znamen << endl;
    }
    void div(int x)
    {
        znamen *= x;
        cout << "�����:  " << chisl << '/' << znamen << endl;

    }
    
    void sum(int x)
    {
        chisl += (x * znamen);
        cout << "�����:  " << chisl << '/' << znamen << endl;
    }
    void sub(int x)
    {
        chisl -= (x * znamen);
        cout << "�����:  " << chisl << '/' << znamen << endl;

    }
    void show()
    {
        cout << "������� ��������:  " << chisl << '/' << znamen << endl;
    }
    void show_1()
    {
        cout << "������� ��������:  " << 1 << '/' << 1 << endl;
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
        cout << "������� ���������:" << endl;
        cin >> a;
        cout << "������� �����������:" << endl;
        cin >> b;
        if (b == 0) {
            cout << "�� 0 ������ ������" << endl;
            goto enter;
        }
        



        Drob st;

        st.input(a, b);
        do {
            st.reduct(st.peredacha());
            st.show();
            cout << "�������� ��������" << endl;
            cout << "1:��������� � ����� �����" << endl;
            cout << "2:������ �� ����� �����" << endl;
            cout << "3:�������� ����� �� �����" << endl;
            cout << "4:��������� ����� �� �����" << endl;

            cin >> m;


            switch (m)
            {
            case 1:
                cout << "������� ��������� " << endl;
                cin >> a;
                st.sum(a);
                break;
            case 2:
                cout << "������� ����������" << endl;
                cin >> a;
                st.sub(a);
                break;
            case 3:
                cout << "������� ���������" << endl;
                cin >> a;
                st.mult(a);
                break;
            case 4:
                cout << "������� ��������" << endl;
                cin >> a;
                st.div(a);
                break;
            default:
                cout << "������������ ����" << endl;
            }
            cout << "���������� ��������?(y/n)" << endl;
            cin >> c;
        } while (c != 'n');
    enter: cout << "" << endl;
        return 0;
    
}