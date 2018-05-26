/*
 * Mercado.h
 *
 *  Created on: 21 may. 2018
 *      Author: cristian
 */

#ifndef SRC_MERCADO_H_
#define SRC_MERCADO_H_
#include "Semilla.h"
#include "Terreno.h"

class Mercado {
private:
	ui costoTipoA;
	ui costoTipoB;
	ui costoTipoC;
	ui costoParcelaTerreno;
	Semilla *tipoA;
	Semilla *tipoB;
	Semilla *tipoC;
public:
	Mercado(struct Semillas cultivos);
	void mostrarInfo();
	/*pre: tamnio a vender para el almacen
	 * post: devuelve costo*/
	ui venderTamanioAlmacen(ui tamanio);
	/*pre: tipo de cosecha exitente y cantidad que no supere
	 * post: devuelve ganancia*/
	ui venderCosecha(char tipo, ui cant);
	ui cotizarTerreno( Terreno **terrenoACotizar);
	ui venderTerreno(ui fila, ui columna);
	/*pre: tipo de cultivo exitente,
	 * post:
	 * devuelve costo por tipo de cultivo*/
	ui ventaSemillas(char tipoSemilla, ui cantidad);

	virtual ~Mercado();
};

#endif /* SRC_MERCADO_H_ */
