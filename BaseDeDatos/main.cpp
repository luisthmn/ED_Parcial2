#include <cstdlib>
#include <iostream>
#include "Clases.cpp"

using namespace std;

int main()
{

    cout << "Este programa crea una base de datos de nombres ordenados alfabeticamente por nombre o por apellido" << endl;
    BD BD;

    BD.agregar(1, 2);
    BD.agregar(2, 4);
    BD.agregar(4, 6);
    BD.agregar(32, 12);
    BD.pintar1();
    cout << endl;
    BD.pintar2();
    cout << endl;
    system("pause");
    return 0;
}
