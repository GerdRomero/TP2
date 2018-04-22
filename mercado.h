/*
 * mercado.h
 *
 *  Created on: 18/04/2018
 *      Author: romero_gerard
 */

#ifndef MERCADO_H_
#define MERCADO_H_

class Mercado{
	private:
			char tipoDeSemillaComprada;
			//preciosde terrenos por dificultad;
			//Podria haber clase terrenos para consulta de precios.
			int preciosTerrenos[2];
			int* direccionPreciosTerrenos=&preciosTerrenos;
			/*Consultas en clase Semilla de precios*/
			Semilla *tipoSemilla;

	public:
			/* pre: Valor valido en mercado,
			 * post: Agrega la compra.
			 */
			void comprarSemilla(char semiillaAComprar, Semilla *tipoSemilla);

			/*pre: Solo consulta a la clase.
			*post: Agrega terreno al jugador.
			*/
			void comprarTerreno(int &direccionPreciosTerrenos);

			/*pre: Solo consulta a la clase.
			*post: Quita terreno al jugador.
			*/
			void venderTerreno(int &direccionPreciosTerrenos);

			/*pre: Solo consulta a la clase.
			*post: Agrega terreno al jugador.
			*/
			void comprarCapacidadParaTanqueDeAgua();

			void comprarCapacidadDeAlmacen();


}



#endif /* MERCADO_H_ */
