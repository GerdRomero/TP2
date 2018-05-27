/*
 * Jugador.cpp
 *
 *  Created on: 9 may. 2018
 *      Author: cristian
 */

#include "Jugador.h"
#include "ArchivosL.h"
#include "Terreno.h"

#include<iostream>
#include <string>


Jugador::Jugador(ui dificultad){
	this->terrenos=new Lista<Terreno**>;
	this->posicionTerrenoEnJuego=0;
	this->finTurno=false;
	this->cantTerrenos=0;
	this->mercado=NULL;
	this->dificultad=dificultad;
	cargarDatos();
	cargarDificJugador(dificultad);
	this->mercado=new Mercado(cultivos);

}
void Jugador::cargarDificJugador(ui dificultad){
	ui N,M;
	if(dificultad==1){
		N=2, M=2;
	}else if(dificultad==2){
		N=3, M=3;
	}else if(dificultad==3){
		N=4, M=4;
	}
	agregarTerreno(N,M);
	//Almacen *almacen=new Almacen(2*(N+M));
	this->almacen=new Almacen(2*(N+M));
	this->estado.creditos=2*N*M;
	this->estado.cantAgua=N*M;
	this->estado.turnosRestantes=2*N*M;
	this->aSembrar=NULL;
}
void Jugador::mostrarInfo(){
	/*Mostrar info productos (Vale por mostrar info semillas con punteros)*/
	std::cout<<"1- tipo "<<this->cultivos.tipoA.obtenerTipo()
			<<" "<<this->cultivos.tipoA.precio()<<std::endl;
	std::cout<<"2- tipo "<<this->cultivos.tipoB.obtenerTipo()
			<<" "<<this->cultivos.tipoB.precio()<<std::endl;
	std::cout<<"3- tipo "<<this->cultivos.tipoC.obtenerTipo()
			<<" "<<this->cultivos.tipoC.precio()<<std::endl;
}
ui Jugador::opcionValida(ui min, ui max){
	ui opcion;
	std::cout<<"Ingrese una opcion: "<<std::endl;
	std::cin>>opcion;
	if(opcion>max|| opcion<min){
		opcionValida(min, max);
	}
	return opcion;
}

void Jugador::venderTerreno(){
	ui terrenoAVender=terrenoValido();
	Terreno **terrenoACotizar=this->terrenos->obtener(terrenoAVender);
	if(terrenoAVender!=this->posicionTerrenoEnJuego){
	ui ganancia=this->mercado->cotizarTerreno(terrenoACotizar);
	this->terrenos->remover(terrenoAVender);
	this->estado.creditos+=ganancia;
	std::cout<<"Se vendio el terreno correctamente. "<<std::endl;
	}
	else{
		std::cout<<"Debe cambiar el terreno que está"
				" utilizando para venderlo"<<std::endl;
	}
}

