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
#include <stdlib.h>


#define ARR_VALUE 640
#define PSC_VALUE 65535


int  count = 0;

extern "C" void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_UIF){
					TIM3->SR &= ~TIM_SR_UIF;
					count++;
	}

}

int main(void)
{

	custom_libraries::clock_config sys_clock;
	sys_clock.initialize();



	for(int  i = 0; i<10000;i++);

	//Enable TIM5 clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;




	//SET PRESCALER
	TIM3->PSC = PSC_VALUE;
	//set ARR VALUE
	TIM3->ARR = ARR_VALUE;
	//Initiate update event
	TIM3->EGR |= TIM_EGR_UG;
	//Enable update interrupt
	TIM3->DIER |= TIM_DIER_UIE;
	//only timer overflow generates update event
	TIM3->CR1 |= TIM_CR1_URS;
	//Enable counter
	TIM3->CR1 |= TIM_CR1_CEN;

	//set NVIC priority
	NVIC_SetPriority(TIM3_IRQn,0x03);
		//enable NVIC
	NVIC_EnableIRQ(TIM3_IRQn);









	while(1){




	}
}
