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
			char mostrarTipo(){
				return this->Parcela.tipo;
			}
			ui obtenerCantidadDeFilas();
			ui obtenerCantidadDeColumnas();
			Terreno** crearTerreno(ui fila, ui columna);
			/*
			 * post: Obtiene la fila y la columna
			 */
			void pedirParcela();
			/* post: Devuelve la rentabilidad que tiene la parcela cosechada.*/
			ui obtenerRentabilidad();
			/* post: Agrega dimensiones al terreno.*/
			void agregarDimension(ui fila, ui col);
			/* post: Aumenta la variable numeroDeRiegos cada vez que riega una parcela.*/
			void aumentarNumeroDeRiegos();
			/* post: Cambia el es esta de la parcela cuando coseche.*/
			void cambiarACosechado();
			/* post: Cambia el es esta de la parcela cuando siembre.*/
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
			/* post: Lama a los metodos privados recuperarParcela() 
			         decrementarRecuperacion() y 
				 incrementarTiempoTrassiembra()*/
			void actualizando();
			~Terreno();

	private:
			/* pre: Miestras este cosechada y this->Parcela.recuperacion == 0.
			/* post: Cambia la variable this->Sembrada en false.*/
			void recuperarParcela();
			/* post: Decrementa la variable this->Parcela.recuperacion.*/
			void decrementarRecuperacion();
			/* pre: Mientras this->Sembrada == true.
			/* post: Incrementa la variable this->Parcela.tiempoTrasSiembra. */
			void incrementarTiempoTrasSiembra();
			/*
			 * post: Pudre (this->parcelaPodrida = true) o Recupera la Parcela.
			 */
			void podrirParcela();
};

#endif /* TERRENO_H_ */
