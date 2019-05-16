#include <cstdlib>
#include <iostream>
#include "Estructuras.cpp"

using namespace std;

//////////////////////////////////////////////
class datos{

    Caja1 *lugar_agregado;
    Caja1 *principio;
    int cuantos;

    public:
    datos();
    ~datos();
    void agregar(int a, int b);
    void crear();
    Caja1* lugarAgregado();
    void limpiar();
};
//////////////////////////////////////////////
class indice1{
    Caja1 *principio, *anterior;
    int cuantos;
    enum _encontrado {SI, NO};
    enum _donde {VACIO, PRINCIPIO, ENMEDIO, FINAL};
        enum _encontrado encontrado;
        enum _donde donde;

    public:
    indice1();
    ~indice1();
    void buscar(Caja1 *p1);
    int agregar(Caja1 *p1);
    void limpiar();
    void crear();
    void pintar();
    int Cuantos();

};
//////////////////////////////////////////////
class indice2{

    Caja1 *principio, *anterior;
    int cuantos;
    enum _encontrado {SI, NO};
    enum _donde {VACIO, PRINCIPIO, ENMEDIO, FINAL};
        enum _encontrado encontrado;
        enum _donde donde;

    public:
    indice2();
    ~indice2();
    void buscar(Caja1 *p1);
    int agregar(Caja1 *p1);
    void limpiar();
    void crear();
    void pintar();
    int Cuantos();
};
//////////////////////////////////////////////
class BD{
    datos A;
    indice1 B;
    indice2 C;

    public:
    BD();
    ~BD();
    void agregar(int a, int b);
    void pintar1();
    void pintar2();

};
//////////////////////////////////////////////
