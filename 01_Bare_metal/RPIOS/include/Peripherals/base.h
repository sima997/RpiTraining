#pragma once

#if RPI_VERSION == 3
#define PBASE 0x3f000000

#elif RPI_VERSION == 4
#define PBASE 0xfe000000

#else
#define PBASE 0
#error RPI_VERSION NOT DEFINED

#endif