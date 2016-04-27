#include <Servo.h>
#include <Sonido.h>
#include <FabricaPiezas.h>
#include <Ojo.h>
#include <CodificadorMorse.h>
#include <Brazo.h>
#include <Boca.h>
#include <Baile.h>

/****************************************/
/********** EJEMPLO USO BAILE ***********/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

  /** VARIABLES **/

//Habilidad deliberativa de baile.
Baile baile;

//Fábrica de las partes del robot.
FabricaPiezas fabrica;

//Tiempo desde la última ejecución.
unsigned long tiempo = 0;

//Tiempo que esperamos de inactividad.
int tiempoInactividad = 10000;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  Serial.begin(9600);
  
  /** MELODÍA VICTORIA FINAL FANTASY **/
  //re' re' re' re' si# do' re' do' re'
  int melodia[] = {RE_5,    RE_5,    RE_5,    RE_5,  LA_SI_4, DO_5,  RE_5,    SILENCIO,    DO_5,    RE_5};
  int figuras[] = {CORCHEA, CORCHEA, CORCHEA, NEGRA, NEGRA,   NEGRA, CORCHEA, SEMICORCHEA, CORCHEA, BLANCA};
  int numnotas = 10;
  
  baile = Baile(fabrica);
  
  baile.asignar(melodia, figuras, numnotas);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
    if(baile.ejecutar()){
      tiempo = millis();
    }else if(millis() > tiempo + tiempoInactividad){
      baile.rebobinar();
    }
}
