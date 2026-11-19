/* Pizza Connection 2 - typed state structs (skeleton)
 * Generated from class_skeletons.json + state_model.json.
 * Fields are placed at exact observed offsets; padding is explicit.
 * Names are structural (field_0xNN); comments carry save order and
 * observing functions. This is an analysis skeleton, not original source.
 */
#ifndef PIZZA2_GAME_STRUCTS_H
#define PIZZA2_GAME_STRUCTS_H

#include <stdint.h>

#pragma pack(push, 1)

/* Game - 194704 bytes, vtable 0x55c5d0 */
typedef struct Game {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: Game_InitDateState; observed-only */
    uint32_t field_0x8;  /* obs: Game_InitDateState; observed-only */
    uint32_t field_0xc;  /* obs: Game_Construct, Game_Destroy, Game_InitDateState; observed-only */
    uint32_t field_0x10;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x14;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x18;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x1c;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x20;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x24[13];
    uint16_t field_0x31;  /* obs: Game_InitDateState; observed-only */
    uint8_t field_0x33;  /* obs: Game_InitDateState; observed-only */
    uint32_t field_0x34;  /* obs: Game_InitStatBaselines; observed-only */
    uint8_t pad_0x38[52];
    uint32_t field_0x6c;  /* obs: Game_ResetBuildingUtilization; observed-only */
    uint8_t pad_0x70[32];
    uint32_t field_0x90;  /* obs: Game_InitScenario, Game_LoadSaveGame; observed-only */
    uint64_t field_0x94;  /* obs: Game_LoadSaveGame; observed-only */
    uint32_t field_0x9c;  /* obs: Game_LoadSaveGame; observed-only */
    uint8_t pad_0xa0[8];
    uint32_t field_0xa8;  /* obs: Game_ResetBuildingUtilization; observed-only */
    uint8_t pad_0xac[20];
    uint32_t field_0xc0;  /* obs: Game_InitDateState; observed-only */
    uint8_t pad_0xc4[2];
    uint8_t field_0xc6;  /* obs: Game_InitDateState; observed-only */
    uint8_t pad_0xc7[1];
    uint32_t field_0xc8;  /* obs: Game_InitDateState; observed-only */
    uint8_t pad_0xcc[4];
    uint32_t field_0xd0;  /* obs: Game_InitDateState; observed-only */
    uint32_t field_0xd4;  /* obs: Game_InitDateState; observed-only */
    uint8_t pad_0xd8[76];
    uint32_t field_0x124;  /* obs: Game_ResetRecordTurnCounters; observed-only */
    uint8_t pad_0x128[164];
    uint32_t field_0x1cc;  /* obs: Game_ResetBuildingUtilization; observed-only */
    uint8_t pad_0x1d0[48];
    uint32_t field_0x200;  /* obs: Game_InitScenario; observed-only */
    uint8_t pad_0x204[32];
    uint32_t field_0x224;  /* obs: Game_InitScenario, Game_LoadSaveGame; observed-only */
    uint8_t pad_0x228[24];
    uint32_t field_0x240;  /* obs: Game_InitScenario, Game_LoadBackgroundImage, Game_ResetStats; observed-only */
    uint32_t field_0x244;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x248;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x24c;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x250;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x254;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x258;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x25c;  /* obs: Game_ResetStats; observed-only */
    uint32_t field_0x260;  /* obs: Game_ResetStats; observed-only */
    uint8_t pad_0x264[52];
    uint8_t field_0x298[32];  /* save#0; bytes[32]; obs: Game_LoadSaveGame */
    uint8_t field_0x2b8[32];  /* save#1; bytes[32]; obs: Game_LoadSaveGame */
    uint32_t field_0x2d8;  /* save#2; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x2dc;  /* save#3; u32/i32/float; obs: Game_LoadSaveGame */
    uint8_t pad_0x2e0[8];
    uint32_t field_0x2e8;  /* save#7; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x2ec;  /* save#4; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x2f0;  /* save#5; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x2f4;  /* save#6; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x2f8;  /* save#8; u32/i32/float; obs: Game_LoadSaveGame */
    uint8_t pad_0x2fc[4];
    uint32_t field_0x300;  /* obs: Game_LoadBackgroundImage; observed-only */
    uint8_t pad_0x304[56];
    uint32_t field_0x33c;  /* save#9; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x340;  /* save#15; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x344;  /* save#13; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x348;  /* save#10; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x34c;  /* save#11; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x350;  /* save#12; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x354;  /* save#14; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x358;  /* save#19; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x35c;  /* save#20; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x360;  /* save#18; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x364;  /* save#16; u32/i32/float; obs: Game_LoadSaveGame */
    uint32_t field_0x368;  /* save#17; u32/i32/float; obs: Game_LoadSaveGame */
    uint8_t pad_0x36c[1200];
    uint32_t field_0x81c;  /* obs: Game_ResetPlayerStatsByCity; observed-only */
    uint32_t field_0x820;  /* obs: Game_ResetPlayerStatsByCity; observed-only */
    uint8_t pad_0x824[2340];
    uint32_t field_0x1148;  /* obs: Game_InitCompanyAIStrategy; observed-only */
    uint32_t field_0x114c;  /* obs: Game_InitCompanyAIStrategy; observed-only */
    uint32_t field_0x1150;  /* obs: Game_InitCompanyAIStrategy; observed-only */
    uint32_t field_0x1154;  /* obs: Game_InitCompanyAIStrategy; observed-only */
    uint8_t pad_0x1158[896];
    uint32_t field_0x14d8;  /* obs: Game_InitStatBaselines; observed-only */
    uint8_t pad_0x14dc[912];
    uint32_t field_0x186c;  /* obs: Game_InitStatBaselines; observed-only */
    uint8_t pad_0x1870[5408];
    uint32_t field_0x2d90;  /* save#21; u32/i32/float; obs: Game_LoadSaveGame */
    uint8_t pad_0x2d94[144];
    uint32_t field_0x2e24;  /* obs: Game_LoadSaveGame; observed-only */
    uint8_t pad_0x2e28[168220];
    uint32_t field_0x2bf44;  /* obs: Game_Construct; observed-only */
    uint8_t field_0x2bf48;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bf49[3];
    uint32_t field_0x2bf4c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf50;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf54;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf58;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf5c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf60;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf64;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf68;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bf6c[8];
    uint32_t field_0x2bf74;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf78;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf7c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf80;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf84;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf88;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bf8c[4];
    uint32_t field_0x2bf90;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf94;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf98;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bf9c;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bfa0[4];
    uint32_t field_0x2bfa4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfa8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfac;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bfb0[16];
    uint32_t field_0x2bfc0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfc4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfc8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfcc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfd0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfd4;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bfd8[8];
    uint32_t field_0x2bfe0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfe4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfe8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2bfec;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2bff0[28];
    uint32_t field_0x2c00c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c010;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c014;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c018;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c01c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c020;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c024;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c028;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c02c[28];
    uint32_t field_0x2c048;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c04c[4];
    uint32_t field_0x2c050;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c054;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c058;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c05c;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c060[64];
    uint32_t field_0x2c0a0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0a4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0a8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0ac;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c0b0[28];
    uint32_t field_0x2c0cc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0d0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0d4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0d8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0dc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0e0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0e4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0e8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0ec;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0f0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0f4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0f8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c0fc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c100;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c104;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c108;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c10c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c110;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c114;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c118;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c11c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c120;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c124;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c128;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c12c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c130;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c134;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c138;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c13c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c140;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c144;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c148;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c14c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c150;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c154;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c158;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c15c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c160;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c164;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c168;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c16c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c170;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c174;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c178;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c17c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c180;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c184;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c188;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c18c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c190;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c194;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c198;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c19c;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c1a0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1a4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1a8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1ac;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1b0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1b4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c1b8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1bc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1c0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1c4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1c8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1cc;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c1d0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1d4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1d8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1dc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1e0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1e4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c1e8;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c1ec;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1f0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1f4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1f8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c1fc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c200;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c204;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c208;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c20c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c210;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c214;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c218;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c21c;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c220;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c224;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c228;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c22c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c230;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c234;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c238;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c23c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c240;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c244;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c248;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c24c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c250;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c254[8];
    uint32_t field_0x2c25c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c260;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c264[4];
    uint32_t field_0x2c268;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c26c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c270;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c274[4];
    uint32_t field_0x2c278;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c27c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c280;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c284;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c288[4];
    uint32_t field_0x2c28c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c290;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c294;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c298[4];
    uint32_t field_0x2c29c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2a0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2a4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2a8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2ac;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2b0;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2b4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2b8;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c2bc[56];
    uint32_t field_0x2c2f4;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2f8;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c2fc;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c300;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c304;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c308;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c30c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c310;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c314[28];
    uint32_t field_0x2c330;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c334[4];
    uint32_t field_0x2c338;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c33c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c340;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2c344;  /* obs: Game_Construct; observed-only */
    uint8_t pad_0x2c348[108];
    uint32_t field_0x2c3b4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3b8;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3bc;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3c0;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3c4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3c8;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3cc;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3d0;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3d4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3d8;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3dc;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3e0;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3e4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3e8;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3ec;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3f0;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c3f4;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint8_t pad_0x2c3f8[28];
    uint32_t field_0x2c414;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint32_t field_0x2c418;  /* obs: Game_Construct, Game_Destroy; observed-only */
    uint8_t pad_0x2c41c[13408];
    uint32_t field_0x2f87c;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2f880;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2f884;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2f888;  /* obs: Game_Construct; observed-only */
    uint32_t field_0x2f88c;  /* obs: Game_Construct; observed-only */
} Game;

