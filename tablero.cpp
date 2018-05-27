#include "tablero.h"
#include "EasyBMP.h"
#include <string>
#include <sstream>


Tablero :: Tablero ()

{
    parcelaVacia.ReadFromFile("parcelaVacia.bmp");

	cultivoAParaCosechar.ReadFromFile("cultivoAParaCosechar.bmp");

	cultivoBParaCosechar.ReadFromFile("cultivoBParaCosechar.bmp");

	cultivoCParaCosechar.ReadFromFile("cultivoCParaCosechar.bmp");

	cultivoAEnCrecimiento.ReadFromFile("cultivoAEnCrecimiento.bmp");

	cultivoBEnCrecimiento.ReadFromFile("cultivoBEnCrecimiento.bmp");

	cultivoCEnCrecimiento.ReadFromFile("cultivoCEnCrecimiento.bmp");

	cultivoPodrido.ReadFromFile("cultivoPodrido.bmp");

	cultivoSeco.ReadFromFile("cultivoSeco.bmp");

	ceroTurnos.ReadFromFile("ceroTurnos.bmp");

	unTurno.ReadFromFile("unTurno.bmp");

	dosTurnos.ReadFromFile("dosTurnos.bmp");

	tresTurnos.ReadFromFile("tresTurnos.bmp");

	cuatroTurnos.ReadFromFile("cuatroTurnos.bmp");

	parcelaEnRecuperacion.ReadFromFile("parcelaEnRecuperacion.bmp");





}

void Tablero::crearTablero(int filas, int columnas)

{

    tableroSalida.SetSize(columnas*60, filas*60);

    tableroSalida.SetBitDepth(PROFUNDIDAD);

    RGBApixel color;

    for (unsigned int i = 0; i < columnas*60; i++)
    {
        for (unsigned int j = 0; j < filas*60; j++)
        {
            color.Green = 0;
            color.Blue  = 0;
            color.Red   = 0;
            tableroSalida.SetPixel(i, j, color);
        }
    }


}

/*PRE: Recibe datos del jugador actual y un string con el pie de la ruta que se necesita para la salida de las imagenes de los tableros.
  POST: Devuelve el nombre completo y armado de la ruta necesaria.*/



  /* NOTA DE CORRECCION: ESTA FUNCION ES AUXILIAR, NO ES DEL TDA EN CONCRETO, POR ESO NO ESTA EN EL .H
                         LO QUE HACE ESTA FUNCION ES RECIBIR EL OBJETO JUGADOR Y EXTRAER NUMERO DE JUGADOR
                         Y NUMERO DE TURNO ACTUAL. CON ESTE PROCEDIMIENTO ARMO LA RUTA DE SALIDA DE LAS
                         IMAGENES CON NUMERO DE JUGADOR Y TURNO.

                         EJ: TE QUEDARIA " JUGADOR1TURNO3tableroTurnosHastaCosecharse.bmp"

                         */


char* rutaImagenesSalida (DATOS JUGADOR, string rutas)

{
 INT  TURNO =  DATOS JUGADOR. TURNO ACTUAL;
 INT  JUGADOR= DATOS JUGADOR. JUGADOR ACTUAL;


string cadenaTurno ="";
string cadenaJugador ="";
cadenaTurno = static_cast<std::ostringstream*>(&(std::ostringstream()<<TURNO))->str();
cadenaJugador=static_cast<std::ostringstream*>(&(std::ostringstream()<<JUGADOR))->str();

string ruta ="Jugador"+cadenaJugador+"Turno"+ cadenaTurno+rutas;


char* nombreRuta;

nombreRuta=(char*)ruta.c_str();

return nombreRuta;
}




/* NOTA DE CORRECCION : ACA SE COMPARA CON LAS LETRAS S - PARCELA SECA, P - PARCELA PODRIDA, X - PARCELA EN RECUPERACION
                        O - PARCELA VACIA. A, B Y C ES PARA LOS CULTIVOS. */


void Tablero::actualizarTableroCultivosTurnoActual(DATOS TERRENO, DATOS JUGADOR, int filas, int columnas, int turno)

{



	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {



				switch (DATOS TERRENO . CONTENIDO DE LA PARCELA) {

			case 'O' : RangedPixelToPixelCopy(parcelaVacia,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 'S' : RangedPixelToPixelCopy(cultivoSeco,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 'P' : RangedPixelToPixelCopy(cultivoPodrido,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 'A' : RangedPixelToPixelCopy(cultivoAParaCosechar,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;


            case 'B' : RangedPixelToPixelCopy(cultivoBParaCosechar,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;


            case 'C' : RangedPixelToPixelCopy(cultivoCParaCosechar,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 'X' : RangedPixelToPixelCopy(parcelaEnRecuperacion,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

		}
	}
	}

 string ruta = "tableroCultivos.bmp";



	tableroSalida.WriteToFile(rutaImagenesSalida(DATOS JUGADOR,ruta));
}



/* NOTA DE CORRECCION : ACA SE COMPARA CON EL NUMERO DE TURNOS HASTA QUE ESTE DISPONIBLE LA COSECHA */

void Tablero::actualizarTableroTurnosHastaCosecharse(DATOS TERRENO, DATOS JUGADOR, int filas, int columnas)


{



	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {



				switch (terreno[j][i].turnosHastaSerDesocupada) {

			case 0 : RangedPixelToPixelCopy(ceroTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 1 : RangedPixelToPixelCopy(unTurno,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 2 : RangedPixelToPixelCopy(dosTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 3 : RangedPixelToPixelCopy(tresTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 4 : RangedPixelToPixelCopy(cuatroTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;



		}
	}
	}

string ruta = "tableroTurnosHastaCosecharse.bmp";



	tableroSalida.WriteToFile(rutaImagenesSalida(DATOS JUGADOR,ruta));
}


/* NOTA DE CORRECCION : ACA SE COMPARA CON EL NUMERO DE TURNOS HASTA QUE ESTE DISPONIBLE LA COSECHA */

void Tablero::actualizarTableroTurnosHastaDesocuparParcelas(terrenoGranjero terreno, int filas, int columnas)


{



	for (int i = 0; i < columnas; i++) {

		for (int j = 0; j < filas; j++) {



				switch (terreno[j][i].turnosHastaSerDesocupada) {

			case 0 : RangedPixelToPixelCopy(ceroTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 1 : RangedPixelToPixelCopy(unTurno,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

			case 2 : RangedPixelToPixelCopy(dosTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 3 : RangedPixelToPixelCopy(tresTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;

            case 4 : RangedPixelToPixelCopy(cuatroTurnos,0,59,59,0,tableroSalida, i*59+1 , j*59 + 1);
				break;



		}
	}
	}

string ruta = "tableroTurnosRecuperacion.bmp";



	tableroSalida.WriteToFile(rutaImagenesSalida(DATOS JUGADOR,ruta));
}













