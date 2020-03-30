/*
 * Timerconfiguration.h
 *
 *  Created on: Mar 30, 2020
 *      Author: MCLEANS
 */

#ifndef TIMERCONFIGURATION_H_
#define TIMERCONFIGURATION_H_

#include "stm32f4xx.h"

namespace custom_libraries {

class Timer_configuration {

private:
	uint16_t auto_reload_value;
	uint16_t prescaler_value;
private:

public:

public:
	Timer_configuration();
	~Timer_configuration();
	void set_prescaler(uint16_t prescaler_value);
	uint16_t get_prescaler(void);
	void set_auto_reload_value(uint16_t auto_reload_value);
	uint16_t get_auto_reload_value(void);
};

} /* namespace custom_libraries */

#endif /* TIMERCONFIGURATION_H_ */
