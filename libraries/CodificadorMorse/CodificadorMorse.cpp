/*
  CodificadorMorse.h - Librer�a para hablar en lenguaje morse.
  
  Created  2013 Apr 21
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "CodificadorMorse.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
CodificadorMorse::CodificadorMorse()
{

}

/**
 * Constructor principal que inicializa los par�metros.
 * @param paramBoca: Boca que emite los mensajes.
 */
CodificadorMorse::CodificadorMorse(Boca paramBoca){
	boca = paramBoca;
}

/** M�TODOS P�BLICOS **/

/**
 * Codifica y emite un mensaje.
 */
Sonido CodificadorMorse::codificar(char* mensaje){
	Sonido s = Sonido(boca);
	return s;
}

/**
 * Codifica el mensaje S.O.S.
 */
Sonido CodificadorMorse::codificarSOS(){
	Sonido s = Sonido(boca);

	int notas[]	  = {SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO, SOL_4, SILENCIO};
	int figuras[] = {PUNTO, PUNTO,	  PUNTO, PUNTO,	   PUNTO, PUNTO,	RAYA,  PUNTO,	 RAYA,	PUNTO,	  RAYA,  PUNTO,	   PUNTO, PUNTO,	PUNTO, PUNTO,	 PUNTO, RAYA};
	int num		  = 18;

	s.asignar(notas, figuras, num);

	return s;
}