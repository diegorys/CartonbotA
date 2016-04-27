#include <Servo.h>
#include <Sonido.h>
#include <FabricaPiezas.h>
#include <Ojo.h>
#include <CodificadorMorse.h>
#include <Brazo.h>
#include <Boca.h>
#include <FobiaOscuridad.h>

/****************************************/
/***** EJEMPLO USO FOBIA OSCURIDAD ******/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

  /** VARIABLES **/

//Instinto de fobia a la oscuridad.
FobiaOscuridad fobiaOscuridad;

//Fábrica de las partes del robot.
FabricaPiezas fabrica;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  Serial.begin(9600);
  
  fobiaOscuridad = FobiaOscuridad(fabrica);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
    fobiaOscuridad.ejecutar();
}
