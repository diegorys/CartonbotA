/*
  Boca.h - Librer�a para el manejo de la boca del robot.
  
  Created  2013 Apr 18
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Boca_h
#define Boca_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Clase Boca
class Boca {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		Boca();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param pin: pin donde est� ubicado el buzzer.
		 */
		Boca(int pin);
	
		/** M�TODOS **/

		/**
		 * Emite un sonido.
		 */
		void hablar(int sonido, int duracion);

		/**
		 * Detiene el sonido.
		 */
		void callar();

	private:

		/** ATRIBUTOS **/

		//Pin al que est� conectado el buzzer.
		int buzzer;

};

#endif
