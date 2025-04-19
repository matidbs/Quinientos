#include <iostream>
#include "funciones.h"
#include <cstdlib>
#include "rlutil.h"
#include <time.h>
#include <string>
#include "graficos.h"


using namespace std;

int main(){

int y = 0;
int opMenu = 5;
int ptsRecord = 0;
char userPtsRecord[21];
bool primerJuego = true;

///Para moverse por el menu,se deben utilizar las flechas del teclado

do{
int tam=6;
int valoresDado[tam]={0};
int puntosLanzamiento = 0, ptsRondaMax = 0, puntosJg1 = 0,puntosJg2 = 0, contRondas = 0, cont2Jugadores = 0;
char nombreJg1[21];
char nombreJg2[21];
bool si_sexteto6;

rlutil::hidecursor();
system ("cls");
rlutil::cls;

mostrarMenuPrincipal(y);

switch (rlutil::getkey()){ ///Switch para identificar donde esta el cursor

case 14:///Tecla up
    rlutil::locate(43,6 + y);
    cout<<" "<<endl;
    y--;
    if (y<0){
        y = 0;
    }
break;

case 15: ///Tecla down
    rlutil::locate(43,6 + y);
    cout<<" "<<endl;
    y++;
    if (y>3){
        y = 3;
    }
break;

case 1: ///Tecla enter

///////////////////////////////////////////////////////////////////

switch (y){ ///Switch de opciones

//////////////////////////////////////////////////////////////////

case 0: ///Juego un jugador

    system("cls");
    pedirNombreUsuario(nombreJg1);

    for (int j=1;j<=6;j++){ ///Rondas
    contRondas++;
    ptsRondaMax=0;
    si_sexteto6 = false;
        for (int i=1;i<=3;i++){ ///Lanzamientos
    puntosLanzamiento = 0;

    system("cls");

    generarVectorAleatorio(valoresDado,tam);
    ordenarVector(valoresDado,tam);
    mostrarMenuEnPartida(i,j,nombreJg1,ptsRondaMax,puntosJg1);
    dibujarDados(valoresDado,tam);
    escalera(valoresDado,tam,&puntosLanzamiento);
    trioX(valoresDado,tam,&puntosLanzamiento);
    sumaDeDados(valoresDado,tam,&puntosLanzamiento);
    sexteto6(valoresDado,tam,&puntosLanzamiento,&si_sexteto6);
    sextetoX(valoresDado,tam,&puntosLanzamiento);
    mostrarResultado(puntosLanzamiento);

    evaluarRonda(&ptsRondaMax,i,puntosLanzamiento,si_sexteto6);

    if (ptsRondaMax >= 500){
        i=10;
        j=42;
    }
    rlutil::locate(1,15);
    system("pause");
    system("cls");
}
    puntosJg1 += ptsRondaMax;

    if (puntosJg1<500){
    menuEntreRondaM1Jugador(contRondas,nombreJg1,puntosJg1);}
}
    menuFinalPartidaUnJugador(nombreJg1,contRondas,puntosJg1);
    guardarPtsRecord(&primerJuego,nombreJg1,puntosJg1,&ptsRecord,userPtsRecord);

break;

/////////////////////////////////////////////////////////////////////////////////

case 1: ///Juego dos jugadores

    /// Impar = Jugador 1, Par = Jugador 2

    system("cls");
    rlutil::locate(47,5);
    cout<<"Jugador 1"<<endl;
    rlutil::locate(47,6);
    cout<<"----------------------------"<<endl;
    pedirNombreUsuario(nombreJg1);

    system("cls");
    rlutil::locate(47,5);
    cout<<"Jugador 2"<<endl;
    rlutil::locate(47,6);
    cout<<"----------------------------"<<endl;
    pedirNombreUsuario(nombreJg2);

    for (int j=1;j<=12;j++){ ///Rondas
    cont2Jugadores++;
    if (j%2!=0){
    contRondas++;}
    ptsRondaMax=0;
    si_sexteto6 = false;
        for (int i=1;i<=3;i++){ ///Lanzamientos
    puntosLanzamiento = 0;

    system("cls");

    if (cont2Jugadores%2!=0){ ///Menu de jugador 1
    generarVectorAleatorio(valoresDado,tam);
    ordenarVector(valoresDado,tam);
    mostrarMenuEnPartida(i,contRondas,nombreJg1,ptsRondaMax,puntosJg1);
    dibujarDados(valoresDado,tam);
    escalera(valoresDado,tam,&puntosLanzamiento);
    trioX(valoresDado,tam,&puntosLanzamiento);
    sumaDeDados(valoresDado,tam,&puntosLanzamiento);
    sexteto6(valoresDado,tam,&puntosLanzamiento,&si_sexteto6);
    sextetoX(valoresDado,tam,&puntosLanzamiento);
    mostrarResultado(puntosLanzamiento);
    }

    if (cont2Jugadores%2==0){ ///Menu de jugador 2
    generarVectorAleatorio(valoresDado,tam);
    ordenarVector(valoresDado,tam);
    mostrarMenuEnPartida(i,contRondas,nombreJg2,ptsRondaMax,puntosJg2);
    dibujarDados(valoresDado,tam);
    escalera(valoresDado,tam,&puntosLanzamiento);
    trioX(valoresDado,tam,&puntosLanzamiento);
    sumaDeDados(valoresDado,tam,&puntosLanzamiento);
    sexteto6(valoresDado,tam,&puntosLanzamiento,&si_sexteto6);
    sextetoX(valoresDado,tam,&puntosLanzamiento);
    mostrarResultado(puntosLanzamiento);
    }

    evaluarRonda(&ptsRondaMax,i,puntosLanzamiento,si_sexteto6);

    if (puntosJg1 >= 500){
        if (cont2Jugadores%2==0){
            j=339;}
    }
    if (puntosJg2 >= 500){
        if (cont2Jugadores%2!=0){
            j=339;}
    }
    rlutil::locate(1,15);
    system("pause");
    system("cls");
}
    if (cont2Jugadores%2!=0){
    puntosJg1 += ptsRondaMax;}

    if (cont2Jugadores%2==0){
    puntosJg2 += ptsRondaMax;}

    if (puntosJg1<500||puntosJg2<500){
    menuEntreRondaM2Jugadores(contRondas,nombreJg1,nombreJg2,puntosJg1,puntosJg2,cont2Jugadores);}
}

    if (puntosJg1>puntosJg2){
    menuFinalPartidaDosJugadores(nombreJg1,contRondas,puntosJg1);
    guardarPtsRecord(&primerJuego,nombreJg1,puntosJg1,&ptsRecord,userPtsRecord);
    }else if (puntosJg2>puntosJg1){
    menuFinalPartidaDosJugadores(nombreJg2,contRondas,puntosJg2);
    guardarPtsRecord(&primerJuego,nombreJg2,puntosJg2,&ptsRecord,userPtsRecord);
    }else {
    menuEmpate(nombreJg1,nombreJg2,puntosJg1,puntosJg2);
    guardarPtsRecord(&primerJuego,nombreJg1,puntosJg1,&ptsRecord,userPtsRecord);
    }

break;

//////////////////////////////////////////////////////////////////////////

case 2: ///Mostrar puntuacion

    menuMayorPuntuacion(ptsRecord,userPtsRecord);

break;

case 3: ///Salir del juego
    opMenu = 0;
break;

default:
break;
} ///Switch del MENU



break; ///Break del ENTER

default:
break;

}

}while (opMenu!=0);


return 0;}

