/*
 * lectura.h
 *
 *  Created on: 28/04/2018
 *      Author: romero_gerard
 */

#ifndef LECTURA_H_
#define LECTURA_H_
#include<fstream>
#include<string>

class ManejoArchivoLectura{
		private:
					std::ifstream variableArchivo;
					bool existeArchivo;
					std::string nombreDeArchivo;

		public:
					// post:Pide el nombre del archivo
					void pedirNombreDeArchivo();

					/*
					 * post:Abre el archivo de Lectura
					 */
					void abrirArchivoLectura();
					/*
					 * post:Lee todo el archivo
					 */
					void leerArchivo();

					/*
					 * pre: El archivo tiene que existir
					 * post:Cierra el archivo
					 */
					~ManejoArchivoLectura();
};


#endif /* LECTURA_H_ */
