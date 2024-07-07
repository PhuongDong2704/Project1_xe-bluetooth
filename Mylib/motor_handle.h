#ifndef MOTOR_HANDLE_H
#define MOTOR_HANDLE_H

#include "stm32f1xx_hal.h"

typedef enum
{
	MOTOR_CR, //Cung chieu kim dong ho
	MOTOR_CCR, //Nguoc chieu kim dong ho
	MOTOR_STOP,
}MOTOR_STATE;

typedef struct
{
	MOTOR_STATE motor_state;
	GPIO_TypeDef *MOTOR_GPIOx;
	uint16_t MOTOR_Pin;
	TIM_HandleTypeDef *htim;
	uint32_t channel;
	uint8_t speed;
}MotorTypeDef;

void motor_handle(MotorTypeDef *Motorx, MOTOR_STATE motor_state, uint8_t speed);
void motor_init(MotorTypeDef *Motorx,TIM_HandleTypeDef *htim, uint32_t channel, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
#endif
