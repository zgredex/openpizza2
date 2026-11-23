// Game_ClearPendingMapObjects: ported from Pizza Connection 2 at 0x47c730.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c730
#include "pc2_port.h"

void __fastcall Game_ClearPendingMapObjects(int arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  
  value2 = Get_Field19F4(arg1);
  if (0 < value2) {
    do {
      uptr3 = (uint32_t *)IDMap_Lookup((void *)(arg1 + 0x19e0),0,(int *)0x0);
      value2 = uptr3[8];
      value1 = *(int *)(*(int *)(arg1 + 0x14e0) + 0x4c);
      *(uint32_t *)(*(int *)(value1 + 8 + value2 * 0xc) + 0x1c) = 0xffffffff;
      Map_SetTileFieldWithDefault(*(void **)(arg1 + 0x14e0),value1 + value2 * 0xc,-1,1);
      IDMap_RemoveByKey((void *)(arg1 + 0x19e0),(intptr_t)uptr3);
      if (uptr3 != (uint32_t *)0x0) {
        (**(code **)*uptr3)(1);
      }
      value2 = Get_Field19F4(arg1);
    } while (0 < value2);
    *(uint32_t *)(arg1 + 0x1718) = 0;
  }
  return;
}
