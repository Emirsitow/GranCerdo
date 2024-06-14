#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<string.h>
#include <limits>
using namespace std;

#include "FuncionesCerdo.h"



int main(){
	int opcion=1, stats1[4]={},  stats2[3]={};
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



