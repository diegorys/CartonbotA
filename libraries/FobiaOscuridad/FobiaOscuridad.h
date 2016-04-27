/*
  FobiaOscuridad.h - Librer�a que representa la escotofobia.
  
  Created  2013 Apr 21
  Version 0.1
*/

// ensure this library description is only included once
#ifndef FobiaOscuridad_h
#define FobiaOscuridad_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <EEPROM.h>

#include "CodificadorMorse.h"
#include "Ojo.h"
#include "Brazo.h"
#include "FabricaPiezas.h"

// Clase FobiaOscuridad
class FobiaOscuridad {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o.
		 */
		FobiaOscuridad();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param fabrica: F�brica de piezas.
		 */
		FobiaOscuridad(FabricaPiezas);

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
		 * @return: true si no ha acabado la ejecuci�n. False en caso contrario.
		 */
		bool ejecutar();

		/**
		 * Obtiene el porcentaje de miedo.
		 */
		int getMiedo();

		/**
		 * Elimina la memoria.
		 */
		void eliminarMemoria();

	private:

		/** ATRIBUTOS **/

		/* Par�metros */

		//Indica si el robot est� en estado de alerta.
		bool alerta;

		//Posici�n de reproducci�n del c�digo morse.
		int posicion;

		//Tiempo que esperamos hasta empezar a tener miedo.
		int tiempoReaccion;

		//Porcentaje de miedo a la oscuridad.
		int miedo;

		//Tiempo que llevamos esperando hasta empezar a tener miedo.
		unsigned long tiempoEspera;

		/* Piezas */

		//Ojos para iluminarlos en ausencia de luz.
		Ojo ojos;

		//Boca para emitir la se�al de socorro.
		Boca boca;

		//Brazos, para levantarlos cuando se pide socorro.
		Brazo brazoDerecho;
		Brazo brazoIzquierdo;

		/* Sonido */

		//Sonido a emitir en peligro;
		Sonido sonido;

		/* M�todos privados */

		/**
		 * Inicializa los par�metros.
		 */
		void iniciarParametros();

};

#endif
