// Game_CheckObjectUpgrade: ported from Pizza Connection 2 at 0x47f100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f100
#include "pc2_port.h"

uint32_t __fastcall Game_CheckObjectUpgrade(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  int value3;
  
  self = *(void **)((intptr_t)arg1 + 0x16f0);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  pvVar1 = *(void **)(value2 + 0xfa8);
  value2 = Game_CountAgedAdjacentBuildings(arg1);
  value3 = Game_CountPlayersByByte(arg1,5);
  if ((value2 < 4) || (value3 < 1)) {
    Map_SetObjectFlags(self,pvVar1,0x10);
    *(uint32_t *)((intptr_t)arg1 + 0x28) = *(uint32_t *)((intptr_t)arg1 + 0x28) | 4;
    return 1;
  }
  Map_ClearObjectFlags(self,pvVar1,0x10);
  *(uint32_t *)((intptr_t)arg1 + 0x28) = *(uint32_t *)((intptr_t)arg1 + 0x28) & 0xfb;
  return 0;
}
