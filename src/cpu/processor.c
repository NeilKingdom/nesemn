#include "../../include/6502/processor.h"

mProc6502_Ctx ctx6502 = { 0 };

void proc6502_set_vpb(enum State state) {
    ctx6502.vpb = state;
}

void proc6502_set_rdy(enum State state) {
    ctx6502.rdy = state;
}

void proc6502_set_phi1o(enum State state) {
    ctx6502.phi1o = state;
}

void proc6502_set_irqb(enum State state) {
    ctx6502.irqb = state;
}

void proc6502_set_mlb(enum State state) {
    ctx6502.mlb = state;
}

void proc6502_set_nmib(enum State state) {
    ctx6502.nmib = state;
}

void proc6502_set_sync(enum State state) {
    ctx6502.sync = state;
}

void proc6502_set_vdd(enum State state) {
    ctx6502.vdd = state;
}

void proc6502_set_a0(enum State state) {
    ctx6502.a0 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a1(enum State state) {
    ctx6502.a1 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a2(enum State state) {
    ctx6502.a2 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a3(enum State state) {
    ctx6502.a3 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a4(enum State state) {
    ctx6502.a4 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a5(enum State state) {
    ctx6502.a5 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a6(enum State state) {
    ctx6502.a6 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a7(enum State state) {
    ctx6502.a7 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a8(enum State state) {
    ctx6502.a8 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a9(enum State state) {
    ctx6502.a9 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a10(enum State state) {
    ctx6502.a10 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a11(enum State state) {
    ctx6502.a11 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a12(enum State state) {
    ctx6502.a12 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a13(enum State state) {
    ctx6502.a13 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a14(enum State state) {
    ctx6502.a14 = (ctx6502.be) ? state : LO;
}

void proc6502_set_a15(enum State state) {
    ctx6502.a15 = (ctx6502.be) ? state : LO;
}

void proc6502_set_resb(enum State state) {
    ctx6502.a15 = state;
}

void proc6502_set_phi2o(enum State state) {
    ctx6502.phi2o = state;
}

void proc6502_set_sob(enum State state) {
    ctx6502.sob = state;
}

void proc6502_set_phi2(enum State state) {
    ctx6502.phi2 = state;
}

void proc6502_set_be(enum State state) {
    ctx6502.be = state;
}

void proc6502_set_nc(enum State state) {
    return;
}

void proc6502_set_rwb(enum State state) {
    ctx6502.rwb = (ctx6502.be) ? state : HI;
}

void proc6502_set_d0(enum State state) {
    ctx6502.d0 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d1(enum State state) {
    ctx6502.d1 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d2(enum State state) {
    ctx6502.d2 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d3(enum State state) {
    ctx6502.d3 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d4(enum State state) {
    ctx6502.d4 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d5(enum State state) {
    ctx6502.d5 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d6(enum State state) {
    ctx6502.d6 = (ctx6502.be) ? state : LO;
}

void proc6502_set_d7(enum State state) {
    ctx6502.d7 = (ctx6502.be) ? state : LO;
}

void proc6502_set_vss(enum State state) {
    ctx6502.vss = state;
}

uint8_t proc6502_get_data_bus(void) {
    uint8_t data = 0x00;
    data |= (ctx6502.d7 << 0x07);
    data |= (ctx6502.d6 << 0x06);
    data |= (ctx6502.d5 << 0x05);
    data |= (ctx6502.d4 << 0x04);
    data |= (ctx6502.d3 << 0x03);
    data |= (ctx6502.d2 << 0x02);
    data |= (ctx6502.d1 << 0x01);
    data |= (ctx6502.d0 << 0x00);
    return data;
}

void proc6502_set_data_bus(uint8_t data) {
    proc6502_set_d7(data & 0x80);
    proc6502_set_d6(data & 0x40);
    proc6502_set_d5(data & 0x20);
    proc6502_set_d4(data & 0x10);
    proc6502_set_d3(data & 0x08);
    proc6502_set_d2(data & 0x04);
    proc6502_set_d1(data & 0x02);
    proc6502_set_d0(data & 0x01);
}

uint16_t proc6502_get_addr_bus(void) {
    uint8_t addr = 0x00;
    addr |= (ctx6502.a15 << 0x0F);
    addr |= (ctx6502.a14 << 0x0E);
    addr |= (ctx6502.a13 << 0x0D);
    addr |= (ctx6502.a12 << 0x0C);
    addr |= (ctx6502.a11 << 0x0B);
    addr |= (ctx6502.a10 << 0x0A);
    addr |= (ctx6502.a9  << 0x09);
    addr |= (ctx6502.a8  << 0x08);
    addr |= (ctx6502.a7  << 0x07);
    addr |= (ctx6502.a6  << 0x06);
    addr |= (ctx6502.a5  << 0x05);
    addr |= (ctx6502.a4  << 0x04);
    addr |= (ctx6502.a3  << 0x03);
    addr |= (ctx6502.a2  << 0x02);
    addr |= (ctx6502.a1  << 0x01);
    addr |= (ctx6502.a0  << 0x00);
    return addr;
}

void proc6502_set_addr_bus(uint16_t addr) {
    proc6502_set_a15(addr & 0x8000);
    proc6502_set_a14(addr & 0x4000);
    proc6502_set_a13(addr & 0x2000);
    proc6502_set_a12(addr & 0x1000);
    proc6502_set_a11(addr & 0x0800);
    proc6502_set_a10(addr & 0x0400);
    proc6502_set_a9(addr & 0x0200);
    proc6502_set_a8(addr & 0x0100);
    proc6502_set_a7(addr & 0x0080);
    proc6502_set_a6(addr & 0x0040);
    proc6502_set_a5(addr & 0x0020);
    proc6502_set_a4(addr & 0x0010);
    proc6502_set_a3(addr & 0x0008);
    proc6502_set_a2(addr & 0x0004);
    proc6502_set_a1(addr & 0x0002);
    proc6502_set_a0(addr & 0x0001);
}

void proc6502_turn_on(void) {
    ctx6502.vss = HI;
    ctx6502.vdd = LO;
}
