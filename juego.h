
#ifndef JUEGO_H_
#define JUEGO_H_


class Juego{

private:
  int cantidadTurnos;
  int cantidadJugadores[cant];
  int dificultades[2];
  Jugador *jugador;

public:
  //post: devuelve un *jugador con atributos por dificultad.
  Jugador* agregarJugador();
  //post:devuelve valor valido para finalizar Juego
  int turnosJuego();

private:
  //post: Descuenta un turno luego de que todos los jugadores lo utilicen.
  void descontarTurnos();

}

#endif /* JUEGO_H_ */
