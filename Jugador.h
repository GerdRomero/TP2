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
#include "Almacen.h"
#include "Semilla.h"
typedef unsigned short int ui;
class Jugador {
private:
	struct estadoJugador{
	int creditos;
	int cantAgua;
	int turnosRestantes;
	}estado;
	struct Semillas{
		Semilla *tipoA;
		Semilla *tipoB;
		Semilla *tipoC;
	}cultivos;
	Lista<Terreno**> *terrenos;
	Terreno **terrenoEnJuego;
	Almacen *almacen;
	ui cantTerrenos;
	ui posicionTerrenoEnJuego;
	ui pos[];
	bool finTurno;
public:
	/*pre: dificultad valida, pedida en clase Juego
	 * post: crea objeto y llama a subrutinas cargarDatos()
	 *  y cargarDificJugador()*/
	Jugador(ui dificultad);
	/*post: setea pos[] con una fila y columna pedida para un terreno*/
	void pedirPosicion();
	/*post:setea finTurno=true, para en clase Juego cambiar de Jugador*/


	void comprarSemillas();
	void comprarMercado();
	/*pre:numero de terreno valido en lista terrenos
	 * post:cambia la posicion en lista terrenos para setear terrenoEnJuego*/
	void obtenerTerrenoEnJuego(ui posicionTerreno);
	/*post: cambia finTurno para cambiar al jugador en clase juego*/
	void finalizarTurno();
	/*post: regresa atributo finTurno, false:continua jugando
	 *  el mismo jugador en clase Juego*/
	bool noFinalizado();
	/*pre: datos validos ui
	  post:crea terreno y agrega en lista terrenos */
	void agregarTerreno(ui fila, ui col);
	void agregarTerreno();

	/*pre: datos validos ui
	 * post: siembra en terrenoEnJuego */
	void sembrarTerreno();
	/*pre: datos validos ui
		 * post: riega en terrenoEnJuego cambiando estados en Terreno */
	void regarTerreno();
	/*pre: datos validos ui
		 * post: cosecha en terrenoEnJuego, cambiando estados en Terreno */
	void cosecharTerreno();
	/*post: devuelve un numero de terreno valido en lista terrenos*/
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
private:
	/*post:leé un archivo de cultivos, crea una lista y setea en tipos de semillas a usar
	 * (subrutinas datosLista() y cargarCultivosJugador()*/
	void cargarDatos();
	ui filaTerreno();
	ui columnaTerreno();
	/*pre:Se llama luego de invocar al contructor, recibe una linea de texto
	 * y una referencia a una lista
	 * post:En la lista referenciada carga los datos de la linea de texto*/
	void datosLista(std::string linea,Lista<std::string>&datos);
	/*pre:Se invoca luego del constructor y de datosLista()
	 * post:Setea las propiedades de Semilla con una referencia a lista
	 * */
	void cargarCultivosJugador(Lista<std::string>&datos);
	/*pre:Invocado luego del contructor
	 * post:Setea propiedades de Jugador de acuerdo a dificultad*/
	void cargarDificJugador(ui dificultad);
/*post: devuelve terrenoActual(el que esta usando el jugador de la lista de terrenos
 * , solo para hacer pruebas)*/
	Terreno** obtenerTerreno();
};

#endif /* JUGADOR_H_ */
