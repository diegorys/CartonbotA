/*
  Brazo.h - Librería para el manejo de un brazo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Brazos_h
#define Brazos_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Servo.h>

// Clase Brazo
class Brazo {
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío. Usar sólo en la declaración.
		 */
		Brazo();

		/**
		 * Constructor principal que inicializa los parámetros.
		 * @param pin: pin donde está ubicado el servo.
		 */
		Brazo(int pin);
	
		/** MÉTODOS **/

		/**
		 * Levanta el brazo.
		 */
		void levantar();

		/**
		 * Baja el brazo.
		 */
		void bajar();

		/**
		 * Obtiene la posición del brazo.
		 */
		int posicion();

		/**
		 * Asigna la posición del brazo.
		 */
		void colocar(int posicion);

	private:

		/** ATRIBUTOS **/

		//Servo que mueve el brazo.
		Servo servo;

};

#endif
