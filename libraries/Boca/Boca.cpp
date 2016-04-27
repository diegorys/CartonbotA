/*
  Boca.h - Librer�a para el manejo de la boca del robot.
  
  Created  2013 Apr 18
  Version 0.1
*/

// Incluye el archivo de descripci�n.
#include "Boca.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
Boca::Boca()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param pin: pin donde est� ubicado el buzzer.
 */
Boca::Boca(int pin){
	buzzer = pin;
	pinMode(buzzer, OUTPUT);
}

/** M�TODOS P�BLICOS **/

/**
 * Emite un sonido.
 */
void Boca::hablar(int sonido, int duracion){
	tone(buzzer, sonido, duracion);
	delay(duracion+10);
}

/**
 * Detiene el sonido.
 */
void Boca::callar(){
	noTone(buzzer);
}