// Map_BuildOccupiedCellList: ported from Pizza Connection 2 at 0x4d5940.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5940
#include "pc2_port.h"

void __fastcall Map_BuildOccupiedCellList(void *arg1)

{
  uint32_t *self;
  int value1;
  int value2;
  
  self = City_CollectBuildingsByType(arg1,0x20,0,'\0');
  value2 = 0;
  if (0 < (intptr_t)self[5]) {
    do {
      value1 = IDMap_Lookup(self,value2,(int *)0x0);
      value1 = Array_GetRecord28(*(void **)((intptr_t)arg1 + 0xfa8),1,*(int *)(value1 + 0x54));
      if ((value1 != 0) && (*(char *)(value1 + 6) == '\x02')) {
        List_Add((void *)(*(int *)((intptr_t)arg1 + 0xfa8) + 0x11c),value1);
      }
      value2 = value2 + 1;
    } while (value2 < (intptr_t)self[5]);
  }
  List_Node_Reset((intptr_t)self);
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  return;
}
