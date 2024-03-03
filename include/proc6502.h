#ifndef PROC6502_H
#define PROC6502_H

#include "common.h"

typedef struct {
    State vpb;      /* Vector pull */
    State rdy;      /* Ready pin */
    State phi1O;    /* Phase 1 out clock */
    State irqb;     /* Interrupt request (bar) */
    State mlb;      /* Memory lock (bar) */
    State nmib;     /* Non-maskable interrupt (bar) */
    State sync;     /* Synchronize */
    State vdd;      /* Voltage drain */
    State a0;       /* Address 0 */
    State a1;       /* Address 1 */
    State a2;       /* Address 2 */
    State a3;       /* Address 3 */
    State a4;       /* Address 4 */
    State a5;       /* Address 5 */
    State a6;       /* Address 6 */
    State a7;       /* Address 7 */
    State a8;       /* Address 8 */
    State a9;       /* Address 9 */
    State a10;      /* Address 10 */
    State a11;      /* Address 11 */
    State a12;      /* Address 12 */
    State a13;      /* Address 13 */
    State a14;      /* Address 14 */
    State a15;      /* Address 15 */
    State resb;     /* Reset (bar) */
    State phi2O;    /* Phase 2 out clock */
    State sob;      /* Set overflow (bar) */
    State phi2;     /* Phase 2 in clock */
    State be;       /* Bus enable */
    State nc;       /* No connection */
    State rwb;      /* R/W enable (bar) */
    State d0;       /* Data 0 */
    State d1;       /* Data 1 */
    State d2;       /* Data 2 */
    State d3;       /* Data 3 */
    State d4;       /* Data 4 */
    State d5;       /* Data 5 */
    State d6;       /* Data 6 */
    State d7;       /* Data 7 */
    State vss;      /* Internal logic ground */
} proc6502Ctx;

/* Forward function decls */
void proc6502_set_vss(State state) {

}

#endif /* PROC6502_H */