/* GameWorld - 11804 bytes, vtable 0x55c44c */
typedef struct GameWorld {
    uint8_t pad_0x0[136];
    uint32_t field_0x88;  /* obs: GameState_Destruct; observed-only */
    uint8_t pad_0x8c[4];
    uint32_t field_0x90;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x94;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x98;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x9c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0xa0;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint8_t field_0xa4;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint8_t field_0xa5;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0xa6[370];
    uint32_t field_0x218;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x21c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x220;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x224[24];
    uint32_t field_0x23c;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x240;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x244;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x248;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x24c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x250;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x254;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x258;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x25c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x260;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x264;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x268;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x26c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x270;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x274;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x278;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x27c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x280;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x284;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x288[8];
    uint32_t field_0x290;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint8_t pad_0x294[8];
    uint32_t field_0x29c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2a0;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2a4;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2a8;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2ac;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2b0;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2b4;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x2b8[32];
    uint32_t field_0x2d8;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2dc;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2e0;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2e4;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2e8;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2ec;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2f0;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2f4;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2f8;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2fc;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x300;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x304[56];
    uint32_t field_0x33c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x340;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x344;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x348;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x34c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x350;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x354;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x358;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x35c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x360;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x364;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x368;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x36c[24];
    uint32_t field_0x384;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x388[2013];
    uint8_t field_0xb65;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0xb66[2466];
    uint32_t field_0x1508;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x150c;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x1510[6144];
    uint32_t field_0x2d10;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2d14;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2d18;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x2d1c[112];
    uint32_t field_0x2d8c;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2d90;  /* obs: GameSession_Construct; observed-only */
    uint8_t pad_0x2d94[4];
    uint32_t field_0x2d98;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2d9c;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint32_t field_0x2da0;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2da4;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2da8;  /* obs: GameSession_Construct; observed-only */
    uint32_t field_0x2dac;  /* obs: GameSession_Construct, GameState_Destruct; observed-only */
    uint8_t pad_0x2db0[104];
    uint32_t field_0x2e18;  /* obs: GameSession_Construct; observed-only */
} GameWorld;

/* Company - 496 bytes, vtable 0x55c568 */
typedef struct Company {
    uint8_t pad_0x0[8];
    uint8_t field_0x8[64];  /* save#0; bytes[64]; obs: Company_Load */
    uint32_t field_0x48;  /* save#1; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x4c;  /* save#2; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x50;  /* save#4; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x54;  /* save#5; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x58;  /* save#23; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint16_t field_0x5c;  /* save#3; u16; obs: Company_ConstructDefault, Company_Load */
    uint8_t pad_0x5e[2];
    uint32_t field_0x60;  /* save#22; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x64;  /* save#10; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x68;  /* save#11; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x6c;  /* save#12; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint8_t field_0x70[36];  /* save#13; bytes[36]; obs: Company_Load */
    uint8_t field_0x94[24];  /* save#14; bytes[24]; obs: Company_Load */
    uint32_t field_0xac;  /* save#15; bytes[6]; obs: Company_ConstructDefault, Company_Load */
    uint16_t field_0xb0;  /* obs: Company_ConstructDefault; observed-only */
    uint8_t pad_0xb2[2];
    uint8_t field_0xb4[24];  /* save#17; bytes[24]; obs: Company_Load */
    uint8_t field_0xcc[24];  /* save#16; bytes[24]; obs: Company_Load */
    uint32_t field_0xe4;  /* save#21; bytes[10]; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0xe8;  /* obs: Company_ConstructDefault; observed-only */
    uint16_t field_0xec;  /* obs: Company_ConstructDefault; observed-only */
    uint8_t pad_0xee[2];
    uint32_t field_0xf0;  /* save#18; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0xf4;  /* save#19; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0xf8;  /* save#20; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0xfc;  /* save#25; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x100;  /* save#26; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint8_t pad_0x104[4];
    uint32_t field_0x108;  /* save#7; u64/double; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x10c;  /* obs: Company_ConstructDefault; observed-only */
    uint8_t pad_0x110[20];
    uint32_t field_0x124;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x128[52];
    uint32_t field_0x15c;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x160[24];
    uint32_t field_0x178;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x17c[24];
    uint32_t field_0x194;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x198[24];
    uint32_t field_0x1b0;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x1b4[24];
    uint32_t field_0x1cc;  /* obs: Company_Destroy; observed-only */
    uint8_t pad_0x1d0[4];
    uint32_t field_0x1d4;  /* obs: Company_ConstructDefault, Company_Destroy, Company_Load; observed-only */
    uint32_t field_0x1d8;  /* obs: Company_ConstructDefault, Company_Load; observed-only */
    uint32_t field_0x1dc;  /* save#6; u32/i32/float; obs: Company_Load */
    uint32_t field_0x1e0;  /* save#9; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x1e4;  /* save#8; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint32_t field_0x1e8;  /* save#24; u32/i32/float; obs: Company_ConstructDefault, Company_Load */
    uint8_t pad_0x1ec[4];
} Company;

