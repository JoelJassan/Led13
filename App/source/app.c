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

//	CONSTRUIR UN OBJETO IMPLICA RESERVAR MEMORIA PARA EL OBJETO Y DARLE UN VALOR INICIAL...


static Pin led;	//variable que solo se ve en app.c - creo un objeto que se llama "led"; reservo su espacio de memoria


void setup(void){
	Pin_init(&led, Led_GPIO_Port, Led_Pin);		//inicializo el objeto "led", y se asocia el puerto y pin de Led (corresponde al PC13)
												//" &led " toma la direccion de la variable "led"
}
void loop(void){
	Pin_escribir(&led, !Pin_leer(&led));	//escribir en "led" lo opuesto que está en "led"
	HAL_Delay(500);
}
