#ifndef MOTOR_PWM_H
#define MOTOR_PWM_H

#include "stm32f1xx_hal.h"

void motor_pwm_handle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t duty);
#endif