/* Branch - 6716 bytes, vtable 0x55c30c */
typedef struct Branch {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[32];  /* save#0; bytes[32]; obs: Branch_Load, Branch_Save */
    uint32_t field_0x24;  /* save#2; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x28;  /* save#3; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x2c;  /* save#1; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x30;  /* save#4; u32/i32/float; obs: Branch_Construct, Branch_InitCityObjects, Branch_Load */
    uint32_t field_0x34;  /* save#5; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x38;  /* save#54; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x3c;  /* save#6; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x40;  /* save#7; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x44[324];  /* save#8; bytes[324]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x188[324];  /* save#9; bytes[324]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x2cc[324];  /* save#12; bytes[324]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x410[324];  /* save#13; bytes[324]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x554[3600];  /* save#10; bytes[3600]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x1364[36];  /* save#11; bytes[36]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x1388[72];  /* save#14; bytes[72]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x13d0[72];  /* save#15; bytes[72]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x1418[72];  /* save#16; bytes[72]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x1460[72];  /* save#17; bytes[72]; obs: Branch_Load, Branch_Save */
    uint32_t field_0x14a8;  /* save#18; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14ac;  /* save#19; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14b0;  /* save#28; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14b4;  /* save#63; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14b8;  /* save#72; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14bc;  /* save#73; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14c0;  /* save#24; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14c4;  /* obs: Branch_Construct, Branch_Load; observed-only */
    uint32_t field_0x14c8;  /* save#20; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14cc;  /* save#21; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14d0;  /* save#22; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14d4;  /* save#23; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14d8;  /* save#25; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x14dc;  /* obs: Branch_Construct, Branch_Load, Branch_Save; observed-only */
    uint32_t field_0x14e0;  /* obs: Branch_Construct, Branch_Destroy, Branch_InitCityObjects; observed-only */
    uint8_t pad_0x14e4[20];
    uint32_t field_0x14f8;  /* obs: Branch_Destroy, Branch_Save; observed-only */
    uint8_t pad_0x14fc[24];
    uint32_t field_0x1514;  /* obs: Branch_Load, Branch_Save; observed-only */
    uint8_t pad_0x1518[4];
    uint8_t field_0x151c[416];  /* save#34; bytes[416]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x16bc[52];  /* save#35; bytes[52]; obs: Branch_Load, Branch_Save */
    uint32_t field_0x16f0;  /* obs: Branch_Construct, Branch_Destroy, Branch_InitCityObjects; observed-only */
    uint8_t field_0x16f4;  /* save#27; u8/bool; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x16f5;  /* save#26; u8/bool; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t pad_0x16f6[22];
    uint32_t field_0x170c;  /* obs: Branch_Destroy, Branch_Save; observed-only */
    uint8_t pad_0x1710[4];
    uint32_t field_0x1714;  /* save#29; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1718;  /* save#30; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x171c;  /* save#31; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1720;  /* save#32; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1724;  /* save#33; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t pad_0x1728[20];
    uint32_t field_0x173c;  /* obs: Branch_Save; observed-only */
    uint8_t pad_0x1740[24];
    uint32_t field_0x1758;  /* obs: Branch_Save; observed-only */
    uint8_t pad_0x175c[24];
    uint32_t field_0x1774;  /* obs: Branch_Save; observed-only */
    uint8_t pad_0x1778[4];
    uint8_t field_0x177c[32];  /* save#36; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x179c[32];  /* save#37; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x17bc[32];  /* save#38; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x17dc[32];  /* save#39; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x17fc[32];  /* save#40; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x181c[32];  /* save#41; bytes[32]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x183c[20];  /* save#42; bytes[20]; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1850;  /* save#43; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1854;  /* save#44; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1858;  /* save#45; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x185c;  /* save#46; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1860;  /* save#47; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1864;  /* save#48; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1868;  /* save#49; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x186c;  /* save#50; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1870;  /* save#51; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1874;  /* save#52; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x1878;  /* save#53; u32/i32/float; obs: Branch_Load, Branch_Save */
    uint32_t field_0x187c;  /* save#57; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x1880;  /* save#61; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x1881;  /* obs: Branch_Construct; observed-only */
    uint8_t field_0x1882;  /* obs: Branch_Construct; observed-only */
    uint8_t field_0x1883;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x1884;  /* save#66; bytes[16]; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1888;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x188c;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x1890;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x1894;  /* save#74; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x1898[64];  /* save#55; bytes[64]; obs: Branch_Load, Branch_Save */
    uint8_t field_0x18d8[192];  /* save#56; bytes[192]; obs: Branch_Load, Branch_Save */
    uint8_t pad_0x1998[20];
    uint32_t field_0x19ac;  /* obs: Branch_Destroy, Branch_Save; observed-only */
    uint8_t pad_0x19b0[4];
    uint32_t field_0x19b4;  /* save#62; bytes[16]; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x19b8;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x19bc;  /* obs: Branch_Construct; observed-only */
    uint32_t field_0x19c0;  /* obs: Branch_Construct; observed-only */
    uint8_t pad_0x19c4[20];
    uint32_t field_0x19d8;  /* obs: Branch_Destroy, Branch_Save; observed-only */
    uint8_t pad_0x19dc[24];
    uint32_t field_0x19f4;  /* obs: Branch_Save; observed-only */
    uint8_t pad_0x19f8[4];
    uint32_t field_0x19fc;  /* save#58; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a00;  /* save#59; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a04;  /* save#60; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t pad_0x1a08[24];
    uint8_t field_0x1a20;  /* save#64; u8/bool; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t field_0x1a21;  /* save#65; u8/bool; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint8_t pad_0x1a22[2];
    uint32_t field_0x1a24;  /* save#71; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a28;  /* obs: Branch_Construct, Branch_ConstructFromStream; observed-only */
    uint32_t field_0x1a2c;  /* save#67; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a30;  /* save#68; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a34;  /* save#69; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
    uint32_t field_0x1a38;  /* save#70; u32/i32/float; obs: Branch_Construct, Branch_Load, Branch_Save */
} Branch;

/* Player - 176 bytes, vtable 0x55c684 */
typedef struct Player {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: Player_Destroy, Player_Load, Player_Save; observed-only */
    uint32_t field_0x8;  /* save#2; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint8_t field_0xc[32];  /* save#3; bytes[32]; obs: Player_Load, Player_Save */
    uint32_t field_0x2c;  /* save#4; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x30;  /* save#5; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x34;  /* save#19; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x38;  /* save#20; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x3c;  /* save#6; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x40;  /* save#7; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x44;  /* save#8; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x48;  /* save#9; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x4c;  /* save#10; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x50;  /* save#11; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x54;  /* save#12; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x58;  /* save#13; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x5c;  /* save#14; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x60;  /* save#15; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x64;  /* save#16; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint32_t field_0x68;  /* save#17; u32/i32/float; obs: Player_Construct, Player_Load, Player_Save */
    uint8_t field_0x6c[24];  /* save#18; bytes[24]; obs: Player_Load, Player_Save */
    uint32_t field_0x84;  /* save#0; u32/i32/float; obs: Player_Construct, Player_Load, Player_ResetAiState */
    uint32_t field_0x88;  /* save#1; u32/i32/float; obs: Player_Construct, Player_Load, Player_ResetAiState */
    uint8_t pad_0x8c[20];
    uint32_t field_0xa0;  /* obs: Player_Destroy, Player_Save; observed-only */
    uint8_t pad_0xa4[4];
    uint32_t field_0xa8;  /* obs: Player_Construct, Player_Destroy, Player_Load; observed-only */
    uint32_t field_0xac;  /* obs: Player_Construct, Player_Destroy, Player_InitSlotFlags; observed-only */
} Player;

