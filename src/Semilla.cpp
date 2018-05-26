/*
 * Semilla.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#include "Semilla.h"

Semilla::Semilla() {
	this->tipo=64;
	this->costo=NULL;
	this->tiempoCosecha=NULL;
	this->rentabilidad=NULL;
	this->tiempoRecup=NULL;
	this->aguaTurno=NULL;
	this->cantidadDisponible=0;
}
/*
void Semilla::agregarInfo(Lista<std::string> *datos){

	this->tipo=(char)*datos->obtener(1).c_str();
	this->costo=(ui)((char)*datos->obtener(2).c_str());
	this->tiempoCosecha=(ui)((char)*datos->obtener(3).c_str());
	this->rentabilidad=(ui)((char)*datos->obtener(4).c_str());
	this->tiempoRecup=(ui)((char)*datos->obtener(5).c_str());
	this->aguaTurno=(ui)((char)*datos->obtener(6).c_str());
	this->cantidadDisponible=0;


}
*/
ui Semilla::precio(){
	return this->costo;
}
ui Semilla::cantidadAguaTurno(){
	return this->aguaTurno;
}
ui Semilla::turnosRecuperacion(){
	return this->tiempoRecup;
}
ui Semilla::ganancia(){
	return this->rentabilidad;
}
ui Semilla::turnosCosecha(){
	return this->tiempoCosecha;
}
void Semilla::agregar(ui cantAgregar){
	this->cantidadDisponible+=cantAgregar;
}
bool Semilla::haySemilla(){
	return this->cantidadDisponible>0;
}
ui Semilla::cantDisponible(){

	return this->cantidadDisponible;
}

void agregarCosto(std::string costo){
		this->costo=4;
}
void agregarTiempoCosec(std::string turnos){
	this->tiempoCosecha=5;//atoi(turnos.c_str());
	//std::cout<<this->tiempoCosecha;
}
void agregarRentabilidad(std::string ganancia){
	this->rentabilidad=5;// atoi(ganancia.c_str());
	//std::cout<<this->rentabilidad;
}
void agregarTiempoRecup(std::string recuperacion){
	this->tiempoRecup=6;//atoi(recuperacion.c_str());
	//std::cout<<this->tiempoRecup;
}
void agregarAguaTurno(std::string aguaPorTurno){
	this->aguaTurno=7;//atoi(aguaPorTurno.c_str());
	//std::cout<<this->aguaTurno;
}
Semilla::~Semilla() {
	// TODO Auto-generated destructor stub
}

