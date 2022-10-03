


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

void Timer0_PWM_Init(unsigned char set_duty_cycle);


#define DC_PORT               PORTB_ID
#define DC_PIN_ENABLE         PIN3_ID
#define DC_IN1                PIN0_ID
#define DC_IN2                PIN1_ID



typedef enum{
	STOP, CW,ACW
}DcMotor_State;


/*    FUNCTION PROTOTYPES  */
void DcMotor_Init(void);

void DcMotor_Rotate(DcMotor_State state,uint8 speed);




#endif /* DC_MOTOR_H_ */
