/*
 * Juego.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Juego.h"
#include "Jugador.h"
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

void Juego::descontarTurnos(){
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

void Juego::contarTurnos(){

	this->turnosJuego-=1;
}
void Juego::comenzarTurno(){

	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		this->jugadorActual=this->jugadores->obtenerCursor();
		Jugar();
	}
	contarTurnos();
}

void Juego::Jugar(){
	while(this->jugadorActual->noFinalizado()){
		this->jugadorActual->obtenerTerrenoEnJuego(this->jugadorActual->terrenoValido());
		mostrarOpciones();

	}
}

ui Juego::opcionValida(){
	char opcion;
	std::cout <<"Opcion: ";
	std::cin>> opcion;
	while ((int)opcion < 0 || (int)opcion > 5){
		std::cout <<"Opcion: ";
		std::cin>> opcion;
	}
	return ((ui)opcion);

}

void  Juego::opciones(){
	std::cout<<"********************"<<std::endl;
	std::cout<<"******* MENU *******"<<std::endl;
	std::cout<<"********************"<<std::endl;
	std::cout<<"1)SEMBRAR."<<std::endl;
	std::cout<<"2)REGAR."<<std::endl;
	std::cout<<"3)COSECHAR."<<std::endl;
	std::cout<<"7)PASAR TURNO."<<std::endl;
}

	
void Juego::mostrarOpciones(){
	opciones();
	int opcionMenu = opcionValida();
	switch(opcionMenu){
	case 1:
		this->jugadorActual->sembrarTerreno();
		break;
	case 2:
		this->jugadorActual->regarTerreno();
		break;
	case 3:
		this->jugadorActual->cosecharTerreno();
		break;
	case 4:
		this->jugadorActual->agregarTerreno();
		break;
	case 5:
		this->jugadorActual->comprarSemillas();
		break;
	case 6:
		/*Cambia pos de terreno a terrenoEnJuego*/
		this->jugadorActual->obtenerTerrenoEnJuego(this->jugadorActual->terrenoValido());

		break;
	case 7:
		this->jugadorActual->finalizarTurno();

		break;

	default:
		break;


	}
}
Juego::~Juego() {
	delete this->jugadores;
}


