// Branch_ClearInteriorObjects: ported from Pizza Connection 2 at 0x47c5e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47c5e0
#include "pc2_port.h"

void __thiscall Branch_ClearInteriorObjects(void *self,int arg1)

{
  int value1;
  int value2;
  uint32_t *this_00;
  uint32_t *uptr3;
  float local_8;
  int iStack_4;
  
                    /* Deletes branch interior objects, refunds them, and clears orders. */
  value1 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x30));
  value2 = Game_GetPlayerCity(value1);
  local_8 = 0.0;
  Game_ClearPendingMapObjects((intptr_t)self);
  value1 = *(int *)((intptr_t)self + 0x170c);
  while (0 < value1) {
    this_00 = (uint32_t *)IDMap_Lookup((void *)((intptr_t)self + 0x16f8),0,(int *)0x0);
    uptr3 = Grid_CollectFootprintCells(*(void **)((intptr_t)self + 0x14e0),(intptr_t)this_00);
    Map_DrawObjectList(*(void **)((intptr_t)self + 0x14e0),0,uptr3);
    if (uptr3 != (uint32_t *)0x0) {
      (**(code **)*uptr3)(1);
    }
    value1 = *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x4c) + this_00[8] * 0xc;
    Object_ClearState(value1);
    Map_SetTileFieldWithDefault(*(void **)((intptr_t)self + 0x14e0),value1,-1,1);
    Branch_RemoveConstructionOrder(self,(intptr_t)this_00);
    Game_ComputeEventValue(this_00,value2,&iStack_4);
    local_8 = (float)iStack_4 + local_8;
    if (this_00 != (uint32_t *)0x0) {
      (**(code **)*this_00)(1);
    }
    value1 = *(int *)((intptr_t)self + 0x170c);
  }
  IsoMap_MarkPlayerFootprints(*(void **)((intptr_t)self + 0x14e0),(intptr_t)self);
  if (arg1 == 0) {
    Stats_AddRecordValue(self,0x15,local_8,-1);
  }
  Branch_RemoveAllBuildings(self);
  *(uint32_t *)((intptr_t)self + 0x1718) = 0;
  if (*(int *)((intptr_t)DAT_0057c670 + 0x2fc) == *(int *)((intptr_t)self + 0x14e0)) {
    *(uint32_t *)(*(int *)((intptr_t)self + 0x14e0) + 0xf4) = 1;
  }
  if (arg1 == 0) {
    *(uint32_t *)((intptr_t)self + 0x28) = *(uint32_t *)((intptr_t)self + 0x28) | 4;
    Game_CheckObjectUpgrade(self);
  }
  return;
}
