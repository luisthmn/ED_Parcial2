#include <iostream>
#include <cstdlib>
#include "Clases.cpp"

using namespace std;

//////////////////////
cola::cola(){
    principio = NULL;
    Final = NULL;
    cuantos = 0;
    cuantosmax = 0;
}
///////////////////////
cola::~cola(){
    cliente *p;

    while(principio){
        p = principio;
        principio = p -> siguiente;
    }
    return;
}
//////////////////////
void cola::agregar(int a, int b){
    cliente *p;

    p = new cliente;
    p -> tiempollegada = a;
    p -> tiempoCaja = b;

    if(principio != NULL){
        p->siguiente = NULL;
        Final->siguiente = p;
        Final = p;
    }
    else{
        p-> siguiente = NULL;
        principio = p;
        Final = p;
    }
    cuantos++;
    if(cuantos > cuantosmax) cuantosmax = cuantos;
}
///////////////////////
void cola::sacar(){
    cliente *p;

    if(principio != NULL){
        p = principio;
        principio = p -> siguiente;
        delete p;
        cuantos--;
    }
    else{
        Final = NULL;
        return;
    }
    return;
}
//////////////////////////
int cola::Cuantos(){
    return(cuantos);
}
///////////////////////////

int cola::ColaMax(){
    return (cuantosmax);
}
///////////////////////////
int cola::regresarTiempoLlegada(){
    cliente *p;

    p = principio;
    return p -> tiempollegada;
}
///////////////////////////
int cola::regresarTiempoCajera(){
    cliente *p;

    p = principio;
    return p -> tiempoCaja;
}
/////////////////////////////
void cola::EstablecerTiempoFila(int a){
    cliente *p;
    p = principio;
    p ->tiempofila = a;
}
////////////////////////////
int cola::regresarTiempoFila(){
    cliente *p;
    p = principio;
    return p->tiempofila;
}
///////////////////////////////////
void cola::EstablecerLlegadaCaja(int a){
    cliente *p;
    p = principio;
    p ->horaAtencion = a;
}
///////////////////////////////
int cola::regresarLlegadaCaja(){
    cliente *p;

    p = principio;
    return p ->horaAtencion;
}
////////////////////////////////////
void cola::EstablecerTiempoSalida(int a){
    cliente *p;
    p = principio;
    p ->tiempoSalida = a;
}
////////////////////////////////
int cola::regresarTiempoSalida(){
    cliente *p;
    p = principio;
    return p ->tiempoSalida;
}
////////////////////////////////////
