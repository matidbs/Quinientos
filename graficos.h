#ifndef GRAFICOS_H_INCLUDED
#define GRAFICOS_H_INCLUDED
#include "rlutil.h"

///Muestra menu principal
void mostrarMenuPrincipal (int y);

///Muestra menu en partida
void mostrarMenuEnPartida (int ronda, char *nombreUsuario,int lanzamiento,int ptsTotal);

///Muestra menu entre ronda en modo UN JUGADOR
void menuEntreRondaM1Jugador (int ronda,char *nombreUsuario,int ptsTotal);

///Muestra menu entre ronda en modo DOS JUGADORES
void menuEntreRondaM2Jugadores (int ronda,char *nombreUsuario,int ptsTotalJg1,int ptsTotalJg2);

///Muestra menu cuando finaliza la partida DOS JUGADORES
void menuFinalPartidaUnJugador (char *nombreUsuario, int ronda,int ptsTotal);

///Muestra menu cuando finaliza la partida DOS JUGADORES
void menuFinalPartidaDosJugadores (char *nombreUsuario, int ronda,int ptsTotal);

///Muestra menu en caso de empate
void menuEmpate (char *nombreJg1,char *nombreJg2, int puntosJg1, int puntosJg2);

///Muestra los valores del vector
void mostrarVector (int *vec, int tam);

///Muestra el resultado del lanzamiento
void mostrarResultado (int puntos);

///Pedir nombre de usuario
void pedirNombreUsuario (char *vec);

///Muestra menu de mayor puntuacion
void menuMayorPuntuacion (int ptsRecord,char *userPtsRecord);

///Pinta la opcion seleccionada actualmente en el menu
void mostrarSeleccion (const* texto,int posx, int posy, bool selected);

///Dibujar los dados
void dibujarDados (int *vec,int tam);

void mostrarMenuPrincipal (int y){
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(56,4);
cout<<"Quinientos"<<endl;
rlutil::locate(56,5);
cout<<"----------"<<endl;

rlutil::locate(45,6 + y);
cout<<(char)16 <<endl;

if (y==0){
rlutil::setBackgroundColor(rlutil::LIGHTRED);
rlutil::locate(47,6);
cout<<"INICIAR JUEGO UN JUGADOR"<<endl;
}else {
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(47,6);
cout<<"INICIAR JUEGO UN JUGADOR"<<endl;}

if (y==1){
rlutil::setBackgroundColor(rlutil::LIGHTRED);
rlutil::locate(47,7);
cout<<"INICIAR JUEGO DOS JUGADORES"<<endl;
}else {
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(47,7);
cout<<"INICIAR JUEGO DOS JUGADORES"<<endl;}

if (y==2){
rlutil::setBackgroundColor(rlutil::LIGHTRED);
rlutil::locate(47,8);
cout<<"PUNTUACION MAS ALTA"<<endl;
}else {
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(47,8);
cout<<"PUNTUACION MAS ALTA"<<endl;
}

if (y==3){
rlutil::setBackgroundColor(rlutil::LIGHTRED);
rlutil::locate(47,9);
cout<<"SALIR"<<endl;
}else {
rlutil::setBackgroundColor(rlutil::BLACK);
rlutil::locate(47,9);
cout<<"SALIR"<<endl;
}
rlutil::setBackgroundColor(rlutil::BLACK);

}

void mostrarMenuEnPartida (int lanzamiento,int ronda, char *nombreUsuario,int maxPts,int ptsTotal){
cout<<"Turno de "<<nombreUsuario<<" | Ronda N";
printf("%c",248);
cout<<" "<<ronda<<" | Puntaje total: "<<ptsTotal<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"Maximo puntaje de la ronda: "<<maxPts<<endl;
cout<<"Lanzamiento: "<<lanzamiento<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
}

void menuEntreRondaM1Jugador (int ronda,char *nombreUsuario,int ptsTotal){
rlutil::locate(56,4);
cout<<"Ronda N";
printf("%c",248);
cout<<" "<<ronda<<endl;
rlutil::locate(47,5);
cout<<"----------------------------"<<endl;
rlutil::locate(53,6);
cout<<"Puntaje "<<nombreUsuario<<": "<<ptsTotal<<endl;
rlutil::locate(47,7);
cout<<"----------------------------"<<endl;

rlutil::locate(44,8);
system("pause");
system("cls");
}

void menuEntreRondaM2Jugadores (int ronda,char *nombreJg1,char *nombreJg2,int ptsTotalJg1,int ptsTotalJg2,int reloj){
rlutil::locate(56,4);
cout<<"Ronda N";
printf("%c",248);
cout<<" "<<ronda<<endl;
rlutil::locate(47,5);
cout<<"----------------------------"<<endl;
if (reloj%2!=0){
rlutil::locate(51,6);
cout<<"Proximo turno: "<<nombreJg2<<endl;
}else if (reloj%2==0){
rlutil::locate(51,6);
cout<<"Proximo turno: "<<nombreJg1<<endl;
}
rlutil::locate(51,7);
cout<<"Puntaje "<<nombreJg1<<": "<<ptsTotalJg1<<endl;
rlutil::locate(51,8);
cout<<"Puntaje "<<nombreJg2<<": "<<ptsTotalJg2<<endl;
rlutil::locate(47,9);
cout<<"----------------------------"<<endl;
rlutil::locate(44,10);
system("pause");
system("cls");
}

