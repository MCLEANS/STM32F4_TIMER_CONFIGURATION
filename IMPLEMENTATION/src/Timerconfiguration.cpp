/*
 * Timerconfiguration.cpp
 *
 *  Created on: Mar 30, 2020
 *      Author: MCLEANS
 */

#include "Timerconfiguration.h"

namespace custom_libraries {

Timer_configuration::Timer_configuration(TIM_TypeDef *TIMER, uint16_t prescaler_value, uint16_t auto_reload_value) : TIMER(TIMER),
																												prescaler_value(prescaler_value),
																												auto_reload_value(auto_reload_value){
		TIMER->PSC = this->prescaler_value;
		TIMER->ARR = this-> auto_reload_value;
}

void Timer_configuration::set_prescaler(uint16_t prescaler_value){
	this->prescaler_value = prescaler_value;

	if(this->prescaler_value != TIMER->PSC) TIMER->PSC = prescaler_value;
}

uint16_t Timer_configuration::get_prescaler(void) const{
	return this->prescaler_value;
}

void Timer_configuration::set_auto_reload_value(uint16_t auto_reload_value){
	this->auto_reload_value = auto_reload_value;

	if(this->auto_reload_value != TIMER->ARR) TIMER->ARR = this->auto_reload_value;
}

uint16_t Timer_configuration::get_auto_reload_value(void) const{
	return this->auto_reload_value;
}

void Timer_configuration::initialize(){
	//Enable Timer RCC
	switch(TIMER){
	case TIM1:
			RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
			break;
	case TIM2:
			RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
			break;
	case TIM3:
			RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
			break;
	case TIM4:
			RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
			break;
	case TIM5:
			RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
			break;
	case TIM6:
			RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
			break;
	case TIM7:
			RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
			break;
	case TIM8:
			RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
			break;
	case TIM9:
			RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
			break;
	case TIM10:
			RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
			break;
	case TIM11:
			RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
			break;
	case TIM12:
			RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
			break;
	case TIM13:
			RCC->APB1ENR |= RCC_APB1ENR_TIM13EN;
			break;
	case TIM14:
			RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
			break;
	}
}

Timer_configuration::~Timer_configuration() {
	// TODO Auto-generated destructor stub
}

} /* namespace custom_libraries */
