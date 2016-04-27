/*
  FabricaPiezas.h - Librería que crea las piezas del robot. Es el único sitio
  donde se configuran los pines de conexión
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "FabricaPiezas.h"
   
/** CONSTRUCTORES **/

/**
 * Constructor vacío.
 */
FabricaPiezas::FabricaPiezas()
{
}

/** MÉTODOS PÚBLICOS **/

/**
 * Crea el ojo.
 * @return: un ojo. 
 */
Ojo FabricaPiezas::crearOjo(){
	Ojo ojo = Ojo(11, A5);

	return ojo;
}


/**
 * Crea la boca.
 * @return: una boca.
 */
Boca FabricaPiezas::crearBoca(){
	Boca boca = Boca(15);

	return boca;
}

/**
 * Crea el brazo derecho.
 * @return: el brazo derecho.
 */
Brazo FabricaPiezas::crearBrazoDerecho(){
	Brazo brazo = Brazo(5);

	return brazo;
}

/**
 * Crea el brazo izquierdo.
 * @return: el brazo izquierdo.
 */
Brazo FabricaPiezas::crearBrazoIzquierdo(){
	Brazo brazo = Brazo(3);

	return brazo;
}