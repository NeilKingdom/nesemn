#include "../../include/cpu/cpu.h"

void cpu_print_regs(void) {
    printf(
        "Accumulator     | Hex: 0x%02X,   Dec: %d\n"
        "Index Y         | Hex: 0x%02X,   Dec: %d\n"
        "Index X         | Hex: 0x%02X,   Dec: %d\n"
        "Program Counter | Hex: 0x%04X, Dec: %d\n"
        "Stack Pointer   | Hex: 0x%02X,   Dec: %d\n"
        "Status Register | N V O B D I Z C\n"
        "                  %d %d %d %d %d %d %d %d\n\n",

        cpu_ctx.regs.a,         cpu_ctx.regs.a,
        cpu_ctx.regs.y,         cpu_ctx.regs.y,
        cpu_ctx.regs.x,         cpu_ctx.regs.x,
        cpu_ctx.regs.pc.pch,    cpu_ctx.regs.pc.pch,
        cpu_ctx.regs.sp.s,      cpu_ctx.regs.sp.s,

        PFLAG_N(cpu_ctx.regs.p),
        PFLAG_V(cpu_ctx.regs.p),
        PFLAG_O,
        PFLAG_B(cpu_ctx.regs.p),
        PFLAG_D(cpu_ctx.regs.p),
        PFLAG_I(cpu_ctx.regs.p),
        PFLAG_Z(cpu_ctx.regs.p),
        PFLAG_C(cpu_ctx.regs.p)
    );
}
