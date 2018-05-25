/*
 * Terreno.h
 *
 *  Created on: 13 may. 2018
 *      Author: cristian
 */


#ifndef TERRENO_H_
#define TERRENO_H_
#define VACIA (char) 35
typedef unsigned short int ui;
#include "Semilla.h"
enum Estado{vacia,sembrada,reposo};
struct IntervaloParcela{
	ui rentabilidad;
	ui recuperacion;
	ui tiempoHastaCosecha;
	ui numeroDeRiegos;
	ui tiempoTrasSiembra;
	char tipo;
};
class Terreno{
	private:
	private:
	/*Ubicar estos atributos en un struct Parcela, cambiar el constructor*/
			IntervaloParcela Parcela;
			ui cantidadDeFilas;
			ui cantidadDecolumas;
			bool Sembrada;
			bool parcelaPodrida;
			bool seCosecho;
			Estado ESTADO;
			Terreno **terreno;

	public:
			Terreno();
			ui obtenerCantidadDeFilas();
			ui obtenerCantidadDeColumnas();
			Terreno** crearTerreno(ui fila, ui columna);
			/*
			 * post: Obtiene la fila y la columna
			 */
			void pedirParcela();
			ui obtenerRentabilidad();

			void aumentarNumeroDeRiegos();

			void cambiarACosechado();

			void cambiarEstadoDeParcelaSembrada(Semilla* aSembrar);
			/*
			 * post:Devuelve true si la parcela esta llena o
			 * 	   false en caso contrario.
			 */
			bool estaSembrada();
			/*
			 * post:Devuelve true si los numeroDeRieegos son
			 * 	   iguales al tiempoHastaCosechar.
			 */
			bool regoCorrectamente();

			void actualizando();

			void mostrarTerreno(Terreno **terreno);

	private:
			void recuperarParcela();

			void decrementarRecuperacion();

			void incrementarTiempoTrasSiembra();
			/*
			 * post: Pudre (this->parcelaPodrida = true) o Recupera la Parcela.
			 */
			void podrirParcela();
};

#endif /* TERRENO_H_ */
