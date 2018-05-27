/*
 * Almacen.h
 *
 *  Created on: 17 may. 2018
 *      Author: cristian
 */
#include "Semilla.h"
#include <string>
#ifndef SRC_ALMACEN_H_
#define SRC_ALMACEN_H_
typedef unsigned short int ui;
struct Cosecha{
	std::string destino;
	ui cant;
	ui costo;
	char tipo;
};
struct Cosechas{
				Cosecha tipoA;
				Cosecha tipoB;
				Cosecha tipoC;
			};


class Almacen{
	private:
			Cosechas *cosechas;
			ui tam;
			ui espacioDisponible;
			Cosecha *cosechaEnviar;

	public:
			Almacen();
			Almacen(ui tam);
			//Pre: Ingrese un tipo de cosecha valido
			//Post: Devuelve la cantidad disponible de la cosecha
			ui cantidadDeCosecha(char tipoCosecha);

			//Pre: Ingresar cantidad valida de cosecha
			//Post: -
			void guardarCosecha(ui cantCosecha);
			//Pre: -
			//Post: Devuelve la cantidad de espacio disponible
			ui cantEspacioDisponible();
			/*post:
			 * extiende el tamño del almacen*/
			void extender(ui tamanio);
			void leerDestino();
			void guardarCosecha(ui cantCosecha,  char tipoCosecha);
			ui prepararCosecha(ui cantCosecha);
			char obtenerTipoCosechaPreparada(){
				return this->cosechaEnviar->tipo;
			}
			void vaciarCosecha(){
				this->cosechaEnviar->cant=0;
			}
			void mostrarInfoEnvios();
			ui elegirCosecha();
			~Almacen();
	private:
			void elegirCosechaGuardar(ui cantCosecha, char tipoCosecha);
			void cargarDestinosCosechas(Lista<std::string>*datos);
			ui opcionValida();
			ui obtenerGanancia(ui cantEnviada);
};


#endif /* SRC_ALMACEN_H_ */
