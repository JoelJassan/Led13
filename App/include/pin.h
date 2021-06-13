/*
 * pin.h
 *
 *  Created on: 13 jun. 2021
 *      Author: joelj
 */

#ifndef INCLUDE_PIN_H_
#define INCLUDE_PIN_H_


//------------------	Pin     -     encabezado (.h) ---------------//

#include <stdint.h>			//para la definicion de uint16_t
#include <stm32f1xx.h>		//incluye todo los drivers de ST, por este include es que queda definido GPIO_TypeDef.
							//Se agrega esta acá y no antes xq habria que referenciar al main. SI REFERENCIARA AL MAIN, NO PODRIA USARLO EN CUALQUIER CODIGO


typedef struct Pin{
	GPIO_TypeDef *puerto;
	uint16_t pin;
}Pin;	//estructura "Pin(primero)" de tipo "Pin(segundo)"


void Pin_init(Pin *self, GPIO_TypeDef *puerto, uint16_t pin);	//Pin_init puede modificar el contenido de la variable
																//asigna espacio de memoria para la variable-estructura Pin
																//" *self " indica que se establece un puntero a la direccion donde está la clase (la clase se llama a si misma)
																//se asigna el tipo de variable a traves del puntero " *puerto ". Asigno un puntero a una estructura GPIO_TypeDef (tocar con el mouse para ver mas)
																//uint16_t indica la posicion del pin
int Pin_leer(Pin *self);	//puede leer el contenido de la variable
void Pin_escribir(Pin *self, int estado);

#endif /* INCLUDE_PIN_H_ */