/* PlayerAIState - 592 bytes, vtable 0x55c664 */
typedef struct PlayerAIState {
    uint8_t pad_0x0[4];
    uint8_t field_0x4;  /* save#0; u8/bool; obs: Player_AIState_Load, Player_AIState_Save */
    uint8_t pad_0x5[3];
    uint32_t field_0x8;  /* save#13; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint8_t field_0xc[52];  /* save#1; bytes[52]; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x40;  /* save#3; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x44;  /* save#2; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x48;  /* save#4; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x4c;  /* save#5; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x50;  /* save#6; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x54;  /* save#7; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x58;  /* save#8; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0x5c;  /* save#9; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save, Player_AIState_StreamConstruct */
    uint8_t field_0x60;  /* save#10; u8/bool; obs: Player_AIState_Load, Player_AIState_Save */
    uint8_t pad_0x61[3];
    uint32_t field_0x64;  /* save#11; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint8_t pad_0x68[20];
    uint64_t field_0x7c;  /* obs: Player_AIState_Save; observed-only */
    uint32_t field_0x84;  /* save#12; u32/i32/float; obs: Player_AIState_Load, Player_AIState_Save */
    uint8_t field_0x88[32];  /* save#14; bytes[228]; obs: Player_AIState_Load, Player_AIState_Save */
    uint32_t field_0xa8;  /* obs: Player_AIState_Init; observed-only */
    uint32_t field_0xac;  /* obs: Player_AIState_Init; observed-only */
    uint8_t pad_0xb0[188];
    uint8_t field_0x16c[228];  /* save#15; bytes[228]; obs: Player_AIState_Load, Player_AIState_Save */
} PlayerAIState;

/* PlayerMissionState - 216 bytes, vtable 0x55c5e8 */
typedef struct PlayerMissionState {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[12];  /* save#0; bytes[12]; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint8_t field_0x10[176];  /* save#1; bytes[176]; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint32_t field_0xc0;  /* save#2; u32/i32/float; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint8_t field_0xc4[3];  /* save#3; bytes[3]; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint8_t pad_0xc7[1];
    uint32_t field_0xc8;  /* save#4; u32/i32/float; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint8_t field_0xcc;  /* save#5; u8/bool; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint8_t pad_0xcd[3];
    uint32_t field_0xd0;  /* save#6; u32/i32/float; obs: Player_MissionState_Load, Player_MissionState_Save */
    uint32_t field_0xd4;  /* save#7; u32/i32/float; obs: Player_MissionState_Load, Player_MissionState_Save */
} PlayerMissionState;

/* Player_Event - 12 bytes, vtable 0x55c660 */
typedef struct Player_Event {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* save#0; u32/i32/float; obs: Player_Event_Load, Player_Event_Save */
    uint16_t field_0x8;  /* save#1; u16; obs: Player_Event_Load, Player_Event_Save, Player_Event_StreamConstruct */
    uint8_t pad_0xa[2];
} Player_Event;

/* City - 4440 bytes, vtable 0x55c500 */
typedef struct City {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[16];  /* save#3; bytes[24]; serialized-only */
    uint32_t field_0x14;  /* obs: City_InitOfferSlots; observed-only */
    uint8_t pad_0x18[4];
    uint32_t field_0x1c;  /* obs: City_InitBuildings; observed-only */
    uint32_t field_0x20;  /* obs: City_InitBuildings; observed-only */
    uint32_t field_0x24;  /* obs: City_InitBuildings; observed-only */
    uint32_t field_0x28;  /* obs: City_InitBuildings; observed-only */
    uint8_t pad_0x2c[24];
    uint32_t field_0x44;  /* save#1; u32/i32/float; serialized-only */
    uint32_t field_0x48;  /* obs: City_InitPopulation; observed-only */
    uint8_t pad_0x4c[3024];
    uint32_t field_0xc1c;  /* save#0; u32/i32/float; obs: City_InitPopulation */
    uint8_t field_0xc20[24];  /* save#2; bytes[24]; serialized-only */
    uint8_t field_0xc38[96];  /* save#6; bytes[96]; serialized-only */
    uint8_t field_0xc98[24];  /* save#7; bytes[24]; serialized-only */
    uint8_t field_0xcb0[24];  /* save#13; bytes[24]; serialized-only */
    uint8_t field_0xcc8[24];  /* save#8; bytes[24]; serialized-only */
    uint8_t field_0xce0[96];  /* save#12; bytes[96]; serialized-only */
    uint8_t field_0xd40[24];  /* save#9; bytes[24]; serialized-only */
    uint8_t field_0xd58[48];  /* save#10; bytes[48]; serialized-only */
    uint8_t field_0xd88[36];  /* save#11; bytes[36]; serialized-only */
    uint8_t pad_0xdac[24];
    uint32_t field_0xdc4;  /* save#4; u32/i32/float; obs: City_ConstructFromName */
    uint8_t field_0xdc8[480];  /* save#5; bytes[480]; serialized-only */
    uint32_t field_0xfa8;  /* obs: City_ConstructFromName, City_Destroy, City_InitBuildings; observed-only */
    uint8_t pad_0xfac[20];
    uint32_t field_0xfc0;  /* obs: City_Destroy, City_InitPopulation; observed-only */
    uint8_t pad_0xfc4[24];
    uint32_t field_0xfdc;  /* obs: City_Destroy; observed-only */
    uint8_t pad_0xfe0[4];
    uint8_t field_0xfe4[192];  /* save#14; bytes[192]; serialized-only */
    uint32_t field_0x10a4;  /* save#29; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10a8;  /* obs: City_Destroy; observed-only */
    uint32_t field_0x10ac;  /* save#15; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10b0;  /* save#16; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10b4;  /* save#17; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10b8;  /* save#18; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10bc;  /* save#22; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10c0;  /* save#21; u32/i32/float; serialized-only */
    uint32_t field_0x10c4;  /* save#19; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10c8;  /* save#24; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x10cc;  /* save#23; u32/i32/float; obs: City_ConstructFromName */
    uint8_t field_0x10d0[120];  /* save#20; bytes[120]; serialized-only */
    uint32_t field_0x1148;  /* save#25; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x114c;  /* save#26; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x1150;  /* save#27; u32/i32/float; obs: City_ConstructFromName */
    uint32_t field_0x1154;  /* save#28; u32/i32/float; obs: City_ConstructFromName */
} City;

