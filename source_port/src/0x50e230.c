// Game_UpdateBuildingStates: ported from Pizza Connection 2 at 0x50e230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e230
#include "pc2_port.h"

void __fastcall Game_UpdateBuildingStates(int arg1)

{
  int value1;
  void *pvVar2;
  int value3;
  
  value3 = 0;
  pvVar2 = *(void **)(arg1 + 0xf4);
  if (0 < *(int *)((intptr_t)pvVar2 + 0x8c)) {
    do {
      pvVar2 = (void *)Game_MapRecordToGlobal(pvVar2,value3);
      value1 = *(int *)((intptr_t)pvVar2 + 0x30);
      if ((((value1 == 0x16) || (value1 == 0x1e)) || (value1 == 0x1f)) &&
         (*(int *)((intptr_t)pvVar2 + 0x38) == 0x38)) {
        Object_SetState(pvVar2,0x39);
        *(uint32_t *)((intptr_t)pvVar2 + 0x108) = 6;
        *(uint32_t *)((intptr_t)pvVar2 + 0xcc) = *(uint32_t *)(arg1 + 0xcc);
      }
      pvVar2 = *(void **)(arg1 + 0xf4);
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)pvVar2 + 0x8c));
  }
  return;
}
