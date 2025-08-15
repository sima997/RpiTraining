#pragma once

#include <stdint.h>
#include <stdio.h>

#define WAVE_RES        32 //Wave resolution 
#define SINE_LUT_OFFSET 15
#define EDGE_OFFSET    2

extern const int8_t sine_lut[WAVE_RES];

typedef struct {
    int16_t angle;
    uint8_t quadrant;
    int8_t sin_val;
    uint8_t cli_out;
    uint8_t periode;
    uint16_t angle_step;
}SineWave;

typedef struct {
    uint8_t periode;
    uint8_t periode_cnt;
    uint8_t value;
    uint8_t step;
}TriangularWave;

typedef struct {
    uint8_t periode;
    uint8_t periode_cnt;
    uint8_t value;
    uint8_t step;
}SquareWave;

SineWave* sin_init(uint8_t periode);
void sin_update(SineWave *sine);
TriangularWave* triangular_init(uint8_t periode);
void triangular_update(TriangularWave *triag);
SquareWave *  square_init(uint8_t periode);
void square_update(SquareWave *square);