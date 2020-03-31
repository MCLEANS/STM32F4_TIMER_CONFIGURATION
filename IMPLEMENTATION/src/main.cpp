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

#define ARR_VALUE 640
#define PSC_VALUE 65535

custom_libraries::clock_config sys_clock;
custom_libraries::Timer_configuration timer(TIM3,65535,640);


uint32_t  count = 0;


extern "C" void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_UIF){
					TIM3->SR &= ~TIM_SR_UIF;
					count++;
	}

}

int main(void)
{

	sys_clock.initialize();
	timer.initialize();


	//set NVIC priority
	NVIC_SetPriority(TIM3_IRQn,0x03);
		//enable NVIC
	NVIC_EnableIRQ(TIM3_IRQn);



	while(1){




	}
}
