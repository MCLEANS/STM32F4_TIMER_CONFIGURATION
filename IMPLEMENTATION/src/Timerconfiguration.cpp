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

Timer_configuration::~Timer_configuration() {
	// TODO Auto-generated destructor stub
}

} /* namespace custom_libraries */
