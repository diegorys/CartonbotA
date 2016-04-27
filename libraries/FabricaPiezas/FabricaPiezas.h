/*
  FabricaPiezas.h - Librería que crea las piezas del robot. Es el único sitio
  donde se configuran los pines de conexión.
  
  Created  2013 Apr 20
  Version 0.1
*/

// ensure this library description is only included once
#ifndef FabricaPiezas_h
#define FabricaPiezas_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ojo.h";
#include "Boca.h";
#include "Brazo.h";

// Clase FabricaPiezas
class FabricaPiezas {
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío.
		 */
		FabricaPiezas();
	
		/** MÉTODOS **/

		/**
		 * Crea el ojo.
		 * @return: un ojo. 
		 */
		Ojo crearOjo();


		/**
		 * Crea la boca.
		 * @return: una boca.
		 */
		Boca crearBoca();

		/**
		 * Crea el brazo derecho.
		 * @return: el brazo derecho.
		 */
		Brazo crearBrazoDerecho();

		/**
		 * Crea el brazo izquierdo.
		 * @return: el brazo izquierdo.
		 */
		Brazo crearBrazoIzquierdo();

		/* Piezas */

		//Ojos para iluminarlos en las notas pares.
		Ojo ojo;

		//Boca para reproducir la melodía.
		Boca boca;

		//Brazos, para moverlos al ritmo de la melodía.
		Brazo brazoDerecho;
		Brazo brazoIzquierdo;

};

#endif