/* IsoMap - 65912 bytes, vtable 0x55c5d4 */
typedef struct IsoMap {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy; observed-only */
    uint32_t field_0x8;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy; observed-only */
    uint32_t field_0xc;  /* save#0; u32/i32/float; obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save */
    uint32_t field_0x10;  /* save#1; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x14;  /* save#2; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x18;  /* save#3; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x1c;  /* save#4; u32/i32/float; obs: IsoMap_Destroy, IsoMap_Save */
    uint32_t field_0x20;  /* save#5; u32/i32/float; obs: IsoMap_Destroy, IsoMap_Save */
    uint32_t field_0x24;  /* save#6; u32/i32/float; obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save */
    uint32_t field_0x28;  /* save#7; u32/i32/float; obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Save */
    uint32_t field_0x2c;  /* save#8; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x30;  /* save#9; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x34;  /* save#10; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x38;  /* save#11; u32/i32/float; obs: IsoMap_Save */
    uint8_t field_0x3c[16];  /* save#12; bytes[16]; obs: IsoMap_Save */
    uint32_t field_0x4c;  /* save#21; u32/i32/float; obs: IsoMap_Destroy, IsoMap_Load, IsoMap_Save */
    uint32_t field_0x50;  /* obs: IsoMap_Destroy; observed-only */
    uint32_t field_0x54;  /* obs: IsoMap_Destroy; observed-only */
    uint8_t pad_0x58[8];
    uint32_t field_0x60;  /* save#13; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x64;  /* obs: IsoMap_Destroy; observed-only */
    uint8_t pad_0x68[4];
    uint32_t field_0x6c;  /* save#14; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0x70;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy; observed-only */
    uint32_t field_0x74;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy; observed-only */
    uint32_t field_0x78;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream, IsoMap_Destroy; observed-only */
    uint8_t field_0x7c[30];  /* save#15; bytes[30]; obs: IsoMap_Load, IsoMap_Save */
    uint8_t pad_0x9a[2];
    uint32_t field_0x9c;  /* save#19; u8/bool; obs: IsoMap_Destroy, IsoMap_Save */
    uint32_t field_0xa0;  /* save#20; u8/bool; obs: IsoMap_Destroy, IsoMap_Save */
    uint8_t pad_0xa4[4];
    uint32_t field_0xa8;  /* save#18; u32/i32/float; obs: IsoMap_Save */
    uint8_t pad_0xac[4];
    uint32_t field_0xb0;  /* obs: IsoMap_Destroy; observed-only */
    uint8_t pad_0xb4[6];
    uint16_t field_0xba;  /* save#16; u16; obs: IsoMap_Save */
    uint8_t pad_0xbc[44];
    uint32_t field_0xe8;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream; observed-only */
    uint32_t field_0xec;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream; observed-only */
    uint32_t field_0xf0;  /* save#17; u32/i32/float; obs: IsoMap_Save */
    uint32_t field_0xf4;  /* obs: IsoMap_Load; observed-only */
    uint8_t pad_0xf8[24];
    uint32_t field_0x110;  /* obs: IsoMap_Destroy; observed-only */
    uint32_t field_0x114;  /* obs: IsoMap_Destroy; observed-only */
    uint32_t field_0x118;  /* save#22; u32/i32/float; obs: IsoMap_Destroy, IsoMap_Save */
    uint8_t pad_0x11c[28];
    uint32_t field_0x138;  /* obs: IsoMap_Destroy; observed-only */
    uint8_t pad_0x13c[65568];
    uint32_t field_0x1015c;  /* obs: IsoMap_Construct, IsoMap_ConstructFromStream; observed-only */
    uint8_t pad_0x10160[24];
} IsoMap;

/* MapObject - 204 bytes, vtable 0x55c4ec */
typedef struct MapObject {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* save#0; u32/i32/float; obs: MapObject_Construct, MapObject_Destroy, MapObject_Load */
    uint32_t field_0x8;  /* save#1; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0xc;  /* save#8; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint8_t field_0x10[16];  /* save#11; bytes[16]; obs: MapObject_Load, MapObject_Save */
    uint32_t field_0x20;  /* save#12; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x24;  /* save#13; u32/i32/float; obs: MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load */
    uint32_t field_0x28;  /* obs: MapObject_Construct, MapObject_Load; observed-only */
    uint32_t field_0x2c;  /* save#4; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x30;  /* save#5; u32/i32/float; obs: MapObject_Construct, MapObject_InitRenderRecord, MapObject_Load */
    uint32_t field_0x34;  /* save#6; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x38;  /* save#7; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x3c;  /* save#9; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x40;  /* save#14; u64/double; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x44;  /* obs: MapObject_Construct; observed-only */
    uint32_t field_0x48;  /* save#15; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x4c;  /* save#2; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x50;  /* save#3; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint32_t field_0x54;  /* save#16; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint8_t pad_0x58[20];
    uint32_t field_0x6c;  /* obs: MapObject_Save; observed-only */
    uint8_t pad_0x70[4];
    uint32_t field_0x74;  /* obs: MapObject_Construct, MapObject_Destroy, MapObject_InitRenderRecord; observed-only */
    uint8_t pad_0x78[20];
    uint64_t field_0x8c;  /* obs: MapObject_Save; observed-only */
    uint32_t field_0x94;  /* save#10; u32/i32/float; obs: MapObject_Construct, MapObject_Load, MapObject_Save */
    uint8_t pad_0x98[44];
    uint32_t field_0xc4;  /* obs: MapObject_InitRenderRecord; observed-only */
    uint32_t field_0xc8;  /* obs: MapObject_InitRenderRecord; observed-only */
} MapObject;

/* WorldObject - 364 bytes, vtable 0x55c668 */
typedef struct WorldObject {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[32];  /* save#0; bytes[32]; serialized-only */
    uint32_t field_0x24;  /* save#1; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x28;  /* save#2; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x2c;  /* save#36; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x30;  /* save#3; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x34;  /* save#4; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x38;  /* save#5; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x3c;  /* save#6; u32/i32/float; obs: Object_Construct */
    uint16_t field_0x40;  /* save#7; u16; obs: Object_Construct */
    uint8_t pad_0x42[2];
    uint32_t field_0x44;  /* save#8; u32/i32/float; serialized-only */
    uint32_t field_0x48;  /* save#9; u32/i32/float; serialized-only */
    uint32_t field_0x4c;  /* save#10; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x50;  /* save#11; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x54;  /* save#12; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x58;  /* save#13; u32/i32/float; obs: Object_Construct */
    uint8_t field_0x5c[24];  /* save#14; bytes[24]; serialized-only */
    uint32_t field_0x74;  /* save#15; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x78;  /* save#16; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x7c;  /* save#17; u32/i32/float; obs: Object_Construct */
    uint8_t field_0x80;  /* save#18; u8/bool; obs: Object_Construct */
    uint8_t field_0x81;  /* save#19; u8/bool; obs: Object_Construct */
    uint8_t pad_0x82[2];
    uint32_t field_0x84;  /* save#20; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x88;  /* save#21; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x8c;  /* save#22; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x90;  /* save#23; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x94;  /* save#25; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x98;  /* save#26; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x9c;  /* save#27; u32/i32/float; obs: Object_Construct */
    uint32_t field_0xa0;  /* save#29; u32/i32/float; obs: Object_Construct */
    uint32_t field_0xa4;  /* save#30; u32/i32/float; obs: Object_Construct */
    uint32_t field_0xa8;  /* save#31; u32/i32/float; obs: Object_Construct */
    uint8_t field_0xac[24];  /* save#35; bytes[24]; serialized-only */
    uint32_t field_0xc4;  /* obs: Object_Construct; observed-only */
    uint8_t pad_0xc8[4];
    uint32_t field_0xcc;  /* obs: Object_Construct; observed-only */
    uint32_t field_0xd0;  /* obs: Object_Construct; observed-only */
    uint8_t pad_0xd4[32];
    uint32_t field_0xf4;  /* obs: Object_Construct; observed-only */
    uint32_t field_0xf8;  /* obs: Object_Construct; observed-only */
    uint8_t pad_0xfc[4];
    uint32_t field_0x100;  /* obs: Object_Construct; observed-only */
    uint8_t field_0x104;  /* save#33; u8/bool; obs: Object_Construct */
    uint8_t pad_0x105[3];
    uint32_t field_0x108;  /* save#34; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x10c;  /* save#24; u32/i32/float; obs: Object_Construct */
    uint32_t field_0x110;  /* save#32; u32/i32/float; obs: Object_Construct */
    uint8_t pad_0x114[20];
    uint32_t field_0x128;  /* save#37; u32/i32/float; serialized-only */
    uint8_t pad_0x12c[32];
    uint8_t field_0x14c[24];  /* save#28; bytes[24]; serialized-only */
    uint32_t field_0x164;  /* obs: Object_Construct; observed-only */
    uint32_t field_0x168;  /* obs: Object_Construct, Person_ConstructFromSave; observed-only */
} WorldObject;

