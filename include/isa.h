#ifndef ISA_H
#define ISA_H

enum Mnemonic {
    ADC,    /* Add with carry */
    AND,    /* AND (with accumulator) */
    ASL,    /* Arithmetic shift left */
    BCC,    /* Branch on carry clear */
    BCS,    /* Branch on carry set */
    BEQ,    /* Branch on equal (zero set) */
    BIT,    /* Bit test */
    BMI,    /* Branch on minus (negative set) */
    BNE,    /* Branch not equal (zero clear) */
    BPL,    /* Branch on plus (negative clear) */
    BRK,    /* Break/interrupt */
    BVC,    /* Branch on overflow clear */
    BVS,    /* Branch on overflow set */
    CLC,    /* Clear carry */
    CLD,    /* Clear decimal */
    CLI,    /* Clear interrupt disable */
    CLV,    /* Clear overflow */
    CMP,    /* Compare (with accumulator) */
    CPX,    /* Compare with x */
    CPY,    /* Compare with y */
    DEC,    /* Decrement */
    DEX,    /* Decrement x */
    DEY,    /* Decrement y */
    EOR,    /* Exclusive OR (with accumulator) */
    INC,    /* Increment */
    INX,    /* Increment x */
    INY,    /* Increment y */
    JMP,    /* Jump */
    JSR,    /* Jump to subroutine */
    LDA,    /* Load accumulator */
    LDX,    /* Load x */
    LDY,    /* Load y */
    LSR,    /* Logical shift right */
    NOP,    /* No operation */
    ORA,    /* OR with accumulator */
    PHA,    /* Push accumulator */
    PHP,    /* Push processor status */
    PLA,    /* Pull accumulator */
    PLP,    /* Pull processor status */
    ROL,    /* Rotate left */
    ROR,    /* Rotate right */
    RTI,    /* Return from interrupt */
    RTS,    /* Return from subroutine */
    SBC,    /* Subtract with carry */
    SEC,    /* Set carry */
    SED,    /* Set decimal */
    SEI,    /* Set interrupt disable */
    STA,    /* Store accumulator */
    STX,    /* Store x */
    STY,    /* Store y */
    TAX,    /* Transfer accumulator to x */
    TAY,    /* Transfer accumulator to y */
    TSX,    /* Transfer SP to x */
    TXA,    /* Transfer x to accumulator */
    TXS,    /* Transfer x to SP */
    TYA     /* Transfer y to accumulator */
};

/**
 * Address Modes
 *
 * A     -> Accumulator          opCode A        Operand is A (implied single-byte instruction)
 * abs   -> Absolute             opCode $LLHH    Operand is address $HHLL
 * abs,X -> Absolute, x-indexed  opCode $LLHH,X  Operand is address; effective address is address incremented by X with carry
 * abs,Y -> Absolute, y-indexed  opCode $LLHH,Y  Operand is address; effective address is address incremented by Y with carry
 * #     -> Immediate            opCode #$BB     Operaand is byte BB
 * impl  -> Implied              opCode          Operand is implied
 * ind   -> Indirect             opCode ($LLHH)  Operand is address; effective address is contetns of word at address: C.w($HHLL)
 * inx,x -> Indirect, x-indexed  opCode ($LL,X)  Oparand is zeropage address; effective address is word in (LL + X, LL + X + 1), inc. without carry: C.w($00LL + X)
 * ind,y -> Indirect, y-indexed  opCode ($LL,Y)  Oparand is zeropage address; effective address is word in (LL, LL + 1), incremented by y with carry: C.w($00LL) + Y
 * rel   -> Relative             opCode $BB      Branch target is PC + signed offset BB
 * zpg   -> Zeropage             opCode $LL      Oparand is zeropage address (hi-byte is zero, address = $00LL)
 * zpg,x -> Zeropage, x-indexed  opCode $LL,X    Oparand is zeropage address; effective address is address incremented by X without carry
 * zpg,y -> Zeropage, y-indexed  opCode $LL,Y    Oparand is zeropage address; effective address is address incremented by Y without carry
 */
enum AddrMode {
    ILL,    /* Illegal */
    ACCM,   /* Accumulator */
    ABS,    /* Absolute */
    ABSX,   /* Absolute, x-indexed */
    ABSY,   /* Absolute, y-indexed */
    IMDT,   /* Immediate */
    IMPL,   /* Implied */
    IND,    /* Indirect */
    INDX,   /* Indirect, x-indexed */
    INDY,   /* Indirect, y-indexed */
    REL,    /* Relative */
    ZPG,    /* Zeropage */
    ZPGX,   /* Zeropage, x-indexed */
    ZPGY    /* Zeropage, y-indexed */
};

typedef struct {
    Mnemonic inst;
    AddrMode mode;
} opCode;

#define ILL_OP ((opCode){ NOP, ILL })

