#include "cpu.h"

CpuCtx_t cpu_ctx = { 0 };

static void *clock_signal(void *data) {

}

int main(void) {
    uint8_t dbus = 0xF1;
    cpu_set_data_bus(dbus);
    assert(cpu_get_data_bus() == 0xF1);

    cpu_print_regs();

    return EXIT_SUCCESS;
}
