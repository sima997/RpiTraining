#pragma once

#include "Peripherals/base.h"
#include "common.h"



struct auxiliaryRegs {
    reg32 irq_status;
    reg32 enables;
    reg32 resv[14];
    reg32 mu_io;
    reg32 mu_ier;
    reg32 mu_iir;
    reg32 mu_lcr;
    reg32 mu_mcr;
    reg32 mu_lsr;
    reg32 mu_msr;
    reg32 mu_scratch;
    reg32 mu_control;
    reg32 mu_status;
    reg32 mu_baud_rate;
    reg32 resv2[30]; //Other peripherals not used
};

#define REGS_auxiliary ((struct auxiliaryRegs *)(PBASE + 0x00215000))