/*
  Sonido.h - Librer�a para la gesti�n de sonidos.
  
  Created  2013 Apr 21
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "Sonido.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
Sonido::Sonido()
{

}

/**
 * Constructor principal que inicializa los par�metros.
 * @param boca: Boca que emite los mensajes.
 */
Sonido::Sonido(Boca paramBoca){
	boca = paramBoca;
}

/** M�TODOS P�BLICOS **/

/**
 * Hace sonar una nota.
 * @param posicion: posici�n de la nota.
 * @return la siguiente posici�n a tocar, -1 si ha acabado.
 */
int Sonido::sonar(int posicion){
	if(posicion >= 0 && posicion < total){
		boca.hablar(notas[posicion], figuras[posicion]);
		return posicion+1;
	}else{
		return -1;
	}
}

/**
 * Obtiene la nota de una posici�n.
 * @param posicion: posici�n de la nota.
 */
int Sonido::getFrecuencia(int posicion){
	return notas[posicion];
}

/**
 * Obtiene la frecuencia m�xima de la secuencia.
 */
int Sonido::getFrecuenciaMaxima(){
	int max = notas[0];

	for(int i = 0; i < total; i++){
		if(notas[i] > max){
			max = notas[i];
		}
	}

	return max;
}

/**
 * Obtiene la frecuencia m�nima de la secuencia.
 */
int Sonido::getFrecuenciaMinima(){
	int min = getFrecuenciaMaxima();

	for(int i = 0; i < total; i++){
		if(notas[i] < min && notas[i] > 0){
			min = notas[i];
		}
	}

	return min;
}

/**
 * Asigna la secuencia de notas.
 * @param paramNotas:	frecuencias de cada sonido de la secuencia.
 * @param paramFiguras:	duraci�n de cada nota.
 * @param paramTotal:	total de notas.
 */
void Sonido::asignar(int paramNotas[], int paramFiguras[], int paramTotal){
	total = paramTotal;
	notas	= (int *)malloc(paramTotal*sizeof(int));
	figuras = (int *)malloc(paramTotal*sizeof(int));
	for(int i = 0; i < paramTotal; i++){
		notas[i]	= paramNotas[i];
		figuras[i]  = paramFiguras[i];
	}
}
