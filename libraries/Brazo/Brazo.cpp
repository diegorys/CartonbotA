/*
  Brazo.h - Librería para el manejo de los brazo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "Brazo.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
Brazo::Brazo()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param pin: pin donde está ubicado el servo.
 */
Brazo::Brazo(int pin){
	servo.attach(pin);
}

/** MÉTODOS PÚBLICOS **/

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
 * Obtiene la posición del brazo.
 */
int Brazo::posicion(){
	int posicion = servo.read();

	return posicion;
}

/**
 * Asigna la posición del brazo.
 */
void Brazo::colocar(int posicion){
	servo.write(posicion);
}