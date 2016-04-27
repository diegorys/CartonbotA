/*
  Ojo.h - Librer�a para el manejo de un ojo del robot.
  
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
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		Ojo();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param pinLed: pin donde est�n ubicados los leds.
		 * @param pinLDR: pin donde est� ubicado el LDR.
		 */
		Ojo(int pinLed, int pinLDR);
	
		/** M�TODOS **/

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
		 * Comprueba si el ojo est� abierto.
		 * return: HIGH si est� abierto, LOW si est� cerrado.
		 */
		int estanAbiertos();

	private:

		/** ATRIBUTOS **/

		//Pin al que est�n conectados los leds.
		int led;

		//Pin al que est� contectado el LDR.
		int LDR;

		//Estado de los ojos. HIGH abiertos, LOW cerrados.
		int estado;

};

#endif
