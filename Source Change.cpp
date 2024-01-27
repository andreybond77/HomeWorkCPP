#include <iostream>
#include <string>
using namespace std;


class Ñonvector {
private:
    double sum ,a;
    double rub_dol=0.011171;
    double rub_eur=0.010299;
    double dol_rub=89.52;
    double dol_eur=0.921946;
    double eur_rub=97.09;
    double eur_dol=1.08;
    
public:
  
    void Rub_dol(double a )
    {
        this->rub_dol = rub_dol;
          a*=rub_dol ;
          cout << "Summa dol " << ":" << a << endl;
    }
    void Rub_eur(double a)
    {
        this->rub_eur = rub_eur;
        a*=rub_eur ;
        cout << "Summa eur" << ":" << a << endl;
    }
    void Dol_rub(double a)
    {
        this->dol_rub = dol_rub;
       a*= dol_rub ;
       cout << "Summa rub" << ":" << a << endl;
    }
    void Dol_eur(double a)
    {
        this->dol_eur = dol_eur;
       a*= dol_eur ;
       cout << "Summa eur" << ":" << a << endl;
    }
    void Eur_rub(double a)
    {
        this->eur_rub = eur_rub;
        a*=eur_rub ;
        cout << "Summa rub" << ":" << a << endl;
    }
    void Eur_dol(double a)
    {
        this->eur_dol = eur_dol;
        a*=eur_dol ;
        cout << "Summa dol" << ":" << a << endl;
    }
   
  
};

int main() {
    Ñonvector st;
    int m;
    double a;
    char c = 'y';
    do {

        cout << "Select an action" << endl;
        cout << "1:Change rubles to dollars ." << endl;
        cout << "2:Change rubles to euros." << endl;
        cout << "3:Change dollars to rubles." << endl;
        cout << "4:Change dollars to euros." << endl;
        cout << "5:Change euros to rubles." << endl;
        cout << "6:Change euros to dollars." << endl;
        cin >> m;
       
        switch (m)
        {
        case 1:

            cout << "quantity_rub: ";
            cin >> a ;
            st.Rub_dol(a);
            
            break;
        case 2:
            cout << "quantity_rub: ";
            cin >> a;
            st.Rub_eur(a);
           
            break;
        case 3:
            cout << "quantity_dol: ";
            cin >> a;
            st.Dol_rub(a);
            
            break;
        case 4:

            cout << "quantity_dol: ";
            cin >> a;
            st.Dol_eur(a);
           
            break;
        case 5:
            cout << "quantity_eur: ";
            cin >> a;
            st.Eur_rub(a);
           
            break;
        case 6:
            cout << "quantity_eur: ";
            cin >> a;
            st.Eur_dol(a);
           
            break;




        default:
            cout << "Incorrect input" << endl;
        }
        cout << "Continue the action?(y/n)" << endl;
        cin >> c;
    } while (c != 'n');


    return 0;

}
