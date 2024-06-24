#ifndef FUNCIONESCERDO_H_INCLUDED
#define FUNCIONESCERDO_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<string.h>
#include <limits>

using namespace std;

// Prototipos de funciones
string quienTiraPrimero(const string& Jugador1, const string& Jugador2);
void TiradaDados(int Vec[], int Tam);
bool ProcesarDados(int Vec[], int Tam, int vecStat[], bool *BanderaTresDatos);
bool hayUnaCaraDistinta(int Vec[], int Tam);
bool sonTodasIgualesEntreSi(int Vec[], int Tam);
bool hayDosCarasIgualesYSonAses(int Vec[], int Tam);
bool ningunaEsAs(int Vec[], int Tam);
bool todasLasCarasSonAses(int Vec[], int Tam);
void Jugar(int vecStat1[], int vecStat2[]);
void jugarRonda(int vecStat[], bool *BanderaTresDatos);

// Implementación de las funciones

void TiradaDados(int Vec[], int Tam) {
    srand(time(NULL));
    for (int i = 0; i < Tam; i++) {
        Vec[i] = (rand() % 6 + 1);
        cout << "Los dados dieron: " << Vec[i] << endl;
    }
}

string quienTiraPrimero(const string& Jugador1, const string& Jugador2) {
    int dadosIniciales[2] = {};
    string jugadorPrimero;
    srand(time(NULL));
    cout << "El primer jugador tira" << endl;
    TiradaDados(dadosIniciales, 2);
    int SumJugador1 = dadosIniciales[0] + dadosIniciales[1];
    int DadoMayorJugador1 = (dadosIniciales[0] > dadosIniciales[1]) ? dadosIniciales[0] : dadosIniciales[1];

    cout << "El segundo jugador tira" << endl;
    TiradaDados(dadosIniciales, 2);
    int SumJugador2 = dadosIniciales[0] + dadosIniciales[1];
    int DadoMayorJugador2 = (dadosIniciales[0] > dadosIniciales[1]) ? dadosIniciales[0] : dadosIniciales[1];

    if (SumJugador1 > SumJugador2) {
        jugadorPrimero = Jugador1;
    } else if (SumJugador1 == SumJugador2) {
        jugadorPrimero = (DadoMayorJugador1 > DadoMayorJugador2) ? Jugador1 : Jugador2;
    } else {
        jugadorPrimero = Jugador2;
    }

    return jugadorPrimero;
}

bool sonTodasIgualesEntreSi(int Vec[], int Tam) {
    bool sonIguales = Vec[0] == Vec[Tam - 1];
    if (Tam == 3) {
        for (int i = 0; i < Tam - 1; i++) {
            if (Vec[i] == Vec[i + 1]) {
                sonIguales = true;
            }
        }
    }
    return sonIguales;
}

bool hayDosCarasIgualesYSonAses(int Vec[], int Tam) {
    bool sonDosIguales = false;
    bool sonAses = false;
    bool sonTodasIguales = false;
    for (int i = 0; i < Tam - 1; i++) {
        if (Vec[i] == Vec[i + 1] && Vec[i] == 1) {
            sonDosIguales = true;
            sonAses = true;
        }
    }
    if (Tam == 3 && Vec[0] == Vec[2] && Vec[0] == 1) {
        if (sonDosIguales && sonAses) {
            sonTodasIguales = true;
        } else {
            sonDosIguales = true;
            sonAses = true;
        }
    }
    return sonDosIguales && sonAses && !sonTodasIguales;
}

bool ningunaEsAs(int Vec[], int Tam) {
    bool hayUnAs = false;
    for (int i = 0; i < Tam; i++) {
        if (Vec[i] == 1) {
            hayUnAs = true;
        }
    }
    return hayUnAs;
}

bool todasLasCarasSonAses(int Vec[], int Tam) {
    bool sonAses = true;
    for (int i = 0; i < Tam; i++) {
        if (Vec[i] != 1) {
            sonAses = false;
        }
    }
    return sonAses;
}

