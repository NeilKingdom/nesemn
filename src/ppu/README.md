# Ricoh 2C02

### References
- [NES Dev Wiki](https://www.nesdev.org/wiki/CPU)

### About

The Ricoh RP2C02 Picture Processing Unit (PPU) is a custom IC made for the NES.

---

### PPU Memory Map

| Address range | Size  | Device                                                                               |
|---------------|-------|--------------------------------------------------------------------------------------|
| $0000-$07FF   | $0800 | 2 KB internal RAM                                                                    |
| $0800-$0FFF   | $0800 |                                                                                      |
| $1000-$17FF   | $0800 | Mirrors of $0000-$07FF                                                               |
| $1800-$1FFF   | $0800 |                                                                                      |
| $2000-$2007   | $0008 | NES PPU registers                                                                    |
| $2008-$3FFF   | $1FF8 | Mirrors of $2000-$2007 (repeats every 8 bytes)                                       |
| $4000-$4017   | $0018 | NES APU and I/O registers                                                            |
| $4018-$401F   | $0008 | APU and I/O functionality that is normally disabled                                  |
| $4020-$FFFF   | $BFE0 | Unmapped. Available for cartridge use                                                |
| $6000-$7FFF   | $2000 | Usually cartridge RAM when present                                                   |
| $8000-$FFFF   | $8000 | Usually cartridge ROM and mapper registers                                           |

---

### Object Attribute Memory

The PPU contains some internal memory allocated as the Object Attribute Memory (OAM). This memory contains a
list of up to 64 objects A.K.A. sprites. Each sprite/object occupies 4 bytes of OAM.

##### Object Byte Structure

- Byte 0: Used as the y position of the top left corner of the sprite. You must subtract 1 from the y position
since the drawing of the sprite is delayed by 1 scanline. A sprite can be hidden offscreen by writing values
between $EF-$FF. Sprites cannot be placed partially off the top of the screen.
- Byte 1: The tile index number. For 8x8 sprites, the tile number is located at bit 3 of PPUCTRL ($2000). For
8x16 sprites (bit 5 of PPUCTRL is set), the PPU ignores the pattern table selection and selects a pattern
table from bit 0 of this number.

76543210
||||||||
|||||||+- Bank ($0000 or $1000) of tiles
+++++++-- Tile number of top of sprite (0 to 254; bottom half gets the next tile)

- Byte 2: Attributes.

76543210
||||||||
||||||++- Palette (4 to 7) of sprite
|||+++--- Unimplemented (read 0)
||+------ Priority (0: in front of background, 1: behind background)
|+------- Flip sprite horizontally
+-------- Flip sprite vertically

Flipping does not change the position of the sprite's bounding box, just the position of pixels withn the
sprite.

- Byte 3: Used as the x position of the top left corner of the sprite. To place a sprite offscreen, you can
write from values $F9-$FF. Sprites cannot be partially off the left side of the screen.
