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
	this->posJugadorEnJugadores=0;
}


void Juego::agregarJugadores(ui cantidad){
	{
		for(ui i=1; i<=cantidad; i++){
			mostrarDificultades();
			Jugador *jugador=new Jugador(pedirDificultad());
			this->jugadores->agregar(jugador);
			this->cantJugadores +=1;
			}
		}
}
void Juego::mostrarDificultades(){
	std::cout<<"Granjeros V1.0:"<<std::endl;
	//std::cout<<"Info de Dif Facil "<<std::endl;
	//std::cout<<"Info de Dif Normal "<<std::endl;
	//std::cout<<"Info de Dif Dificil "<<std::endl;

}
ui Juego::pedirDificultad(){
	ui dificultad;
	std::cout<<"Ingrese una dificultad para los jugador/es(solo numeros): "<<std::endl;
	std::cout<<"1-Facil"<<std::endl;
	std::cout<<"2-Normal"<<std::endl;
	std::cout<<"3-Dificil"<<std::endl;
	std::cout<<"Ingrese una opcion: "<<std::endl;
	std::cin>>dificultad;
	if(dificultad>3||dificultad==0){
		pedirDificultad();
	}
	return dificultad;
}

Jugador* Juego::obtenerJugador(){
	return this->jugadorActual;
}

void Juego::contarTurnos(){

	this->turnosJuego-=1;
	if(this->turnosJuego==0){
		this->estadoGranjeros.finalizado=true;
	}
}
bool Juego::finJuego(){
		return this->estadoGranjeros.finTurno;
	}
void Juego::comenzarTurno(){

	this->jugadores->iniciarCursor();
	while(this->jugadores->avanzarCursor()){
		this->jugadorActual=this->jugadores->obtenerCursor();
		this->posJugadorEnJugadores+=1;
		Jugar();
	}

	contarTurnos();
}

void Juego::Jugar(){
	while(!this->jugadorActual->noFinalizado()){
		this->jugadorActual->obtenerTerrenoEnJuego(this->jugadorActual->terrenoValido());
		mostrarOpciones();

	}
}

ui Juego::opcionValida(){
	ui opcion;
	std::cout <<"Opcion: ";
	std::cin>> opcion;
	if (opcion <= 0 || opcion > 6){
		opcionValida();
	}
	return opcion;

}

void  Juego::menu(){
	std::cout<<"******* MENU *******"<<std::endl;
	std::cout<<"1)SEMBRAR."<<std::endl;
	std::cout<<"2)REGAR."<<std::endl;
	std::cout<<"3)COSECHAR."<<std::endl;
	std::cout<<"4)COMPRAR."<<std::endl;
	std::cout<<"5)CAMBIAR TERRENO EN JUEGO."<<std::endl;
	std::cout<<"6)MOSTRAR TERRENO EN JUEGO."<<std::endl;
	std::cout<<"7)PASAR TURNO."<<std::endl;
}
/*Para hacer pruebas*/
/*
void Juego::revisarEstados(){
	this->jugadorActual->terrenosSembrados();
}*/

void Juego::mostrarOpciones(){
	this->jugadorActual->mostrarTerreno();
	menu();
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
		this->jugadorActual->comprar();
		break;
	case 5:
		this->jugadorActual->obtenerTerrenoEnJuego(this->jugadorActual->terrenoValido());
		break;
	case 6:
		//this->jugadorActual->mostrarTerreno();
		break;
	case 7:
		this->jugadorActual->finalizarTurno();
		break;
	}
}

Juego::~Juego() {
	delete this->jugadores;
}


