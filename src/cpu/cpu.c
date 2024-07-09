#include "../../include/cpu/cpu.h"

/**
 * @brief Write HI/LO to a pin
 * @since 06-07-2024
 * @param pin The pin that will be written to
 * @param state The state being written i.e. HI or LO
 */
void cpu_write_pin(CpuPin_t pin, State_t state) {
    cpu_ctx.pins[pin].state = state;
}

/**
 * @brief Read the state of a pin
 * @since 06-07-2024
 * @param pin The pin that will be read from
 * @returns The state of the pin
 */
State_t cpu_read_pin(CpuPin_t pin) {
    return cpu_ctx.pins[pin].state;
}

/**
 * @brief Gets the status of the 8-bit data bus as a byte
 * @since 06-07-2024
 * @returns The status of the 8-bit data bus as a byte
 */
uint8_t cpu_get_data_bus(void) {
    uint8_t data_bus = 0;
    data_bus |= (uint8_t)(cpu_ctx.pins[D0].state << 7);
    data_bus |= (uint8_t)(cpu_ctx.pins[D1].state << 6);
    data_bus |= (uint8_t)(cpu_ctx.pins[D2].state << 5);
    data_bus |= (uint8_t)(cpu_ctx.pins[D3].state << 4);
    data_bus |= (uint8_t)(cpu_ctx.pins[D4].state << 3);
    data_bus |= (uint8_t)(cpu_ctx.pins[D5].state << 2);
    data_bus |= (uint8_t)(cpu_ctx.pins[D6].state << 1);
    data_bus |= (uint8_t)(cpu_ctx.pins[D7].state << 0);
    return data_bus;
}

/**
 * @brief Writes to each line of the 8-bit data bus
 * @since 06-07-2024
 * @param data The byte of data to be written to the data bus
 */
void cpu_set_data_bus(uint8_t data) {
    cpu_ctx.pins[D0].state = (data & 0x80) >> 7;
    cpu_ctx.pins[D1].state = (data & 0x40) >> 6;
    cpu_ctx.pins[D2].state = (data & 0x20) >> 5;
    cpu_ctx.pins[D3].state = (data & 0x10) >> 4;
    cpu_ctx.pins[D4].state = (data & 0x08) >> 3;
    cpu_ctx.pins[D5].state = (data & 0x04) >> 2;
    cpu_ctx.pins[D6].state = (data & 0x02) >> 1;
    cpu_ctx.pins[D7].state = (data & 0x01) >> 0;
}

/**
 * @brief Gets the status of the 16-bit address bus as a short
 * @since 06-07-2024
 * @returns The status of the 16-bit data bus as a short
 */
uint16_t cpu_get_addr_bus(void) {
    uint16_t addr_bus = 0;
    addr_bus |= (uint16_t)(cpu_ctx.pins[A0].state  << 15);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A1].state  << 14);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A2].state  << 13);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A3].state  << 12);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A4].state  << 11);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A5].state  << 10);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A6].state  << 9);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A7].state  << 8);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A8].state  << 7);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A9].state  << 6);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A10].state << 5);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A11].state << 4);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A12].state << 3);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A13].state << 2);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A14].state << 1);
    addr_bus |= (uint16_t)(cpu_ctx.pins[A15].state << 0);
    return addr_bus;
}

/**
 * @brief Writes to each line of the 16-bit address bus
 * @since 06-07-2024
 * @param addr The 16-bit address to be written to the address bus
 */
void cpu_set_addr_bus(uint16_t addr) {
    cpu_ctx.pins[A0].state  = (addr & 0x8000) >> 15;
    cpu_ctx.pins[A1].state  = (addr & 0x4000) >> 14;
    cpu_ctx.pins[A2].state  = (addr & 0x2000) >> 13;
    cpu_ctx.pins[A3].state  = (addr & 0x1000) >> 12;
    cpu_ctx.pins[A4].state  = (addr & 0x0800) >> 11;
    cpu_ctx.pins[A5].state  = (addr & 0x0400) >> 10;
    cpu_ctx.pins[A6].state  = (addr & 0x0200) >> 9;
    cpu_ctx.pins[A7].state  = (addr & 0x0100) >> 8;
    cpu_ctx.pins[A8].state  = (addr & 0x0080) >> 7;
    cpu_ctx.pins[A9].state  = (addr & 0x0040) >> 6;
    cpu_ctx.pins[A10].state = (addr & 0x0020) >> 5;
    cpu_ctx.pins[A11].state = (addr & 0x0010) >> 4;
    cpu_ctx.pins[A12].state = (addr & 0x0008) >> 3;
    cpu_ctx.pins[A13].state = (addr & 0x0004) >> 2;
    cpu_ctx.pins[A14].state = (addr & 0x0002) >> 1;
    cpu_ctx.pins[A15].state = (addr & 0x0001) >> 0;
}
