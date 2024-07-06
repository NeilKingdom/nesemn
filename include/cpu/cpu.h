#ifndef CPU_H
#define CPU_H

#include "../common.h"
#include "registers.h"

#define NUM_PINS 40

typedef enum {
    VPB = 0,  /* Vector pull */
    RDY,      /* Ready pin */
    PHI1O,    /* Phase 1 out clock */
    IRQB,     /* Interrupt request (bar) */
    MLB,      /* Memory lock (bar) */
    NMIB,     /* Non-maskable interrupt (bar) */
    SYNC,     /* Synchronize */
    VDD,      /* Voltage drain */
    A0,       /* Address 0 */
    A1,       /* Address 1 */
    A2,       /* Address 2 */
    A3,       /* Address 3 */
    A4,       /* Address 4 */
    A5,       /* Address 5 */
    A6,       /* Address 6 */
    A7,       /* Address 7 */
    A8,       /* Address 8 */
    A9,       /* Address 9 */
    A10,      /* Address 10 */
    A11,      /* Address 11 */
    A12,      /* Address 12 */
    A13,      /* Address 13 */
    A14,      /* Address 14 */
    A15,      /* Address 15 */
    RESB,     /* Reset (bar) */
    PHI2O,    /* Phase 2 out clock */
    SOB,      /* Set overflow (bar) */
    PHI2,     /* Phase 2 in clock */
    BE,       /* Bus enable */
    NC,       /* No connection */
    RWB,      /* R/W enable (bar) */
    D0,       /* Data 0 */
    D1,       /* Data 1 */
    D2,       /* Data 2 */
    D3,       /* Data 3 */
    D4,       /* Data 4 */
    D5,       /* Data 5 */
    D6,       /* Data 6 */
    D7,       /* Data 7 */
    VSS,      /* Internal logic ground */
} PinName_t;

typedef struct {
    Pin_t       pins[NUM_PINS];
    CpuRegs_t   regs;
} CpuCtx_t;

extern CpuCtx_t cpu_ctx;

/* Forward function declarations */

void        cpu_write_pin(PinName_t pin, State_t state);
State_t     cpu_read_pin(PinName_t pin);
uint8_t     cpu_get_data_bus(void);
void        cpu_set_data_bus(uint8_t data);
uint16_t    cpu_get_addr_bus(void);
void        cpu_set_addr_bus(uint16_t addr);

#endif /* CPU_H */
