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
	/* post: Agrego el costo de la Semilla*/
	void agregarCosto(std::string costo);
	/* post: Agrego el tiempo de Cosecha de la Semilla*/
	void agregarTiempoCosec(std::string turnos);
	/* post: Agrego la rentabilidad de la Semilla*/
	void agregarRentabilidad(std::string ganancia);
	/* post: Agrego el tiempo de recuperacion de la Semilla*/
	void agregarTiempoRecup(std::string recuperacion);
	/* post: Agrego la cantidaqd de agua que requiere la Semilla*/
	void agregarAguaTurno(std::string aguaPorTurno);
	/* post: Devuelve la cantidad de semillas compradas*/
	ui cantDisponible()
	/* post: Devuelve la cantidad de agua que requiere la Semilla*/
	ui cantidadAguaTurno();
	/* post: Devuelve el tiempo de recuperacion*/
	ui turnosRecuperacion();
	/* post: Devuelve la rentabilidad */
	ui ganancia();
	/* post: Devuelve los turnos hasta cosechar*/
	ui turnosCosecha();
	void agregar(ui cantAgregar);
	/* post: Devuelve true si hay semillas comrpadas. */
	bool haySemilla();
	virtual ~Semilla();
};

#endif /* SRC_SEMILLA_H_ */
