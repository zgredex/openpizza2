// Branch_PlaceBuildPreview: ported from Pizza Connection 2 at 0x4c2ed0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c2ed0
#include "pc2_port.h"

void __cdecl Branch_PlaceBuildPreview(void *arg1)

{
  void *self;
  void *this_00;
  void *this_01;
  int value1;
  int value2;
  uint32_t *uptr3;
  
  self = *(void **)(DAT_0057c670 + 0x9c);
  this_00 = *(void **)((intptr_t)self + 0x14e0);
  this_01 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)((intptr_t)arg1 + 4),(int *)0x0
                                );
  if (((*(int *)((intptr_t)this_01 + 8) == 1) || (*(int *)((intptr_t)this_01 + 8) == 2)) &&
     (value1 = UI_IsClickOccluded(self,(intptr_t)arg1), value1 != 0)) {
    return;
  }
  *(uint32_t *)(DAT_0057c670 + 0x344) = *(uint32_t *)((intptr_t)arg1 + 4);
  *(uint32_t *)(DAT_0057c670 + 0x354) = *(uint32_t *)((intptr_t)arg1 + 8);
  Branch_RemoveConstructionOrder(self,(intptr_t)arg1);
  Game_DrawMapObjectSprite(arg1,this_00);
  value1 = *(int *)((intptr_t)this_00 + 0x4c) + *(int *)((intptr_t)arg1 + 0x20) * 0xc;
  Object_ClearState(value1);
  *(uint32_t *)((intptr_t)this_00 + 0x60) = 1;
  *(uint32_t *)((intptr_t)this_00 + 0x68) = *(uint32_t *)(*(int *)(value1 + 8) + 0x10);
  value2 = Game_FindGroupSlot(this_01,*(int *)(*(int *)(value1 + 8) + 0x10),*(int *)((intptr_t)arg1 + 8)
                            );
  *(int *)(DAT_0057c670 + 0x350) = value2;
  Map_SetTileFieldWithDefault(this_00,value1,-1,1);
  *(uint32_t *)(DAT_0057c670 + 0x348) = *(uint32_t *)((intptr_t)arg1 + 0x18);
  *(uint32_t *)(DAT_0057c670 + 0x34c) = *(uint32_t *)((intptr_t)arg1 + 0x1c);
  *(uint32_t *)(DAT_0057c670 + 0x35c) = 1;
  uptr3 = Grid_CollectFootprintCells(this_00,(intptr_t)arg1);
  Map_DrawObjectList(this_00,0,uptr3);
  if (uptr3 != (uint32_t *)0x0) {
    (**(code **)*uptr3)(1);
  }
  IsoMap_MarkPlayerFootprints(this_00,(intptr_t)self);
  *(uint32_t *)((intptr_t)this_00 + 0xf4) = 1;
  return;
}
