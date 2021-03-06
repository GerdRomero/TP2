/*
 * Jugador.h
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "Lista.h"
#include "Almacen.h"
#include "Semilla.h"
#include "Mercado.h"
typedef unsigned short int ui;
struct Semillas{
		Semilla tipoA;
		Semilla tipoB;
		Semilla tipoC;
	};
class Jugador {
private:
	struct estadoJugador{
	int creditos;
	int cantAgua;
	int turnosRestantes;
	}estado;
	Semillas cultivos;
	Semilla *aSembrar;
	Lista<Terreno**> *terrenos;
	Terreno **terrenoEnJuego;
	Almacen *almacen;
	Mercado *mercado;
	ui dificultad;
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

 /*post:opciones de compra, clase Mercado*/
	void comprar();
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

	/*pre: datos validos ui, aSembrar debe estar seteado desde elegirSemilla()
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
	/*post: setea Semilla aSembrar deacuerdo al dato ingresado*/
	void pedirSemillaSembrar();
	/*post:Muestra info Semillas*/
	void mostrarInfoSemilla();
	/*post: Castea un tipo de Semilla existente*/
	char tipoSemillaValida();
	/*post: Retorna la cantidad de credito que posee el jugador.*/
	int verCreditos(){
		return this->estado.creditos;
	};
	/*post: Retorna la cantidad de agua que posee el jugador.*/
	int verCantAgua(){
		return this->estado.cantAgua;
	}
	/*post: Retorna la cantidad de turnos que posee el jugador.*/
	int verTurnos(){
		return this->estado.turnosRestantes;
	}
	void mostrarTerreno();
	virtual ~Jugador();
private:
	/*post:leé un archivo de cultivos, crea una lista y setea en tipos de semillas a usar
	 * (subrutinas datosLista() y cargarCultivosJugador()*/

	void cargarDatos();
	ui filaTerreno();
	ui columnaTerreno();
	/*post:
	 * imprime info de los cultivos*/
	void mostrarInfo();
	/*pre: valores del menu a utilizar
	 * post: devuelve un valor valido entre min y max*/
	ui opcionValida(ui min, ui max);
	/*pre:Debe haber un terreno en lista del jugador
	 * post: cotiza,remueve y agrega creditos al jugador*/
	void venderTerreno();

	void comprarSemillas();
	/*pre: tipo de semilla existente en los cultivos del jugador
	 * post: setea en jugador el cultivo *aSembrar con el tipo de cultivo selleccionado */
	void elegirSemilla(ui opcion);
	void comprarTerreno();
	void comprarCapacAlmacen();
	/*pre: el costo de alguna compra del menu
	 * post: verifica si el jugador tiene creditos suficientes para esa compra*/
	bool hayCreditos(ui costoCompra);
	void mostrarMenuCompras();
	/*pre:Se llama luego de invocar al contructor, recibe una linea de texto
	 * y una referencia a una lista
	 * post:En la lista referenciada carga los datos de la linea de texto*/
	void datosLista(std::string linea,Lista<std::string>&datos);
	/*pre:Se invoca luego del constructor y de datosLista()
	 * post:Setea las propiedades de Semilla con una referencia a lista
	 * */
	void cargarCultivosJugador(Lista<std::string>*datos);
	/*pre:Invocado luego del contructor
	 * post:Setea propiedades de Jugador de acuerdo a dificultad*/
	void cargarDificJugador(ui dificultad);
	void agregarCultivos(char tipo, ui cant);
	char semillaValida(ui opcion);
	void filaColValido();
	void verificarDimensionTerreno();
/*post: devuelve terrenoActual(el que esta usando el jugador de la lista de terrenos
 * , solo para hacer pruebas)*/
	Terreno** obtenerTerreno();

	void venderCosecha();
};

#endif /* JUGADOR_H_ */
