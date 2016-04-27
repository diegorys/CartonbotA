#include <Boca.h>
#include <Sonido.h>

/****************************************/
/*********** EJEMPLO USO SONIDO **********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Sonido
Sonido sonido;

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
  
  /** MELODÍA VICTORIA FINAL FANTASY **/
  //re' re' re' re' si# do' re' do' re'
  int melodia[] = {RE_5,    RE_5,    RE_5,    RE_5,  LA_SI_4, DO_5,  RE_5,    SILENCIO,    DO_5,    RE_5};
  int figuras[] = {CORCHEA, CORCHEA, CORCHEA, NEGRA, NEGRA,   NEGRA, CORCHEA, SEMICORCHEA, CORCHEA, BLANCA};
  Boca boca = Boca(15);
  sonido = Sonido(boca);
  sonido.asignar(melodia, figuras, numnotas);
  posicion = 0;
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
    posicion = sonido.sonar(posicion);
}
