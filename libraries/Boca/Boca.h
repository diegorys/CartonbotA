/*
  Boca.h - Librería para el manejo de la boca del robot.
  
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
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío. Usar sólo en la declaración.
		 */
		Boca();

		/**
		 * Constructor principal que inicializa los parámetros.
		 * @param pin: pin donde está ubicado el buzzer.
		 */
		Boca(int pin);
	
		/** MÉTODOS **/

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

		//Pin al que está conectado el buzzer.
		int buzzer;

};

#endif
