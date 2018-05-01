/*
 * lectura.cpp
 *
 *  Created on: 28/04/2018
 *      Author: romero_gerard
 */
#include "lectura.h"
#include <iostream>
#include<string>
using namespace std;
#include<fstream>

void ManejoArchivoLectura::pedirNombreDeArchivo(){
	string nombre;
	cout<<"Ingrese el Nombre del Archivo: ";
	cin>>nombre;
	this->nombreDeArchivo=nombre;
	abrirArchivoLectura();
}

void ManejoArchivoLectura::abrirArchivoLectura(){
	string nombre = this->nombreDeArchivo;
	(this->variableArchivo).open(nombre.c_str());
	if (this->variableArchivo.fail()){
		cout<<"NO SE PUEDE ABRIR EL ARCHIVO"<<endl;
		pedirNombreDeArchivo();
	}
	this->existeArchivo = true;
}

void ManejoArchivoLectura::leerArchivo(){
	string linea;
	while(!(this->variableArchivo.eof())){
		getline(this->variableArchivo,linea);
		cout<<linea<<endl;
	}
}

ManejoArchivoLectura::~ManejoArchivoLectura(){
	if ((this->existeArchivo)){
		(this->variableArchivo).close();
		this->existeArchivo=false;
	}
	else{
		cout<<"Archivo que desea cerrar No Existe."<<endl;
	}
}
