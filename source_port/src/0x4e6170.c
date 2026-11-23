// Game_UpdateObject: ported from Pizza Connection 2 at 0x4e6170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e6170
#include "pc2_port.h"

void __thiscall Game_UpdateObject(void *self,void *arg1)

{
  void *this_00;
  void *pvVar1;
  int *ptr2;
  int value3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = *(void **)((intptr_t)arg1 + 0x14e0);
  if (this_00 != (void *)0x0) {
    pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)((intptr_t)self + 4),(int *)0x0);
    ptr2 = (int *)Grid_GetCell(this_00,*(int *)((intptr_t)self + 0x18),*(int *)((intptr_t)self + 0x1c));
    value3 = *(int *)(ptr2[2] + 0x10);
    if ((value3 < 0x5d) || (100 < value3)) {
      *(int *)((intptr_t)self + 0x14) = value3;
      local_28 = Game_FindGroupSlot(pvVar1,value3,*(int *)((intptr_t)self + 8));
      if (*(int *)((intptr_t)pvVar1 + 8) == 1) {
        value3 = local_28 + 0x5d;
        if (0x60 < value3) {
          value3 = 0x60;
        }
        Game_ApplyOwnerWideObjectEvent(arg1,(intptr_t)self);
      }
      else if ((*(int *)((intptr_t)pvVar1 + 8) == 2) ||
              (Object_GetPair68(pvVar1,&local_2c,&local_24), local_2c == 4)) {
        value3 = local_28 + 0x61;
        if (100 < value3) {
          value3 = 100;
        }
      }
      else {
        value3 = local_28 + 0x5d;
        if (0x60 < value3) {
          value3 = 0x60;
        }
      }
      Game_SetModeByte(self,0);
      Object_ClearState((intptr_t)ptr2);
      Map_SetTileFieldWithDefault(this_00,(intptr_t)ptr2,value3,1);
      pvVar1 = (void *)SparseMap_Lookup48(DAT_0057c5cc,*(int *)((intptr_t)self + 0x14));
      if (pvVar1 != (void *)0x0) {
        UI_AlignSpriteToRect(this_00,ptr2,pvVar1,&local_20,&local_18);
        Sprite_GetHotspot(pvVar1,&local_1c,&local_14);
        Sprite_GetSize(pvVar1,&local_2c,&local_24);
        local_10 = local_1c + -10 + local_20;
        local_c = local_14 + -10 + local_18;
        local_8 = local_10 + 0x14 + local_2c;
        local_4 = local_c + 0x14 + local_24;
        Gfx_BlitRectList(DAT_0058072c,&local_10);
      }
    }
  }
  return;
}
