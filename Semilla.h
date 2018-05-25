/*
 * Semilla.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#ifndef SRC_SEMILLA_H_
#define SRC_SEMILLA_H_
typedef unsigned short int ui;
#include <list>
#include<string>
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
	Semilla(Lista<std::string> &datos);
	char obtenerTipo(){
		return this->tipo;
	}
	ui precio();
	ui cantidadAguaTurno();
	ui turnosRecuperacion();
	ui ganancia();
	ui turnosCosecha();
	void agregar(ui cantAgregar);
	bool haySemilla();
	virtual ~Semilla();
};

#endif /* SRC_SEMILLA_H_ */
