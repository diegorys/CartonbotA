/*
  Sonido.h - Librer�a para la gesti�n de sonidos.
  
  Created  2013 Apr 21
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Sonido_h
#define Sonido_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Boca.h"

/** NOTAS MUSICALES **/
#define SILENCIO 0
#define DO_4	262
#define RE_4	294
#define MI_4	330
#define FA_4	349
#define SOL_4	392
#define LA_4	440
#define LA_SI_4 466
#define SI_4	494
#define DO_5	523
#define RE_5	587

/** FIGURAS MUSICALES **/
#define SEMICORCHEA 111
#define CORCHEA     SEMICORCHEA*2
#define NEGRA       CORCHEA*2
#define BLANCA      NEGRA*2
#define REDONDA     BLANCA*2

// Clase Sonido
class Sonido {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		Sonido();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param boca: Boca que emite el sonido.
		 */
		Sonido(Boca paramBoca);

		/**
		 * Carga un sonido de memoria.
		 */
		void cargar();

		/**
		 * Guarda un sonido en memoria.
		 */
		void guardar();

		/**
		 * Hace sonar una nota.
		 * @param posicion: posici�n de la nota.
		 * @return true si quedan notas por tocar, false si ha sonado la �ltima.
		 */
		int sonar(int posicion);

		/**
		 * Obtiene la nota de una posici�n.
		 * @param posicion: posici�n de la nota.
		 */
		int getFrecuencia(int posicion);

		/**
		 * Obtiene la frecuencia m�xima de la secuencia.
		 */
		int getFrecuenciaMaxima();

		/**
		 * Obtiene la frecuencia minima de la secuencia.
		 */
		int getFrecuenciaMinima();

		/**
		 * Asigna la secuencia de notas.
		 * @param paramNotas:	frecuencias de cada sonido de la secuencia.
		 * @param paramFiguras:	duraci�n de cada nota.
		 * @param paramTotal:	total de notas.
		 */
		void asignar(int paramNotas[], int paramFiguras[], int paramTotal);

	private:

		/** ATRIBUTOS **/

		//Boca que emite los mensajes.
		Boca boca;

		//Frecuencias de cada sonido de la secuencia.
		int *notas;

		//Duraci�n de cada nota.
		int *figuras;

		//Total de notas.
		int total;

};

#endif
