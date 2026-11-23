// Game_UpdateObject2: ported from Pizza Connection 2 at 0x4e6020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e6020
#include "pc2_port.h"

void __thiscall Game_UpdateObject2(void *self,void *arg1)

{
  short svalue1;
  void *this_00;
  char cVar2;
  int *ptr3;
  void *pvVar4;
  int value5;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  this_00 = arg1;
  if (0 < *(int *)((intptr_t)self + 0xc)) {
    return;
  }
  ptr3 = (int *)Grid_GetCell(arg1,*(int *)((intptr_t)self + 0x18),*(int *)((intptr_t)self + 0x1c));
  Game_SetModeByte(self,100);
  Map_SetTileFieldWithDefault(this_00,(intptr_t)ptr3,*(int *)((intptr_t)self + 0x14),1);
  pvVar4 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)((intptr_t)self + 4),(int *)0x0);
  cVar2 = Game_GetPlayerByte8((intptr_t)self);
  if (cVar2 == '\x01') {
    value5 = Game_FindGroupSlot(pvVar4,*(int *)((intptr_t)self + 0x14),*(int *)((intptr_t)self + 8));
    if (value5 == 2) {
      svalue1 = *(short *)((intptr_t)pvVar4 + *(int *)((intptr_t)self + 8) * 0xc + 0x80);
    }
    else {
      if (value5 != 3) {
        *(uint32_t *)(ptr3[2] + 0x1c) = 0xffffffff;
        goto LAB_004e60c8;
      }
      svalue1 = *(short *)((intptr_t)pvVar4 + *(int *)((intptr_t)self + 8) * 0xc + 0x82);
    }
    *(int *)(ptr3[2] + 0x1c) = (intptr_t)svalue1;
  }
LAB_004e60c8:
  pvVar4 = (void *)SparseMap_Lookup48(DAT_0057c5cc,*(int *)((intptr_t)self + 0x14));
  if (pvVar4 != (void *)0x0) {
    UI_AlignSpriteToRect(this_00,ptr3,pvVar4,(int *)&arg1,&local_20);
    Sprite_GetHotspot(pvVar4,&local_24,&local_1c);
    Sprite_GetSize(pvVar4,&local_18,&local_14);
    local_10 = local_24 + -10 + (intptr_t)arg1;
    local_c = local_1c + -10 + local_20;
    local_8 = local_10 + 0x14 + local_18;
    local_4 = local_c + 0x14 + local_14;
    Gfx_BlitRectList(DAT_0058072c,&local_10);
  }
  return;
}
