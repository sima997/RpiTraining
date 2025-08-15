#include "gpio.h"
#include "utills.h"
#include "Peripherals/auxiliary.h"
#include "mini_uart.h"

#define TXD 14
#define RXD 15

void uart_init() {
    gpio_pin_set_func(TXD, GFAlt5);
    gpio_pin_set_func(RXD, GFAlt5);

    //Only for RPI3
    gpio_pin_enable(TXD);
    gpio_pin_enable(RXD);

    REGS_auxiliary->enables = 1;
    REGS_auxiliary->mu_control = 0;
    REGS_auxiliary->mu_ier = 0;
    REGS_auxiliary->mu_lcr = 3;
    REGS_auxiliary->mu_mcr = 0;

#if RPI_VERSION == 3
    REGS_auxiliary->mu_baud_rate = 270; // = 115200 @ 250 Mhz
#endif

#if RPI_VERSION == 4
    REGS_auxiliary->mu_baud_rate = 541; // = 115200 @ 500 Mhz
#endif

    REGS_auxiliary->mu_control = 3;

    uart_send('\r');
    uart_send('\n');
    uart_send('\n');
}

void uart_send(char c) {
    while(!(REGS_auxiliary->mu_lsr & (1<<5)));

    REGS_auxiliary->mu_io = c;
}

char uart_recv() {
    while(!(REGS_auxiliary->mu_lsr & (1<<0)));

    return REGS_auxiliary->mu_io & 0xff;
}

void uart_send_string(char *str) {
    while(*str) {
        if(*str == '\n') {
            uart_send('\r');
        }

        uart_send(*str);
        str++; 
    }
}