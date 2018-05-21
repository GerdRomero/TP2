/*
 * Semilla.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#include "Semilla.h"

Semilla::Semilla(Lista<string> &datos) {
	this->costo=(ui)((char*)datos.obtener(2).c_str());
	this->tiempoCosecha=(ui)((char)*datos.obtener(3).c_str());
	this->rentabilidad=(ui)((char)*datos.obtener(4).c_str());
	this->tiempoRecup=(ui)((char)*datos.obtener(5).c_str());
	this->aguaTurno=(ui)((char)*datos.obtener(6).c_str());
}
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

Semilla::~Semilla() {
	// TODO Auto-generated destructor stub
}

