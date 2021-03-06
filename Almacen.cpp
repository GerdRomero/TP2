/*
 * Almacen.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#include"ArchivosL.h"
#include "Almacen.h"
#include <iostream>
#define VACIO ""

Almacen::Almacen(ui tam){
	this->cosechas=NULL;
	this->espacioDisponible=0;
	this->tam=tam;
	this->cosechaEnviar=NULL;
}

void Almacen::extender(ui tamanio){

	this->tam+=tamanio;

}
void Almacen::leerDestino(){

	ArchivosL destinos;
	destinos.pedirNombreDeArchivo();
	destinos.abrirArchivoLectura();
	std::string linea=destinos.leerLinea();
	while(linea!=VACIO){
		Lista<std::string>datosDestino;
		destinos.datosLista(linea, datosDestino);
		cargarDestinosCosechas(datosDestino);
	}
}
ui Almacen::opcionValida(){
	ui opcion;
	std::cout<<"INgrese una opcion para enviar: "<<std::endl;
	std::cin>>opcion;
	if(opcion>3 ||opcion==0|| !isdigit(opcion)){
		opcionValida();
	}
	return opcion;
}
ui Almacen::elegirCosecha(){
	/*Mostrar cosechas disponibles, metodo aparte*/
	std::cout<<this->cosechas->tipoA.tipo<<this->cosechas->tipoA.destino<<std::endl;
	std::cout<<"1-"<<std::endl;
	std::cout<<"2-"<<std::endl;
	std::cout<<"3-"<<std::endl;
	ui cosechaEnviar=opcionValida();
	ui cantCosecha;
	switch(cosechaEnviar){
	case 1:
		cantCosecha=this->cosechas->tipoA.cant;
		this->cosechaEnviar=&this->cosechas->tipoA;
		//this->cosechas->tipoA.cant=0;
		break;
	case 2:
		cantCosecha=this->cosechas->tipoA.cant;
		this->cosechaEnviar=&this->cosechas->tipoB;
		//this->cosechas->tipoB.cant=0;
		break;
	case 3:
		cantCosecha=this->cosechas->tipoA.cant;
		this->cosechaEnviar=&this->cosechas->tipoC;
		//this->cosechas->tipoC.cant=0;
		break;
	}
	return cantCosecha;
}
ui Almacen::prepararCosecha(ui cantCosecha){
	ui costo=cantCosecha*this->cosechaEnviar->costo;
	return costo;
}

void Almacen::cargarDestinosCosechas(Lista<std::string>&datos){
	std::string tipoCultivo=datos.obtener(4);
	if(tipoCultivo=="A"){
		this->cosechas->tipoA.destino=datos.obtener(1).c_str();
		this->cosechas->tipoA.costo=(ui)(char)*datos.obtener(1).c_str();
		this->cosechas->tipoA.tipo=(char)*datos.obtener(4).c_str();
		}
	else if(tipoCultivo=="B"){
		this->cosechas->tipoB.destino=datos.obtener(1).c_str();
		this->cosechas->tipoB.costo=(ui)(char)*datos.obtener(1).c_str();
		this->cosechas->tipoB.tipo=(char)*datos.obtener(4).c_str();

		}
	else{
		this->cosechas->tipoC.destino=datos.obtener(1).c_str();
		this->cosechas->tipoC.costo=(ui)(char)*datos.obtener(1).c_str();
		this->cosechas->tipoC.tipo=(char)*datos.obtener(4).c_str();

		}
}

ui Almacen::cantidadDeCosecha(char tipoCosecha){
	ui cant;
	switch(tipoCosecha){
	case 'A':
		cant=this->cosechas->tipoA.cant;
		break;
	case'B':
		cant=this->cosechas->tipoB.cant;
		break;
	case'C':
		cant=this->cosechas->tipoC.cant;
		break;
	}
	return cant;
}


ui Almacen::cantEspacioDisponible(){

	return this->espacioDisponible;
}
void Almacen::elegirCosechaGuardar(ui cantCosecha, char tipoCosecha){
	switch(tipoCosecha){

	case 'A':
		this->cosechas->tipoA.cant+=cantCosecha;
		break;
	case 'B':
		this->cosechas->tipoB.cant+=cantCosecha;
		break;
	case 'C':
		this->cosechas->tipoC.cant+=cantCosecha;
		break;
	}
	this->espacioDisponible-=cantCosecha;
}
void Almacen::guardarCosecha(ui cantCosecha,  char tipoCosecha)
{
	ui hayEspacio=this->espacioDisponible-cantCosecha;
	if (hayEspacio>=0){
		elegirCosechaGuardar(cantCosecha,tipoCosecha);
	}
	else{
		std::cout<<"Necesita extender el almacen o vender cosecha..."<<std::endl;
	}
	}
