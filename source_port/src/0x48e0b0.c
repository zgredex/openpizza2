// Game_CacheCurrentCityGlobals: ported from Pizza Connection 2 at 0x48e0b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48e0b0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall Game_CacheCurrentCityGlobals(int arg1)

{
  uint32_t uvalue1;
  int value2;
  uint32_t *uptr3;
  uint32_t *uptr4;
  
  value2 = Game_GetPlayerCity(*(int *)(arg1 + 0x200 + *(int *)(arg1 + 0x2ec) * 4));
  DAT_0057c1f8 = *(uint32_t *)(value2 + 0x3c);
  DAT_0057c1fc = *(uint32_t *)(value2 + 0x40);
  DAT_0057c200 = *(uint32_t *)(value2 + 0x44);
  DAT_0057c204 = *(uint32_t *)(value2 + 0x48);
  DAT_0057c208 = *(uint32_t *)(value2 + 0x4c);
  DAT_0057c20c = *(uint32_t *)(value2 + 0x50);
  DAT_0057c210 = *(uint32_t *)(value2 + 0x54);
  DAT_0057c214 = *(uint32_t *)(value2 + 0x58);
  DAT_0057c218 = *(uint32_t *)(value2 + 0x5c);
  DAT_0057c21c = *(uint32_t *)(value2 + 0x60);
  DAT_0057c220 = *(uint32_t *)(value2 + 100);
  DAT_0057c224 = *(uint32_t *)(value2 + 0x68);
  DAT_0057c240 = *(uint32_t *)(value2 + 0x2c);
  DAT_0057c244 = *(uint32_t *)(value2 + 0x30);
  DAT_0057c248 = *(uint32_t *)(*(int *)(value2 + 4) + 0x40);
  DAT_0057c24c = (DAT_0057c24c & ~(0x0u << 16)) | (((*(uint16_t *)(*(int *)(arg1 + 0x94) + 4)) & 0x0u) << 16);
  DAT_0057c24c = (DAT_0057c24c & ~(0xffffu << 8)) | (((*(uint8_t *)(*(int *)(arg1 + 0x94) + 8)) & 0xffffu) << 8);
  uptr3 = (uint32_t *)(value2 + 0x6c);
  _DAT_0057c250 = (uint32_t)*(uint8_t *)(*(int *)(arg1 + 0x94) + 7);
  uptr4 = &DAT_0057c228;
  do {
    uvalue1 = *uptr3;
    uptr3 = uptr3 + 1;
    *uptr4 = uvalue1;
    uptr4 = uptr4 + 1;
  } while ((intptr_t)uptr4 < 0x57c240);
  return;
}
