#ifndef PPU_REGISTERS_H
#define PPU_REGISTERS_H

#include "../common.h"

/*** Regsiter map ***/

#define REG_ADDR_PPUCTRL        0x2000
#define REG_ADDR_PPUMASK        0x2001
#define REG_ADDR_PPUSTATUS      0x2002
#define REG_ADDR_OAMADDR        0x2003
#define REG_ADDR_OAMDATA        0x2004
#define REG_ADDR_PPUSCROLL      0x2005
#define REG_ADDR_PPUADDR        0x2006
#define REG_ADDR_PPUDATA        0x2007
#define REG_ADDR_OAMDMA         0x4014

#endif /* PPU_REGISTERS_H */
