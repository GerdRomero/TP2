/*
 * Jugador.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Jugador.h"
#include "Terreno.h"
#include <iostream>

Jugador::Jugador() {
	// TODO Auto-generated constructor stub
	this->estado.cantAgua=10;
	this->estado.creditos=50;
	this->estado.turnosRestantes=20;
	this->terrenos=NULL;
	this->terrenoEnJuego=NULL;
	this->posicionTerrenoEnJuego=0;
	this->finTurno=false;
	agregarTerreno();

}
void Jugador::finalizarTurno(){

}
void Jugador::agregarTerreno(){

	pedirPosicion();
	ui fila=this->pos[0];
	ui columna=this->pos[1];
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
}

void Jugador::obtenerTerrenoEnJuego(ui posicionTerreno){
	this->terrenoEnJuego=this->terrenos->obtener(posicionTerreno);

}

void Jugador::sembrarTerreno(){}
void Jugador::regarTerreno(){}
void Jugador::cosecharTerreno(){}
Terreno**Jugador::obtenerTerreno(){
	return this->terrenoEnJuego;

}
ui Jugador::filaTerreno(){
	ui fila=this->pos[0];
	return fila;
}
ui Jugador::columnaTerreno(){
	ui col=this->pos[1];
	return col;
}


void Jugador::pedirPosicion(){
	ui fila, col;
	std::cout<<"Ingrese fila:"<<"\n";
	std::cin>>fila;
	this->pos[0]=fila;
	std::cout<<"Ingrese columna:"<<"\n";
	std::cin>>col;
	this->pos[1]=col;

}
Jugador::Jugador(int dificultad){
		switch(dificultad){
		case 1:
			this->estado.creditos=30;
			this->estado.turnosRestantes=14;
			break;
		case 2:
			this->estado.creditos=20;
			this->estado.turnosRestantes=12;
			break;
		case 3:
			this->estado.creditos=10;
			this->estado.turnosRestantes=10;
			break;
		default:
			this->estado.cantAgua=0;
			this->terrenos=NULL;
			this->terrenoEnJuego=NULL;
			this->finTurno=false;
			this->posicionTerrenoEnJuego=0;

		}
	}

Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

