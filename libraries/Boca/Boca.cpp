/*
  Boca.h - Librería para el manejo de la boca del robot.
  
  Created  2013 Apr 18
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "Boca.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
Boca::Boca()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param pin: pin donde está ubicado el buzzer.
 */
Boca::Boca(int pin){
	buzzer = pin;
	pinMode(buzzer, OUTPUT);
}

/** MÉTODOS PÚBLICOS **/

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