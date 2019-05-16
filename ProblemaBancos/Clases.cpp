#include <iostream>
#include <cstdlib>
#include "Estructuras.cpp"

using namespace std;

//////////////////////////////
class cola{
    cliente *principio, *Final;
    int cuantos;
    int cuantosmax;

    public:
    cola();
    ~cola();
    void agregar(int a, int b);
    void sacar();
    int Cuantos();
    int ColaMax();
    int regresarTiempoLlegada();
    int regresarTiempoCajera();
    int regresarTiempoFila();
    int regresarLlegadaCaja();
    int regresarTiempoSalida();
    void EstablecerTiempoFila(int a);
    void EstablecerLlegadaCaja(int a);
    void EstablecerTiempoSalida(int a);
};
/////////////////////////////
