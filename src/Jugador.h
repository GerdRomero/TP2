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
	Terreno **terrenoEnJuego;
	ui posicionTerrenoEnJuego;
	ui pos[];
public:
	Jugador();
	Jugador(int dificultad);
	void pedirPosicion();
	ui filaTerreno();
	ui columnaTerreno();
	void comprarSemillas();
	/*pre: datos validos ui
	  post:crea terreno y agrega en lista terrenos */
	void agregarTerreno(ui fila, ui columna);
	/*pre: Mientras se pueda avanzar en lista terrenos.
	 *post:  Avanza un terreno y setea en terrenoEnJuego. Considerar que ya se avanzo antes
	 */
	void avanzarTerreno();
	/*pre: datos validos ui
	 * post: siembra en terrenoEnJuego */
	void sembrarTerreno(int fila, int columna);
	/*pre: datos validos ui
		 * post: riega en terrenoEnJuego cambiando estados en Terreno */
	void regarTerreno(int fila, int columna);
	/*pre: datos validos ui
		 * post: cosecha en terrenoEnJuego, cambiando estados en Terreno */
	void cosecharTerreno(int fila, int columna);
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
private:
	Terreno** obtenerTerreno();
};

#endif /* JUGADOR_H_ */
