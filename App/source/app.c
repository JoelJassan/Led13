/*
 * app.c
 *
 *  Created on: Jun 13, 2021
 *      Author: joelj
 */


#include <app.h>
#include <main.h>

//--------	Pin     -     encabezado -----//
#include <stdint.h>	//para la definicion de uint16_t

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


//--------  Pin     -     implementacion -//

//ejecucion de acciones
void Pin_init(Pin *self, GPIO_TypeDef *puerto, uint16_t pin){
	self->puerto=puerto;
	self->pin=pin;
}	//asigno los valores de la clase a los parametros de la funcion

int Pin_leer(Pin *self){
	return HAL_GPIO_ReadPin(self->puerto,self->pin);
}	//lectura del valor actual

void Pin_escribir(Pin *self, int estado){
	HAL_GPIO_WritePin(self->puerto, self->pin, estado);
}	//escritura


//----------------------------------------//
void setup(void){

}
void loop(void){
	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
	HAL_Delay(500);
}
