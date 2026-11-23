// Game_ReassignObjectsFromRemovedBuilding: ported from Pizza Connection 2 at 0x48b500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b500
#include "pc2_port.h"

void __thiscall Game_ReassignObjectsFromRemovedBuilding(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  uint32_t uvalue3;
  int value4;
  
                    /* Repoints objects attached to a removed building. */
  value4 = 0;
  value1 = *(int *)((intptr_t)self + 0x50);
  if (0 < value1) {
    do {
      this_00 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x3c),value4,(int *)0x0);
      if ((*(int *)((intptr_t)this_00 + 0x30) != 0x2e) && (*(int *)((intptr_t)this_00 + 0xfc) == arg1)) {
        uvalue3 = Game_GetTimeSegment((intptr_t)self);
        value2 = *(int *)((intptr_t)this_00 + uvalue3 * 4 + 0xd4);
        Object_SetDestinationAndTarget(this_00,6,value2);
        *(int *)((intptr_t)this_00 + 0xd0) = value2;
      }
      value4 = value4 + 1;
    } while (value4 < value1);
  }
  return;
}
