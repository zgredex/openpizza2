// Game_ClearObjectFlag20: ported from Pizza Connection 2 at 0x47edc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47edc0
#include "pc2_port.h"

void __fastcall Game_ClearObjectFlag20(int arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  
  self = *(void **)(arg1 + 0x16f0);
  value2 = IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  pvVar1 = *(void **)(value2 + 0xfa8);
  if (*(int *)(arg1 + 0x14dc) != 0) {
LAB_0047ee1d:
    Map_ClearObjectFlags(self,pvVar1,0x20);
    *(uint32_t *)(arg1 + 0x28) = *(uint32_t *)(arg1 + 0x28) & 0xdf;
    return;
  }
  value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)(arg1 + 0x30));
  if (value2 != 0) {
    value2 = Game_CountActiveCompanies(value2);
    if (0 < value2) goto LAB_0047ee1d;
  }
  Map_SetObjectFlags(self,pvVar1,0x20);
  *(uint32_t *)(arg1 + 0x28) = *(uint32_t *)(arg1 + 0x28) | 0x20;
  return;
}