char Jugador::semillaValida(ui opcion){
	char cultivo;
	switch(opcion){
	case 1:
		cultivo='A';
		break;
	case 2:
		cultivo='B';
		break;
	case 3:
		cultivo='C';
		break;
	default:
		std::cout<<"Error sin controlar en semillaValida()"<<std::endl;
	}
	return cultivo;
}
void Jugador::comprarSemillas(){
	std::cout<<"Ingrese el tipo de cultivo a comprar: "<<std::endl;
	mostrarInfo();
	ui cantidad;
	ui opcion=opcionValida(1,3);
	char tipoSemilla=semillaValida(opcion);
	std::cout<<"Cuantas semillas desea comprar: "<<std::endl;
	std::cin>>cantidad;
	ui costo=this->mercado->ventaSemillas(tipoSemilla, cantidad);
	if(hayCreditos(costo)){
		this->estado.creditos-=costo;
		agregarCultivos(tipoSemilla, cantidad);
		std::cout<<"Compro correctamente. "<<std::endl;
	}else{
		std::cout<<"No hay creditos suficientes"<<std::endl;
	}
}
void Jugador::agregarCultivos(char tipoSemilla,ui cantidad){
	switch(tipoSemilla){
		case 'A':
			this->cultivos.tipoA.agregar(cantidad);
			break;
		case 'B':
			this->cultivos.tipoB.agregar(cantidad);
			break;
		case 'C':
			this->cultivos.tipoC.agregar(cantidad);
			break;
		}
}
void Jugador::verificarDimensionTerreno(){
	ui fil, col;
	std::cout<<"Ingrese la fila :"<<std::endl;
	std::cin>>fil;
	this->pos[0]=fil;
	std::cout<<"Ingrese la columna: "<<std::endl;
	std::cin>>col;
	this->pos[1]=col;
	if (fil>(2*this->dificultad)||col>(2*this->dificultad)){
		std::cout<<"Puede comprar un terreno de hasta "<<
				(2*this->dificultad)<<"*"<<(2*this->dificultad)<<std::endl;
		verificarDimensionTerreno();
	}
}
void Jugador::comprarTerreno(){
	/*falta tomar el caso de pedir dimension por dificultad*/
	verificarDimensionTerreno();
	ui fil=filaTerreno();
	ui col=columnaTerreno();
	//std::cout<<fil<<" * "<<col<<"dimensiones "<<std::endl;
	ui costo=this->mercado->venderTerreno(fil, col);
	if(hayCreditos(costo)){
		agregarTerreno(fil,col);
		this->estado.creditos-=costo;
		std::cout<<"Se compro un terreno exitosamente. "<<std::endl;
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
		std::cout<<"Se extendio el almacen en "<<capac<<std::endl;
	}else{
		std::cout<<"No hay creditos suficientes "<<std::endl;
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
	if(hayCreditos(costo)&&cantAEnviar>0){
		char cosecha=this->almacen->obtenerTipoCosechaPreparada();
		ui ganancia=this->mercado->venderCosecha(cosecha,cantAEnviar);
		this->estado.creditos+=ganancia;
		std::cout<<"Se envio correctamente la cosecha. "<<std::endl;
		std::cout<<"Obtuvo "<<ganancia<< " de ganancia. "<<std::endl;
		this->almacen->vaciarCosecha();
	}
	else{
		std::cout<<"No hay creditos suficientes o no tiene cosecha de ese tipo."<<std::endl;
	}
}
void Jugador::mostrarMenuCompras(){
	std::cout<<"1- Comprar semillas "<<std::endl;
	std::cout<<"2- Vender Cosecha "<<std::endl;
	std::cout<<"3- Comprar Terreno "<<std::endl;
	std::cout<<"4 -Vender Terreno "<<std::endl;
	std::cout<<"5- Comprar espacio en Almacen "<<std::endl;
	std::cout<<"6- Volver al Menu anterior "<<std::endl;


}
void Jugador::comprar(){
	mostrarMenuCompras();
	ui opcion=opcionValida(1,6);
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
	case 6:

		break;
	}
}

bool Jugador::noFinalizado(){
	return this->finTurno;
}

void Jugador::agregarTerreno(ui fil, ui col){
	ui fila=fil;
	ui columna=col;
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ ){
	  terreno[col] = new Terreno[columna];
	}
	terreno[0][0].agregarDimension(fila, columna);
	this->terrenos->agregar(terreno);
	//std::cout<<"terrenos agregados "<<this->terrenos->contarElementos()<<std::endl;
	this->cantTerrenos+=1;
	//std::cout<<this->cantTerrenos<<std::endl;

}
void Jugador::agregarTerreno(){
	pedirPosicion();
	ui fila=this->pos[0];
	ui columna=this->pos[1];
	Terreno ** terreno = new Terreno*[fila];
	for( ui col=0; col<fila; col++ )
	  terreno[col] = new Terreno[columna];
	this->terrenos->agregar(terreno);
	this->cantTerrenos+=1;
}

void Jugador::obtenerTerrenoEnJuego(ui posicionTerreno){
	this->terrenoEnJuego=this->terrenos->obtener(posicionTerreno);
}
ui Jugador::terrenoValido(){
	ui posTerreno;
	std::cout<<this->cantTerrenos<<std::endl;
	std::cout<<"Ingrese un numero de terreno: "<<std::endl;
	std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. "<<std::endl;
	std::cin>>posTerreno;
	if(posTerreno>this->cantTerrenos|| posTerreno<=0){
		std::cout<<"Tiene "<<this->cantTerrenos<<" terrenos. "<<std::endl;
		std::cout<<"Ingrese un numero de terreno valido: "<<std::endl;
		terrenoValido();
	}
	return posTerreno;
}

void Jugador::sembrarTerreno(){
	ui fil, col;
	std::cout<<"Ingrese la fila :"<<std::endl;
	std::cin>>fil;
	fil-=1;
	std::cout<<"Ingrese la columna: "<<std::endl;
	std::cin>>col;
	col-=1;
	pedirSemillaSembrar();
	if (!(this->terrenoEnJuego[fil][col].estaSembrada())
			&&this->aSembrar->cantDisponible()>0){
		this->terrenoEnJuego[fil][col].cambiarEstadoDeParcelaSembrada(this->aSembrar);
		std::cout<<"Sembro correctamente. "<<std::endl;
		//this->cantidad.creditos = (this->cantidad.creditos - this->aSembrar->precio());
	}
	else{
		std::cout <<"No hay semillas del cultivo seleccionado o ya se encuentra "
				"sembrado "<<std::endl;
	}
}

