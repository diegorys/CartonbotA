/*
  Ojo.h - Librer�a para el manejo de un ojo del robot.
  
  Created  2013 Apr 20
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "Ojo.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
Ojo::Ojo()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param pinLed: pin donde est�n ubicados los leds.
 * @param pinLDR: pin donde est� ubicado el LDR.
 */
Ojo::Ojo(int pinLed, int pinLDR){
	led = pinLed;
	LDR = pinLDR;
	pinMode(led, OUTPUT);
	pinMode(LDR, INPUT);
	estado = LOW;
}

/** M�TODOS P�BLICOS **/

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
 * Comprueba si el ojo est� abierto.
 * return: HIGH si est� abierto, LOW si est� cerrado.
 */
int Ojo::estanAbiertos(){
	return estado;
}