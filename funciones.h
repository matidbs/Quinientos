#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <ctime>
#include <string.h>
#include "rlutil.h"

using namespace std;

///Genera vector con 6 VALORES = 1 LANZAMIENTO
void generarVectorAleatorio(int *vec, int tam);

///Ordena el vector para evaluar
void ordenarVector (int *vec, int tam);

///Funcion para evaluar si ESCALERA = TRUE
void escalera (int *vec, int tam, int *puntos);

///Evalua si TRIOX = TRUE
void trioX (int *vec, int tam, int *puntos);

///Evalua si SumaDeDados = TRUE
void sumaDeDados (int *vec, int tam, int *puntos);

///Evalua si SEXTETO6 = TRUE
void sexteto6 (int *vec, int tam, int *puntos);

///Evalua si SEXTETOX = TRUE
void sextetoX (int *vec, int tam, int *puntos);

///Evaluar ronda y puntuacion
void evaluarRonda (int ptsRondaMax,int i,int puntosLanzamiento, bool si_sexteto6);

///Guarda el mayor puntaje
void guardarPtsRecord (bool *primerJuego, char *nombreUs, int rondas, int puntos,int *ptsRecord, char *userPtsRecord);

void generarVectorAleatorio (int *vec, int tam){
    srand(time(NULL));
    for (int i=0;i<tam ;i++ ){
        vec[i] = rand()%6+1;}}

void ordenarVector (int *vec, int tam){
for (int k = 0; k < 5; k++){
    for (int f = 0; f < 5 - k; f++){
        if (vec[f] > vec[f + 1]){
        int aux;
        aux = vec[f];
        vec[f] = vec[f + 1];
        vec[f + 1] = aux;}}}
}

void escalera (int *vec, int tam, int *puntos){
int num=1,contEscalera=0;
 for (int i=0; i<tam;i++){
    if (vec[i]==num){
        contEscalera++;}
        num++;}
    if (contEscalera==6){
        rlutil::locate(1,12);
        cout<<"Es ESCALERA. Ganaste"<<endl;
        *puntos+=500;}
}

void trioX (int *vec, int tam, int *puntos){
int contIguales = 0,numRep;
    for (int i=0;i<5;i++){
        for (int j=0;j<tam;j++){
            if (vec[i]==vec[j]){
                contIguales++;}
                }
                if (contIguales>=3&&contIguales<=5){
                    numRep = vec[i];
                    i = 10;}
                else {contIguales=0;}
}

    if (contIguales>=3&&contIguales<=5){
        //rlutil::locate(1,12);
        //cout<<"Es TRIO X++"<<endl;
        *puntos += numRep * 10;}
}

void sumaDeDados (int *vec, int tam, int *puntos){
int contIguales = 0, num = 1;
bool siSumaDados = true;
for (int j=0;j<tam;j++){
    for (int i=0;i<tam;i++){
        if (vec[i]==num){
            contIguales++;
        }
    }       if (contIguales>=3){
                siSumaDados = false;}
    contIguales = 0;
    num++;
}

int numA=1,contEscalera=0;

 for (int i=0; i<tam;i++){
    if (vec[i]==numA){
        contEscalera++;}
        numA++;}
    if (contEscalera==6){
        siSumaDados = false;
    }

    if (siSumaDados==true){
        //rlutil::locate(1,12);
        //cout<<"Es SUMA DE DADOS"<<endl;
        for (int i=0;i<tam;i++){
            *puntos+=vec[i];
        }
    }
}

void sexteto6 (int *vec, int tam, int *puntos, bool *si_sexteto6){
int cont6 = 0;
    for (int i=0;i<tam;i++){
        if (vec[i]==6){
        cont6++;
        }
    }

    if (cont6==6){
    //rlutil::locate(1,12);
    //cout<<"Es SEXTETO6--"<<endl;
    *puntos=0;
    *si_sexteto6 = true;
    }
}

void sextetoX (int *vec, int tam, int *puntos){
int contSextetoX = 0,num = 1;

    for (int j=1;j<5;j++){
    for (int i=0;i<tam;i++){
        if (vec[i]==num){
            contSextetoX++;
        }
    } if (contSextetoX<6){
    contSextetoX=0;}
    num++;
}
if (contSextetoX==6){
    //rlutil::locate(1,12);
    //cout<<"Es SEXTETO X"<<endl;
    *puntos+=vec[1]*50;}
}

void evaluarRonda (int *ptsRondaMax,int i,int puntosLanzamiento, bool si_sexteto6){
    if (i==0){
        *ptsRondaMax = puntosLanzamiento;
    }
    if (puntosLanzamiento>*ptsRondaMax){
        *ptsRondaMax = puntosLanzamiento;
    }
    if (si_sexteto6 == true){
        *ptsRondaMax = 0;
    }
}

void guardarPtsRecord (bool *primerJuego, char *nombreUs,int puntos,int *ptsRecord, char *userPtsRecord){

    if (*primerJuego==true){
        *ptsRecord = puntos;
        strcpy(userPtsRecord,nombreUs);
        *primerJuego = false;
    }
    else if (puntos>*ptsRecord){
        *ptsRecord = puntos;
        strcpy(userPtsRecord,nombreUs);}
}

#endif // FUNCIONES_H_INCLUDED
