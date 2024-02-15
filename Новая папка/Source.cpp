#include <iostream>
using namespace std;
#include "FileReader.h"
#include "Lines.h"
#include "Data.h"
#include <Windows.h>





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    FileReader fr;
    Lines lines = fr.read("data.xml");
    Lines line(lines.getArray()[0], ';');
    Data st(line);
    st.showInfo();


}