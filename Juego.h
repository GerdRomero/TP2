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
	ui cantJugadores;
	ui turnosJuego;
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
	void Jugar();
	bool finJuego(){
		return this->estadoGranjeros.finTurno;
	}
	void mostrarOpciones();
	void opciones();
	void descontarTurnos();

	virtual ~Juego();
private:
	void pasarTurno();
	ui opcionValida();
	Jugador* obtenerJugador();

	void contarTurnos();

};

#endif /* JUEGO_H_ */