void menuFinalPartidaUnJugador (char *nombreUsuario, int ronda,int ptsTotal){
rlutil::locate(55,4);
cout<<"Nombre: "<<nombreUsuario<<endl;
rlutil::locate(47,5);
cout<<"----------------------------"<<endl;
rlutil::locate(56,6);
cout<<"Puntos: "<<ptsTotal<<endl;
rlutil::locate(56,7);
cout<<"Rondas: "<<ronda<<endl;
rlutil::locate(44,10);
system("pause");
}

void menuFinalPartidaDosJugadores (char *nombreUsuario, int ronda,int ptsTotal){
rlutil::locate(55,4);
cout<<"Ganador: "<<nombreUsuario<<endl;
rlutil::locate(47,5);
cout<<"----------------------------"<<endl;
rlutil::locate(56,6);
cout<<"Puntos: "<<ptsTotal<<endl;
rlutil::locate(56,7);
cout<<"Rondas: "<<ronda<<endl;
rlutil::locate(44,10);
system("pause");
}

void menuEmpate (char *nombreJg1,char *nombreJg2, int puntosJg1, int puntosJg2){
rlutil::locate(58,4);
cout<<"Empate"<<endl;
rlutil::locate(47,5);
cout<<"----------------------------"<<endl;
rlutil::locate(52,6);
cout<<"Puntaje "<<nombreJg1<<": "<<puntosJg1<<endl;
rlutil::locate(52,7);
cout<<"Puntaje "<<nombreJg2<<": "<<puntosJg2<<endl;
rlutil::locate(44,10);
system("pause");
}

void mostrarVector (int *vec, int tam){
    for (int i=0; i<tam;i++){
    cout<<"Valores: "<<vec[i]<<endl;}
}

void mostrarResultado (int puntos){
rlutil::locate(1,12);
cout<<endl<<"Puntos del lanzamiento: "<<puntos<<endl;
}

void pedirNombreUsuario (char *vec){
rlutil::locate(47,7);
cout<<"Ingrese nombre: ";
cin>>vec;}

void menuMayorPuntuacion (int ptsRecord,char *userPtsRecord){

    if(ptsRecord==0){ ///Caso de no registrar ninguna puntuacion
    system("cls");
    cout<<"Mayor puntuacion: "<<endl;
    cout<<"---------------------------------------------------"<<endl;
    system("pause");
    }else{ ///Caso habiendo registrado al menos una puntuacion
    system("cls");
    cout<<"Mayor puntuacion: "<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Nombre: "<<userPtsRecord<<" | Puntuacion: "<<ptsRecord<<endl;
    system("pause");}
}

void mostrarSeleccion (const* texto,int posx, int posy, bool selected){
if (selected){
    rlutil::setBackgroundColor(rlutil::BLUE);
}else {
    rlutil::setBackgroundColor(rlutil::BLACK);
}
    rlutil::locate(posx,posy);
    cout<<texto<<endl;
}

void dibujarDados (int *vec,int tam){
int ini,fin;
rlutil::resetColor();
for (int i=0;i<tam;i++){


if (i==0){
    ini = 2;
    fin = 10;
}
if (i==1){
    ini = 12;
    fin = 20;
}if (i==2){
    ini = 22;
    fin = 30;
}if (i==3){
    ini = 32;
    fin = 40;
}if (i==4){
    ini = 42;
    fin = 50;
}if (i==5){
    ini = 52;
    fin = 60;
}

for(int x=ini;x<=fin;x++){
rlutil::setColor(rlutil::WHITE);
rlutil::locate(x,7);
cout<<char(220)<<endl;
rlutil::locate(x,8);
cout<<char(219)<<endl;
rlutil::locate(x,9);
cout<<char(219)<<endl;
rlutil::locate(x,10);
cout<<char(219)<<endl;
rlutil::locate(x,11);
cout<<char(223)<<endl;
}

switch (vec[i]){
case 1:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-4,9);
    cout<<char(254)<<endl;
break;

case 2:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-6,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,10);
    cout<<char(254)<<endl;
break;

case 3:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-6,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,10);
    cout<<char(254)<<endl;
    rlutil::locate(fin-4,9);
    cout<<char(254)<<endl;
break;

case 4:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-6,10);
    cout<<char(254)<<endl;
    rlutil::locate(fin-6,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,10);
    cout<<char(254)<<endl;
break;

case 5:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-6,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-6,10);
    cout<<char(254)<<endl;
    rlutil::locate(fin-4,9);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,10);
    cout<<char(254)<<endl;
break;

case 6:
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    rlutil::locate(fin-6,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-6,9);
    cout<<char(254)<<endl;
    rlutil::locate(fin-6,10);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,8);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,9);
    cout<<char(254)<<endl;
    rlutil::locate(fin-2,10);
    cout<<char(254)<<endl;
break;

default:
break;
}
rlutil::resetColor();
}

}

#endif // GRAFICOS_H_INCLUDED
