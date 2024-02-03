#include <iostream>
#include <string>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)
const int countNames = 5;
const string models[] = { "Toyota", " Honda","Nissan","Mazda", "Mitsubishi" };
class Garag {
    int gos_num;
    string model;
    static int id;
    int uniqId;
    string name = "noname";
    int* marks = nullptr;
    int countMarks = 0;
    int number;
public:
   
    Garag(string name) {
        uniqId = id++;
        this->name = name;      
        this->model = models[random(0, countNames - 1)];
        this->gos_num = random(100, 999);
    }
    Garag() {
        model = models[random(0, countNames - 1)];
        gos_num = random(100, 999);
    }

    
    void addMark(int gos_num, string model) {
       
           


                int* buf = new int[countMarks + 1];
                for (int i = 0; i < countMarks; i++) {
                    buf[i] = marks[i];
                }
                buf[countMarks++] = gos_num;
                delete[]marks;
                marks = buf;
            
        
    }
    

    void removeMarkByIndex(int index){

        if (countMarks==0 || index < 0 || index > countMarks - 1) return;
        int* buf = new int[countMarks - 1];
        for (int i = 0; i < index; i++) {
            buf[i] = marks[i];
        }
        for (int i = index - 1; i < countMarks; i++) {
            buf[i - 1] = marks[i];
       }
        delete[]marks;
        marks = buf;
        countMarks--;
           
    }
    void addMarkByIndex(int index, int gos_num, string model) {
        cout <<toString() << gos_num << ", " << model << endl;
       /*
        
       // if (countMarks == 0 || index < 0 || index > countMarks + 1) return;/// Не могу понять почему не работает функция?
        int* buf = new int[countMarks + 1];
        for (int i = 0; i < index; i++) {
            buf[i] = marks[i];
        }
        buf[index] = gos_num, model;
        for (int i = index+1 ; i < countMarks; i++) {
            buf[i + 1] = marks[i];
        }
        delete[]marks;
        marks = buf;
        countMarks++;
       
       */
    }
    void changeMarkByIndex(int uniqId, int gos_num, string model) {
        marks[uniqId] =  gos_num, model;
    }
    string getModel() {
        model = models[random(0, countNames - 1)];
        return model;
    }

    string toString() {
        string marksStr = "";
       
       

               for (int i = 0; i < countMarks; i++) {
                   marksStr +=  to_string(marks[i]) + " " + getModel() + ",  ";
                }
              

             
        return "Num: " + to_string(uniqId) + ", Garag: "
            + name + ", car: " +  marksStr;
    }
    void showInfo() {
      
        for (int i = 0; i < 5; i++) {
            cout<< toString() << gos_num << " : " << model << endl;
        }

    }

};

int Garag::id = 1;



int main()
{
    srand(time(NULL));
     Garag st1("Autodoc.   ");
     Garag st2("Dolcar.    ");
     Garag st3("Colors-auto");
     Garag st4("Jabmotors  ");
     Garag st5("Cabby      ");

     for (int i = 0; i < 5; i++) 

         st1.addMark(random(100, 999), models[random(0, countNames - 1)]);

         cout << st1.toString() << endl;

         st1.removeMarkByIndex(0);
         cout << st1.toString() << endl;
         st1.addMarkByIndex( 0,333, "Lada");
        // cout << st1.toString() << endl;
     cout << endl;
     for (int i = 0; i < 5; i++)
        
         st2.addMark(random(100, 999), models[random(0, countNames - 1)]);
       
         cout << st2.toString() << endl;
        
     cout << endl;
     for (int i = 0; i < 5; i++)
         
         st3.addMark(random(100, 999), models[random(0, countNames - 1)]);
   
     cout << st3.toString() << endl;
    
     cout << endl;
     for (int i = 0; i < 5; i++)
         
         st4.addMark(random(100, 999), models[random(0, countNames - 1)]);
   
     cout << st4.toString() << endl;
   
     cout << endl;
     for (int i = 0; i < 5; i++)
        
         st5.addMark(random(100, 999), models[random(0, countNames - 1)]);
    
     cout << st5.toString() << endl;
    
}