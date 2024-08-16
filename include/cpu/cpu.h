#ifndef CPU_H
#define CPU_H

#include "../common.h"
#include "registers.h"

#define CPU_NUM_PINS 40

/**
 *         .--\/--.
 *  AD1 <- |01  40| -- VCC
 *  AD2 <- |02  39| -> OUT0
 * RSTB -> |03  38| -> OUT1
 *  A00 <- |04  37| -> OUT2
 *  A01 <- |05  36| -> OE1B
 *  A02 <- |06  35| -> OE2B
 *  A03 <- |07  34| -> R/W
 *  A04 <- |08  33| <- NMIB
 *  A05 <- |09  32| <- IRQB
 *  A06 <- |10  31| -> M2
 *  A07 <- |11  30| <- TST (usually GND)
 *  A08 <- |12  29| <- CLK
 *  A09 <- |13  28| <> D0
 *  A10 <- |14  27| <> D1
 *  A11 <- |15  26| <> D2
 *  A12 <- |16  25| <> D3
 *  A13 <- |17  24| <> D4
 *  A14 <- |18  23| <> D5
 *  A15 <- |19  22| <> D6
 *  GND -- |20  21| <> D7
 *         `------'
 */
typedef enum {
    AD1,        /* Audio out pin (both pulse waves) */
    AD2,        /* Audio out pin (triangle, noise, and DPCM) */
    RSTB,       /* Reset (bar) */
    A00,        /* Address pin 0 */
    A01,        /* Address pin 1 */
    A02,        /* Address pin 2 */
    A03,        /* Address pin 3 */
    A04,        /* Address pin 4 */
    A05,        /* Address pin 5 */
    A06,        /* Address pin 6 */
    A07,        /* Address pin 7 */
    A08,        /* Address pin 8 */
    A09,        /* Address pin 9 */
    A10,        /* Address pin 10 */
    A11,        /* Address pin 11 */
    A12,        /* Address pin 12 */
    A13,        /* Address pin 13 */
    A14,        /* Address pin 14 */
    A15,        /* Address pin 15 */
    GND,        /* Ground */
    VCC,        /* Voltage common collector */
    OUT0,       /* Output pin used by controllers + strobe signal */
    OUT1,       /* Output pin used by controllers */
    OUT2,       /* Output pin used by controllers */
    OE1B,       /* Output enable 1 (bar) */
    OE2B,       /* Output enable 2 (bar) */
    RW,         /* Read/write pin */
    NMIB,       /* Non-maskable interrupt (bar) */
    IRQB,       /* Interrupt request (bar) */
    M2,         /* Signals ready pin */
    TST,        /* Test pin (normally low, but setting high enables extra diagnostics */
    CLK,        /* Clock pin (21.47727 MHz (NTSC) or 26.6017 MHz (PAL)) */
    D0,         /* Data pin 0 */
    D1,         /* Data pin 1 */
    D2,         /* Data pin 2 */
    D3,         /* Data pin 3 */
    D4,         /* Data pin 4 */
    D5,         /* Data pin 5 */
    D6,         /* Data pin 6 */
    D7,         /* Data pin 7 */
} CpuPin_t;

typedef struct {
    Pin_t       pins[CPU_NUM_PINS];
    CpuRegs_t   regs;
} CpuCtx_t;

extern CpuCtx_t cpu_ctx;

/* Forward function declarations */

void        cpu_write_pin(CpuPin_t pin, PinState_t state);
PinState_t  cpu_read_pin(CpuPin_t pin);
uint8_t     cpu_get_data_bus(void);
void        cpu_set_data_bus(uint8_t data);
uint8_t     cpu_get_ctrl_bus(void);
void        cpu_set_ctrl_bus(uint8_t data);
uint16_t    cpu_get_addr_bus(void);
void        cpu_set_addr_bus(uint16_t addr);

#endif /* CPU_H */
