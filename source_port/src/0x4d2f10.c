// Building_EvictOccupants: ported from Pizza Connection 2 at 0x4d2f10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2f10
#include "pc2_port.h"

void __fastcall Building_EvictOccupants(void *arg1)

{
  int value1;
  int value2;
  void *self;
  uint32_t uvalue3;
  
                    /* Evicts occupants when a building is removed or converted. */
  Game_ReassignDestroyedObjectReferences(DAT_0057c670,(intptr_t)arg1);
  value1 = *(int *)((intptr_t)arg1 + 0x8c);
  while (value1 = value1 + -1, -1 < value1) {
    self = (void *)Game_MapRecordToGlobal(arg1,value1);
    if (*(short *)((intptr_t)self + 0x40) == 0x11) {
      *(uint32_t *)((intptr_t)self + 0x4c) = 0;
      *(uint32_t *)((intptr_t)self + 0x54) = 0;
      UI_SetChildState(self,0xffff);
      Game_GetTimeByMode(self,0);
    }
    if (*(void **)((intptr_t)self + 0xfc) == arg1) {
      uvalue3 = Game_GetTimeSegment((intptr_t)DAT_0057c670);
      value2 = *(int *)((intptr_t)self + uvalue3 * 4 + 0xd4);
      Object_SetDestinationAndTarget(self,6,value2);
      *(int *)((intptr_t)self + 0xd0) = value2;
    }
    else {
      Game_RemoveObjectFromList(arg1,self,1);
    }
  }
  Game_ReassignObjectsFromRemovedBuilding(DAT_0057c670,(intptr_t)arg1);
  return;
}
