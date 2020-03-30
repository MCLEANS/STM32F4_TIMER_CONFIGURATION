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
custom_libraries::Timer_configuration timer(TIM3);


int  count = 0;

uint16_t auto_reload = 0;
uint16_t prescaler = 0;

extern "C" void TIM3_IRQHandler(void){
	if(TIM3->SR & TIM_SR_UIF){
					TIM3->SR &= ~TIM_SR_UIF;
					count++;
	}

}

int main(void)
{

	sys_clock.initialize();
	timer.set_auto_reload_value(640);
	timer.set_prescaler(65535);
	timer.initialize();






	//Enable TIM5 clock
	//RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;




/*	//SET PRESCALER
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

*/

	//set NVIC priority
	NVIC_SetPriority(TIM3_IRQn,0x03);
		//enable NVIC
	NVIC_EnableIRQ(TIM3_IRQn);









	while(1){

		auto_reload = timer.get_auto_reload_value();
		prescaler = timer.get_prescaler();


	}
}
