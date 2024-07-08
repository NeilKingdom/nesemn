#ifndef PPU_H
#define PPU_H

#include "../common.h"
#include "registers.h"

#define PPU_NUM_PINS 40

/**
 *         .--\/--.
 *  R/W <- |01  40| -- VCC
 *   D0 <- |02  39| -> ALE
 *   D1 -> |03  38| -> A0
 *   D2 <- |04  37| -> A1
 *   D3 <- |05  36| -> A2
 *   D4 <- |06  35| -> A3
 *   D5 <- |07  34| -> A4
 *   D6 <- |08  33| <- A5
 *   D7 <- |09  32| <- A6
 *  RS2 <- |10  31| -> A7
 *  RS1 <- |11  30| <- PA08
 *  RS0 <- |12  29| <- PA09
 * DBEB <- |13  28| <> PA10
 * EXT0 <- |14  27| <> PA11
 * EXT1 <- |15  26| <> PA12
 * EXT2 <- |16  25| <> PA13
 * EXT3 <- |17  24| <> RDB
 *  CLK <- |18  23| <> WEB
 * INTB <- |19  22| <> RSTB
 *  GND -- |20  21| <> VOUT
 *         `------'
 */
typedef enum {
} PpuPin_t;

typedef struct {
    Pin_t       pins[PPU_NUM_PINS];
    PpuRegs_t   regs;
} PpuCtx_t;

extern PpuCtx_t ppu_ctx;

/* Forward function declarations */

#endif /* PPU_H */
