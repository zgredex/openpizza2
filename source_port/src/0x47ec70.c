// Game_ToggleObjectFlag2: ported from Pizza Connection 2 at 0x47ec70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47ec70
#include "pc2_port.h"

void __fastcall Game_ToggleObjectFlag2(void *arg1)

{
  void *self;
  void *pvVar1;
  int value2;
  int value3;
  int value4;
  
  self = *(void **)((intptr_t)arg1 + 0x16f0);
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)((intptr_t)self + 0x28),(int *)0x0);
  pvVar1 = *(void **)(value2 + 0xfa8);
  value2 = Game_CountObjectsByType(arg1,0);
  if (value2 == 0) {
    Map_SetObjectFlags(self,pvVar1,2);
  }
  else {
    Map_ClearObjectFlags(self,pvVar1,2);
  }
  value3 = Game_CountObjectsByType(arg1,2);
  if (value3 == 0) {
    Map_SetObjectFlags(self,pvVar1,4);
  }
  else {
    Map_ClearObjectFlags(self,pvVar1,4);
  }
  value4 = Game_CountObjectsByType(arg1,3);
  if (value4 == 0) {
    Map_SetObjectFlags(self,pvVar1,8);
  }
  else {
    Map_ClearObjectFlags(self,pvVar1,8);
    if (value3 != 0 && value2 != 0) {
      *(uint32_t *)((intptr_t)arg1 + 0x28) = *(uint32_t *)((intptr_t)arg1 + 0x28) & 0xfd;
      return;
    }
  }
  *(uint32_t *)((intptr_t)arg1 + 0x28) = *(uint32_t *)((intptr_t)arg1 + 0x28) | 2;
  return;
}