/* Character - 2088 bytes, vtable 0x55c4fc */
typedef struct Character {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* save#0; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x8;  /* save#1; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0xc;  /* save#2; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x10;  /* save#3; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x14;  /* save#19; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x18;  /* save#20; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x1c;  /* save#21; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x20;  /* save#22; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x24;  /* save#4; u32/i32/float; obs: Character_Load, Character_Save */
    uint32_t field_0x28;  /* save#5; u32/i32/float; obs: Character_Load, Character_Save */
    uint32_t field_0x2c;  /* save#6; u32/i32/float; obs: Character_Load, Character_Save */
    uint32_t field_0x30;  /* save#7; u32/i32/float; obs: Character_Load, Character_Save */
    uint32_t field_0x34;  /* save#8; u32/i32/float; obs: Character_Load, Character_Save */
    uint32_t field_0x38;  /* save#9; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x3c;  /* save#10; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x40;  /* save#17; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint8_t field_0x44[400];  /* save#11; bytes[2000]; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x1d4;  /* obs: Character_Construct; observed-only */
    uint8_t pad_0x1d8[396];
    uint32_t field_0x364;  /* obs: Character_Construct; observed-only */
    uint8_t pad_0x368[396];
    uint32_t field_0x4f4;  /* obs: Character_Construct; observed-only */
    uint8_t pad_0x4f8[396];
    uint32_t field_0x684;  /* obs: Character_Construct; observed-only */
    uint8_t pad_0x688[396];
    uint32_t field_0x814;  /* save#12; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x818;  /* save#13; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x81c;  /* save#14; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint32_t field_0x820;  /* save#15; u32/i32/float; obs: Character_Construct, Character_Load, Character_Save */
    uint8_t field_0x824;  /* save#16; u8/bool; obs: Character_Construct, Character_Load, Character_Save */
    uint8_t field_0x825;  /* save#18; u8/bool; obs: Character_Construct, Character_Load, Character_Save */
    uint8_t pad_0x826[2];
} Character;

/* Recipe - 812 bytes, vtable 0x55c698 */
typedef struct Recipe {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[64];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x44;  /* obs: Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream; observed-only */
    uint8_t pad_0x48[20];
    uint64_t field_0x5c;  /* obs: Recipe_SaveToStream; observed-only */
    uint8_t field_0x64[344];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t field_0x1bc[28];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x1d8;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t field_0x1dc;  /* obs: Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream; observed-only */
    uint8_t field_0x1dd;  /* obs: Recipe_Construct, Recipe_CreateGenerated; observed-only */
    uint8_t pad_0x1de[2];
    uint8_t field_0x1e0[96];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x240;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x244;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x248;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x24c;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x250;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x254;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x258;  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t pad_0x25c[8];
    uint8_t field_0x264[32];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t field_0x284[32];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t field_0x2a4[32];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint8_t field_0x2c4[64];  /* obs: Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x304;  /* obs: Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream; observed-only */
    uint32_t field_0x308;  /* obs: Recipe_Construct, Recipe_CreateGenerated, Recipe_LoadFromStream; observed-only */
    uint32_t field_0x30c;  /* obs: Recipe_Construct, Recipe_LoadFromStream, Recipe_SaveToStream; observed-only */
    uint32_t field_0x310;  /* obs: Recipe_CreateGenerated, Recipe_StreamConstruct; observed-only */
    uint8_t pad_0x314[4];
    uint32_t field_0x318;  /* obs: Recipe_CreateGenerated; observed-only */
    uint32_t field_0x31c;  /* obs: Recipe_CreateGenerated; observed-only */
    uint32_t field_0x320;  /* obs: Recipe_CreateGenerated; observed-only */
    uint32_t field_0x324;  /* obs: Recipe_CreateGenerated; observed-only */
    uint32_t field_0x328;  /* obs: Recipe_CreateGenerated; observed-only */
} Recipe;

/* Ingredient - 508 bytes, vtable 0x55c5b8 */
typedef struct Ingredient {
    uint8_t pad_0x0[168];
    uint8_t field_0xa8;  /* obs: Ingredient_Construct; observed-only */
    uint8_t pad_0xa9[3];
    uint32_t field_0xac;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xb0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xb4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xb8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xbc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xc0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xc4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xc8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xcc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xd0;  /* obs: Ingredient_Construct, Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xd4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xd8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xdc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xe0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xe4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xe8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xec;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xf0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xf4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xf8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0xfc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x100;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x104;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x108;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x10c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x110;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x114;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x118;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x11c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x120;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x124;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x128;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x12c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x130;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x134;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x138;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x13c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x140;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x144;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x148;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x14c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x150;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x154;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x158;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x15c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x160;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x164;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x168;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x16c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x170;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x174;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x178;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x17c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x180;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x184;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x188;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x18c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x190;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x194;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x198;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x19c;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1a0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1a4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1a8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1ac;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1b0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1b4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1b8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1bc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1c0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1c4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1c8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1cc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1d0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1d4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1d8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1dc;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1e0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1e4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1e8;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1ec;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1f0;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1f4;  /* obs: Ingredient_LoadMarketTable; observed-only */
    uint32_t field_0x1f8;  /* obs: Ingredient_LoadMarketTable; observed-only */
} Ingredient;

/* GameClock - 40 bytes, vtable 0x55c564 */
typedef struct GameClock {
    uint8_t pad_0x0[4];
    uint16_t field_0x4;  /* save#3; u16; obs: GameClock_Reset */
    uint8_t field_0x6;  /* save#1; u8/bool; obs: GameClock_Reset */
    uint8_t field_0x7;  /* save#0; u8/bool; obs: GameClock_Reset */
    uint8_t field_0x8;  /* save#2; u8/bool; obs: GameClock_Reset */
    uint8_t pad_0x9[1];
    uint16_t field_0xa;  /* save#4; u16; obs: GameClock_Reset */
    uint32_t field_0xc;  /* save#5; u32/i32/float; obs: GameClock_Reset */
    uint32_t field_0x10;  /* save#9; u32/i32/float; obs: GameClock_Reset */
    uint32_t field_0x14;  /* save#8; u32/i32/float; obs: GameClock_Construct */
    uint8_t field_0x18;  /* save#7; u8/bool; obs: GameClock_Reset */
    uint8_t field_0x19;  /* save#6; u8/bool; obs: GameClock_Reset */
    uint8_t pad_0x1a[2];
    uint32_t field_0x1c;  /* obs: GameClock_Construct; observed-only */
    uint32_t field_0x20;  /* obs: GameClock_Construct, GameClock_Destroy; observed-only */
    uint32_t field_0x24;  /* obs: GameClock_Construct, GameClock_Destroy; observed-only */
} GameClock;

