// Game_CollectBuildingHitsAtPoint: ported from Pizza Connection 2 at 0x47dd00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47dd00
#include "pc2_port.h"

void __thiscall Game_CollectBuildingHitsAtPoint(void *self,void *arg1,int arg2,int arg3)

{
  int value1;
  int value2;
  void *this_00;
  uint8_t *uptr3;
  int value4;
  int value5;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_30 = 0;
  if (0 < *(int *)((intptr_t)self + 0x170c)) {
    value4 = local_10;
    value5 = local_c;
    do {
      local_14 = IDMap_Lookup((void *)((intptr_t)self + 0x16f8),local_30,(int *)0x0);
      if (local_14 != 0) {
        value1 = *(int *)(local_14 + 0x20);
        value2 = *(int *)(*(int *)((intptr_t)self + 0x14e0) + 0x4c);
        this_00 = (void *)SparseMap_Lookup48(DAT_0057c5cc,
                                             *(int *)(*(int *)(value2 + 8 + value1 * 0xc) + 0x10));
        if (this_00 != (void *)0x0) {
          UI_AlignSpriteToRect
                    (*(void **)((intptr_t)self + 0x14e0),(int *)(value2 + value1 * 0xc),this_00,&local_2c,
                     &local_24);
          Sprite_GetSize(this_00,&local_1c,&local_18);
          Sprite_GetHotspot(this_00,&local_28,&local_20);
          value4 = local_28 + local_2c;
          value5 = local_20 + local_24;
          local_8 = value4 + local_1c;
          local_4 = local_18 + value5;
        }
        if ((((value4 <= arg2) && (arg2 <= local_8)) && (value5 <= arg3)) &&
           (arg3 <= local_4)) {
          uptr3 = operator_new(8);
          *uptr3 = 3;
          *(int *)(uptr3 + 4) = local_14;
          List_Add(arg1,uptr3);
        }
      }
      local_30 = local_30 + 1;
    } while (local_30 < *(int *)((intptr_t)self + 0x170c));
  }
  return;
}
