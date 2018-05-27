/*
 * main.cpp
 *
 *  Created on: 22 may. 2018
 *      Author: cristian
 */

#include "Juego.h"
#include "Lista.h"
#include"ArchivosL.h"


using namespace std;
int main(){


	Juego granjeros;
	granjeros.agregarJugadores(1);
	while(!granjeros.finJuego()){

		granjeros.comenzarTurno();
	}


return 0;
}


