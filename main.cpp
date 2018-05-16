/*
 * main.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */


#include <iostream>
#include "Juego.h"
#include "Lista.h"
#include "Jugador.h"
#include "Terreno.h"
#include <list>
using namespace std;
int main(){
	Juego granjeros;
	granjeros.agregarJugadores(3,1);
	while(!granjeros.finJuego()){
	granjeros.comenzarTurno();
	}
	/*
	Terreno ** terreno = new Terreno*[2];
	for( ui col=0; col<=2; col++ )
	  terreno[col] = new Terreno[2];

	cout<<""<<terreno[1][1].obtenerEstado();

	Lista<Terreno**> terrenos;
	terrenos.agregar(terreno);
	terrenos.iniciarCursor();
	while(terrenos.avanzarCursor()){
		Terreno **miTerreno=terrenos.obtenerCursor();
		cout<<miTerreno[1][1].obtenerEstado();
	}
*/
/*
	Juego granja;
	granja.agregarJugadores(1,1);
	Jugador *jugador= granja.obtenerJugador();
	jugador->agregarTerreno(2,2);
	Terreno** terreno =jugador->obtenerTerreno();
	cout<<"imprimo"<<terreno[1][1].obtenerEstado();
*/


/*
	Lista <char> caracteres;
	caracteres.iniciarCursor();
	caracteres.agregar('A');
	caracteres.agregar('B');
	caracteres.agregar('C');
	caracteres.agregar('D');
	*/
	//Lista<Jugador*> *jugadores;
	/*
	Jugador* jugador=new Jugador;
	Jugador* jugador2=new Jugador;
	jugadores->agregar(jugador);
	jugadores->agregar(jugador2);

	cout<<""<<jugadores->obtener(1)->verCantAgua();
	cout<<""<<jugadores->obtener(2)->verCreditos();
*/


	//Jugador jugador;
	/*
	std::cout<<caracteres.obtener(4);
int cant=1;
	while(cant<4){
		Jugador jugador;
		jugadores.agregar(jugador);
		std::cout<<jugadores.obtener(cant).verCreditos();
		std::cout<<"\n";
		cant+=1;
}

*/
	/*

	int cant=1;
	Juego granjeros;
	granjeros.agregarJugadores(3);
	while(cant<4){
		Jugador *jugador=granjeros.verJugador(cant);
		std::cout<<jugador->verCreditos();
		cant++;
	}
	*/
	return 0;
}

