/*
 * jugador.cpp
 *
 *  Created on: 15/04/2018
 *      Author: romero_gerard
 */

#include "jugador.h"
#include <iostream>
using namespace std;

void Jugador :: pedirParcela(int fila, int columna){
	cout <<"Ingrese numero de Fila: ";
	cin >> fila;
	cout << "Ingrese numero de columna: ";
	cin >> columna;

	filaPedida = fila;
	columnaPedida = columna;
}

void Jugador :: comparSemillas(char eleccionDeSemilla , int cantidadRequerida){
	cout << "Tipo de Semilla que desea comprar: ";
	cin >> toupper(eleccionDeSemilla);
	cout << "Cunatas semillas desea comprar: ";
	cin >> cantidadRequerida;

	tipoDeSemilla = eleccionDeSemilla;
	semillasCompradas = cantidadRequerida;

}

