#include <Pasivo.h>
#include <Servo.h>
#include <FabricaPiezas.h>
#include <Ojo.h>
#include <Brazo.h>
#include <Boca.h>


/****************************************/
/********** EJEMPLO USO PASIVO **********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

  /** VARIABLES **/

//Habilidad deliberativa de pasivo.
Pasivo pasivo;

//Fábrica de las partes del robot.
FabricaPiezas fabrica;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  Serial.begin(9600);
  
  pasivo = Pasivo(fabrica);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  pasivo.ejecutar();
}
