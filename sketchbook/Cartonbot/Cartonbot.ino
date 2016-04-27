#include <EEPROM.h>

#include <Servo.h>
#include <Sonido.h>
#include <FabricaPiezas.h>
#include <Ojo.h>
#include <CodificadorMorse.h>
#include <Brazo.h>
#include <Boca.h>
#include <FobiaOscuridad.h>
#include <Pasivo.h>
#include <Baile.h>

/****************************************/
/*************** CARTONBOT **************/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

/** VARIABLES **/

//Fábrica de las partes del robot.
FabricaPiezas fabrica;

//Habilidad de baile
Baile baile;

//Habilidad pasiva
Pasivo pasivo;

//Instinto de fobia a la oscuridad.
FobiaOscuridad fobiaOscuridad;

//Orden recibida por el puerto serial.
int orden = 0;

//Indica si el robot está bailando.
bool bailando = false;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  Serial.begin(9600);
  
  //Inicializamos todos los parámetros.
  fabrica = FabricaPiezas();
  
    //re' re' re' re' si# do' re' do' re'
  int melodia[] = {RE_5,    RE_5,    RE_5,    RE_5,  LA_SI_4, DO_5,  RE_5,    SILENCIO,    DO_5,    RE_5};
  int figuras[] = {CORCHEA, CORCHEA, CORCHEA, NEGRA, NEGRA,   NEGRA, CORCHEA, SEMICORCHEA, CORCHEA, BLANCA};
  int numnotas = 10;
  
  Ojo ojo = fabrica.crearOjo();
  Boca boca = fabrica.crearBoca();
  Brazo brazoDcho = fabrica.crearBrazoDerecho();
  Brazo brazoIzdo = fabrica.crearBrazoIzquierdo();
  
  baile.asignarPiezas(ojo, boca, brazoDcho, brazoIzdo);
  fobiaOscuridad.asignarPiezas(ojo, boca, brazoDcho, brazoIzdo);
  pasivo.asignarPiezas(ojo, boca, brazoDcho, brazoIzdo);
  
  baile.asignar(melodia, figuras, numnotas);
  
  //Menú
  Serial.println("1. Bailar");
  Serial.println("2. Borrar memoria");
  Serial.println("3. Ver estado");
  Serial.println("Seleccionar: ");
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
  //Si hay miedo, no hacemos nada más, ignoramos todo.
  if(!fobiaOscuridad.ejecutar()){
    obtenerOrden();
    ejecutarOrden();
    comprobarBaile();
  }
}

/**
 * Recibe la orden del serial.
 */
void obtenerOrden(){   
  //Recibimos la orden.
  if (Serial.available() > 0) {
    orden = Serial.parseInt();
  }else{
    orden = 0;
  }
}

/**
 * Ejecuta la orden recibida.
 */
void ejecutarOrden(){
    //Ejecutamos la orden.
    switch(orden){
      case 0:
        //No se ha recibido nada.
        break;
      case 1:
        Serial.println("Bailando");
        bailando = true;
        break;
      case 2:
        //Si recibimos un 2, borramos la memoria.
        fobiaOscuridad.eliminarMemoria();
        Serial.println("No me acuerdo de nada...");
        break;
      case 3:
        Serial.print("Fobia a la oscuridad: ");
        Serial.print(fobiaOscuridad.getMiedo());
        Serial.println("%");
        break;
      default:
        //Se ejecuta cuando se recibe una orden desconocida.
          pasivo.ejecutar();
          Serial.println("No te entiendo...");
     }
}

/**
 * Comprueba si se está ejecutando el baile.
 */
void comprobarBaile(){       
   //Si la orden era baile, bailamos.
   if(bailando){
    if(baile.ejecutar()){
      bailando = true;
    }else{
      baile.rebobinar();
      bailando = false;
    }
  }
}