opCode isa_table[16][16] = {
           /*  0x00        0x01      0x02         0x03    0x04          0x05        0x06      0x07      0x08        0x09        0x0A      0x0B    0x0C          0x0D        0x0E      0x0F */
/* 0x00 */ {{BRK,IMPL}, {ORA,INDX}, ILL_OP,      ILL_OP, ILL_OP,     {ORA,ZPG }, {ASL,ZPG }, ILL_OP, {PHP,IMPL}, {ORA,IMDT}, {ASL,ACCM}, ILL_OP, ILL_OP,     {ORA,ABS }, {ASL,ABS }, ILL_OP},
/* 0x10 */ {{BPL,REL }, {ORA,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {ORA,ZPGX}, {ASL,ZPGX}, ILL_OP, {CLC,IMPL}, {ORA,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {ORA,ABSX}, {ASL,ABSX}, ILL_OP},
/* 0x20 */ {{JSR,ABS }, {AND,INDX}, ILL_OP,      ILL_OP, {BIT,ZPG }, {AND,ZPG }, {ROL,ZPG }, ILL_OP, {PLP,IMPL}, {AND,IMDT}, {ROL,ACCM}, ILL_OP, {BIT,ABS }, {AND,ABS }, {ROL,ABS }, ILL_OP},
/* 0x30 */ {{BMI,REL }, {AND,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {AND,ZPGX}, {ROL,ZPGX}, ILL_OP, {SEC,IMPL}, {AND,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {AND,ABSX}, {ROL,ABSX}, ILL_OP},
/* 0x40 */ {{RTI,IMPL}, {EOR,INDX}, ILL_OP,      ILL_OP, ILL_OP,     {EOR,ZPG }, {LSR,ZPG }, ILL_OP, {PHA,IMPL}, {EOR,IMDT}, {LSR,ACCM}, ILL_OP, {JMP,ABS }, {EOR,ABS }, {LSR,ABS }, ILL_OP},
/* 0x50 */ {{BVC,REL }, {EOR,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {EOR,ZPGX}, {LSR,ZPGX}, ILL_OP, {CLI,IMPL}, {EOR,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {EOR,ABSX}, {LSR,ABSX}, ILL_OP},
/* 0x60 */ {{RTS,IMPL}, {ADC,INDX}, ILL_OP,      ILL_OP, ILL_OP,     {ADC,ZPG }, {ROR,ZPG }, ILL_OP, {PLA,IMPL}, {ADC,IMDT}, {ROR,ACCM}, ILL_OP, {JMP,IND }, {ADC,ABS }, {ROR,ABS }, ILL_OP},
/* 0x70 */ {{BVS,REL }, {ADC,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {ADC,ZPGX}, {ROR,ZPGX}, ILL_OP, {SEI,IMPL}, {ADC,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {ADC,ABSX}, {ROR,ABSX}, ILL_OP},
/* 0x80 */ {ILL_OP,     {STA,INDX}, ILL_OP,      ILL_OP, {STY,ZPG }, {STA,ZPG }, {STX,ZPG }, ILL_OP, {DEY,IMPL}, ILL_OP,     {TXA,IMPL}, ILL_OP, {STY,ABS }, {STA,ABS }, {STX,ABS }, ILL_OP},
/* 0x90 */ {{BCC,REL }, {STA,INDY}, ILL_OP,      ILL_OP, {STY,ZPGX}, {STA,ZPGX}, {STX,ZPGY}, ILL_OP, {TYA,IMPL}, {STA,ABSY}, {TXS,IMPL}, ILL_OP, ILL_OP,     {STA,ABSX}, ILL_OP,     ILL_OP},
/* 0xA0 */ {{LDY,IMDT}, {LDA,INDX}, {LDX ,IMDT}, ILL_OP, {LDY,ZPG }, {LDA,ZPG }, {LDX,ZPG }, ILL_OP, {TAY,IMPL}, {LDA,IMDT}, {TAX,IMPL}, ILL_OP, {LDY,ABS }, {LDA,ABS }, {LDX,ABS }, ILL_OP},
/* 0xB0 */ {{BCS,REL }, {LDA,INDY}, ILL_OP,      ILL_OP, {LDY,ZPGX}, {LDA,ZPGX}, {LDX,ZPGY}, ILL_OP, {CLV,IMPL}, {LDA,ABSY}, {TSX,IMPL}, ILL_OP, {LDY,ABSX}, {LDA,ABSX}, {LDX,ABSY}, ILL_OP},
/* 0xC0 */ {{CPY,IMDT}, {CMP,INDX}, ILL_OP,      ILL_OP, {CPY,ZPG }, {CMP,ZPG }, {DEC,ZPG }, ILL_OP, {INY,IMPL}, {CMP,IMDT}, {DEX,IMPL}, ILL_OP, {CPY,ABS }, {CMP,ABS }, {DEC,ABS }, ILL_OP},
/* 0xD0 */ {{BNE,REL }, {CMP,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {CMP,ZPGX}, {DEC,ZPGX}, ILL_OP, {CLD,IMPL}, {CMP,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {CMP,ABSX}, {DEC,ABSX}, ILL_OP},
/* 0xE0 */ {{CPX,IMDT}, {SBC,INDX}, ILL_OP,      ILL_OP, {CPX,ZPG }, {SBC,ZPG }, {INC,ZPG }, ILL_OP, {INX,IMPL}, {SBC,IMDT}, {NOP,IMPL}, ILL_OP, {CPX,ABS }, {SBC,ABS }, {INC,ABS }, ILL_OP},
/* 0xF0 */ {{BEQ,REL }, {SBC,INDY}, ILL_OP,      ILL_OP, ILL_OP,     {SBC,ZPGX}, {INC,ZPGX}, ILL_OP, {SED,IMPL}, {SBC,ABSY}, ILL_OP,     ILL_OP, ILL_OP,     {SBC,ABSX}, {INC,ABSX}, ILL_OP},
};

#endif /* ISA_H */
