// MapActor_RelocateToRandomTile: ported from Pizza Connection 2 at 0x4d3680.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3680
#include "pc2_port.h"

void __fastcall MapActor_RelocateToRandomTile(void *arg1)

{
  int *ptr1;
  int value2;
  int value3;
  
  Gfx_BlitShiftedRect((intptr_t)arg1);
  ptr1 = *(int **)((intptr_t)arg1 + 8);
  if ((short)ptr1[10] != -1) {
    Record_ClearFlags48((void *)ptr1[0x16],*ptr1);
    Object_ClearField4(*(int *)((intptr_t)arg1 + 8) + 0x14);
    Object_SetShort28(*(void **)((intptr_t)arg1 + 8),0xffff);
  }
  do {
    value2 = Array_GetRandomRecord28B(*(void **)((intptr_t)arg1 + 4),(int *)0x0);
    value3 = CityView_IsCarSpawnCellFree(*(void **)((intptr_t)arg1 + 4),value2);
  } while (value3 == 0);
  CityView_ReserveCarCell(*(void **)((intptr_t)arg1 + 4),value2,*(int *)((intptr_t)arg1 + 8));
  MapObject_PlaceAtPoint(arg1,value2);
  return;
}
