/*
 * app.c
 *
 *  Created on: Jun 13, 2021
 *      Author: joelj
 */


#include <app.h>
#include <main.h>

void setup(void){

}
void loop(void){
	HAL_GPIO_TogglePin(Led_GPIO_Port, Led_Pin);
	HAL_Delay(500);
}
