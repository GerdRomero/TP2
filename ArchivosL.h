/*
 * ArchivosL.h
 *
 *  Created on: 20 may. 2018
 *      Author: cristian
 */

#ifndef SRC_ARCHIVOSL_H_
#define SRC_ARCHIVOSL_H_
#include<fstream>
#include<string>
class ArchivosL {
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
			std::string leerLinea();
			void leerArchivo();



			/*
			 * pre: El archivo tiene que existir
			 * post:Cierra el archivo
			 */
			void ManejoArchivoLectura();
};

#endif /* SRC_ARCHIVOSL_H_ */
