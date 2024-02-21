#include "../include/main.h"

s32 LHeldFrameCounter = 0;
f32 yPosCopy = 0.0f;

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct PlayerData {
    char unk_00[0x0C];
    Vec3f pos;
} PlayerData;

typedef struct Player {
    char unk_00[0x18];
    PlayerData* playerData;
} Player;

extern u16 p1ButtonsHeld;
extern Player PlayerMain;

void LevitateHook(void) {
    if (p1ButtonsHeld & 0x2000) {
        if (LHeldFrameCounter == 0) {
            yPosCopy = PlayerMain.playerData->pos.y;
        }
        LHeldFrameCounter++;
        yPosCopy += 10.0f;
        PlayerMain.playerData->pos.y = yPosCopy;
    } else {
        LHeldFrameCounter = 0;
        yPosCopy = 0.0f;
    }
}

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