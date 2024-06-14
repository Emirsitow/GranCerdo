#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<string.h>
#include <limits>
using namespace std;



int main(){
	int opcion=1, quienTiraPrimero, stats1[4]={},  stats2[3]={};
	// stats = [trufas, oinks, lanzamientos];
	string Jugador1, Jugador2, jugadorInicial;

	while(opcion!=0){
	system("cls");
		cout<<"------------------"<<endl;
		cout<<"1 - Jugar"<<endl;
		cout<<"2 - Estadisticas"<<endl;
		cout<<"3 - Creditos"<<endl;
		cin>>opcion;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		switch(opcion) {
			case 1:
				cout << "Ingrese el nombre del primer jugador: " << endl;
				getline(cin, Jugador1);
				cout << "Ingrese el nombre del segundo jugador: " << endl;
				getline(cin, Jugador2);
				cout << "Jugador 1: " << Jugador1 << endl;
				cout << "Jugador 2: " << Jugador2 << endl;
				jugadorInicial = quienTiraPrimero(Jugador1, Jugador2);
				if (Jugador1 == jugadorInicial) {
					Jugar(stats1, stats2);
				} else {
					Jugar(stats2, stats1);
				}
				// evaluarGanador(stats1, stats2);
				break;
			case 2:
				// mostrarEstadisticas();
				break;
			case 3:
				// mostrarCreditos();
				break;
			default:
				cout<<"No ingreso una opcion valida"<<endl;
				break;
		}
		system("pause");
	}

	cout<<endl<<endl;
	system("pause");
	return 0;
}

////////------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// void MostrarDados(int Vec[],int Tam){
// 	for (int i=0; i<Tam; i++){
// 		cout<<"El numero del dado "<<i+1<<" es "<<Vec[i]<<endl;
// 	}
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void TiradaDados(int dados[], int n) {
    for (int i = 0; i < n; i++) {
        dados[i] = rand() % 6 + 1; // Simula el lanzamiento de un dado (1-6)
    }
}

string quienTiraPrimero (Jugador1, Jugador2) {
	dadosIniciales[2]={}
	string jugadorPrimero;
	srand(time(NULL));
	int dadoMax = 0;
	cout<<"El primer jugador tira"<<endl;
	TiradaDados(dadosIniciales, 2);
	int SumJugador1 = dadosIniciales[0] + dadosIniciales[1];
	int DadoMayorJugador1 = 0;
	if (dadosIniciales[0] > dadosIniciales[1]) {
		DadoMayorJugador1 = dadosIniciales[0];
	} else {
		DadoMayorJugador1 = dadosIniciales[1];
	}

	cout<<"El segundo jugador tira"<<endl;
	TiradaDados(dadosIniciales, 2);
	int SumJugador2 = dadosIniciales[0] + dadosIniciales[1];
	int DadoMayorJugador2 = 0;
	if (dadosIniciales[0] > dadosIniciales[1]) {
		DadoMayorJugador2 = dadosIniciales[0];
	} else {
		DadoMayorJugador2 = dadosIniciales[1];
	}

	if (SumJugador1 > SumJugador2) {
		jugadorPrimero = Jugador1;
	} else if (SumJugador1 == SumJugador2) {
		if (DadoMayorJugador1 > DadoMayorJugador2) {
			jugadorPrimero = Jugador1;
		} else {
			jugadorPrimero = Jugador2;
		}
	} else {
		jugadorPrimero = Jugador2;
	}

	return jugadorPrimero;
}

void TiradaDados(int Vec[], int Tam){
	srand(time(NULL));
	for (int i=0; i<Tam; i++){
		Vec[i]=(rand()%6+1);
		cout<<"Los dados dieron: "<<Vec[i]<<endl;
	}
}
bool ProcesarDados(int Vec[], int Tam, int vecStat, bool *BanderaTresDatos){
	int Trufas=0, Oinks=0;
	bool SiguienteRonda = true;
	bool puedeElegirSiguienteRonda = true;
	if(hayUnaCaraDistinta(Vec, Tam) && ningunaEsAs(Vec, Tam)) {

	} else if (sonTodasIgualesEntreSi(Vec, Tam) && ningunaEsAs(Vec, Tam)) {

	} else if (hayUnaCaraDistinta(Vec, Tam) && !ningunaEsAs(Vec, Tam)) {

	} else if (((Tam == 2 && sonTodasIgualesEntreSi(Vec, Tam)) || Tam == 3 && hayDosCarasIgualesYSonAses(Vec, Tam))&& todasLasCarasSonAses(Vec, Tam)) {

	} else if (Tam == 3 && sonTodasIgualesEntreSi(Vec, Tam) && todasLasCarasSonAses(Vec, Tam)) {

	}
	if (puedeElegirSiguienteRonda) {
		// ver si elegir siguiente ronda o si no se puede
		// SiguienteRonda...
	}
	return SiguienteRonda;
}
bool hayUnaCaraDistinta(int Vec, int Tam) {
	bool esDistinta = Vec[0] != Vec[Tam - 1];
	if (Tam == 3 && !esDistinta) {
		for (int i = 0; i < Tam - 1; i++){
			if(Vec[i] != Vec[i+1]) {
				esDistinta = true;
			}
		}
	}
	return esDistinta;
}

bool sonTodasIgualesEntreSi(int Vec, int Tam) {
	bool sonIguales = Vec[0] == Vec[Tam - 1];
	if (Tam == 3) {
		for (int i=0; i<Tam-1; i++){
			if(Vec[i] == Vec[i+1]) {
				sonIguales = true;
			}
		}
	}
	return sonIguales;
}

bool hayDosCarasIgualesYSonAses(int Vec, int Tam) {
	bool sonDosIguales = false;
	bool sonAses = false;
	bool sonTodasIguales = false;
	for (int i=0; i<Tam-1; i++){
		if(Vec[i] == Vec[i+1] && Vec[i] == 1) {
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

bool ningunaEsAs(int Vec, int Tam) {
	bool hayUnAs = false;
	for (int i=0; i<Tam; i++){
		if(Vec[i] == 1) {
			hayUnAs = true;
		}
	}
	return hayUnAs;
}

bool todasLasCarasSonAses(int Vec, int Tam) {
	bool sonAses = true;
	for (int i=0; i<Tam; i++){
		if(Vec[i] != 1) {
			sonAses = false;
		}
	}
	return sonAses;
}

void Jugar(int vecStat1[], int vecStat2[]) {
	const int Rondas=5;
	bool BanderaTresDatos = false;
	bool SiguienteRonda=false;
	for (int i=0; i<Rondas; i++){
		jugarRonda(vecStat1, *BanderaTresDatos);
		jugarRonda(vecStat2, *BanderaTresDatos);
	}
}

void jugarRonda(int vecStat, bool *BanderaTresDatos) {
	int DosDados[2]={}, TresDados[3]={};
	const int Tam2=2, Tam3=3;
	const int CantJugadores=2;
	for(int i=0; i<CantJugadores; i++){
		SiguienteRonda=false;
		while(!SiguienteRonda){
			if (BanderaTresDatos) {
				TiradaDados(DosDados, Tam2);
				SiguienteRonda = ProcesarDados(DosDados, Tam2, vecStat, *BanderaTresDatos);
			} else {
				TiradaDados(TresDados, Tam3);
				SiguienteRonda = ProcesarDados(TresDados Tam3, vecStat, *BanderaTresDatos);
			}
		}
	}
}

