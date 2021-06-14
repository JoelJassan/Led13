/*
 * timer_sys.h
 *
 *  Created on: 13 jun. 2021
 *      Author: joelj
 */

#ifndef INCLUDE_TIMER_SYS_H_
#define INCLUDE_TIMER_SYS_H_


#include <stdint.h> /*uint32_t*/
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




#endif /* INCLUDE_TIMER_SYS_H_ */
