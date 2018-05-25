/*
 * Jugador.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Jugador.h"
#include "ArchivosL.h"
#include<iostream>
#include <string>
#define VACIO ""

Jugador::Jugador(ui dificultad){
	this->terrenos=NULL;
	this->posicionTerrenoEnJuego=0;
	this->finTurno=false;
	this->cantTerrenos=0;
	this->terrenos=NULL;
	this->mercado=NULL;
	cargarDatos();
	cargarDificJugador(dificultad);
	Mercado mercado (cultivos);
	this->mercado=&mercado;

}
void Jugador::cargarDificJugador(ui dificultad){
	ui N,M;
	switch(dificultad){
	case 1:
		N=2, M=2;
		break;
	case 2:
		N=3, M=3;
		break;
	case 3:
		N=4, M=4;
		break;
	agregarTerreno(N,M);
	Almacen almacen(2*(N+M));
	this->almacen=&almacen;
	this->estado.creditos=2*N*M;
	this->estado.cantAgua=N*M;
	this->estado.turnosRestantes=2*N*M;
	this->aSembrar=NULL;
	}
}
void Jugador::mostrarInfo(){
	/*Mostrar info productos (Vale por mostrar info semillas con punteros)*/
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;


}
ui Jugador::opcionValida(ui min, ui max){
	ui opcion;
	std::cout<<"Ingrese una opcion: "<<std::endl;
	std::cin>>opcion;
	if(!isdigit(opcion)|| opcion>max|| opcion<min){
		opcionValida(min, max);
	}
	return opcion;
}
void Jugador::venderTerreno(){
	ui terrenoAVender=terrenoValido();
	Terreno **terrenoACotizar=this->terrenos->obtener(terrenoAVender);
	ui ganancia=this->mercado->cotizarTerreno(terrenoACotizar);
	this->terrenos->remover(terrenoAVender);
	this->estado.creditos+=ganancia;
}
void Jugador::comprarSemillas(){
	std::cout<<"Ingrese el tipo de cultivo a comprar: "<<std::endl;
	mostrarInfo();
	ui cantidad;
	char tipoSemilla=tipoSemillaValida();
	std::cout<<"Cuantas semillas desea comprar: "<<std::endl;
	std::cin>>cantidad;
	ui costo=this->mercado->ventaSemillas(tipoSemilla, cantidad);
	if(hayCreditos(costo)){
		this->estado.creditos-=costo;
		agregarCultivos(tipoSemilla, cantidad);
	}else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}
void Jugador::agregarCultivos(char tipoSemilla,ui cantidad){
	//char a=this->cultivos->tipoA->obtenerTipo();
	switch(tipoSemilla){
		case 'A':
			this->cultivos->tipoA->agregar(cantidad);
			break;
		case 'B':
			this->cultivos->tipoB->agregar(cantidad);
			break;
		case 'C':
			this->cultivos->tipoC->agregar(cantidad);
			break;
		}
}
void Jugador::comprarTerreno(){
	pedirPosicion();
	/*falta tomar el caso de pedir dimension por dificultad*/
	ui fila=this->pos[0];
	ui col=this->pos[1];
	ui costo=this->mercado->venderTerreno(fila, col);
	if(hayCreditos(costo)){
		agregarTerreno(fila,col);
		this->estado.creditos-=costo;
	}else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}
void Jugador::comprarCapacAlmacen(){
	/*porsu faltan metodos de comprobacion*/
	ui capac;
	std::cout<<"Ingrese la capacidad a agregar: "<<std::endl;
	cin>>capac;
	/*Multiplicar costo por dificultad*/
	ui costo=this->mercado->venderTamanioAlmacen(capac);
	if(hayCreditos(costo)){
		this->almacen->extender(capac);
		this->estado.creditos-=costo;
	}else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}
/*Metodo a practicar uso en todas las compras*/
bool Jugador::hayCreditos(ui costoCompra){
	ui comparacion=this->estado.creditos;
	return (comparacion-costoCompra)>=0;
}

void Jugador::venderCosecha(){
	ui costo, cantAEnviar;
	this->almacen->leerDestino();
	cantAEnviar=this->almacen->elegirCosecha();
	costo=this->almacen->prepararCosecha(cantAEnviar);
	if(hayCreditos(costo)){
		char cosecha=this->almacen->obtenerTipoCosechaPreparada();
		ui ganancia=this->mercado->venderCosecha(cosecha,cantAEnviar);
		this->estado.creditos+=ganancia;
		this->almacen->vaciarCosecha();
	}
	else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}
void Jugador::mostrarMenuCompras(){
	/*imprimir opciones de compra en comprar()*/
}
void Jugador::comprar(){
	mostrarMenuCompras();
	ui opcion=opcionValida(1,5);
	switch(opcion){
	case 1:
		comprarSemillas();
		break;
	case 2:
		venderCosecha();
		break;
	case 3:
		comprarTerreno();
		break;
	case 4:
		venderTerreno();
		break;
	case 5:
		comprarCapacAlmacen();
		break;
	}
}

bool Jugador::noFinalizado(){
	return this->finTurno;
}

void Jugador::agregarTerreno(ui fil, ui col){
	//pedirPosicion();
	ui fila=this->pos[0]||fil;
	ui columna=this->pos[1]||col;
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
}
void Jugador::agregarTerreno(){
	pedirPosicion();
	ui fila=this->pos[0];
	ui columna=this->pos[1];
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
}

