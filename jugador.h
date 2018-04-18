/*
 * jugador.h
 *
 *  Created on: 15/04/2018
 *      Author: romero_gerard
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

class Jugador {
	private:
			int credito;
			int turnos;
			int potenciador;
			int aguaEnTanque;

	public:
			/*
			 *  pre:
			 *  post:
			 */
			Jugador();

			/*
			 *
			 */
			void guardarAguaEnTanque();

			/*
			 * post: Retorna el potenciador entre 1 y 6.
			 */
			void tirarDados();

};

#endif /* JUGADOR_H_ */
