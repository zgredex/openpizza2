// MapObject_RemoveFromMap: ported from Pizza Connection 2 at 0x481050.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481050
#include "pc2_port.h"

void __thiscall MapObject_RemoveFromMap(void *self,uint32_t *arg1)

{
  uint32_t *uptr1;
  
                    /* Removes a map object, redraws the map, and marks footprints dirty. */
  uptr1 = Grid_CollectFootprintCells(*(void **)((intptr_t)self + 0x14e0),(intptr_t)arg1);
  Map_DrawObjectList(*(void **)((intptr_t)self + 0x14e0),0,uptr1);
  MapObject_RemoveAndRefund(self,arg1);
  if (uptr1 != (uint32_t *)0x0) {
    (**(code **)*uptr1)(1);
  }
  IsoMap_MarkPlayerFootprints(*(void **)((intptr_t)self + 0x14e0),(intptr_t)self);
  return;
}
