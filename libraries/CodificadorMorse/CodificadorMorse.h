/*
  CodificadorMorse.h - Librer�a para hablar en lenguaje morse.
  
  Created  2013 Apr 21
  Version 0.1
*/

// ensure this library description is only included once
#ifndef CodificadorMorse_h
#define CodificadorMorse_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Boca.h"
#include "Sonido.h";

#define PUNTO	90
#define RAYA	PUNTO*3

// Clase CodificadorMorse
class CodificadorMorse {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		CodificadorMorse();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param paramBoca: Boca que emite los mensajes.
		 */
		CodificadorMorse(Boca paramBoca);

		/**
		 * Codifica un mensaje.
		 */
		Sonido codificar(char* mensaje);

		/**
		 * Codifica el mensaje S.O.S.
		 */
		Sonido codificarSOS();

	private:

		/** ATRIBUTOS **/

		//Boca que emite los mensajes.
		Boca boca;

};

#endif
