/*
  Ojo.h - Librería para el manejo de un ojo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Ojo_h
#define Ojo_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Clase Ojo
class Ojo {
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío. Usar sólo en la declaración.
		 */
		Ojo();

		/**
		 * Constructor principal que inicializa los parámetros.
		 * @param pinLed: pin donde están ubicados los leds.
		 * @param pinLDR: pin donde está ubicado el LDR.
		 */
		Ojo(int pinLed, int pinLDR);
	
		/** MÉTODOS **/

		/**
		 * Abre el ojo.
		 */
		void abrir();

		/**
		 * Cierra el ojo.
		 */
		void cerrar();

		/**
		 * Comprueba si hay luz.
		 * @return: la cantidad de luz que ve.
		 */
		int verLuz();

		/**
		 * Comprueba si el ojo está abierto.
		 * return: HIGH si está abierto, LOW si está cerrado.
		 */
		int estanAbiertos();

	private:

		/** ATRIBUTOS **/

		//Pin al que están conectados los leds.
		int led;

		//Pin al que está contectado el LDR.
		int LDR;

		//Estado de los ojos. HIGH abiertos, LOW cerrados.
		int estado;

};

#endif
