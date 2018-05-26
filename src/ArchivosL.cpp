/*
 * ArchivosL.cpp
 *
 *  Created on: 20 may. 2018
 *      Author: cristian
 */

#include "ArchivosL.h"

#include <iostream>
#include<string>
#define EOF ""
using namespace std;
#include<fstream>
typedef unsigned short int ui;

Lista<std::string>* ArchivosL::datosLista(std::string linea){
	std::string dato;
	Lista<std::string>*datosLista=new Lista<std::string>;
	for(ui i=0;i<=linea.length();i++){
		if(linea[i]!=','){
			dato+=linea[i];
			if(linea.length()==(ui)(i+1)){
				datosLista->agregar(dato);
		}
		else{
			datosLista->agregar(dato);
			dato="";
		}
		}		}
	return datosLista;
}


void ArchivosL::pedirNombreDeArchivo(std::string archivo){
	string nombre;
	std::cout<<"Ingrese el Nombre del Archivo "<<archivo<<" :"<<std::endl;
	std::cin>>nombre;
	this->nombreDeArchivo=nombre;
	//abrirArchivoLectura();
}

void ArchivosL::abrirArchivoLectura(std::string nombreReferencia){
	string nombre = this->nombreDeArchivo;
	(this->variableArchivo).open(nombre.c_str());
	if (this->variableArchivo.fail()){
		std::cout<<"NO SE PUEDE ABRIR EL ARCHIVO"<<std::endl;
		pedirNombreDeArchivo(nombreReferencia);
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
				//cout<<"linea sin tocar "<<linea<<endl;
	}
	else{
		linea=EOF;
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

