/*
  Brazo.h - Librer�a para el manejo de un brazo del robot.
  
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
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		Brazo();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param pin: pin donde est� ubicado el servo.
		 */
		Brazo(int pin);
	
		/** M�TODOS **/

		/**
		 * Levanta el brazo.
		 */
		void levantar();

		/**
		 * Baja el brazo.
		 */
		void bajar();

		/**
		 * Obtiene la posici�n del brazo.
		 */
		int posicion();

		/**
		 * Asigna la posici�n del brazo.
		 */
		void colocar(int posicion);

	private:

		/** ATRIBUTOS **/

		//Servo que mueve el brazo.
		Servo servo;

};

#endif
