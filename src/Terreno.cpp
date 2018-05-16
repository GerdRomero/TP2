/*
 * Terreno.cpp
 *
 *  Created on: 13 may. 2018
 *      Author: cristian
 */

#include "Terreno.h"

Terreno::Terreno() {
	this->estaSembrada=false;
	this->parcelaPodrida=false;
	this->terreno=0;
	this->seCosecho=false;
	this->estado=VACIA;
	this->rentabilidad=0;
	this->turnosDeRecuperacion=0;
	this->turnosParaCosechar=0;

}

Terreno** Terreno::crearTerreno(ui fila, ui columna){
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];

	return terreno;
}


