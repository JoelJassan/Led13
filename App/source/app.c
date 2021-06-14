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
//funciones para corregir el error de tiempo (a estas dos no las entiendo xq no entiendo el delay). Son las funciones que hacen las dos partes de delay
void TimerSys_estableceTiempo(TimerSys *self, uint32_t tiempo_ms);
int TimerSys_tiempocumplido(TimerSys *self);
//otra funcion
void TimerSys_esperaTiempoCumplido(TimerSys *self);
//estas ultimas tres hacen que pueda manejar el tiempo del led independiente de las instrucciones que generen retardo



//--------------TimerSys     -     implementacion (.c)---------------//

void TimerSys_init (TimerSys *self){
	self->cuentaInicial = HAL_GetTick();
	self->retardo = 0;
}

void TimerSys_estableceTiempo(TimerSys *self, uint32_t tiempo_ms){
	self->cuentaInicial = HAL_GetTick();

	if(tiempo_ms > 0 && tiempo_ms < UINT32_MAX) self->retardo = tiempo_ms + 1;
	else self->retardo = tiempo_ms;
}

int TimerSys_tiempocumplido(TimerSys *self){
	return (HAL_GetTick() - self->cuentaInicial) >= self->retardo; //?????????
}

void TimerSys_esperaTiempoCumplido(TimerSys *self){
	while(!TimerSys_tiempocumplido(self));
}

void TimerSys_delay(TimerSys *self, uint32_t tiempo_ms){
	TimerSys_estableceTiempo(self, tiempo_ms);				//pone el tiempo que hay q esperar
	TimerSys_esperaTiempoCumplido(self);					//hace un lazo infinito hasta que pasa el tiempo
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


	TimerSys_estableceTiempo(&timer, tiempo_ms);	//inicializo el timer para que empiece a hacer la cuenta
	Pin_escribir(&led, !Pin_leer(&led));	//escribir en "led" lo opuesto que está en "led"
	HAL_Delay(450);
	//TimerSys_delay(&timer,tiempo_ms);		borro el delay
	TimerSys_esperaTiempoCumplido(&timer);
}
