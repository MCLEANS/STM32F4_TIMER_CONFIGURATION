/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "clockconfig.h"
#include "Timerconfiguration.h"

int count = 0;

custom_libraries::clock_config sys_clock;
custom_libraries::Timer_configuration timer(TIM5,65535,640);

extern "C" void TIM5_IRQHandler(void){
	if(TIM5->SR & TIM_SR_UIF){
					TIM5->SR &= ~TIM_SR_UIF;
					count++;
	}

}

int main(void)
{

	sys_clock.initialize();
	timer.initialize();

	//set NVIC priority
	NVIC_SetPriority(TIM5_IRQn,0x03);
	//enable NVIC
	NVIC_EnableIRQ(TIM5_IRQn);



	while(1){

	}
}
