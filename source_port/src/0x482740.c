// City_Register: ported from Pizza Connection 2 at 0x482740.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482740
#include "pc2_port.h"

void __thiscall City_Register(void *self,void *arg1,int arg2,int arg3)

{
  int value1;
  
  List_Add((void *)((intptr_t)self + 4),arg1);
  value1 = Map_FindIndex((void *)((intptr_t)self + 4),(intptr_t)arg1);
  *(int *)((intptr_t)arg1 + 0xc1c) = value1;
  City_InitBuildings((intptr_t)arg1);
  City_InitOfferSlots(arg1);
  City_InitPopulation(arg1,arg2,arg3);
  Map_BuildOccupiedCellList(arg1);
  return;
}
