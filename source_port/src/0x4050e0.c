// Game_GenerateRandomPlayers: ported from Pizza Connection 2 at 0x4050e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4050e0
#include "pc2_port.h"

void Game_GenerateRandomPlayers(void)

{
  int *ptr1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t *uptr5;
  int value6;
  int value7;
  uint32_t *uptr8;
  uint32_t *uptr9;
  uint32_t uvalue10;
  
  value6 = 0;
  ptr1 = &DAT_0057b768;
  do {
    *ptr1 = value6;
    ptr1 = ptr1 + 1;
    value6 = value6 + 1;
  } while ((intptr_t)ptr1 < 0x57b788);
  value6 = 0;
  ptr1 = &DAT_0057c258;
  do {
    *ptr1 = value6;
    ptr1 = ptr1 + 1;
    value6 = value6 + 1;
  } while ((intptr_t)ptr1 < 0x57c278);
  uvalue2 = Random_RangeFast(10,0x19);
  if (0 < (intptr_t)uvalue2) {
    do {
      uvalue3 = Random_RangeFast(0,7);
      uvalue4 = Random_RangeFast(0,7);
      uvalue10 = (&DAT_0057b768)[uvalue3];
      (&DAT_0057b768)[uvalue3] = (&DAT_0057b768)[uvalue4];
      (&DAT_0057b768)[uvalue4] = uvalue10;
      uvalue3 = Random_RangeFast(0,7);
      uvalue4 = Random_RangeFast(0,7);
      uvalue10 = (&DAT_0057c258)[uvalue3];
      (&DAT_0057c258)[uvalue3] = (&DAT_0057c258)[uvalue4];
      uvalue2 = uvalue2 - 1;
      (&DAT_0057c258)[uvalue4] = uvalue10;
    } while (uvalue2 != 0);
  }
  uptr8 = &DAT_0057bdc0;
  uptr5 = (uint32_t *)&DAT_0057bb20;
  for (value6 = 0x16e; value6 != 0; value6 = value6 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  DAT_0057bb20 = 0;
  DAT_0057bb54 = (DAT_0057bb54 & ~(0x0u << 8)) | (((0) & 0x0u) << 8);
  DAT_0057bd14 = 1;
  value6 = 0;
  do {
    uvalue2 = Random_RangeFast(0,1);
    uptr8[-2] = uvalue2;
    uvalue2 = Random_RangeFast(0,DAT_0058557c - 1);
    value7 = DAT_00585580;
    uptr8[-1] = uvalue2;
    uvalue2 = Random_RangeFast(0,value7 - 1);
    value7 = DAT_00585584;
    *uptr8 = uvalue2;
    uvalue2 = Random_RangeFast(0,value7 - 1);
    uptr8[1] = uvalue2;
    uvalue4 = Random_RangeFast(0,DAT_00585588 - 1);
    uvalue2 = *(uint32_t *)((intptr_t)&DAT_0057b76c + value6);
    uvalue3 = *(uint32_t *)((intptr_t)&DAT_0057c25c + value6);
    uptr8[2] = uvalue4;
    uptr8[3] = uvalue2;
    uptr8[4] = uvalue3;
    uptr8[-10] = 100;
    uptr8[-9] = 0;
    uptr9 = uptr8 + -8;
    for (value7 = 6; value7 != 0; value7 = value7 + -1) {
      *uptr9 = 0;
      uptr9 = uptr9 + 1;
    }
    IDMap_GetRandomName(DAT_0057ba10,uptr8[-2],(char *)(uptr8 + -0x2a));
    uvalue10 = 0;
    uvalue2 = Random_RangeFast(0,0x29);
    String_Format((uint8_t *)(uptr8 + -0x1a),*(uint8_t **)(&DAT_00583bb0 + uvalue2 * 4),uvalue10);
    uptr8[5] = 1;
    value6 = value6 + 4;
    uptr8 = uptr8 + 0x30;
  } while (value6 < 0x14);
  uptr5 = &DAT_0057be94;
  do {
    *uptr5 = 0;
    uptr5 = uptr5 + 0x30;
  } while ((intptr_t)uptr5 < 0x57c194);
  return;
}