void Jugador::regarTerreno(){
	ui fil, col;
	std::cout<<"Ingrese la fila :"<<std::endl;
	std::cin>>fil;
	fil-=1;
	std::cout<<"Ingrese la columna: "<<std::endl;
	std::cin>>col;
	col-=1;
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
		char siembra=this->terrenoEnJuego[fil][col].mostrarTipo();
		this->almacen->guardarCosecha(1,siembra);
		//this->almacen->guardarCosecha();
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
	std::cout<<"Ingrese un tipo de cultivo: "<<std::endl;
	std::cin>>semillaValida;
	if(semillaValida!='A'&&semillaValida!='C'&&semillaValida!='C'){
		std::cout<<"Ingrese una opcion valida de semilla: "<<std::endl;
		tipoSemillaValida();
	}
	return semillaValida;
}
void Jugador::pedirSemillaSembrar(){
	ui opcion;
	mostrarInfoSemilla();
	std::cout<<"Ingrese el cultivo a sembrar: "<<std::endl;
	std::cout<<"1- "<<this->cultivos.tipoA.obtenerTipo()<<std::endl;
	std::cout<<"2- "<<this->cultivos.tipoB.obtenerTipo()<<std::endl;
	std::cout<<"3- C "<<std::endl;
	opcion=opcionValida(1,3);
	elegirSemilla(opcion);
}
void Jugador::elegirSemilla(ui opcion){
	switch(opcion){
	case 1:
		this->aSembrar=&this->cultivos.tipoA;
		break;
	case 2:
		this->aSembrar=&this->cultivos.tipoB;
		break;
	case 3:
		this->aSembrar=&this->cultivos.tipoC;
		break;
	default:
		pedirSemillaSembrar();
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
	std::string nomReferencia="cultivos";
	cultivos.pedirNombreDeArchivo(nomReferencia);
	cultivos.abrirArchivoLectura(nomReferencia);
	std::string linea=cultivos.leerLinea();
	while(linea!=EOF){
		Lista<std::string>*infoCultivos=cultivos.datosLista(linea);
		cargarCultivosJugador(infoCultivos);
		linea=cultivos.leerLinea();
		infoCultivos=NULL;
	}
}
/*Falta modular, no funciono de otra forma*/
void Jugador::cargarCultivosJugador(Lista<std::string>*datos){
	std::string tipoSemilla=datos->obtener(1).c_str();
	std::string costo=datos->obtener(2);
	std::string tiemCosecha=datos->obtener(3);
	std::string rentabilidad=datos->obtener(4);
	std::string tiemRecu=datos->obtener(5);
	std::string aguaTurno=datos->obtener(6);
	if(tipoSemilla=="A"){
		this->cultivos.tipoA.agregarTipo((char)*tipoSemilla.c_str());
		this->cultivos.tipoA.agregarCosto(costo);
		this->cultivos.tipoA.agregarTiempoCosec(tiemCosecha);
		this->cultivos.tipoA.agregarRentabilidad(rentabilidad);
		this->cultivos.tipoA.agregarTiempoRecup(tiemRecu);
		this->cultivos.tipoA.agregarAguaTurno(aguaTurno);
	}
	else if(tipoSemilla=="B"){
		this->cultivos.tipoB.agregarTipo((char)*tipoSemilla.c_str());
		this->cultivos.tipoB.agregarCosto(costo);
		this->cultivos.tipoB.agregarTiempoCosec(tiemCosecha);
		this->cultivos.tipoB.agregarRentabilidad(rentabilidad);
		this->cultivos.tipoB.agregarTiempoRecup(tiemRecu);
		this->cultivos.tipoB.agregarAguaTurno(aguaTurno);
	}
	else if(tipoSemilla=="C"){
		this->cultivos.tipoC.agregarTipo((char)*tipoSemilla.c_str());
		this->cultivos.tipoC.agregarCosto(costo);
		this->cultivos.tipoC.agregarTiempoCosec(tiemCosecha);
		this->cultivos.tipoC.agregarRentabilidad(rentabilidad);
		this->cultivos.tipoC.agregarTiempoRecup(tiemRecu);
		this->cultivos.tipoC.agregarAguaTurno(aguaTurno);
	}
	else{
		std::cout<<"No se cargaron los cultivos..."<<std::endl;
	}
}

void Jugador::mostrarTerreno(){
	ui fila = this->terrenoEnJuego[0][0].obtenerCantidadDeFilas();
	ui columna = this->terrenoEnJuego[0][0].obtenerCantidadDeColumnas();

	cout<<"\nBienvenido a granjeros. "<<endl;
	for(int i=0;i<fila;i++){
		for(int j=0;j<columna;j++){
			cout<<"||\t"<<(terrenoEnJuego[i][j]).mostrarTipo()<<"\t";
		}
	cout<<"||";
	cout<<"\n";
	}
}

Jugador::~Jugador() {
	delete this->almacen;
	delete this->mercado;
	// TODO Auto-generated destructor stub
}

