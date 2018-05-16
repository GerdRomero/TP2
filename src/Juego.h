/*
 * Juego.h
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#ifndef JUEGO_H_
#define JUEGO_H_
#include "Jugador.h"
#include "Lista.h"
typedef unsigned short int ui;
class Juego {
private:
	Lista<Jugador*> *jugadores;
	unsigned int cantJugadores;
	unsigned int turnosJuego;
	Jugador *jugadorActual;
	struct estadoJuego{
		bool comenzado;
		bool jugando;
		bool finTurno;
		bool finalizado;
	}estadoGranjeros;
public:
	Juego();
	void agregarJugadores(int cantidad, int dificultad);
	void comenzarTurno();
	void jugar(int opcion);

	virtual ~Juego();
private:
	void pasarTurno();
	ui opcionValida();
	Jugador* obtenerJugador();

	void contarTurnos();

};

#endif /* JUEGO_H_ */
