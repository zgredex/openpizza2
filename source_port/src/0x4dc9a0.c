// City_PlaceObjectOnMap: ported from Pizza Connection 2 at 0x4dc9a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc9a0
#include "pc2_port.h"

void __thiscall City_PlaceObjectOnMap(void *self,void *arg1,void *arg2)

{
  int value1;
  int value2;
  int value3;
  
                    /* Re-inserts an object into the city map as a building. */
  value1 = Map_GetRandomBuildingOfType(self,(intptr_t)arg2,(intptr_t)arg1,'\x01');
  if (value1 != 0) {
    value2 = *(int *)(value1 + 0x48);
    if ((-1 < value2) && (value2 < 4)) {
      value2 = *(int *)(&DAT_00568188 + value2 * 4);
    }
    value3 = *(int *)((intptr_t)arg1 + 0x48);
    if ((-1 < value3) && (value3 < 4)) {
      value3 = *(int *)(&DAT_00568188 + value3 * 4);
    }
    MapObject_SpawnByKind(self,arg1,5,-1,arg2,value3 + (*(int *)(value1 + 0x20) - value2));
  }
  return;
}
