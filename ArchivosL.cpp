/*
 * ArchivosL.cpp
 *
 *  Created on: 20 may. 2018
 *      Author: cristian
 */

#include "ArchivosL.h"

#include <iostream>
#include<string>
#define VACIO ""
using namespace std;
#include<fstream>

void ArchivosL::pedirNombreDeArchivo(){
	string nombre;
	std::cout<<"Ingrese el Nombre del Archivo: ";
	std::cin>>nombre;
	this->nombreDeArchivo=nombre;
	abrirArchivoLectura();
}

void ArchivosL::abrirArchivoLectura(){
	string nombre = this->nombreDeArchivo;
	(this->variableArchivo).open(nombre.c_str());
	if (this->variableArchivo.fail()){
		std::cout<<"NO SE PUEDE ABRIR EL ARCHIVO"<<std::endl;
		pedirNombreDeArchivo();
	}
	this->existeArchivo = true;
}

void ArchivosL::leerArchivo(){
	std::string linea;
	std::string separador=",";
	while(!(this->variableArchivo.eof())){
		getline(this->variableArchivo,linea);
		std::cout<<linea<<endl;
	}

}
std::string ArchivosL::leerLinea(){
	std::string linea;
	if(!this->variableArchivo.eof()){
		getline(this->variableArchivo,linea);
				//cout<<linea<<endl;
	}
	else{
		linea=VACIO;
	}
	return linea;
}


void ArchivosL::ManejoArchivoLectura(){
	if ((this->existeArchivo)){
		(this->variableArchivo).close();
		this->existeArchivo=false;
	}
	else{
		std::cout<<"Archivo que desea cerrar No Existe."<<std::endl;
	}
}

