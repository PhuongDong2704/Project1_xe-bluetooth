#include "car_control.h" 
#include "motor_handle.h" 

//Khoi tao dong co trai va phai
MotorTypeDef motor_right;
MotorTypeDef motor_left;

void car_handle(CAR_STATE car_state,uint8_t speed)
{
	switch(car_state)//Thay doi trang thai xe
	{
		case CAR_STOP:
			motor_handle(&motor_right, MOTOR_STOP, 0);
			motor_handle(&motor_left, MOTOR_STOP, 0);
			break;
		case CAR_FORWARD:
			motor_handle(&motor_right, MOTOR_CR, speed);
			motor_handle(&motor_left, MOTOR_CR, speed);
			break;
		case CAR_BACKWARD:
			motor_handle(&motor_right, MOTOR_CCR, speed);
			motor_handle(&motor_left, MOTOR_CCR, speed);
			break;
		case CAR_RIGHT:
			motor_handle(&motor_right, MOTOR_CCR, speed);
			motor_handle(&motor_left, MOTOR_CR, speed);
			break;
		case CAR_LEFT:
			motor_handle(&motor_right, MOTOR_CR, speed);
			motor_handle(&motor_left, MOTOR_CCR, speed);
			break;
		case CAR_FORWARD_LEFT:
			motor_handle(&motor_right, MOTOR_CR, speed);
			motor_handle(&motor_left, MOTOR_CCR, speed/2);
			break;
		case CAR_FORWARD_RIGHT:
			motor_handle(&motor_right, MOTOR_CR, speed/2);
			motor_handle(&motor_left, MOTOR_CCR, speed);
			break;
		case CAR_BACKWARD_LEFT:
			motor_handle(&motor_right, MOTOR_CR, speed);
			motor_handle(&motor_left, MOTOR_CCR, speed/2);
			break;
		case CAR_BACKWARD_RIGHT:
			motor_handle(&motor_right, MOTOR_CR, speed/2);
			motor_handle(&motor_left, MOTOR_CCR, speed);
			break;
		default:
			break;
	}
}
void car_init(TIM_HandleTypeDef *htim)
{
	motor_init(&motor_right,htim,TIM_CHANNEL_2,GPIOB, GPIO_PIN_15);
	motor_init(&motor_left,htim,TIM_CHANNEL_1,GPIOB, GPIO_PIN_14);
	car_handle(CAR_STOP,0);
}