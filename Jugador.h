/*
 * Jugador.h
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Terreno.h"
#include "Lista.h"
typedef unsigned short int ui;
#include<iostream>
class Jugador {
private:
	struct estadoJugador{
	int creditos;
	int cantAgua;
	int turnosRestantes;
	}estado;
	Lista<Terreno**> *terrenos;
	ui cantTerrenos;
	Terreno **terrenoEnJuego;
	ui posicionTerrenoEnJuego;
	ui pos[];
	bool finTurno;
public:
	Jugador();
	Jugador(int dificultad);
	void pedirPosicion();
	void pasarTurno();
	void seguirTurno();
	ui filaTerreno();
	ui columnaTerreno();
	void comprarSemillas();
	void obtenerTerrenoEnJuego(ui posicionTerreno);
	/*post: cambia finTurno para el jugador*/
	void finalizarTurno();
	/*post: regresa atributo finTurno*/
	bool noFinalizado();
	/*pre: datos validos ui
	  post:crea terreno y agrega en lista terrenos */
	void agregarTerreno();
	/*pre: Mientras se pueda avanzar en lista terrenos.
	 *post:  Avanza un terreno y setea en terrenoEnJuego. Considerar que ya se avanzo antes
	 */
	void avanzarTerreno();
	/*pre: datos validos ui
	 * post: siembra en terrenoEnJuego */
	void sembrarTerreno();
	/*pre: datos validos ui
		 * post: riega en terrenoEnJuego cambiando estados en Terreno */
	void regarTerreno();
	/*pre: datos validos ui
		 * post: cosecha en terrenoEnJuego, cambiando estados en Terreno */
	void cosecharTerreno();
	ui terrenoValido();
	int verCreditos(){
		return this->estado.creditos;
	};
	int verCantAgua(){
		return this->estado.cantAgua;
	}
	int verTurnos(){
		return this->estado.turnosRestantes;
	}
	virtual ~Jugador();

	Terreno** obtenerTerreno();
};

#endif /* JUGADOR_H_ */
