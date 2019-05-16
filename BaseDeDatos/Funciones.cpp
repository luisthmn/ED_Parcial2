#include <cstdlib>
#include <iostream>
#include "Clases.cpp"

using namespace std;

///////////////////////////
///////////////////////////
///////////////////////////
//      DATOS

void datos::crear(){
    lugar_agregado = NULL;
    principio = NULL;
    cuantos = 0;
}
//////////////////////////////
datos::datos(){
    crear();
}
////////////////////////////
void datos::limpiar(){
    Caja1 *p;

    p = principio;
    while(p){
        delete p;
        p = p -> siguiente;
    }
}
/////////////////////////////
datos::~datos(){
    limpiar();
}
///////////////////////////////
void datos::agregar(int a, int b){
    Caja1 *p;

    p = new Caja1;
    p -> nombre = a;
    p -> apellido = b;

    if(principio == NULL){
        p -> siguiente = NULL;
        principio = p;
    }
    else{
        p -> siguiente = principio;
        principio = p;
    }
    cuantos++;
    return;
}
//////////////////////////////
Caja1 * datos::lugarAgregado(){
    Caja1 *p;
    if(principio != NULL){
        p = principio;
        principio = p->siguiente;
        lugar_agregado = p;
        return p;
    }
    else{
        return NULL;
    }
}
////////////////////////////////



/////////////////////////
/////////////////////////
/////////////////////////
//     INDICE 1

////////////////////////////
void indice1::crear(){
    principio = NULL;
    anterior = NULL;
    cuantos = 0;
}
////////////////////////////
indice1::indice1(){
    crear();
}
////////////////////////////
void indice1::limpiar(){
    Caja1 *p;
    p = new Caja1;

    while(p){
        p = principio;
        delete p;
        p = p -> siguiente;
    }
}
////////////////////////////
indice1::~indice1(){
    limpiar();
}
/////////////////////////////
void indice1::buscar(Caja1 *p1){
    Caja1 *p;
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }
    p = principio;
    while(p){
        if(p->nombre == p1 -> nombre && p->apellido == p1 -> apellido){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else if(p->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
        }
        else if(p->nombre < p1 -> nombre || (p ->nombre == p1 -> nombre && p->apellido < p1 ->apellido)){
            encontrado = NO;
            anterior = p;
            p = p->siguiente;
        }
        else if(p->nombre > p1 -> nombre || (p ->nombre == p1 -> nombre && p->apellido > p1 ->apellido)){
            encontrado = NO;
            if(principio == p){
                donde = PRINCIPIO;
            }
            else if(anterior->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
///////////////////////////
int indice1::agregar(Caja1 *p1){
    Caja1 *p;
    buscar(p1);
    if(encontrado == SI) return (0);
    p = new Caja1;
    p -> nombre = p1 ->nombre;
    p -> apellido = p1 ->apellido;

    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    else if (donde == FINAL ){
        p -> siguiente = NULL;
        anterior -> siguiente = p;
    }
    else if(donde == ENMEDIO){
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }
    cuantos++;
    return(1);
}
///////////////////////////
void indice1::pintar(){
    Caja1 *p;
    p = principio;
    while(p){
        cout << "\n " << p -> nombre << ", " << p -> apellido;
        p = p -> siguiente;
    }
}
///////////////////////////
int indice1::Cuantos(){
    return (cuantos);
}


/////////////////////////
/////////////////////////
/////////////////////////
//     INDICE 2

////////////////////////////
void indice2::crear(){
    principio = NULL;
    anterior = NULL;
    cuantos = 0;
}
////////////////////////////
indice2::indice2(){
    crear();
}
////////////////////////////
void indice2::limpiar(){
    Caja1 *p;
    p = new Caja1;

    while(p){
        p = principio;
        delete p;
        p = p -> siguiente;
    }
}
////////////////////////////
indice2::~indice2(){
    limpiar();
}
////////////////////////////
void indice2::buscar(Caja1 *p1){
    Caja1 *p;
    if(principio == NULL){
        encontrado = NO;
        donde = VACIO;
        return;
    }
    p = principio;
    while(p){
        if(p->apellido == p1 -> apellido && p->nombre == p1 -> nombre){
            encontrado = SI;
            if(p == principio){
                donde = PRINCIPIO;
            }
            else if(p->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
        }
        else if(p->apellido < p1 -> apellido || (p ->apellido == p1 -> apellido && p->nombre < p1 ->nombre)){
            encontrado = NO;
            anterior = p;
            p = p->siguiente;
        }
        else if(p->apellido > p1 -> apellido || (p ->apellido == p1 -> apellido && p->nombre > p1 ->nombre)){
            encontrado = NO;
            if(principio == p){
                donde = PRINCIPIO;
            }
            else if(anterior->siguiente == NULL){
                donde = FINAL;
            }
            else{
                donde = ENMEDIO;
            }
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
///////////////////////////
int indice2::agregar(Caja1 *p1){
    Caja1 *p;
    buscar(p1);
    if(encontrado == SI) return (0);
    p = new Caja1;
    p -> nombre = p1 -> nombre;
    p -> apellido = p1 -> apellido;

    if(donde == VACIO){
        p -> siguiente = NULL;
        principio = p;
    }
    else if(donde == PRINCIPIO){
        p -> siguiente = principio;
        principio = p;
    }
    else if (donde == FINAL ){
        p -> siguiente = NULL;
        anterior -> siguiente = p;
    }
    else if(donde == ENMEDIO){
        p -> siguiente = anterior -> siguiente;
        anterior -> siguiente = p;
    }
    cuantos++;
    return(1);
}
///////////////////////////
void indice2::pintar(){
    Caja1 *p;
    p = principio;
    while(p){
        cout << "\n " << p -> apellido << ", " << p -> nombre;
        p = p -> siguiente;
    }
}
///////////////////////////
int indice2::Cuantos(){
    return (cuantos);
}

/////////////////////////
/////////////////////////
/////////////////////////
//   BASE DE DATOS

BD::BD(){
    A.crear();
    B.crear();
    C.crear();
}
////////////////////////
BD::~BD(){
    A.limpiar();
    B.limpiar();
    C.limpiar();
}
///////////////////////
void BD::agregar(int a, int b){
    A.agregar(a,b);

    Caja1 *p;
    p = A.lugarAgregado();

    B.agregar(p);
    C.agregar(p);
}
///////////////////////
void BD::pintar1(){
    B.pintar();
}
/////////////////////////
void BD::pintar2(){
    C.pintar();
}
/////////////////////////
