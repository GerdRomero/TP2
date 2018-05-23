/*
 * Jugador.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Jugador.h"
#include "Terreno.h"
#include "ArchivosL.h"
#include "Lista.h"
#include<iostream>
#include <string>
#include <list>
#define VACIO ""


void Jugador::cargarDificJugador(ui dificultad){
	ui N,M;
	switch(dificultad){
	case 1:
		N=2, M=2;
		break;
	case 2:
		N=3, M=3;
		break;
	case 3:
		N=4, M=4;
		break;
	agregarTerreno(N,M);
	this->estado.creditos=2*N*M;
	this->estado.cantAgua=N*M;
	this->estado.turnosRestantes=2*N*M;
	this->aSembrar=NULL;

	}
}



bool Jugador::noFinalizado(){
	return this->finTurno;
}

void Jugador::agregarTerreno(ui fil, ui col){
	//pedirPosicion();
	ui fila=this->pos[0]||fil;
	ui columna=this->pos[1]||col;
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
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
ui Jugador::terrenoValido(){
	ui posTerreno;
	std::cout<<"Ingrese un numero de terreno"<<std::endl;
	std::cin>>posTerreno;
	while(posTerreno>this->cantTerrenos|| posTerreno<=0){
		std::cout<<"Ingrese un numero de terreno"<<std::endl;
		std::cin>>posTerreno;
	}
	return posTerreno;
}

void Jugador::sembrarTerreno(){
	pedirPosicion();
	if (!(this->terrenoEnJuego[this->pos[0]][this->pos[1]].estaSembrada())){
		this->terrenoEnJuego[this->pos[0]][this->pos[1]].cambiarEstadoDeParcelaSembrada(semilla);
		this->cantidad.creditos = (this->cantidad.creditos - this->semilla->obetenerCosto());
	}
}
void Jugador::regarTerreno(){
	pedirPosicion();
	if (this->terrenoEnJuego[this->pos[0]][this->pos[1]].estaSembrada()){
		this->cantidad.agua = this->cantidad.agua - semilla->obtenerCostoDeAgua();
		this->terrenoEnJuego[pos[0]][pos[1]].aumentarNumeroDeRiegos();
	}
}

void Jugador::cosecharTerreno(){
	pedirPosicion();
	if((this->terrenoEnJuego[pos[0]][pos[1]].estaSembrada()) &&
		(this->terrenoEnJuego[pos[0]][pos[1]].regoCorrectamente())){

		this->cantidad.creditos -= this->terrenoEnJuego[pos[0]][pos[1]].obtenerRentabilidad();
		this->terrenoEnJuego[this->pos[0]][this->pos[1]].cambiarACosechado();
	}
}

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
void Jugador::mostrarInfoSemilla(){
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;

}
char Jugador::tipoSemillaValida(){
	char semillaValida;
	/*hacer metodo*/
	return semillaValida;
}
void Jugador::pedirSemillaSembrar(){
	char tipoSemilla;
	mostrarInfoSemilla();
	std::cout<<"Ingrese la semilla a sembrar: "<<std::endl;
	std::cout<<"1- A "<<std::endl;
	std::cout<<"2- B "<<std::endl;
	std::cout<<"3- C "<<std::endl;
	std::cin>>tipoSemilla=tipoSemillaValida();
	switch(tipoSemilla){

	case 'A':
		this->aSembrar=this->cultivos.tipoA;
		break;
	case 'B':
		this->aSembrar=this->cultivos.tipoB;
		break;
	case 'C':
		this->aSembrar=this->cultivos.tipoC;
		break;
	}

}
void Jugador::finalizarTurno(){

	this->finTurno=true;
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
Jugador::Jugador(ui dificultad){
	this->terrenos=NULL;
	this->almacen=NULL;
	this->posicionTerrenoEnJuego=0;
	this->finTurno=false;
	this->cantTerrenos=0;
	this->terrenos=NULL;
	this->almacen=NULL;
	cargarDatos();
	cargarDificJugador(dificultad);
}
void Jugador::cargarDatos(){
	ArchivosL cultivos;
	cultivos.pedirNombreDeArchivo();
	cultivos.abrirArchivoLectura();
	std::string linea=cultivos.leerLinea();
	while(linea!=VACIO){
		Lista<string>datosCultivo;
		datosLista(linea, datosCultivo);
		cargarCultivosJugador(datosCultivo);
	}
}

void Jugador::cargarCultivosJugador(Lista<std::string>&datos){
	std::string tipoSemilla=datos.obtener(1);
	if(tipoSemilla=="A"){
		Semilla tipoA(datos);
		this->cultivos.tipoA=&tipoA;
	}
	else if(tipoSemilla=="B"){
		Semilla tipoB(datos);
		this->cultivos.tipoB=&tipoB;
	}
	else{
		Semilla tipoC(datos);
		this->cultivos.tipoC=&tipoC;

	}
}
void Jugador::datosLista(std::string linea,Lista<std::string>&datos){
	std::string dato;
	for(ui i=0;linea.length();i++){
		if(linea[i]!=','){
			dato+=linea[i];
		}
		else{
			datos.agregar(dato);
			dato="";
		}
	}
}
Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

