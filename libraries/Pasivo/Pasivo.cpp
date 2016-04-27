/*
  Pasivo.h - Librería que representa la habilidad que realiza
  cuando no tiene nada que hacer.
  
  Created  2013 Apr 23
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "Pasivo.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío.
 */
Pasivo::Pasivo()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param fabrica:	   Fábrica de piezas.
 */
Pasivo::Pasivo(FabricaPiezas fabrica){
	//Piezas
	ojos           = fabrica.crearOjo();
	boca           = fabrica.crearBoca();
	brazoDerecho   = fabrica.crearBrazoDerecho();
	brazoIzquierdo = fabrica.crearBrazoIzquierdo();
}

/** MÉTODOS PÚBLICOS **/

/**
 * Asigna las piezas a la habilidad.
 * @param pOjos: ojos.
 * @param pBoca: boca.
 * @param pBrazoDcho: brazo derecho.
 * @param pBrazoIzdo: brazo izquierdo.
 */
void Pasivo::asignarPiezas(Ojo pOjos, Boca pBoca, Brazo pBrazoDcho, Brazo pBrazoIzdo){
	//Piezas
	ojos = pOjos;
	boca = pBoca;
	brazoDerecho = pBrazoDcho;
	brazoIzquierdo = pBrazoIzdo;
}

/**
 * Ejecuta un ciclo de la habilidad.
 * @return: true si no ha acabado la ejecución. False en caso contrario.
 */
bool Pasivo::ejecutar(){
	if(ojos.estanAbiertos()){
		brazoDerecho.bajar();
		brazoIzquierdo.bajar();
		ojos.cerrar();
		boca.hablar(300, 600);
	}else{
		brazoDerecho.colocar(135);
		brazoIzquierdo.colocar(45);
		ojos.abrir();
		boca.hablar(600, 600);
	}

	return true;
}