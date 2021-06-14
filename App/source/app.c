/*
 * app.c
 *
 *  Created on: Jun 13, 2021
 *      Author: joelj
 */


#include <app.h>
#include <main.h>

#include <pin.h> 	//incluyo el que saqué antes
#include <timer_sys.h>

//-----------acá estaría todo lo que puse en pin.c y pin.h-----------//

//	CONSTRUIR UN OBJETO IMPLICA RESERVAR MEMORIA PARA EL OBJETO Y DARLE UN VALOR INICIAL...


//-----------acá estaría todo lo que puse en timer_sys.c y timer_sys.h-----------//







//-------------------funcionamiento del programa---------------------//

static Pin led;	//variable que solo se ve en app.c - creo un objeto que se llama "led"; reservo su espacio de memoria
static TimerSys timer;

void setup(void){
	Pin_init(&led, Led_GPIO_Port, Led_Pin);		//inicializo el objeto "led", y se asocia el puerto y pin de Led (corresponde al PC13)
												//" &led " toma la direccion de la variable "led"
	TimerSys_init(&timer);	//inicializo el timer
}
void loop(void){
	const uint32_t tiempo_ms = 500;


	//TimerSys_estableceTiempo(&timer, tiempo_ms);	//inicializo el timer para que empiece a hacer la cuenta

	//Establezco un estilo de MEF
	if (TimerSys_tiempocumplido(&timer)){
		TimerSys_estableceTiempo(&timer, tiempo_ms);
		Pin_escribir(&led, !Pin_leer(&led));	//escribir en "led" lo opuesto que está en "led"
	}
	HAL_Delay(10); //cambio el tiempo para analizar el funcionamiento (mirar comentario de abajo)

	/*
	- tiempo cumplido? si --> entra, establece el tiempo y conmuta
	- hace la rutina de 10ms
	- tiempo cumplido? NO --> sigue
	- hace la rutina de 10ms
	- vuelve al loop (se repite la pregunta)

	Esto permite que el if nunca clave el lazo
	*/



	//TimerSys_delay(&timer,tiempo_ms);			borro el delay
	//TimerSys_esperaTiempoCumplido(&timer);	elimino esta para que no se clave, y evitar perder el tiempo en esta rutina. Se agrega el "if". NO USO ESTA EN NINGUN LADO
}
