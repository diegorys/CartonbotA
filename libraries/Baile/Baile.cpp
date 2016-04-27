/*
  Baile.h - Librer�a que representa la habilidad de baile.
  
  Created  2013 Apr 22
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "Baile.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o.
 */
Baile::Baile()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param fabrica:	   F�brica de piezas.
 */
Baile::Baile(FabricaPiezas fabrica){
	//Par�metros
	posicion		 = 0;

	//Piezas
	ojos           = fabrica.crearOjo();
	boca           = fabrica.crearBoca();
	brazoDerecho   = fabrica.crearBrazoDerecho();
	brazoIzquierdo = fabrica.crearBrazoIzquierdo();

	//La melod�a a reproducir.
	sonido = Sonido(boca);
}

/** M�TODOS P�BLICOS **/

/**
 * Asigna las piezas a la habilidad.
 * @param pOjos: ojos.
 * @param pBoca: boca.
 * @param pBrazoDcho: brazo derecho.
 * @param pBrazoIzdo: brazo izquierdo.
 */
void Baile::asignarPiezas(Ojo pOjos, Boca pBoca, Brazo pBrazoDcho, Brazo pBrazoIzdo){
	//Par�metros
	posicion		 = 0;

	//Piezas
	ojos = pOjos;
	boca = pBoca;
	brazoDerecho = pBrazoDcho;
	brazoIzquierdo = pBrazoIzdo;
	
	//La melod�a a reproducir.
	sonido = Sonido(pBoca);
}

/**
 * Asigna la secuencia de notas.
 * @param paramNotas:	frecuencias de cada sonido de la secuencia.
 * @param paramFiguras:	duraci�n de cada nota.
 * @param paramTotal:	total de notas.
 */
void Baile::asignar(int paramNotas[], int paramFiguras[], int paramTotal){
	sonido.asignar(paramNotas, paramFiguras, paramTotal);
	maxFrecuencia = sonido.getFrecuenciaMaxima();
	minFrecuencia = sonido.getFrecuenciaMinima();
}

/**
 * Ejecuta un ciclo de la habilidad.
 * @return: true si no ha acabado la ejecuci�n. False en caso contrario.
 */
bool Baile::ejecutar(){
	if(posicion >= 0){
		int frecuencia = sonido.getFrecuencia(posicion);
		posicion = sonido.sonar(posicion);
		if(frecuencia > 0){
			int giro = map(frecuencia, minFrecuencia, maxFrecuencia, 0, 179);
			brazoDerecho.colocar(giro);
			brazoIzquierdo.colocar(giro);
		}

		if(ojos.estanAbiertos()){
			ojos.cerrar();
		}else{
			ojos.abrir();
		}
		return true;
	}else{
		ojos.cerrar();
		return false;
	}
}

/**
 * Vuelve a poner la melod�a al principio.
 */
void Baile::rebobinar(){
	posicion = 0;
}