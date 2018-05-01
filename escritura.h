/*
 * escritura.h
 *
 *  Created on: 28/04/2018
 *      Author: romero_gerard
 */

#ifndef ESCRITURA_H_
#define ESCRITURA_H_

#include<fstream>
#include<string>

class ManejoArchivoEscritura{
		private:

				std::ofstream variableArchivo;
				bool existeArchivo;
				std::string nombreDeArchivo;
		public:

				// post:Pide el nombre del archivo
				void pedirNombreDeArchivo();

				 /*
				 * post:Abre el archivo si existe o lo crea si no
				 * 		existe.
				 */
				void abrirArchivoEscritura();

				/*
				 * post:Guarda las caracteristicas de cada cultivo.
				 */
				void tiposDeCultivos();

				/*
				 * post:Guarda cada envio que realize el jugador
				 */
				void guardarEnvio();

				/*
				 * pre:El archvo tiene que existir.
				 * post:Cierra el archvo.
				 */
				~ManejoArchivoEscritura();

};



#endif /* ESCRITURA_H_ */
