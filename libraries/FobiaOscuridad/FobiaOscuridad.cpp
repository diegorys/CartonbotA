/*
  FobiaOscuridad.h - Librería que representa la escotofobia.
  
  Created  2013 Apr 21
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "FobiaOscuridad.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío.
 */
FobiaOscuridad::FobiaOscuridad()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param fabrica: Fábrica de piezas.
 */
FobiaOscuridad::FobiaOscuridad(FabricaPiezas fabrica){
	//Piezas
	ojos           = fabrica.crearOjo();
	boca           = fabrica.crearBoca();
	brazoDerecho   = fabrica.crearBrazoDerecho();
	brazoIzquierdo = fabrica.crearBrazoIzquierdo();

	iniciarParametros();
}

/** MÉTODOS PÚBLICOS **/

/**
 * Asigna las piezas a la habilidad.
 * @param pOjos: ojos.
 * @param pBoca: boca.
 * @param pBrazoDcho: brazo derecho.
 * @param pBrazoIzdo: brazo izquierdo.
 */
void FobiaOscuridad::asignarPiezas(Ojo pOjos, Boca pBoca, Brazo pBrazoDcho, Brazo pBrazoIzdo){
	//Piezas
	ojos = pOjos;
	boca = pBoca;
	brazoDerecho = pBrazoDcho;
	brazoIzquierdo = pBrazoIzdo;

	iniciarParametros();
}

/**
 * Ejecuta un ciclo de la habilidad.
 * @return: true si no ha acabado la ejecución. False en caso contrario.
 */
bool FobiaOscuridad::ejecutar(){
	int luz = ojos.verLuz();

	//Si estamos en alerta continuamos emitiendo la señal de socorro..
	if(alerta){
		//Comprobamos si salimos de la alarma.
		if(luz >= 25){
			//Salimos del estado de alerta y volvemos
			//a la posición tranquila.
			posicion = 0;
			boca.callar();
			ojos.cerrar();
			brazoDerecho.bajar();
			brazoIzquierdo.bajar();
			alerta = false;
			//Esto permite ir acostumbrándonos a la luz, hasta un máximo.
			if(tiempoReaccion < 20000){
				tiempoReaccion = tiempoReaccion * 1.5;
				miedo = map(tiempoReaccion, 500, 28832, 0, 100);	//Porcentaje de miedo.
				EEPROM.write(0, miedo);				//Lo almacenamos.
				delay(300);
			}
		}else{
			posicion = sonido.sonar(posicion);
			//Emitimos el mensaje una y otra vez hasta que acabe la alerta.
			if(posicion >= 18) posicion = 0;
		}
	}

	//Comprobamos si estamos en alerta, tras un tiempo de reacción.
	if(millis() > tiempoEspera + tiempoReaccion){
		tiempoEspera = millis();
		if(luz < 25){
			//Si no hay luz, alerta.
			if(!alerta){
				//Comprobamos si es la primera alerta
				//para poner la posición.
				alerta = true;
				ojos.abrir();
				brazoDerecho.levantar();
				brazoIzquierdo.levantar();
				if(miedo < 5){
					Serial.println("¡Tengo mucho miedo!");
				}else if(miedo < 10){
					Serial.println("¡Tengo miedo!");
				}else if(miedo < 15){
					Serial.println("Estoy un poco asustado");
				}else if(miedo < 20){
					Serial.println("No hay luz");
				}else{
					//Ya no se acordaba de lo que era la oscuridad y vuelve a aumentar el miedo.
					Serial.println("¿Qué ha pasado?");
					eliminarMemoria();
				}
			}
		}
	}

	return alerta;
}


/**
 * Obtiene el porcentaje de miedo.
 */
int FobiaOscuridad::getMiedo(){
	return 100-miedo;
}

/**
 * Elimina la memoria.
 */
void FobiaOscuridad::eliminarMemoria(){
	EEPROM.write(0, 0);
	delay(300);
	miedo = 0;
	tiempoReaccion = 500;
}

/**
 * Ejecuta un ciclo de la habilidad.
 * @return: true si no ha acabado la ejecución. False en caso contrario.
 */
void FobiaOscuridad::iniciarParametros(){
	miedo = EEPROM.read(0);	//Lo leemos.
	delay(300);
	//Parámetros
	alerta			 = false;
	posicion		 = 0;
	tiempoReaccion   = map(miedo, 0, 100, 500, 28832);
	tiempoEspera	 = 0;

	//La señal de socorro será S.O.S. en código Morse.
	CodificadorMorse morse = CodificadorMorse(boca);
	sonido				   = morse.codificarSOS();
}