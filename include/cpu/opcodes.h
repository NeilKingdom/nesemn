#ifndef OPCODES_H
#define OPCODES_H

#include "../common.h"

typedef enum {
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
} Mnemonic_t;

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
typedef enum {
    ILL = -1, /* Illegal */

    /* Indexed addressing */
    ZPGX,     /* Zeropage, x-indexed */
    ZPGY,     /* Zeropage, y-indexed */
    ABSX,     /* Absolute, x-indexed */
    ABSY,     /* Absolute, y-indexed */
    INDX,     /* Indirect, x-indexed */
    INDY,     /* Indirect, y-indexed */

    /* Other addressing */
    IMPL,     /* Implicit */
    ACCM,     /* Accumulator */
    IMDT,     /* Immediate */
    ZPG,      /* Zeropage */
    ABS,      /* Absolute */
    REL,      /* Relative */
    IND,      /* Indirect */
} AddrMode_t;

typedef void (*InstCallback_t)(AddrMode_t mode);

typedef struct {
    Mnemonic_t mnem;
    InstCallback_t cb;
} Instruction_t;

/* Instruction callbacks */

void adc_cb(AddrMode_t mode);
void and_cb(AddrMode_t mode);
void asl_cb(AddrMode_t mode);
void bcc_cb(AddrMode_t mode);
void bcs_cb(AddrMode_t mode);
void beq_cb(AddrMode_t mode);
void bit_cb(AddrMode_t mode);
void bmi_cb(AddrMode_t mode);
void bne_cb(AddrMode_t mode);
void bpl_cb(AddrMode_t mode);
void brk_cb(AddrMode_t mode);
void bvc_cb(AddrMode_t mode);
void bvs_cb(AddrMode_t mode);
void clc_cb(AddrMode_t mode);
void cld_cb(AddrMode_t mode);
void cli_cb(AddrMode_t mode);
void clv_cb(AddrMode_t mode);
void cmp_cb(AddrMode_t mode);
void cpx_cb(AddrMode_t mode);
void cpy_cb(AddrMode_t mode);
void dec_cb(AddrMode_t mode);
void dex_cb(AddrMode_t mode);
void dey_cb(AddrMode_t mode);
void eor_cb(AddrMode_t mode);
void inc_cb(AddrMode_t mode);
void inx_cb(AddrMode_t mode);
void iny_cb(AddrMode_t mode);
void jmp_cb(AddrMode_t mode);
void jsr_cb(AddrMode_t mode);
void lda_cb(AddrMode_t mode);
void ldx_cb(AddrMode_t mode);
void ldy_cb(AddrMode_t mode);
void lsr_cb(AddrMode_t mode);
void nop_cb(AddrMode_t mode);
void ora_cb(AddrMode_t mode);
void pha_cb(AddrMode_t mode);
void php_cb(AddrMode_t mode);
void pla_cb(AddrMode_t mode);
void plp_cb(AddrMode_t mode);
void rol_cb(AddrMode_t mode);
void ror_cb(AddrMode_t mode);
void rti_cb(AddrMode_t mode);
void rts_cb(AddrMode_t mode);
void sbc_cb(AddrMode_t mode);
void sec_cb(AddrMode_t mode);
void sed_cb(AddrMode_t mode);
void sei_cb(AddrMode_t mode);
void sta_cb(AddrMode_t mode);
void stx_cb(AddrMode_t mode);
void sty_cb(AddrMode_t mode);
void tax_cb(AddrMode_t mode);
void tay_cb(AddrMode_t mode);
void tsx_cb(AddrMode_t mode);
void txa_cb(AddrMode_t mode);
void txs_cb(AddrMode_t mode);
void tya_cb(AddrMode_t mode);

/* Instructions */

