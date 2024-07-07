#ifndef CAR_CONTROL_H
#define CAR_CONTROL_H

#include "stm32f1xx_hal.h"

typedef enum
{
	CAR_FORWARD,
	CAR_FORWARD_LEFT,
	CAR_FORWARD_RIGHT,
	CAR_BACKWARD,
	CAR_BACKWARD_LEFT,
	CAR_BACKWARD_RIGHT,
	CAR_LEFT,
	CAR_RIGHT,
	CAR_STOP
}CAR_STATE;

void car_handle(CAR_STATE car_state,uint8_t speed);
void car_init(TIM_HandleTypeDef *htim);
#endif
