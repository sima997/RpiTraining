#include "waveforms.h"



const int8_t sine_lut[WAVE_RES] = {
     0, 3, 6, 8, 10, 12, 13, 14,
    15, 14, 13, 12, 10,  8,  6,  3,
     0, -3, -6, -8, -10, -12, -13, -14,
   -15, -14, -13, -12, -10, -8, -6, -3
};

SineWave* sin_init(uint8_t periode) {
    static SineWave sine;
    static uint8_t initialized = 0;

    if(!initialized) {
        sine.angle = 0;
        sine.cli_out = 0;
        sine.periode = periode;
        sine.quadrant = 0;
        sine.sin_val = 0;
        sine.angle_step = (360/periode);
        initialized = 1;
    }
    

    return &sine;
}

void sin_update(SineWave *sine){
    sine->sin_val = sine_lut[(sine->angle-1) * (WAVE_RES>>2) / 90];
    if(sine->angle >= 360){
        sine->angle = 0;
    }
    sine->angle += sine->angle_step;
    sine->cli_out = sine->sin_val + SINE_LUT_OFFSET; 
}
TriangularWave* triangular_init(uint8_t periode) {
    static TriangularWave triag;
    static uint8_t initialized = 0;

    if(!initialized) {
        triag.value = EDGE_OFFSET;
        triag.periode_cnt = 0;
        triag.periode = periode;
        triag.step = ((uint8_t)(WAVE_RES-EDGE_OFFSET)/periode) << 1;
        initialized = 1;
    }

    return &triag;
}
void triangular_update(TriangularWave *triag) {
    

    if(triag->periode_cnt < (triag->periode >> 1)) {
        triag->value += triag->step;
                
    }else {
        triag->value -= triag->step;
       
    }

    if (triag->value > WAVE_RES) {
        triag->value = WAVE_RES;
    }

    triag->periode_cnt++;
    if (triag->periode_cnt >= triag->periode) {
         triag->periode_cnt = 0;
         
    }
    

}
SquareWave * square_init(uint8_t periode) {
    static SquareWave square;
    static uint8_t initialized = 0;

    if(!initialized) {
        square.value = 0;
        square.periode = periode;
        initialized = 1;
    }

    return &square;
}
void square_update(SquareWave *square) {
    if(square->periode_cnt < (square->periode >> 1)) {
        square-> value = EDGE_OFFSET;
    }else {
        square-> value = WAVE_RES-EDGE_OFFSET;
    }

    square->periode_cnt++;
    if (square->periode_cnt >= square->periode) {
         square->periode_cnt = 0;
    }
}