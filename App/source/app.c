/*
 * app.c
 *
 *  Created on: Jun 13, 2021
 *      Author: joelj
 */


#include <app.h>
#include <main.h>

#include <pin.h> 	//incluyo el que saqué antes


//-----------acá estaría todo lo que puse en pin.c y pin.h-----------//

//	CONSTRUIR UN OBJETO IMPLICA RESERVAR MEMORIA PARA EL OBJETO Y DARLE UN VALOR INICIAL...



//----------------TimerSys     -     encabezado (.h)-----------------//
typedef struct TimerSys{
	uint32_t cuentaInicial;
	uint32_t retardo;
}TimerSys;

void TimerSys_init (TimerSys *self);
void TimerSys_delay(TimerSys *self, uint32_t tiempo_ms);

//--------------TimerSys     -     implementacion (.c)---------------//

void TimerSys_init (TimerSys *self){
	self->cuentaInicial = HAL_GetTick();
	self->retardo = 0;
}
void TimerSys_delay(TimerSys *self, uint32_t tiempo_ms){
	self->cuentaInicial = HAL_GetTick();

	if(tiempo_ms > 0 && tiempo_ms < UINT32_MAX) self->retardo = tiempo_ms + 1;
	else self->retardo = tiempo_ms;


	while( (HAL_GetTick() - self->cuentaInicial) < self->retardo);
}



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

	Pin_escribir(&led, !Pin_leer(&led));	//escribir en "led" lo opuesto que está en "led"
	TimerSys_delay(&timer,tiempo_ms);
}
