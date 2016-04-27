/*
  Baile.h - Librer�a que representa la habilidad de baile.
  
  Created  2013 Apr 22
  Version 0.1
*/

// ensure this library description is only included once
#ifndef Baile_h
#define Baile_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "FabricaPiezas.h"
#include "Sonido.h"

// Clase Baile
class Baile {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o.
		 */
		Baile();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param fabrica: F�brica de piezas.
		 */
		Baile(FabricaPiezas fabrica);
		
		/**
		 * Asigna las piezas a la habilidad.
		 * @param pOjos: ojos.
		 * @param pBoca: boca.
		 * @param pBrazoDcho: brazo derecho.
		 * @param pBrazoIzdo: brazo izquierdo.
		 */
		void asignarPiezas(Ojo pOjos, Boca pBoca, Brazo pBrazoDcho, Brazo pBrazoIzdo);

		/**
		 * Asigna la secuencia de notas.
		 * @param paramNotas:	frecuencias de cada sonido de la secuencia.
		 * @param paramFiguras:	duraci�n de cada nota.
		 * @param paramTotal:	total de notas.
		 */
		void asignar(int paramNotas[], int paramFiguras[], int paramTotal);

		/**
		 * Ejecuta un ciclo de la habilidad.
		 * @return: true si no ha acabado la ejecuci�n. False en caso contrario.
		 */
		bool ejecutar();

		/**
		 * Vuelve a poner la melod�a al principio.
		 */
		void rebobinar();

	private:

		/** ATRIBUTOS **/

		/* Par�metros */

		//Posici�n de reproducci�n del sonido.
		int posicion;

		//M�xima frecuencia del sonido.
		int maxFrecuencia;

		//M�nima frecuencia del sonido.
		int minFrecuencia;

		/* Piezas */

		//Ojos para iluminarlos en las notas pares.
		Ojo ojos;

		//Boca para reproducir la melod�a.
		Boca boca;

		//Brazos, para moverlos al ritmo de la melod�a.
		Brazo brazoDerecho;
		Brazo brazoIzquierdo;

		/* Sonido */

		//Melod�a.
		Sonido sonido;

};

#endif
