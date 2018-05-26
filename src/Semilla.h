/*
 * Semilla.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#ifndef SRC_SEMILLA_H_
#define SRC_SEMILLA_H_
typedef unsigned short int ui;
#include<string>
#include<cstdlib>
#include <iostream>
#include "Lista.h"
using namespace std;
class Semilla {
private:
	ui costo;
	ui tiempoCosecha;
	ui rentabilidad;
	ui tiempoRecup;
	ui aguaTurno;
	ui cantidadDisponible;
	char tipo;
public:
	Semilla();
	char obtenerTipo(){
		return this->tipo;
	}
	//void agregarInfo(Lista<std::string>*datos);
	ui precio();
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
	ui cantDisponible();
	ui cantidadAguaTurno();
	ui turnosRecuperacion();
	ui ganancia();
	ui turnosCosecha();
	void agregar(ui cantAgregar);
	bool haySemilla();
	virtual ~Semilla();
};

#endif /* SRC_SEMILLA_H_ */
