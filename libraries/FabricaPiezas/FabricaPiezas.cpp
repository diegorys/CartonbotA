/*
  FabricaPiezas.h - Librer�a que crea las piezas del robot. Es el �nico sitio
  donde se configuran los pines de conexi�n
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "FabricaPiezas.h"
   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o.
 */
FabricaPiezas::FabricaPiezas()
{
}

/** M�TODOS P�BLICOS **/

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