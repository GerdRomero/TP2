/*
 * Almacen.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */
#include "Semilla.h"
#ifndef SRC_ALMACEN_H_
#define SRC_ALMACEN_H_
typedef unsigned short int ui;

class Almacen{
	private:
			struct{
				ui tipoA;
				ui tipoB;
				ui tipoC;
			}*cosechas;

			Semilla *tipoA;
			Semilla *tipoB;
			Semilla *tipoC;
			ui tam;

	public:

			Almacen();

			Almacen(ui tam);

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

public:
			~Almacen();
			void haySemilla();

};


#endif /* SRC_ALMACEN_H_ */
