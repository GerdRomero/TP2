/*
 * escritura.cpp
 *
 *  Created on: 28/04/2018
 *      Author: romero_gerard
 */

#include "escritura.h"
#include <iostream>
#include<string>
using namespace std;
#include<fstream>

void ManejoArchivoEscritura::pedirNombreDeArchivo(){
	string nombre;
	cout<<"Ingrese el Nombre del Archivo: ";
	cin>>nombre;
	this->nombreDeArchivo=nombre;
	abrirArchivoEscritura();
}

void ManejoArchivoEscritura::abrirArchivoEscritura(){
	string nombre = this->nombreDeArchivo;
	(this->variableArchivo).open(nombre.c_str(),ios::app);
	this->existeArchivo = true;
}

void ManejoArchivoEscritura::tiposDeCultivos(){
	string nombre,costo,tiempo,rentabilidad,recuperacion,consumoDeAgua;
	bool seguir=true;
	char opcion;
	while (seguir){
		cout<<"Nombre de Cultivo: ";
		cin>>nombre;
		cout<<"Costo del cultivo: ";
		cin>>costo;
		cout<<"Tiempo hasta cosechar: ";
		cin>>tiempo;
		cout<<"Rentabilidad: ";
		cin>>rentabilidad;
		cout<<"Tiempo de recuperacion: ";
		cin>>recuperacion;
		cout<<"Consumo de agua: ";
		cin>>consumoDeAgua;
		(this->variableArchivo)<<nombre<<","<<costo<<","<<tiempo<<","<<rentabilidad
				<<","<<recuperacion<<","<<consumoDeAgua<<endl;

		cout<<"Seguis s/n: ";
		cin>>opcion;

		if (toupper(opcion) == 'N'){
			seguir=false;
		}
	}
}

void ManejoArchivoEscritura::guardarEnvio(){
	string nombreDeDestino,distanciaKM,precio;
	char nombreDeCultivo;
	cout<<"Nombre del destino de envio: ";
	cin>>nombreDeDestino;
	cout<<"Distancia en Kilometros: ";
	cin>>distanciaKM;
	cout<<"Precio de Envio: ";
	cin>>precio;
	cout<<"Nombre de Cultivo: ";
	cin>>nombreDeCultivo;
	nombreDeCultivo = (toupper(nombreDeCultivo));
	(this->variableArchivo)<<nombreDeDestino<<","<<distanciaKM<<","<<precio
			<<","<<nombreDeCultivo<<endl;

	cout<<"***** GRABADO CORRECTAMENTE ****"<<endl;
}



ManejoArchivoEscritura::~ManejoArchivoEscritura(){
	if ((this->existeArchivo)){
		(this->variableArchivo).close();
		this->existeArchivo=false;
	}
	else{
		cout<<"Archivo que desea cerrar No Existe."<<endl;
	}
}
