#include <Ojo.h>

/****************************************/
/*********** EJEMPLO USO OJO **********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Ojo
Ojo ojo;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  ojo = Ojo(11, A5);
  Serial.begin(9600);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  ojo.abrir();
  delay(300);
  ojo.cerrar();
  if(ojo.estanAbiertos()){
    Serial.println("Abiertos");
  }else{
    Serial.println("Cerrados");
  }
  delay(300);
  int luz = ojo.verLuz();
  Serial.print("Luz: ");
  Serial.println(luz);
  ojo.abrir();
  if(ojo.estanAbiertos()){
    Serial.println("Abiertos");
  }else{
    Serial.println("Cerrados");
  }
}
