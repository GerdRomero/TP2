/*
 * Mercado.cpp
 *
 *  Created on: 21 may. 2018
 *      Author: cristian
 */

#include "Mercado.h"
#include"Jugador.h"



Mercado::Mercado(struct Semillas cultivos){
	this->costoTipoA=cultivos.tipoA.precio();
	this->costoTipoB=cultivos.tipoB.precio();
	this->costoTipoC=cultivos.tipoC.precio();
	this->costoParcelaTerreno=0;
	this->tipoA=&cultivos.tipoA;
	this->tipoB=&cultivos.tipoB;
	this->tipoC=&cultivos.tipoC;
}
void Mercado::mostrarInfo(){}
ui Mercado::venderTamanioAlmacen(ui tamanio){
	ui costo;
	costo=2*tamanio;
	return costo;
}
ui Mercado::venderCosecha(char tipo, ui cantidad){
	ui ganancia;
	if(tipo==this->tipoA->obtenerTipo()){
		ganancia=this->tipoA->ganancia()*cantidad;
	}
	else if(tipo==this->tipoB->obtenerTipo()){
		ganancia=this->tipoB->ganancia()*cantidad;

	}else if(tipo==this->tipoC->obtenerTipo()){
		ganancia=this->tipoB->ganancia()*cantidad;
	}
	else{ ganancia=0;}
	return ganancia;
}
ui Mercado::cotizarTerreno(Terreno **terrenoCotizar){
	ui ganancia=0;
	ui col=terrenoCotizar[0][0].obtenerCantidadDeColumnas();
	ui fil=terrenoCotizar[0][0].obtenerCantidadDeFilas();
	ganancia=(fil*col)*5;
	/*agregar metodo, obtener dimensiones del terreno y devolver ganancia*/

	return ganancia;
}
ui Mercado::venderTerreno(ui fila, ui columna){
	ui ganancia=0;
	

	return ganancia;
}
ui Mercado::ventaSemillas(char tipoSemilla,ui cantidad){
	ui costo;
	switch(tipoSemilla){
	case 'A':
		costo=this->costoTipoA;
		break;
	case 'B':
		costo=this->costoTipoB;
		break;
	case 'C':
		costo=this->costoTipoC;
		break;
	}
	costo=costo*cantidad;

	return costo;
}


Mercado::~Mercado() {
	// TODO Auto-generated destructor stub
}

