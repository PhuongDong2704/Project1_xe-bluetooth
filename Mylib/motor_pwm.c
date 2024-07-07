#include "motor_pwm.h" 

void motor_pwm_handle(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t duty)
{
	//duty 0->100
	uint16_t ccr = duty*(htim->Instance->ARR)/100;//Chuyen tu phan tram sang so nguyen cho ccr
	//Kiem tra channel de gan ccr tuong ung voi channel do
	switch (channel)
	{
		case TIM_CHANNEL_1:
			htim->Instance->CCR1  = ccr;
			break;
		case TIM_CHANNEL_2:
			htim->Instance->CCR2  = ccr;
			break;
		case TIM_CHANNEL_3:
			htim->Instance->CCR3  = ccr;
			break;
		case TIM_CHANNEL_4:
			htim->Instance->CCR4  = ccr;
			break;
	}
}