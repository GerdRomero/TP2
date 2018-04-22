#include <iostream>
#include "Juego.h"
using namespace std;


int main(){

  Juego juego= new Juego;
  int fila,columna;

  while (juego.turnosRestantes()>0){
    //Esto es por ahora nada mas, nose mate
    Jugador *jugador1= Juego.eleccionDificultad(dificultad);
    Jugador *jugador2= Juego.eleccionDificultad(dificultad);
    *jugador1.agregarTerreno(fila, columna);
  }
  //Termino Juego
  //Mostrar estado del mismo.




  delete juego;
  return=0;
}
