#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<string.h>
#include <limits>
using namespace std;

#include "FuncionesCerdo.h"



int main(){
	int opcion=1, stats1[3]={},  stats2[3]={}, PDV1=0, PDV2=0, trufas1, trufas2, oink1, oink2, Cada50[2];
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
                    if (stats1[0]>stats2[0]){
                        PDV1+=5;
                    }
                    else if (stats2[0]>stats1[0]){
                        PDV2+=5;
                    }
                    else {
                        PDV1+=5;
                        PDV2+=5;
                    }
                    oink1=stats1[1]*2;
                    oink2=stats2[1]*2;
                    trufas1=stats1[0];
                    trufas2=stats2[0];

                        while (trufas1 >= 50) {
                            trufas1 -= 50;
                                PDV1++;
                        }
                            while (trufas2 >= 50) {
                                trufas2 -= 50;
                                PDV2++;
                            }
                            Cada50[0]=PDV1*50;
                            Cada50[1]=PDV2*50;

                            if(stats1[2]>stats2[2]){
                                PDV1+=5;
                            }
                            else if(stats2[2]>stats1[2]){
                                PDV2+=5;
                            }
                            else {
                                PDV2+=5;
                                PDV1+=5;
                            }
				break;
			case 2:
				if (PDV1>PDV2){
                    cout<<Jugador1<<PDV1<<" PDV "<<endl;
				}
				else if (PDV2>PDV1){
                    cout<<Jugador2<<PDV2<<" PDV "<<endl;
				}
				break;
			case 3:
				cout<<"Creditos: "<<endl;
				cout<<"Emiliano Ariel Civitillo"<<endl;
				cout<<"Legajo: 28893"<<endl;
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



