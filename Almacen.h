/*
 * Almacen.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */

#ifndef SRC_ALMACEN_H_
#define SRC_ALMACEN_H_

class Almacen{
	private:
			char tipoDeSemilla;
			char tipoDeCosecha;
			int cantTipoDeSemilla;
			int cantTipoDeCosecha;
			int espacioDisponible;
			int espacioTotal;

			typedef unsigned int tamaño;


	public:

			Almacen();

			Almacen(tamaño tam);

			//Pre: Ingrese un tipo de cosecha valido
			//Post: Devuelve la cantidad disponible de la cosecha
			int cantidadDeCosecha(char tipoCosecha);

			//Pre: Idem
			//Post: Idem
			int cantidadDeSemilla(char tipoSemilla);

			//Pre: Ingresar cantidad valida de cosecha
			//Post: -
			void guardarCosecha(int cantCosecha);

			//Pre: Idem
			//Post: -
			void guardarSemilla(int cantSemilla);

			//Pre: -
			//Post: Devuelve la cantidad de espacio disponible
			int cantEspacioDisponible();


};


#endif /* SRC_ALMACEN_H_ */
