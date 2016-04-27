#include <Servo.h>
#include <Brazo.h>

/****************************************/
/*********** EJEMPLO USO BRAZO **********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Brazo
Brazo brazoDerecho;
Brazo brazoIzquierdo;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  brazoDerecho   = Brazo(3);
  brazoIzquierdo = Brazo(5);
  Serial.begin(9600);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  ciclo(brazoDerecho);
  ciclo(brazoIzquierdo);
}

void ciclo(Brazo brazo){
  brazo.levantar();
  delay(3000);
  brazo.bajar();
  delay(3000);
  brazo.colocar(90);
  int posicion = brazo.posicion();
  Serial.println(posicion);
  delay(3000);
}
