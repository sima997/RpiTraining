#include "line_plot.h"
#include <stdio.h>


void plot_init(char *line, size_t len, char no_value_char) {
    for(size_t i = 0; i<len;i++) {
        line[i] = no_value_char;
    }
    line[32] = '\0';
}

void plot_update_waveform(char *line, uint8_t wid,uint8_t wval, char value_char) {
    if (wval > 32) return;
    line[wval] = value_char;
    
}