void Jugador::obtenerTerrenoEnJuego(ui posicionTerreno){
	this->terrenoEnJuego=this->terrenos->obtener(posicionTerreno);
}
ui Jugador::terrenoValido(){
	ui posTerreno;
	std::cout<<"Ingrese un numero de terreno"<<std::endl;
	std::cin>>posTerreno;
	while(posTerreno>this->cantTerrenos|| posTerreno<=0){
		std::cout<<"Ingrese un numero de terreno valido: "<<std::endl;
		std::cout<<"Entre"<<"1 y "<<this->cantTerrenos<<std::endl;
		std::cin>>posTerreno;
	}
	return posTerreno;
}

void Jugador::sembrarTerreno(){
	pedirPosicion();
	ui fil=filaTerreno();
	ui col=columnaTerreno();
	if (!(this->terrenoEnJuego[fil][col].estaSembrada())){
		this->terrenoEnJuego[fil][col].cambiarEstadoDeParcelaSembrada(this->aSembrar);
		//this->cantidad.creditos = (this->cantidad.creditos - this->aSembrar->precio());
	}
}

void Jugador::regarTerreno(){
	pedirPosicion();
	ui fil=filaTerreno();
	ui col=columnaTerreno();
	if (this->terrenoEnJuego[fil][col].estaSembrada()){
		this->estado.cantAgua-=this->aSembrar->cantidadAguaTurno();
		//this->cantidad.agua = this->cantidad.agua - this->aSembrar->cantidadAguaTurno();
		this->terrenoEnJuego[fil][col].aumentarNumeroDeRiegos();
	}
}
void Jugador::cosecharTerreno(){
	pedirPosicion();
	ui fil=filaTerreno();
	ui col=columnaTerreno();
	if((this->terrenoEnJuego[fil][col].estaSembrada()) &&
		(this->terrenoEnJuego[fil][col].regoCorrectamente())){
		//this->estado.creditos += this->terrenoEnJuego[fil][col].obtenerRentabilidad();
		this->terrenoEnJuego[fil][col].cambiarACosechado();
	}
}

Terreno**Jugador::obtenerTerreno(){
	return this->terrenoEnJuego;

}
ui Jugador::filaTerreno(){
	ui fila=this->pos[0];
	return fila;
}
ui Jugador::columnaTerreno(){
	ui col=this->pos[1];
	return col;
}
void Jugador::mostrarInfoSemilla(){
	/*Vale por info con punteros*/
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
	std::cout<<""<<std::endl;
}
char Jugador::tipoSemillaValida(){
	char semillaValida;
	std::cout<<"Ingrese un tipo de cultivo"<<std::endl;
	std::cin>>semillaValida;
	if(!isalpha(semillaValida) ){
		std::cout<<"Ingrese una opcion valida de semilla"<<std::endl;
	}
	return semillaValida;
}
void Jugador::pedirSemillaSembrar(){
	char tipoSemilla;
	mostrarInfoSemilla();
	std::cout<<"Ingrese el cultivo a sembrar: "<<std::endl;
	std::cout<<"1- "<<this->cultivos->tipoA->obtenerTipo()<<std::endl;
	std::cout<<"2- B "<<std::endl;
	std::cout<<"3- C "<<std::endl;
	tipoSemilla=tipoSemillaValida();
	elegirSemilla(tipoSemilla);
}
void Jugador::elegirSemilla(char tipoSemilla){
	switch(tipoSemilla){
	case 'A':
		this->aSembrar=this->cultivos->tipoA;
		break;
	case 'B':
		this->aSembrar=this->cultivos->tipoB;
		break;
	case 'C':
		this->aSembrar=this->cultivos->tipoC;
		break;
	}
}
void Jugador::finalizarTurno(){

	this->finTurno=true;
}
void Jugador::pedirPosicion(){
	ui fila, col;
	std::cout<<"Ingrese fila:"<<"\n";
	std::cin>>fila;
	this->pos[0]=fila;
	std::cout<<"Ingrese columna:"<<"\n";
	std::cin>>col;
	this->pos[1]=col;
}

void Jugador::cargarDatos(){
	ArchivosL cultivos;
	cultivos.pedirNombreDeArchivo();
	cultivos.abrirArchivoLectura();
	std::string linea=cultivos.leerLinea();
	while(linea!=VACIO){
		Lista<std::string>datosCultivo;
		cultivos.datosLista(linea, datosCultivo);
		cargarCultivosJugador(datosCultivo);
	}
}

void Jugador::cargarCultivosJugador(Lista<std::string>&datos){
	std::string tipoSemilla=datos.obtener(1);
	if(tipoSemilla=="A"){
		Semilla tipoA(datos);
		this->cultivos->tipoA=&tipoA;
	}
	else if(tipoSemilla=="B"){
		Semilla tipoB(datos);
		this->cultivos->tipoB=&tipoB;
	}
	else if(tipoSemilla=="C"){
		Semilla tipoC(datos);
		this->cultivos->tipoC=&tipoC;
	}
	else{
		std::cout<<"No se cargaron los cultivos..."<<std::endl;
	}
}
Jugador::~Jugador() {
	// TODO Auto-generated destructor stub
}

