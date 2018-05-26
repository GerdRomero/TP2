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
#include "Lista.h"
#define EOF ""
class ArchivosL {
private:
			std::ifstream variableArchivo;
			bool existeArchivo;
			std::string nombreDeArchivo;

public:
			/* pre: recibe una linea de texto (csv) y una referncia a una lista
			 * post:*/
			Lista<std::string>* datosLista(std::string linea);

			// post:Pide el nombre del archivo
			void pedirNombreDeArchivo(std::string nombreReferencia);

			/*
			 * post:Abre el archivo de Lectura
			 */
			void abrirArchivoLectura(std::string nombreReferencia);
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
