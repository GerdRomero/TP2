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

class Terreno{
	private:
	/*Ubicar estos atributos en un struct Parcela, cambiar el constructor*/
			char estado;
			int turnosParaCosechar;
			int turnosDeRecuperacion;
			bool estaSembrada;
			bool parcelaPodrida;
			int rentabilidad;
			bool seCosecho;
			Terreno *terreno;

	public:
			Terreno();
			Terreno** crearTerreno(ui fila, ui columna);
			/*
			 * post: Obtiene la fila y la columna
			 */
			void pedirParcela();
			char obtenerEstado(){
				return this->estado;
			}

	private:
			/*
			 * post:Devuelve true si la parcela esta vacia o
			 * 	   false en caso contrario.
			 */
			bool verificoSiSePuedeSembrar();

			/*
			 * post:Retorna true si la parcela esta sembrada
			 *      o false en caso contrario.
			 */
			bool verificoSiSePuedeRegar();

			/*
			 * post: Retorna true si numeroDeRiegos == tiempoParaCosechar
			 * 		 o false en caso contario
			 */

			bool verificoSiSePuedeCosechar();

};

#endif /* TERRENO_H_ */
