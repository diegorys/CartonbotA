#include <Ojo.h>

#include <Brazo.h>

#include <FabricaPiezas.h>

#include <Boca.h>
#include <Sonido.h>
#include <CodificadorMorse.h>

/****************************************/
/*********** EJEMPLO USO SONIDO **********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Sonido
Sonido sonido;

//Codificador morse
CodificadorMorse codificador;

//Posición de reprocucción.
int posicion;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  int numnotas = 10;
  Serial.begin(9600);
  Serial.flush();
  FabricaPiezas f = FabricaPiezas();
  
  Boca boca   = f.crearBoca();
  codificador = CodificadorMorse(boca);
  sonido      = codificador.codificarSOS();
  posicion    = 0;
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
    posicion = sonido.sonar(posicion);
    //if(posicion < 0) posicion = 0;
}