bool hayUnaCaraDistinta(int Vec[], int Tam) {
    bool esDistinta = Vec[0] != Vec[Tam - 1];
    if (Tam == 3 && !esDistinta) {
        for (int i = 0; i < Tam - 1; i++) {
            if (Vec[i] != Vec[i + 1]) {
                esDistinta = true;
            }
        }
    }
    return esDistinta;
}

bool ProcesarDados(int Vec[], int Tam, int vecStat1[], int vecStat2[], bool *BanderaTresDatos) {
    int Trufas = 0, Oinks = 0;
    char Siono;
    bool SiguienteRonda = true;
    bool puedeElegirSiguienteRonda = true;
    while(puedeElegirSiguienteRonda){
        if (hayUnaCaraDistinta(Vec, Tam) && ningunaEsAs(Vec, Tam)) {
            for (int i=0; i<3; i++){
            Trufas+=Vec[i];
            }
            cout<<"¿Quiere seguir volver a tirar?"<<endl;
            cout<<"S/N"<<endl;
            cin>>Siono;
                if (Siono=='n'){
                puedeElegirSiguienteRonda= false;
                }
                vecStat1[0]+=Trufas;
        }
      else if (sonTodasIgualesEntreSi(Vec, Tam) && ningunaEsAs(Vec, Tam)) {
            for (int i=0; i<3; i++){
            Trufas+=Vec[i];
            }
            Trufas=Trufas*2;
            Oinks++;
            vecStat1[0]+=Trufas;
            vecStat1[1]++;
            cout<<"Hiciste un oink!"<<endl;
            cout<<"Presione cualquier tecla para volver a lanzar los dados, es obligatorio!"<<endl;
    } else if (hayUnaCaraDistinta(Vec, Tam) && !ningunaEsAs(Vec, Tam)) {
            puedeElegirSiguienteRonda=false;
            Trufas=0;
            cout<<"Mala suerte, perdiste las trufas de esta ronda y perdiste tu turno!"<<endl;
    } else if (((Tam == 2 && sonTodasIgualesEntreSi(Vec, Tam)) || (Tam == 3 && hayDosCarasIgualesYSonAses(Vec, Tam)) && todasLasCarasSonAses(Vec, Tam))) {
        puedeElegirSiguienteRonda=false;
        vecStat1[0]=0;
        Trufas=0;
        cout<<"Que mal, Perdiste todos tus puntos y tambien tu turno!"<<endl;
    } else if (Tam == 3 && sonTodasIgualesEntreSi(Vec, Tam) && todasLasCarasSonAses(Vec, Tam)) {
        *BanderaTresDatos= true;
        vecStat2[0]= Trufas+vecStat1[0];
        vecStat1[0]=0;
        cout<<"Te hundiste en el barro y perdiste todo, mala suerte!"<<endl;

    }

    }
    return SiguienteRonda;
}

void jugarRonda(int vecStat1[], int vecStat2[], bool *BanderaTresDatos) {
    int DosDados[2] = {}, TresDados[3] = {};
    const int Tam2 = 2, Tam3 = 3;
    const int CantJugadores = 2;
    for (int i = 0; i < CantJugadores; i++) {
        bool SiguienteRonda = false;
        while (!SiguienteRonda) {
            if (*BanderaTresDatos) {
                TiradaDados(DosDados, Tam2);
                SiguienteRonda = ProcesarDados(DosDados, Tam2, vecStat1, vecStat2, BanderaTresDatos);
            } else {
                TiradaDados(TresDados, Tam3);
                SiguienteRonda = ProcesarDados(TresDados, Tam3, vecStat1, vecStat2, BanderaTresDatos);
            }
        }
    }
}

void Jugar(int vecStat1[], int vecStat2[]) {
    const int Rondas = 5;
    bool BanderaTresDatos = false;
    for (int i = 0; i < Rondas; i++) {
        jugarRonda(vecStat1, vecStat2, &BanderaTresDatos);
        jugarRonda(vecStat2, vecStat1, &BanderaTresDatos);
    }
}

#endif // FUNCIONESCERDO_H_INCLUDED



