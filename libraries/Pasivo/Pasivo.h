/*
  Pasivo.h - Librería que representa la habilidad que realiza
  cuando no tiene nada que hacer.
  
  Created  2013 Apr 23
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Pasivo_h
#define Pasivo_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "FabricaPiezas.h"

// Clase Pasivo
class Pasivo {
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío.
		 */
		Pasivo();

		/**
		 * Constructor principal que inicializa los parámetros.
		 * @param fabrica: Fábrica de piezas.
		 */
		Pasivo(FabricaPiezas fabrica);

		/**
		 * Asigna las piezas a la habilidad.
		 * @param pOjos: ojos.
		 * @param pBoca: boca.
		 * @param pBrazoDcho: brazo derecho.
		 * @param pBrazoIzdo: brazo izquierdo.
		 */
		void asignarPiezas(Ojo pOjos, Boca pBoca, Brazo pBrazoDcho, Brazo pBrazoIzdo);

		/**
		 * Ejecuta un ciclo de la habilidad.
		 * @return: true si no ha acabado la ejecución. False en caso contrario.
		 */
		bool ejecutar();

	private:

		/** ATRIBUTOS **/

		/* Piezas */

		//Ojos para iluminarlos en las notas pares.
		Ojo ojos;

		//Boca para reproducir la melodía.
		Boca boca;

		//Brazos, para moverlos al ritmo de la melodía.
		Brazo brazoDerecho;
		Brazo brazoIzquierdo;

};

#endif
