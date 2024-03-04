#include "../../include/6502/registers.h"

mProc6502_Regs regs6502 = { 0 };

void proc6502_print_registers(void) {
    printf(
        "Accumulator\tHex: 0x%02X, Dec: %d\n",
        "Index Y    \tHex: 0x%02X, Dec: %d\n",
        "Index X    \tHex: 0x%02X, Dec: %d\n",
        "Index PCH  \tHex: 0x%04X, Dec: %d\n",
        "Index PCL  \tHex: 0x%02X, Dec: %d\n",
        "Index SP   \tHex: 0x%02X, Dec: %d\n\n",
        regs6502.a,         regs6502.a,
        regs6502.y,         regs6502.y,
        regs6502.x,         regs6502.x,
        regs6502.pc.pch,    regs6502.pc.pch,
        regs6502.pc.pcl,    regs6502.pc.pcl,
        regs6502.sp.s,      regs6502.sp.s
    );
}

void proc6502_print_status_reg(void) {
    printf(
        "Status Register:\n"
        "N V O B D I Z C\n"
        "%d %d %d %d %d %d %d %d\n\n",
        PFLAG_N(regs6502.p),
        PFLAG_V(regs6502.p),
        PFLAG_O,
        PFLAG_B(regs6502.p),
        PFLAG_D(regs6502.p),
        PFLAG_I(regs6502.p),
        PFLAG_Z(regs6502.p),
        PFLAG_C(regs6502.p)
   );
}