/* GamePlan - 48 bytes, vtable 0x55c688 */
typedef struct GamePlan {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x8;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0xc;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x10;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x14;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x18;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x1c;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x20;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x24;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x28;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
    uint32_t field_0x2c;  /* obs: GamePlan_Construct, GamePlan_LoadRecord, GamePlan_SaveRecord; observed-only */
} GamePlan;

/* Storage - 96 bytes, vtable 0x55c700 */
typedef struct Storage {
    uint8_t pad_0x0[4];
    uint8_t field_0x4[32];  /* obs: Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x24;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x28;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x2c;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x30;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x34;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint32_t field_0x38;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint8_t field_0x3c;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint8_t pad_0x3d[3];
    uint32_t field_0x40;  /* obs: Storage_Construct, Storage_LoadRecord, Storage_SaveRecord; observed-only */
    uint8_t pad_0x44[20];
    uint64_t field_0x58;  /* obs: Storage_SaveRecord; observed-only */
} Storage;

/* StatsPeriodReport - 860 bytes, vtable 0x55c2e0 */
typedef struct StatsPeriodReport {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* save#3; u32/i32/float; obs: StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct */
    uint32_t field_0x8;  /* save#5; u32/i32/float; obs: StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct */
    uint32_t field_0xc;  /* save#4; u32/i32/float; obs: StatsPeriodReport_Load, StatsPeriodReport_Save, Stats_Report_Construct */
    uint8_t field_0x10[104];  /* save#0; bytes[104]; obs: StatsPeriodReport_Load, StatsPeriodReport_Save */
    uint8_t field_0x78[100];  /* save#1; bytes[100]; obs: StatsPeriodReport_Load, StatsPeriodReport_Save */
    uint8_t field_0xdc[640];  /* save#2; bytes[640]; obs: StatsPeriodReport_Load, StatsPeriodReport_Save */
} StatsPeriodReport;

/* RecipeTopping - 28 bytes, vtable 0x55c4e8 */
typedef struct RecipeTopping {
    uint8_t pad_0x0[4];
    uint8_t field_0x4;  /* save#0; u8/bool; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t field_0x5;  /* save#1; u8/bool; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t field_0x6;  /* save#2; u8/bool; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t pad_0x7[1];
    uint32_t field_0x8;  /* save#3; u32/i32/float; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint32_t field_0xc;  /* save#4; u32/i32/float; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t field_0x10;  /* save#5; u8/bool; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t field_0x11;  /* save#6; u8/bool; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint8_t pad_0x12[2];
    uint32_t field_0x14;  /* save#7; u64/double; obs: RecipeTopping_Load, RecipeTopping_Save, RecipeTopping_StreamConstruct */
    uint32_t field_0x18;  /* obs: RecipeTopping_StreamConstruct; observed-only */
} RecipeTopping;

/* BuildingValue - 32 bytes, vtable 0x55c5a4 */
typedef struct BuildingValue {
    uint8_t pad_0x0[8];
    uint32_t field_0x8;  /* save#1; u32/i32/float; obs: BuildingValue_Load, BuildingValue_Save */
    uint32_t field_0xc;  /* save#0; u32/i32/float; obs: BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load */
    uint32_t field_0x10;  /* save#2; u64/double; obs: BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load */
    uint32_t field_0x14;  /* obs: BuildingValue_Construct, BuildingValue_ConstructDefault; observed-only */
    uint32_t field_0x18;  /* save#3; u32/i32/float; obs: BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load */
    uint8_t field_0x1c;  /* save#4; u8/bool; obs: BuildingValue_Construct, BuildingValue_ConstructDefault, BuildingValue_Load */
    uint8_t pad_0x1d[3];
} BuildingValue;

/* ConstructionOrder - 36 bytes, vtable 0x55c5bc */
typedef struct ConstructionOrder {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* save#0; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0x8;  /* save#1; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0xc;  /* save#2; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0x10;  /* save#3; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Save */
    uint32_t field_0x14;  /* save#4; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0x18;  /* save#5; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0x1c;  /* save#6; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
    uint32_t field_0x20;  /* save#7; u32/i32/float; obs: ConstructionOrder_Construct, ConstructionOrder_Load, ConstructionOrder_Save */
} ConstructionOrder;

/* Car - 20 bytes, vtable 0x55c4f8 */
typedef struct Car {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: Car_Construct, Car_LoadFromStream; observed-only */
    uint32_t field_0x8;  /* obs: Car_Destroy, Car_LoadSpriteRecord, Car_Save; observed-only */
    uint32_t field_0xc;  /* save#0; u32/i32/float; obs: Car_Construct, Car_Destroy, Car_LoadFromStream */
    uint32_t field_0x10;  /* obs: Car_Destroy; observed-only */
} Car;

/* UI_BriefingList - 56 bytes, vtable 0x55cb40 */
typedef struct UI_BriefingList {
    uint8_t pad_0x0[24];
    uint32_t field_0x18;  /* obs: UI_BriefingList_Destroy, UI_BriefingList_Save; observed-only */
    uint8_t pad_0x1c[4];
    uint32_t field_0x20;  /* obs: UI_BriefingList_Construct; observed-only */
    uint32_t field_0x24;  /* obs: UI_BriefingList_Construct; observed-only */
    uint32_t field_0x28;  /* obs: UI_BriefingList_Construct; observed-only */
    uint8_t pad_0x2c[4];
    uint32_t field_0x30;  /* obs: UI_BriefingList_Construct; observed-only */
    uint32_t field_0x34;  /* obs: UI_BriefingList_Construct; observed-only */
} UI_BriefingList;

/* UI_Manager - 33768 bytes, vtable 0x55c778 */
typedef struct UI_Manager {
    uint8_t pad_0x0[8];
    uint32_t field_0x8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0xc;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x10;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x14[44];
    uint32_t field_0x40;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x44[84];
    uint32_t field_0x98;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x9c[264];
    uint32_t field_0x1a4;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x1a8[12];
    uint32_t field_0x1b4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x1b8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x1bc;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x1c0;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x1c4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x1c8;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint8_t pad_0x1cc[88];
    uint32_t field_0x224;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x228;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x22c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x230;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x234;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x238;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x23c;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x240;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x244;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x248;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x24c;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x250[32];
    uint32_t field_0x270;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x274;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x278;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint8_t pad_0x27c[4];
    uint32_t field_0x280;  /* obs: UI_Manager_Destroy; observed-only */
    uint32_t field_0x284;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x288;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x28c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x290;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x294;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x298;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x29c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x2a0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x2a4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x2a8;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t field_0x2ac;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x2ad[3];
    uint8_t field_0x2b0[12292];  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x32b4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x32b8;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x32bc[20480];
    uint32_t field_0x82bc;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82c0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82c4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82c8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82cc;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82d0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82d4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82d8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82dc;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82e0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82e4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82e8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82ec;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x82f0[4];
    uint32_t field_0x82f4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x82f8;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x82fc;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x8300;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8304;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8308;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x830c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8310;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x8314;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8318;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x831c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8320;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint8_t pad_0x8324[20];
    uint32_t field_0x8338;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x833c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8340;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8344;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8348;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x834c;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8350;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x8354;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x8358;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x835c[64];
    uint32_t field_0x839c;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint32_t field_0x83a0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x83a4;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x83a8;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x83ac;  /* obs: UI_Manager_Construct, UI_Manager_Destroy; observed-only */
    uint8_t pad_0x83b0[8];
    uint32_t field_0x83b8;  /* obs: UI_Manager_Construct; observed-only */
    uint8_t pad_0x83bc[36];
    uint32_t field_0x83e0;  /* obs: UI_Manager_Construct; observed-only */
    uint32_t field_0x83e4;  /* obs: UI_Manager_Construct; observed-only */
} UI_Manager;

