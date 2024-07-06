#include "../include/cpu/cpu.h"

CpuCtx_t cpu_ctx = { 0 };

int main(void) {
    cpu_write_pin(RDY, HI);
    printf("RDY pin: %d\n", cpu_read_pin(RDY));

    uint8_t dbus = 0xF1;
    cpu_set_data_bus(dbus);
    assert(cpu_get_data_bus() == 0xF1);

    cpu_print_regs();

    return EXIT_SUCCESS;
}
