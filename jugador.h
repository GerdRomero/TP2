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
			int creditos;
			int turnos;
			int potenciador;
			int aguaEnTanque;
			Terreno** terreno;

	public:
			/* post:Agrega creditos por defecto de acuerdo a la dificultad y turnos.
			 */
			Jugador(int dificultad);

			//pre: Dtos validos, creditos necesarios
			//post: terreno de dimensiones pedidas;
			void agregarTerreno(int fila, int columna);
			//pre: dato valido dentro de la matriz.
			void sembrarParcela(int fila, int columna);

			void guardarAguaEnTanque();

			/*post: Retorna el potenciador entre 1 y 6.
			 */
			int tirarDados();

		private:
			//pre: datos validos en matriz
			//post: cambia atributo en
			agregaTiempoCosecha(int fila, int columna);
};

#endif /* JUGADOR_H_ */
