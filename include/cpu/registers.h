#ifndef CPU_REGISTERS_H
#define CPU_REGISTERS_H

#include "../common.h"

/*** Regsiter map ***/

/* APU pulse wave channel 1 */
#define REG_ADDR_SQ1_VOL        0x4000
#define REG_ADDR_SQ1_SWEEP      0x4001
#define REG_ADDR_SQ1_LO         0x4002
#define REG_ADDR_SQ1_HI         0x4003

/* APU pulse wave channel 2 */
#define REG_ADDR_SQ2_VOL        0x4004
#define REG_ADDR_SQ2_SWEEP      0x4005
#define REG_ADDR_SQ2_LO         0x4006
#define REG_ADDR_SQ2_HI         0x4007

/* APU triangle wave channel */
#define REG_ADDR_TRI_LINEAR     0x4008
#define REG_ADDR_TRI_LO         0x400A
#define REG_ADDR_TRI_HI         0x400B

/* APU noise channel */
#define REG_ADDR_NOISE_VOL      0x400C
#define REG_ADDR_NOISE_LO       0x400E
#define REG_ADDR_NOISE_HI       0x400F

/* APU DMC channel */
#define REG_ADDR_DMC_FREQ       0x4010
#define REG_ADDR_DMC_RAW        0x4011
#define REG_ADDR_DMC_START      0x4012
#define REG_ADDR_DMC_LEN        0x4013

/* Other */
#define REG_ADDR_OAMDMA         0x4014
#define REG_ADDR_SND_CHN        0x4015
#define REG_ADDR_JOY1           0x4016
#define REG_ADDR_JOY2           0x4017

/* General Purpose Registers (GPR) */
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
} CpuRegs_t;

#define PFLAG_N(p) (((p) & (0x80)) >> 0x07)     /* Negative (HI = negative) */
#define PFLAG_V(p) (((p) & (0x40)) >> 0x06)     /* Overflow (HI = true) */
#define PFLAG_O 1                               /* Always 1 */
#define PFLAG_B(p) (((p) & (0x10)) >> 0x04)     /* BRK command (HI = BRK, LOW = IRQB) */
#define PFLAG_D(p) (((p) & (0x08)) >> 0x03)     /* Decimal mode (HI = true) */
#define PFLAG_I(p) (((p) & (0x04)) >> 0x02)     /* IRQB disable (HI = disable) */
#define PFLAG_Z(p) (((p) & (0x02)) >> 0x01)     /* Zero (HI = true) */
#define PFLAG_C(p) (((p) & (0x01)) >> 0x00)     /* Carry (HI = true) */

/* Forward function declarations */

void cpu_print_regs(void);

#endif /* CPU_REGISTERS_H */
