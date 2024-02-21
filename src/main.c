#include "../include/main.h"

s32 test(void) {
    return 1;
}

//if Z toggle pressed
    //NOP 8003D3B0
//else
    //E6000010 (SWC1 f0, 0x0010 (s0))

// void dma_copy(void* romAddr, void* ramAddr, u32 dmaSize) {
//     OSIoMesg sp50;
//     OSMesgQueue sp38;
//     OSMesg sp34;
    

//     osCreateMesgQueue(&sp38, &sp34, 1);
//     osInvalDCache(romAddr, dmaSize);
//     osInvalICache(romAddr, dmaSize);
//     osPiStartDma(&sp50, 0, 0, romAddr, ramAddr, dmaSize, &sp38);
//     osRecvMesg(&sp38, 0, 1);

// }