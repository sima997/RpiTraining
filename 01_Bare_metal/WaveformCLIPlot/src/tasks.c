#include <stdio.h>
#include "tasks.h"



void task_plot_sine(){
    SineWave *sine = sin_init(10); //Will initialize only once
    static char line[WAVE_RES+1];

    plot_init(line, sizeof(line)/sizeof(line[0]),' ');
    sin_update(sine);
    plot_update_waveform(line, 0,sine->cli_out, '*');
    printf("%s",line);
   


}

void task_plot_triangular() {
    TriangularWave *triag = triangular_init(8);
    static char line [WAVE_RES+1];
    plot_init(line, sizeof(line)/sizeof(line[0]),' ');
    triangular_update(triag);
    plot_update_waveform(line, 1,triag->value,'$');
    printf("%s",line);



}
void task_plot_square() {
    SquareWave *square = square_init(4);
    static char line[WAVE_RES + 1];
    plot_init(line, sizeof(line)/sizeof(line[0]),' ');
    square_update(square);
    plot_update_waveform(line, 1,square->value,'@');
    printf("%s",line);
}