

#include "dc_motor.h"
#include "gpio.h"
#include <avr/io.h>



/*         FUNCTIONS DEFINITIONS           */

void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT); //configure PB0 as Output
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT); //configure PB1 as Output

	PORTB= (PORTB&0xFC) | (STOP);

}


void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	PORTB= (PORTB&0xFC) | (state);
	uint8 duty_cycle=0;
	duty_cycle= (uint32)(speed * 255)/100;

     Timer0_PWM_Init(duty_cycle);
}
