/*
 * Terreno.cpp
 *
 *  Created on: 13 may. 2018
 *      Author: cristian
 */

#include "Terreno.h"

Terreno::Terreno() {
	this->Sembrada=false;
	this->parcelaPodrida=false;
	this->terreno = NULL;
	this->seCosecho=false;
	this->Parcela.tipo = '#';
	this->Parcela.numeroDeRiegos = 0;
	this->Parcela.recuperacion = 0;
	this->Parcela.rentabilidad = 0;
	this->Parcela.tiempoHastaCosecha = 0;
	this->Parcela.tiempoTrasSiembra = 0;
	this->ESTADO = vacia;

}

ui Terreno::obtenerCantidadDeFilas(){
	return this->cantidadDeFilas;
}

ui Terreno::obtenerCantidadDeColumnas(){
	return this->cantidadDecolumas;
}

Terreno** Terreno::crearTerreno(ui fila, ui columna){
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];

	return terreno;
}

bool Terreno::estaSembrada(){
	return(!((this->ESTADO == vacia) && !(this->parcelaPodrida)));
}

bool Terreno::regoCorrectamente(){
	return (this->Parcela.numeroDeRiegos == this->Parcela.tiempoHastaCosecha);
}

void Terreno::cambiarACosechado(){
	this->Parcela.rentabilidad  = 0;
	this->Parcela.tiempoHastaCosecha = 0;
	this->ESTADO = reposo;
	this->Parcela.numeroDeRiegos = 0;
	this->seCosecho = true;
	this->Parcela.tipo = '#';
}

void Terreno::recuperarParcela(){
	if ((this->seCosecho && (this->Parcela.recuperacion == 0)) ||
			(this->parcelaPodrida && (this->Parcela.recuperacion == 0))){
		this->Sembrada = false;
	}
}

void Terreno::decrementarRecuperacion(){
	if (((this->Parcela.recuperacion > 0) && this->seCosecho) || (this->parcelaPodrida  && this->Parcela.recuperacion > 0)){
		this->Parcela.recuperacion --;
	}
}

void Terreno::incrementarTiempoTrasSiembra(){
	this->Parcela.tiempoTrasSiembra++;
}

void Terreno::podrirParcela(){
	if((this->Parcela.numeroDeRiegos) < (this->Parcela.tiempoTrasSiembra)){
		this->ESTADO = reposo;
		this->Parcela.tipo = 'P';
		this->Parcela.rentabilidad  = 0;
		this->Parcela.tiempoHastaCosecha = 0;
		this->Parcela.numeroDeRiegos = 0;
		this->parcelaPodrida = true;
	}
}

void Terreno::actualizando(){
	this->incrementarTiempoTrasSiembra();
	this->podrirParcela();
	this->decrementarRecuperacion();
	this->recuperarParcela();
}

ui Terreno::obtenerRentabilidad(){
	return this->Parcela.rentabilidad;
}

void Terreno::aumentarNumeroDeRiegos(){
	this->Parcela.numeroDeRiegos++;
}

void Terreno::cambiarEstadoDeParcelaSembrada(Semillas * semilla){
	this->Parcela.rentabilidad = semilla->obtenerRentabilidad();
	this->Parcela.recuperacion = semilla->obtenerRecuperacion();
	this->Parcela.tiempoHastaCosecha = semilla->obtenertiempoHastaCosecha();
	this->Sembrada = true;
	this->ESTADO = sembrada;
	this->Parcela.numeroDeRiegos = 0;
}



