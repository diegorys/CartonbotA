#include <Boca.h>

/****************************************/
/*********** EJEMPLO USO BOCA ***********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Boca
Boca boca;

//Frecuencia
int frecuencia;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  boca       = Boca(15);
  frecuencia = 100;
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  boca.hablar(frecuencia, 100);
  if(frecuencia < 2000)
  frecuencia += 100;
  boca.callar();
  delay(100);
}
