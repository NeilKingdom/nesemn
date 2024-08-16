# Ricoh 2A03

### References
- [NES Dev Wiki](https://www.nesdev.org/wiki/CPU)
- [W65C02S Datasheet](https://www.westerndesigncenter.com/wdc/documentation/w65c02s.pdf)
- [6502 ISA](https://www.masswerk.at/6502/6502_instruction_set.html)

### About

The Ricoh 2A03 A.K.A. RP2A03 (NTSC) or RP2A07 (PAL) is an offshoot of the 6502 microcontroller. It disables the
MOS6502's decimal mode. The 2A03/7 contains both the CPU and APU (audio processing unit). All illegal opcodes
on the 2A03/7 function identically as the 6502. Every cycle is either a read or write cycle. The 2A03/7 uses
the MOS 6502 ISA for instructions.

---

### CPU Memory Map

The 2A03/7 has a 16-bit address bus, meaning it can support 64K of memory with addresses ranging from
$0000-$FFFF. Memory locations $0000-$07FF are mirrored three times between $0800-$1FFF.

| Address range | Size  | Device                                         |
|---------------|-------|------------------------------------------------|
| $0000-$00FF   | $0100 | Zero page                                      |
| $0100-$01FF   | $0100 | Stack                                          |
| $0200-$07FF   | $0600 | RAM                                            |
| $0800-$0FFF   | $0800 |                                                |
| $1000-$17FF   | $0800 | Mirrors of $0000-$07FF                         |
| $1800-$1FFF   | $0800 |                                                |
| $2000-$2007   | $0008 | I/O registers                                  |
| $2008-$3FFF   | $1FF8 | Mirrors of $2000-$2007 (repeats every 8 bytes) |
| $4000-$401F   | $0020 | I/O regsiters                                  |
| $4020-$5FFF   | $1FE0 | Expansion ROM                                  |
| $6000-$7FFF   | $2000 | SRAM                                           |
| $8000-$BFFF   | $4000 | Usually cartridge RAM when present             |
| $C000-$FFFF   | $4000 | Usually cartridge ROM and mapper registers     |

---

### GPIO Registers

##### Program Counter (CP)

##### Stack Counter (SP)

The stack pointer is an 8-bit register located at memory locations $0100-$01FF. The stack grows downwards,
meaning push operations decrement SP, and pop operations increment it. SP wraps back to $0100 when it reaches
$01FF.

### APU

The APU has 5 channels:

| Address range | Channel               |
|---------------|-----------------------|
| $4000-$4003   | First pulse wave      |
| $4004-$4007   | Second pulse wave     |
| $4008-$400B   | Triangle wave         |
| $400C-$400F   | Noise                 |
| $4010-$4013   | DMC (sample playback) |

##### Pulse Wave Channels

A pulse wave i.e. square wave, is a digital wave form that approximates a sinusoidal wave. It produces a pure
tone when played through a speaker.

- D: Duty cycle
    - 00 = 12.5%
    - 01 = 25%
    - 10 = 50%
    - 11 = 75%
- V: Volume (0000 = silence, 1111 = maximum)
- L: Low bits of raw period
- H: High bits of raw period
- ?: Anything/garbage

| Pulse wave 1 addresses | Pulse wave 2 addresses | Byte arrangement |
|------------------------|------------------------|------------------|
| $4000                  | $4004                  | %DD11VVVV        |
| $4002                  | $4006                  | %LLLLLLLL        |
| $4003                  | $4007                  | %?????HHH        |

Writing to $4003 or $4007 resets the phase of the wave, which can lead to popping

### Initialization

When the NES is powered on or reset, the program should do the following within a fixed bank:

1. Set IRQ ignore bit
2. Disable PPU NMIs and rendering
3. Initialize stack pointer
4. Initialize the mapper (if any)
