
#include"adc.h"
#include"lcd.h"
#include"lm35_sensor.h"
#include "dc_motor.h"

int main(void) {

	uint8 temp = 0; //variable to store the temperature from the sensor
	ADC_ConfigType adc_config = { INTERNAL, EIGHT }; //configuration structure

	ADC_init(&adc_config); //adc initialization
	DcMotor_Init(); //DC Motor initialization
	LCD_init(); //LCD initialization
	Timer0_PWM_Init(0); //PWM initialization
	LCD_displayString("Fan is");
	LCD_moveCursor(1, 0);
	LCD_displayString("Temp =");

	while (1) {
		temp = LM35_getTemperature(); //get temperature from sensor

		LCD_moveCursor(1, 6);
		if (temp > 100)
			LCD_intgerToString(temp);
		else {
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}

		if (temp < 30) {
			LCD_moveCursor(0, 8);
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP, 0);
		} else if ((temp >= 30) & (temp < 60)) {
			LCD_moveCursor(0, 8);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 25);

		} else if ((temp >= 60) & (temp < 90)) {
			LCD_moveCursor(0, 8);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 50);

		} else if ((temp >= 90) & (temp < 120)) {
			LCD_moveCursor(0, 8);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 75);

		} else if ((temp >= 120)) {
			LCD_moveCursor(0, 8);
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW, 100);

		}

	}

}
