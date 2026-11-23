// Branch_RefreshConstructionButtons: ported from Pizza Connection 2 at 0x47fb70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fb70
#include "pc2_port.h"

void __fastcall Branch_RefreshConstructionButtons(void *arg1)

{
  int value1;
  
  if (*(int *)((intptr_t)arg1 + 0x2c) == 7) {
    value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
    Map_ClearObjectFlags(*(void **)((intptr_t)arg1 + 0x16f0),*(void **)(value1 + 0xfa8),0xffffffff);
    return;
  }
  Game_ClearObjectFlag20((intptr_t)arg1);
  Game_ToggleObjectFlag2(arg1);
  Game_UpdateObjectList2((intptr_t)arg1);
  Game_CheckObjectUpgrade(arg1);
  return;
}
