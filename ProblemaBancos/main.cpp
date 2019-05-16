#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include "Clases.cpp"

using namespace std;

int main()
{
    srand(time(NULL));
    cout << "Este programa simula un banco que abre de 9 a 4 (7 horas = 420 minutos)" << endl << endl;
    cout << "Presione cualquier tecla para iniciar la simulaci\242n" << endl;
    system("pause");


    int horaCierre = 420;
    cola Personas;   //Cola de las personas que visitaran el banco
    enum cajera{DISPONIBLE, OCUPADA};
    cajera cajera1 = DISPONIBLE, cajera2 = DISPONIBLE, cajera3 = DISPONIBLE;

    int aux =0;
    while(aux < (horaCierre-20) ){
        aux += rand()%20+1;
        Personas.agregar( aux, rand()%10 + 1);    //Generamos la lista de personas que visitaran el banco con su minuto de llegada
    }                                              // y su tiempo en caja
/////////////////////////////////////////////////////////////
    cola cola; //Fila del banco
    int tiempoCajera1 = 0, tiempoCajera2 = 0, tiempoCajera3 = 0;
    int tiempoEsperaMax = 0, numclientes =0;
    int genteEncola = 0, genteEncolaMax = 0;

    for(int minuto = 0; minuto < horaCierre; minuto++){ //Este ciclo simula nuestro reloj

        if( cola.Cuantos() == 0 && Personas.Cuantos()>0 && Personas.regresarTiempoLlegada() == minuto){//Llegada de un cliente al banco
                if(cajera1 == DISPONIBLE && Personas.Cuantos() > 0 && cola.Cuantos()== 0){
                    cajera1 = OCUPADA;
                    tiempoCajera1 = Personas.regresarTiempoCajera() + minuto;

                    if(tiempoCajera1 > horaCierre) horaCierre = tiempoCajera1;
                    Personas.EstablecerLlegadaCaja( Personas.regresarTiempoLlegada() + minuto);
                    Personas.EstablecerTiempoFila(Personas.regresarLlegadaCaja() - Personas.regresarTiempoLlegada());
                    Personas.EstablecerTiempoSalida( Personas.regresarTiempoFila() + Personas.regresarTiempoCajera() );

                /*    cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << Personas.regresarTiempoLlegada()
                    << endl << "Su tiempo en caja fue de: " << Personas.regresarTiempoCajera() << endl
                    << "Lleg\242 a la caja al minuto: " << Personas.regresarTiempoFila() << endl << "Esper\242 en fila " <<Personas.regresarTiempoFila() - Personas.regresarTiempoLlegada() << " minutos"
                    << endl << "Sali\242 del banco en el minuto " << Personas.regresarTiempoSalida() << endl << endl;*/

                    Personas.sacar();
                    numclientes++;
                }
                else if(cajera2 == DISPONIBLE && Personas.Cuantos() > 0 && cola.Cuantos()== 0){  //Estos tres if del codigo son para los clientes que lleguen y que no haya fila
                    cajera2 = OCUPADA;
                    tiempoCajera2 = Personas.regresarTiempoCajera() + minuto;
                    if(tiempoCajera2 > horaCierre) horaCierre = tiempoCajera2;
                    Personas.EstablecerLlegadaCaja( (Personas.regresarTiempoLlegada()) + minuto);
                    Personas.EstablecerTiempoFila(Personas.regresarLlegadaCaja() - Personas.regresarTiempoLlegada());
                    Personas.EstablecerTiempoSalida( Personas.regresarTiempoFila() + Personas.regresarTiempoCajera() );

                    cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << Personas.regresarTiempoLlegada()
                    << endl << "Su tiempo en caja fue de: " << Personas.regresarTiempoCajera() << endl
                    << "Lleg\242 a la caja al minuto: " << Personas.regresarTiempoFila() << endl << "Esper\242 en fila " <<Personas.regresarTiempoFila() - Personas.regresarTiempoLlegada() << " minutos"
                    << endl << "Sali\242 del banco en el minuto " << Personas.regresarTiempoSalida() << endl << endl;
                    Personas.sacar();
                    numclientes++;
                }
                else if(cajera3 == DISPONIBLE && Personas.Cuantos() > 0 && cola.Cuantos()== 0){
                    cajera3 = OCUPADA;
                    tiempoCajera3 = Personas.regresarTiempoCajera() + minuto;
                    if(tiempoCajera3 > horaCierre) horaCierre = tiempoCajera3;
                    Personas.EstablecerLlegadaCaja( (Personas.regresarTiempoLlegada()) + minuto);
                    Personas.EstablecerTiempoFila(Personas.regresarLlegadaCaja() - Personas.regresarTiempoLlegada());
                    Personas.EstablecerTiempoSalida( Personas.regresarTiempoFila() + Personas.regresarTiempoCajera() );

                    cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << Personas.regresarTiempoLlegada()
                    << endl << "Su tiempo en caja fue de: " << Personas.regresarTiempoCajera() << endl
                    << "Lleg\242 a la caja al minuto: " << Personas.regresarTiempoFila() << endl << "Esper\242 en fila " <<Personas.regresarTiempoFila() - Personas.regresarTiempoLlegada() << " minutos"
                    << endl << "Sali\242 del banco en el minuto " << Personas.regresarTiempoSalida() << endl << endl;
                    Personas.sacar();
                    numclientes++;
                }


                    if(cajera1 == DISPONIBLE && cola.Cuantos()> 0){
                    cajera1 = OCUPADA;
                    tiempoCajera1 = cola.regresarTiempoCajera() + minuto;
                    if(tiempoCajera1 > horaCierre) horaCierre = tiempoCajera1;
                    cola.EstablecerLlegadaCaja( cola.regresarTiempoLlegada() + minuto);
                    cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - cola.regresarLlegadaCaja());
                    cola.EstablecerTiempoSalida( cola.regresarTiempoFila() + cola.regresarTiempoCajera() );
                }
                    else if(cajera2 == DISPONIBLE && cola.Cuantos()> 0){  //Estos tres if del codigo son para los clientes que lleguen y que no haya fila
                    cajera2 = OCUPADA;
                    tiempoCajera2 = cola.regresarTiempoCajera() + minuto;
                    if(tiempoCajera2 > horaCierre) horaCierre = tiempoCajera2;
                    cola.EstablecerLlegadaCaja( (cola.regresarTiempoLlegada()) + minuto);
                    cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - cola.regresarLlegadaCaja());
                    cola.EstablecerTiempoSalida( cola.regresarTiempoFila() + cola.regresarTiempoCajera() );
                }
                    else if(cajera3 == DISPONIBLE && cola.Cuantos()> 0){
                    cajera3 = OCUPADA;
                    tiempoCajera3 = cola.regresarTiempoCajera() + minuto;
                    if(tiempoCajera3 > horaCierre) horaCierre = tiempoCajera3;
                    cola.EstablecerLlegadaCaja( (cola.regresarTiempoLlegada()) + minuto);
                    cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - cola.regresarLlegadaCaja());
                    cola.EstablecerTiempoSalida( cola.regresarTiempoFila() + cola.regresarTiempoCajera() );
                }



                    if(cajera1 == OCUPADA && cajera2 == OCUPADA && cajera3 == OCUPADA && Personas.Cuantos() >= 0){    //Si todas las cajeras están ocupadas formamos al cliente
                    cola.agregar(Personas.regresarTiempoLlegada(), Personas.regresarTiempoCajera());
                    genteEncola++;
                    if(genteEncola > genteEncolaMax) genteEncolaMax = genteEncola;
                    Personas.sacar();
                }
        }
        ///////////////////////////////////////////////////////////////////////////////////
        if(tiempoCajera1 == minuto && cajera1 == OCUPADA){
            cajera1 = DISPONIBLE;  //Si las cajeras no tienen trabajo por hacer
            if(cola.Cuantos() > 0){
                cajera1 = OCUPADA;
                tiempoCajera1 = minuto + cola.regresarTiempoCajera();
                cola.EstablecerLlegadaCaja(minuto);
                cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - minuto);
                cola.EstablecerTiempoSalida(cola.regresarLlegadaCaja()+ cola.regresarTiempoCajera());
                if( cola.regresarTiempoFila() > tiempoEsperaMax && (cola.regresarTiempoFila()<=20)) tiempoEsperaMax = cola.regresarTiempoFila();

                cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << cola.regresarTiempoLlegada()
                << endl << "Su tiempo en caja fue de: " << cola.regresarTiempoCajera() << endl
                << "Lleg\242 a la caja al minuto: " << cola.regresarTiempoFila() << endl << "Esper\242 en fila " <<cola.regresarTiempoFila() - cola.regresarTiempoLlegada() << " minutos"
                << endl << "Sali\242 del banco en el minuto " << cola.regresarTiempoSalida() << endl << endl;
                cola.sacar();
                numclientes++;
            }
        }
        if(tiempoCajera2 == minuto && cajera2 == OCUPADA){
            cajera2 = DISPONIBLE;
            if(cola.Cuantos() > 0){
                cajera2 = OCUPADA;
                tiempoCajera2 = minuto + cola.regresarTiempoCajera();
                if( cola.regresarTiempoFila() > tiempoEsperaMax && (cola.regresarTiempoFila()<=20)) tiempoEsperaMax = cola.regresarTiempoFila();
                cola.EstablecerLlegadaCaja(minuto);
                cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - cola.regresarLlegadaCaja());

                cola.EstablecerTiempoSalida(cola.regresarLlegadaCaja()+ cola.regresarTiempoCajera());
                if( cola.regresarTiempoFila() > tiempoEsperaMax && (cola.regresarTiempoFila()<=20)) tiempoEsperaMax = cola.regresarTiempoFila();

                cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << cola.regresarTiempoLlegada()
                << endl << "Su tiempo en caja fue de: " << cola.regresarTiempoCajera() << endl
                << "Lleg\242 a la caja al minuto: " << cola.regresarTiempoFila() << endl << "Esper\242 en fila " <<cola.regresarTiempoFila() - cola.regresarTiempoLlegada() << " minutos"
                << endl << "Sali\242 del banco en el minuto " << cola.regresarTiempoSalida() << endl << endl;
                cola.sacar();
                numclientes++;
                cola.sacar();
            }
        }
        if(tiempoCajera3 == minuto && cajera3 == OCUPADA){
            cajera3 = DISPONIBLE;
            if(cola.Cuantos() > 0){
                cajera3 = OCUPADA;
                tiempoCajera3 = minuto + cola.regresarTiempoCajera();
                if( cola.regresarTiempoFila() > tiempoEsperaMax && (cola.regresarTiempoFila()<=20)) tiempoEsperaMax = cola.regresarTiempoFila();
                cola.EstablecerLlegadaCaja(minuto);
                cola.EstablecerTiempoFila(cola.regresarTiempoLlegada() - cola.regresarLlegadaCaja());

                cola.EstablecerTiempoSalida(cola.regresarLlegadaCaja()+ cola.regresarTiempoCajera());
                if(cola.regresarTiempoFila()<0) cola.EstablecerTiempoFila(0);
                if( cola.regresarTiempoFila() > tiempoEsperaMax && (cola.regresarTiempoFila()<=20)) tiempoEsperaMax = cola.regresarTiempoFila();

                cout << "El cliente #" << numclientes+1 << " lleg\242 en el minuto: " << cola.regresarTiempoLlegada()
                << endl << "Su tiempo en caja fue de: " << cola.regresarTiempoCajera() << endl
                << "Lleg\242 a la caja al minuto: " << cola.regresarTiempoFila() << endl << "Esper\242 en fila " <<cola.regresarTiempoFila() - cola.regresarTiempoLlegada() << " minutos"
                << endl << "Sali\242 del banco en el minuto " << cola.regresarTiempoSalida() << endl << endl;
                cola.sacar();
                numclientes++;
                cola.sacar();
            }
        }
    }
    cout << endl << "El banco tuvo " << numclientes << " clientes" << endl;
    cout << endl << "La fila tuvo un maximo de " << genteEncolaMax << " personas";
    cout << endl << "El m\240ximo de espera en la fila fue de " << tiempoEsperaMax << " minutos" << endl;
    system("pause");
    return 0;
}
