/*
  Brazo.h - Librer�a para el manejo de los brazo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "Brazo.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
Brazo::Brazo()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param pin: pin donde est� ubicado el servo.
 */
Brazo::Brazo(int pin){
	servo.attach(pin);
}

/** M�TODOS P�BLICOS **/

/**
 * Levanta el brazo.
 */
void Brazo::levantar(){
	servo.write(179);
}

/**
 * Baja el brazo.
 */
void Brazo::bajar(){
	servo.write(0);
}

/**
 * Obtiene la posici�n del brazo.
 */
int Brazo::posicion(){
	int posicion = servo.read();

	return posicion;
}

/**
 * Asigna la posici�n del brazo.
 */
void Brazo::colocar(int posicion){
	servo.write(posicion);
}