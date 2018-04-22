/*
 * terreno.h
 *
 *  Created on: 17/04/2018
 *      Author: romero_gerard
 */

#ifndef TERRENO_H_
#define TERRENO_H_

typedef unsigned int enteroValido;

class Terreno{
	private:
			char estado;
			int tiempoParaCosechar;
			int tiempoDeRecuperacion;
			int numeroDeRiegos;
			bool estaSembrada;
			bool parcelaPodrida;
			int rentabilidad;
			int tiempoTrasSembrar;
			bool seCosecho;
			enteroValido filaPedida;
			enteroValido columnaPedida;s

	public:
			Terreno();

			void operacionSembrar();

			void operacionRegar();

			void operacionCosechar();

			/*
			 * post: Obtiene la fila y la columna
			 */
			void pedirParcela();

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
