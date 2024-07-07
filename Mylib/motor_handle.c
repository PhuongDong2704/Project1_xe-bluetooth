#include "motor_handle.h" 
#include "motor_pwm.h" 

void motor_handle(MotorTypeDef *Motorx, MOTOR_STATE motor_state, uint8_t speed)
{
	//speed 0%->100%
	switch(motor_state)
	{
		case MOTOR_STOP:
			HAL_GPIO_WritePin (Motorx->MOTOR_GPIOx, Motorx->MOTOR_Pin, 0);
			motor_pwm_handle (Motorx->htim, Motorx->channel , 0);
			break;
		case MOTOR_CR://Quay cung chieu kim dong ho
			HAL_GPIO_WritePin (Motorx->MOTOR_GPIOx, Motorx->MOTOR_Pin, 0);
			motor_pwm_handle (Motorx->htim, Motorx->channel , speed);
			break;
		case MOTOR_CCR://Quay nguoc chieu kim dong ho
			HAL_GPIO_WritePin (Motorx->MOTOR_GPIOx, Motorx->MOTOR_Pin, 1);
			motor_pwm_handle (Motorx->htim, Motorx->channel , 100 - speed);
			break;
	}
}
void motor_init(MotorTypeDef *Motorx,TIM_HandleTypeDef *htim, uint32_t channel, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	Motorx->MOTOR_GPIOx = GPIOx;
	Motorx->MOTOR_Pin = GPIO_Pin;
	Motorx->htim = htim;
	Motorx->channel = channel;
	HAL_TIM_PWM_Start (Motorx->htim, Motorx->channel);
}