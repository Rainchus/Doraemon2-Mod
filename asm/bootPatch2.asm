.headersize 0x80025C00 - 0x1000
.org 0x80025C00

//0x30610

LUI t0, 0x800F
ADDIU t0, t0, 0x0A40
LUI t1, 0x0003
ADDIU t1, t1, 0x0610
loop:
SD r0, 0x0000 (t0)
ADDIU t1, t1, 0xFFF8
BNEZ t1, loop
ADDIU t0, t0, 0x0008

LUI sp, 0x8011
ADDIU sp, sp, 0x7720

//a0 happens to be zero here already
ADDU a0, r0, r0
LUI a1, 0x00C0 //0xC00000 rom addr
LUI a2, 0x8040 //0x80400000 ram addr
JAL osPiRawStartDma
LUI a3, 0x000C //dma 0.75 MB (update if more space needed, although savestate location would need adjustment)

//wait on our dma to finish before continuing
dmaBusyLoop:
LUI t0, 0xA460
LW t1, 0x0010 (t0)
ANDI t1, t1, 0x0001
BNEZ t1, dmaBusyLoop
NOP
//J 0x80025C50 //normally the code jumps to this addr, but it's right below
//NOP