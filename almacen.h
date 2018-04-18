/*
 * almacen.h
 *
 *  Created on: 18/04/2018
 *      Author: romero_gerard
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

class Almacen{
	private:
			char tipoDeSemilla;
			int precio;
			int distancia;
			std::string destino;

	public:

			Almacen();

			void guardarEnAlmacen();

			void leerDestino();
};




#endif /* ALMACEN_H_ */
