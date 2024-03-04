#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "../common.h"

typedef struct {
    enum State vpb;      /* Vector pull */
    enum State rdy;      /* Ready pin */
    enum State phi1o;    /* Phase 1 out clock */
    enum State irqb;     /* Interrupt request (bar) */
    enum State mlb;      /* Memory lock (bar) */
    enum State nmib;     /* Non-maskable interrupt (bar) */
    enum State sync;     /* Synchronize */
    enum State vdd;      /* Voltage drain */
    enum State a0;       /* Address 0 */
    enum State a1;       /* Address 1 */
    enum State a2;       /* Address 2 */
    enum State a3;       /* Address 3 */
    enum State a4;       /* Address 4 */
    enum State a5;       /* Address 5 */
    enum State a6;       /* Address 6 */
    enum State a7;       /* Address 7 */
    enum State a8;       /* Address 8 */
    enum State a9;       /* Address 9 */
    enum State a10;      /* Address 10 */
    enum State a11;      /* Address 11 */
    enum State a12;      /* Address 12 */
    enum State a13;      /* Address 13 */
    enum State a14;      /* Address 14 */
    enum State a15;      /* Address 15 */
    enum State resb;     /* Reset (bar) */
    enum State phi2o;    /* Phase 2 out clock */
    enum State sob;      /* Set overflow (bar) */
    enum State phi2;     /* Phase 2 in clock */
    enum State be;       /* Bus enable */
    enum State nc;       /* No connection */
    enum State rwb;      /* R/W enable (bar) */
    enum State d0;       /* Data 0 */
    enum State d1;       /* Data 1 */
    enum State d2;       /* Data 2 */
    enum State d3;       /* Data 3 */
    enum State d4;       /* Data 4 */
    enum State d5;       /* Data 5 */
    enum State d6;       /* Data 6 */
    enum State d7;       /* Data 7 */
    enum State vss;      /* Internal logic ground */
} mProc6502_Ctx;

extern mProc6502_Ctx ctx6502;

/* Set pin states */

void proc6502_set_vpb(enum State state);
void proc6502_set_rdy(enum State state);
void proc6502_set_phi1o(enum State state);
void proc6502_set_irqb(enum State state);
void proc6502_set_mlb(enum State state);
void proc6502_set_nmib(enum State state);
void proc6502_set_sync(enum State state);
void proc6502_set_vdd(enum State state);
void proc6502_set_a0(enum State state);
void proc6502_set_a1(enum State state);
void proc6502_set_a2(enum State state);
void proc6502_set_a3(enum State state);
void proc6502_set_a4(enum State state);
void proc6502_set_a5(enum State state);
void proc6502_set_a6(enum State state);
void proc6502_set_a7(enum State state);
void proc6502_set_a8(enum State state);
void proc6502_set_a9(enum State state);
void proc6502_set_a10(enum State state);
void proc6502_set_a11(enum State state);
void proc6502_set_a12(enum State state);
void proc6502_set_a13(enum State state);
void proc6502_set_a14(enum State state);
void proc6502_set_a15(enum State state);
void proc6502_set_resb(enum State state);
void proc6502_set_phi2o(enum State state);
void proc6502_set_sob(enum State state);
void proc6502_set_phi2(enum State state);
void proc6502_set_be(enum State state);
void proc6502_set_nc(enum State state);
void proc6502_set_rwb(enum State state);
void proc6502_set_d0(enum State state);
void proc6502_set_d1(enum State state);
void proc6502_set_d2(enum State state);
void proc6502_set_d3(enum State state);
void proc6502_set_d4(enum State state);
void proc6502_set_d5(enum State state);
void proc6502_set_d6(enum State state);
void proc6502_set_d7(enum State state);
void proc6502_set_vss(enum State state);

/* Side effects */

/* Helper functions */

uint8_t     proc6502_get_data_bus(void);
void        proc6502_set_data_bus(uint8_t data);
uint16_t    proc6502_get_addr_bus(void);
void        proc6502_set_addr_bus(uint16_t addr);
void        proc6502_turn_on(void);

#endif /* PROCESSOR_H */