static const Instruction_t _adc = { .mnem = ADC, .cb = adc_cb };
static const Instruction_t _and = { .mnem = AND, .cb = and_cb };
static const Instruction_t _asl = { .mnem = ASL, .cb = and_cb };
static const Instruction_t _bcc = { .mnem = BCC, .cb = bcc_cb };
static const Instruction_t _bcs = { .mnem = BCS, .cb = bcs_cb };
static const Instruction_t _beq = { .mnem = BEQ, .cb = beq_cb };
static const Instruction_t _bit = { .mnem = BIT, .cb = bit_cb };
static const Instruction_t _bmi = { .mnem = BMI, .cb = bmi_cb };
static const Instruction_t _bne = { .mnem = BNE, .cb = bne_cb };
static const Instruction_t _bpl = { .mnem = BPL, .cb = bpl_cb };
static const Instruction_t _brk = { .mnem = BRK, .cb = brk_cb };
static const Instruction_t _bvc = { .mnem = BVC, .cb = bvc_cb };
static const Instruction_t _bvs = { .mnem = BVS, .cb = bvs_cb };
static const Instruction_t _clc = { .mnem = CLC, .cb = clc_cb };
static const Instruction_t _cld = { .mnem = CLD, .cb = cld_cb };
static const Instruction_t _cli = { .mnem = CLI, .cb = cli_cb };
static const Instruction_t _clv = { .mnem = CLV, .cb = clv_cb };
static const Instruction_t _cmp = { .mnem = CMP, .cb = cmp_cb };
static const Instruction_t _cpx = { .mnem = CPX, .cb = cpx_cb };
static const Instruction_t _cpy = { .mnem = CPY, .cb = cpy_cb };
static const Instruction_t _dec = { .mnem = DEC, .cb = dec_cb };
static const Instruction_t _dex = { .mnem = DEX, .cb = dex_cb };
static const Instruction_t _dey = { .mnem = DEY, .cb = dey_cb };
static const Instruction_t _eor = { .mnem = EOR, .cb = eor_cb };
static const Instruction_t _inc = { .mnem = INC, .cb = inc_cb };
static const Instruction_t _inx = { .mnem = INX, .cb = inx_cb };
static const Instruction_t _iny = { .mnem = INY, .cb = iny_cb };
static const Instruction_t _jmp = { .mnem = JMP, .cb = jmp_cb };
static const Instruction_t _jsr = { .mnem = JSR, .cb = jsr_cb };
static const Instruction_t _lda = { .mnem = LDA, .cb = lda_cb };
static const Instruction_t _ldx = { .mnem = LDX, .cb = ldx_cb };
static const Instruction_t _ldy = { .mnem = LDY, .cb = ldy_cb };
static const Instruction_t _lsr = { .mnem = LSR, .cb = lsr_cb };
static const Instruction_t _nop = { .mnem = NOP, .cb = nop_cb };
static const Instruction_t _ora = { .mnem = ORA, .cb = ora_cb };
static const Instruction_t _pha = { .mnem = PHA, .cb = pha_cb };
static const Instruction_t _php = { .mnem = PHP, .cb = php_cb };
static const Instruction_t _pla = { .mnem = PLA, .cb = pla_cb };
static const Instruction_t _plp = { .mnem = PLP, .cb = plp_cb };
static const Instruction_t _rol = { .mnem = ROL, .cb = rol_cb };
static const Instruction_t _ror = { .mnem = ROR, .cb = ror_cb };
static const Instruction_t _rti = { .mnem = RTI, .cb = rti_cb };
static const Instruction_t _rts = { .mnem = RTS, .cb = rts_cb };
static const Instruction_t _sbc = { .mnem = SBC, .cb = sbc_cb };
static const Instruction_t _sec = { .mnem = SEC, .cb = sec_cb };
static const Instruction_t _sed = { .mnem = SED, .cb = sed_cb };
static const Instruction_t _sei = { .mnem = SEI, .cb = sei_cb };
static const Instruction_t _sta = { .mnem = STA, .cb = sta_cb };
static const Instruction_t _stx = { .mnem = STX, .cb = stx_cb };
static const Instruction_t _sty = { .mnem = STY, .cb = sty_cb };
static const Instruction_t _tax = { .mnem = TAX, .cb = tax_cb };
static const Instruction_t _tay = { .mnem = TAY, .cb = tay_cb };
static const Instruction_t _tsx = { .mnem = TSX, .cb = tsx_cb };
static const Instruction_t _txa = { .mnem = TXA, .cb = txa_cb };
static const Instruction_t _txs = { .mnem = TXS, .cb = txs_cb };
static const Instruction_t _tya = { .mnem = TYA, .cb = tya_cb };

/* Opcode struct */
typedef struct {
    Instruction_t inst;
    AddrMode_t mode;
} OpCode_t;

#define ILL_OP ((OpCode_t){ .inst = _nop, .mode = ILL })

static OpCode_t isa_table[16][16] = {
/* 0x00 */
    {
        {_brk,IMPL}, {_ora,IND},  ILL_OP,      ILL_OP,      ILL_OP,      {_ora,ZPG}, {_asl,ZPG}, ILL_OP,
        {_php,IMPL}, {_ora,IMDT}, {_asl,ACCM}, ILL_OP,      ILL_OP,      {_ora,ABS}, {_asl,ABS}, ILL_OP,
    },
/* 0x01 */
    {
    },
};

/* Forward function declarations */

void cpu_op_exec(uint16_t addr);

#endif /* OPCODES_H */
