/*
 * mcu_util.h
 *
 * Created: 06.08.2022 14:42:58
 *  Author: shama
 */ 


#ifndef MCU_UTIL_H_
#define MCU_UTIL_H_

#include <avr/io.h>

#include "channel_struct.h"

extern struct Channel;

void voltage_calculation(Channel* channelX);
void voltage_display(Channel* channelX);
void current_calculation(Channel* channelX);
void current_display(Channel* channelX);
void toggle_output_load(void);

#endif /* MCU_UTIL_H_ */