/*
 * pin.c
 *
 *  Created on: 13 jun. 2021
 *      Author: joelj
 */


//------------------  Pin     -     implementacion (.c) -------------//

#include <pin.h>

void Pin_init(Pin *self, GPIO_TypeDef *puerto, uint16_t pin){
	self->puerto=puerto;
	self->pin=pin;
}	//asigno los valores de la clase a los parametros de la funcion

int Pin_leer(Pin *self){
	return !!(self->puerto->IDR & self->pin);	//&:AND bit a bit ----> de todo el registro IDR selecciona los que esten en 1. La doble negacion solo es para tomar el valor lógico del pin 13
}

void Pin_escribir(Pin *self, int estado){
	if (estado != 0) self->puerto->BSRR = self->pin;	//si estado=1 asigno la mascara al Bit Set-Reset
														//El BSRR es un registro de 32 bits, donde los 16LSB corresponden a la parte SET. Al pin que yo escriba con 1, se pone en 1 (en este caso, el pin 13)
	else self->puerto->BRR = self->pin;					//EL BRR pone en cero
}
