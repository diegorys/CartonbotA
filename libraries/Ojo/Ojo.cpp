/*
  Ojo.h - Librería para el manejo de un ojo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "Ojo.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
Ojo::Ojo()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param pinLed: pin donde están ubicados los leds.
 * @param pinLDR: pin donde está ubicado el LDR.
 */
Ojo::Ojo(int pinLed, int pinLDR){
	led = pinLed;
	LDR = pinLDR;
	pinMode(led, OUTPUT);
	pinMode(LDR, INPUT);
	estado = LOW;
}

/** MÉTODOS PÚBLICOS **/

/**
 * Abre el ojo.
 */
void Ojo::abrir(){
	digitalWrite(led, HIGH);
	estado = HIGH;
}

/**
 * Cierra el ojo.
 */
void Ojo::cerrar(){
	digitalWrite(led, LOW);
	estado = LOW;
}

/**
 * Comprueba si hay luz.
 * @return: la cantidad de luz que ve.
 */
int Ojo::verLuz(){
	int luz = analogRead(LDR);

	return luz;
}

/**
 * Comprueba si el ojo está abierto.
 * return: HIGH si está abierto, LOW si está cerrado.
 */
int Ojo::estanAbiertos(){
	return estado;
}