/*
 * Jugador.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Jugador.h"
#include "Terreno.h"

Jugador::Jugador() {
	// TODO Auto-generated constructor stub
	this->estado.cantAgua=10;
	this->estado.creditos=50;
	this->estado.turnosRestantes=20;
	this->terrenos=NULL;
	this->terrenoEnJuego=NULL;
	this->posicionTerrenoEnJuego=0;

}
void Jugador::agregarTerreno(ui fila, ui columna){
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
}
void Jugador::avanzarTerreno(){
	if(this->terrenoEnJuego==NULL){
		this->terrenos->avanzarCursor();
		this->terrenoEnJuego=this->terrenos->obtenerCursor();
		this->posicionTerrenoEnJuego+=1;
	}
	else{
		while(this->terrenos->avanzarCursor()){
			this->terrenos->iniciarCursor();

		}
		this->terrenoEnJuego=this->terrenos->obtener(this->posicionTerrenoEnJuego);
		this->terrenos->avanzarCursor();
		this->terrenoEnJuego=this->terrenos->obtenerCursor();
	}


}

void Jugador::sembrarTerreno(int fila, int columna){}
void Jugador::regarTerreno(int fila, int columna){}
void Jugador::cosecharTerreno(int fila, int columna){}
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

		}
	}

Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