/* Dialog - 712 bytes, vtable 0x55c808 */
typedef struct Dialog {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x8;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0xc;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x10;  /* obs: Dialog_ConstructFixed; observed-only */
    uint8_t field_0x14;  /* obs: Dialog_ConstructFixed; observed-only */
    uint8_t field_0x15;  /* obs: Dialog_Destructor; observed-only */
    uint8_t pad_0x16[2];
    uint32_t field_0x18;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x1c;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x20;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x24;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x28;  /* obs: Dialog_SaveToFile; observed-only */
    uint32_t field_0x2c;  /* obs: Dialog_SaveToFile; observed-only */
    uint32_t field_0x30;  /* obs: Dialog_SaveToFile; observed-only */
    uint32_t field_0x34;  /* obs: Dialog_SaveToFile; observed-only */
    uint8_t pad_0x38[16];
    uint32_t field_0x48;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x4c;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x50;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint8_t field_0x54;  /* obs: Dialog_ConstructWithSprite, Dialog_InitBase; observed-only */
    uint8_t pad_0x55[63];
    uint32_t field_0x94;  /* obs: Dialog_ConstructWithSprite, Dialog_Destructor, Dialog_InitBase; observed-only */
    uint8_t pad_0x98[64];
    uint32_t field_0xd8;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0xdc;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0xe0;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0xe4;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0xe8;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0xec;  /* obs: Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0xf0;  /* obs: Dialog_Destructor, Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0xf4;  /* obs: Dialog_InitBase; observed-only */
    uint8_t field_0xf8;  /* obs: Dialog_ConstructWithPicture, Dialog_ConstructWithSprite, Dialog_Destructor; observed-only */
    uint8_t pad_0xf9[3];
    uint32_t field_0xfc;  /* obs: Dialog_Construct, Dialog_ConstructFixed, Dialog_InitBase; observed-only */
    uint32_t field_0x100;  /* obs: Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0x104;  /* obs: Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0x108;  /* obs: Dialog_ConstructFixed, Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0x10c;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x110[4];
    uint32_t field_0x114;  /* obs: Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint64_t field_0x118;  /* obs: Dialog_ConstructFixed; observed-only */
    uint64_t field_0x120;  /* obs: Dialog_ConstructFixed; observed-only */
    uint64_t field_0x128;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x130;  /* obs: Dialog_ConstructFixed; observed-only */
    uint32_t field_0x134;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0x138;  /* obs: Dialog_ConstructWithPicture, Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0x13c;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x140[28];
    uint32_t field_0x15c;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0x160;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0x164;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x168;  /* obs: Dialog_InitBase, Dialog_SaveToFile; observed-only */
    uint32_t field_0x16c;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x170;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x174;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint8_t field_0x178;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x179[259];
    uint32_t field_0x27c;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x280[4];
    uint32_t field_0x284;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x288[4];
    uint32_t field_0x28c;  /* obs: Dialog_Destructor, Dialog_InitBase; observed-only */
    uint32_t field_0x290;  /* obs: Dialog_Destructor; observed-only */
    uint8_t pad_0x294[4];
    uint32_t field_0x298;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x29c;  /* obs: Dialog_InitBase; observed-only */
    uint8_t pad_0x2a0[28];
    uint32_t field_0x2bc;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x2c0;  /* obs: Dialog_InitBase; observed-only */
    uint32_t field_0x2c4;  /* obs: Dialog_ConstructFixed; observed-only */
} Dialog;

/* Window - 33540 bytes, vtable 0x55c814 */
typedef struct Window {
    uint8_t pad_0x0[4];
    uint32_t field_0x4;  /* obs: FullscreenImage_Load, Window_Construct; observed-only */
    uint32_t field_0x8;  /* obs: FullscreenImage_Load, Window_Construct; observed-only */
    uint32_t field_0xc;  /* obs: Window_Construct; observed-only */
    uint8_t field_0x10;  /* obs: Window_Construct, Window_LoadSpriteCached; observed-only */
    uint8_t field_0x11;  /* obs: FullscreenImage_Load, Window_Construct; observed-only */
    uint8_t pad_0x12[2];
    uint32_t field_0x14;  /* obs: FullscreenImage_Load, Window_Construct, Window_Destroy; observed-only */
    uint32_t field_0x18;  /* obs: FullscreenImage_Load, Window_Construct, Window_Destroy; observed-only */
    uint8_t pad_0x1c[33500];
    uint32_t field_0x82f8;  /* obs: Window_LoadSpriteCached; observed-only */
    uint32_t field_0x82fc;  /* obs: Window_LoadSpriteCached; observed-only */
    uint32_t field_0x8300;  /* obs: Window_LoadSpriteCached; observed-only */
} Window;

/* Renderer - 156 bytes, vtable 0x55c818 */
typedef struct Renderer {
    uint8_t pad_0x0[12];
    uint8_t field_0xc;  /* obs: Renderer_Destroy; observed-only */
    uint8_t pad_0xd[7];
    uint32_t field_0x14;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint8_t field_0x18;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint8_t pad_0x19[1];
    uint16_t field_0x1a;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint16_t field_0x1c;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint8_t pad_0x1e[6];
    uint32_t field_0x24;  /* obs: Renderer_InitOrCopyState; observed-only */
    uint8_t pad_0x28[4];
    uint32_t field_0x2c;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint8_t field_0x30;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint8_t pad_0x31[3];
    uint32_t field_0x34;  /* obs: Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x38;  /* obs: Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x3c;  /* obs: Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x40;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy; observed-only */
    uint32_t field_0x44;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x48;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x4c;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint32_t field_0x50;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy; observed-only */
    uint32_t field_0x54;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot, Renderer_Destroy; observed-only */
    uint32_t field_0x58;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x5c;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x60;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint8_t pad_0x64[16];
    uint32_t field_0x74;  /* obs: Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x78;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint32_t field_0x7c;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint32_t field_0x80;  /* obs: Renderer_ConstructChild, Renderer_ConstructRoot; observed-only */
    uint32_t field_0x84;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x88;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x8c;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x90;  /* obs: Renderer_ConstructRoot, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x94;  /* obs: Renderer_ConstructRoot, Renderer_InitForWindow, Renderer_InitOrCopyState; observed-only */
    uint32_t field_0x98;  /* obs: Renderer_ConstructRoot; observed-only */
} Renderer;

#pragma pack(pop)

#endif /* PIZZA2_GAME_STRUCTS_H */
