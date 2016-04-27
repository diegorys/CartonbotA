/*
  CodificadorMorse.h - Librería para hablar en lenguaje morse.
  
  Created  2013 Apr 21
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "CodificadorMorse.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
CodificadorMorse::CodificadorMorse()
{

}

/**
 * Constructor principal que inicializa los parámetros.
 * @param paramBoca: Boca que emite los mensajes.
 */
CodificadorMorse::CodificadorMorse(Boca paramBoca){
	boca = paramBoca;
}

/** MÉTODOS PÚBLICOS **/

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