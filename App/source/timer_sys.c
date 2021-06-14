/*
 * timer_sys.c
 *
 *  Created on: 13 jun. 2021
 *      Author: joelj
 */

#include <timer_sys.h>
#include <stm32f1xx_hal.h>
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
