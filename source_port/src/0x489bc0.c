// Game_CommitObjectPlacement: ported from Pizza Connection 2 at 0x489bc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x489bc0
#include "pc2_port.h"

uint32_t __thiscall Game_CommitObjectPlacement(void *self,int arg1,int arg2)

{
  void *this_00;
  uint32_t *uptr1;
  int value2;
  int value3;
  
                    /* Stamps a placed object's footprint and rechecks paths. */
  this_00 = *(void **)(arg1 + 0x16f0);
  if (this_00 == (void *)0x0) {
    return 0;
  }
  Game_SuspendSimulation(self);
  uptr1 = Grid_CollectFootprintCells(*(void **)((intptr_t)self + 0x2fc),arg2);
  Map_DrawObjectList(*(void **)((intptr_t)self + 0x2fc),1,uptr1);
  if (uptr1 != (uint32_t *)0x0) {
    (**(code **)*uptr1)(1);
  }
  value3 = 0;
  if (0 < *(int *)((intptr_t)this_00 + 0x8c)) {
    do {
      value2 = Game_MapRecordToGlobal(this_00,value3);
      if (value2 != 0) {
        Building_PruneStaleListRow(value2);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)((intptr_t)this_00 + 0x8c));
  }
  Game_ResumeSimulation(self);
  return 1;
}
