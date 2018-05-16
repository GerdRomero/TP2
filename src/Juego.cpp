/*
 * Juego.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Juego.h"
#include<iostream>


Juego::Juego() {
	this->jugadores=new Lista<Jugador*>;
	this->cantJugadores=0;
	this->turnosJuego=10;
	this->estadoGranjeros.comenzado=true;
	this->estadoGranjeros.jugando=true;
	this->estadoGranjeros.finTurno=false;
	this->jugadorActual=NULL;
}

void Juego::contarTurnos(){
	if(this->estadoGranjeros.finTurno){
		this->turnosJuego-=1;
	}
}
void Juego::pasarTurno(){
	if(!this->estadoGranjeros.finTurno){

	}
}
void Juego::agregarJugadores(int cantidad, int dif){
	{
		for(int i=1; i<=cantidad; i++){
			Jugador *jugador=new Jugador(dif);
			this->jugadores->agregar(jugador);
			this->cantJugadores +=1;
			}
		}
}
Jugador* Juego::obtenerJugador(){
	return this->jugadorActual;
}
void Juego::comenzarTurno(){
	this->jugadores->iniciarCursor();
	/*while(!this->estadoGranjeros.finTurno){
		this->estadoGranjeros.finTurno=jugar(opcionValida());

	}*/
	while(this->jugadores->avanzarCursor()){
		this->jugadorActual=jugadores->obtenerCursor();
		jugar(opcionValida());

	}

	contarTurnos();
	pasarTurno();
}

void Juego::jugar(int opcionMenu){
	this->jugadorActual->pedirPosicion();
	ui fila=this->jugadorActual->filaTerreno();
	ui col=this->jugadorActual->columnaTerreno();

	//this->jugadorActual->avanzarTerreno();
	switch(opcionMenu){
	case 1:
		this->jugadorActual->sembrarTerreno(fila, col);
		break;
	case 2:
		this->jugadorActual->regarTerreno(fila, col);
		break;
	case 3:
		this->jugadorActual->cosecharTerreno(fila,col);
		break;
	case 4:
		this->jugadorActual->agregarTerreno(fila, col);
		break;
	case 5:
		this->jugadorActual->comprarSemillas();
		break;
	case 6:
		this->jugadorActual->avanzarTerreno();
		break;
	case 7:
		/*Finalizar turno Jugador*/

	default:
		break;


	}
}
Juego::~Juego() {
	delete this->jugadores;
}


