#define PATH_6502(file) ("../include/6502/##file")

#include PATH_6502(stack.h)
#include PATH_6502(registers.h)
#include PATH_6502(processor.h)

uint8_t stack[256];
mProc6502_Ctx ctx6502;
mProc6502_Regs regs;

static void nes_turn_on(void) {
    proc6502_turn_on();
}

int main(void) {
    nes_turn_on();

    return EXIT_SUCCESS;
}
