#include <Servo.h>

#include <Brazo.h>

#include <Boca.h>

#include <FabricaPiezas.h>

#include <Ojo.h>

/****************************************/
/******** EJEMPLO FABRICA PIEZAS ********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Fábrica
FabricaPiezas fabrica;

//Ojo
Ojo ojo;

//Brazo derecho
Brazo brazoDerecho;

//Brazo izquierdo;
Brazo brazoIzquierdo;

//Boca
Boca boca;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  ojo            = fabrica.crearOjo();
  brazoDerecho   = fabrica.crearBrazoDerecho();
  brazoIzquierdo = fabrica.crearBrazoIzquierdo();
  boca           = fabrica.crearBoca();
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  ojo.abrir();
  brazoDerecho.levantar();
  brazoIzquierdo.bajar();
  boca.hablar(600, 800);
  delay(3000);
  ojo.cerrar();
  brazoDerecho.bajar();
  brazoIzquierdo.levantar();
  boca.callar();
  delay(3000);
}
