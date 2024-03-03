#ifndef REGISTERS_H
#define REGISTERS_H

#include "common.h"

typedef struct {
    uint8_t a;          /* Accumulator */
    uint8_t y;          /* Index */
    uint8_t x;          /* Index */
    union {             /* Program counter (PCH = 16-bit, PCL = 8-bit LSB) */
        uint16_t pch;
        uint8_t  pcl;
    } pc;
    union {             /* Stack pointer (1 = 9-bit, S = 8-bit LSB) */
        uint16_t o: 9;
        uint8_t  s;
    } sp;
    uint8_t p;          /* Status register */
} proc6502Regs;

#define PFLAG_N(p) (((p) & (0x80)) >> 0x07)     /* Negative (HI = negative) */
#define PFLAG_V(p) (((p) & (0x40)) >> 0x06)     /* Overflow (HI = true) */
#define PFLAG_O 1                               /* Always 1 */
#define PFLAG_B(p) (((p) & (0x10)) >> 0x04)     /* BRK command (HI = BRK, LOW = IRQB) */
#define PFLAG_D(p) (((p) & (0x08)) >> 0x03)     /* Decimal mode (HI = true) */
#define PFLAG_I(p) (((p) & (0x04)) >> 0x02)     /* IRQB disable (HI = disable) */
#define PFLAG_Z(p) (((p) & (0x02)) >> 0x01)     /* Zero (HI = true) */
#define PFLAG_C(p) (((p) & (0x01)) >> 0x00)     /* Carry (HI = true) */

#endif /* REGISTERS_H */
