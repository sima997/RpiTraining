#pragma once

#include <stdint.h>
#include <stdio.h>

#define WAVE_RES        32 //Wave resolution 
#define WAVE_COUNT      3   //Number of waves to plot


//char line[WAVE_RES*WAVE_COUNT + 1];


void plot_init(char *line, size_t len, char no_value_char);

void plot_update_waveform(char *line, uint8_t wid,uint8_t wval, char value_char);