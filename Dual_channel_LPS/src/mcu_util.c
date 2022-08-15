/*
 * mcu_util.c
 *
 * Created: 06.08.2022 14:42:41
 *  Author: shama
 */ 

#include "mcu_util.h"

void voltage_calculation(Channel* channelX)
{
	channelX->voltage_value = ((channelX->voltage_buffer * ADC_VOLTAGE_REFERENCE * VOLTAGE_DIVIDER_RATIO) / 1024) /
								channelX->voltage_counter;
	channelX->voltage_counter = 0;
	channelX->voltage_buffer = 0;
}

void voltage_display(Channel* channelX)
{
	return;
}

void current_calculation(Channel* channelX)
{
	channelX->current_value = ((channelX->current_buffer * ADC_VOLTAGE_REFERENCE) / 1024) /
								channelX->current_counter;
	channelX->current_counter = 0;
	channelX->current_buffer = 0;
}

void current_display(Channel* channelX)
{
	return;
}

void toggle_output_load(void)
{
	return;
}
