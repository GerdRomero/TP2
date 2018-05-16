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
	cout <<"Opcion: ";
	cin>> opcion;
	while ((int)opcion < 0 && (int)opcion > 5){
		cout <<"Opcion: ";
		cin>> opcion;
	}
	return ((int)opcion);

}

void  Juego::opciones(){
	cout<<"********************"<<endl;
	cout<<"******* MENU *******"<<endl;
	cout<<"********************"<<endl;
	cout<<"1)SEMBRAR."<<endl;
	cout<<"2)REGAR."<<endl;
	cout<<"3)COSECHAR."<<endl;
	cout<<"7)PASAR TURNO."<<endl;
}

	
void Juego::mostrarOpciones({
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
		this->jugadorActual->avanzarTerreno();
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


