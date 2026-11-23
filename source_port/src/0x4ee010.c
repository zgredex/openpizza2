// Map_DrawObject: ported from Pizza Connection 2 at 0x4ee010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ee010
#include "pc2_port.h"

void __thiscall Map_DrawObject(void *self,int arg1,uint32_t *arg2,int arg3)

{
  uint8_t flag1;
  int value2;
  int value3;
  uint32_t *uptr4;
  void *this_00;
  int value5;
  int *ptr6;
  uint16_t *uptr7;
  uint32_t uvalue8;
  int value9;
  int local_2c;
  void *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uptr4 = arg2;
  value9 = arg3 * 0xc;
  local_1c = 0;
  local_28 = self;
  this_00 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),*(int *)(arg2[2] + 4 + value9));
  if (this_00 == (void *)0x0) {
    return;
  }
  local_10 = this_00;
  if (arg1 != 3) {
    UI_ComputeCenteredRect(self,(int *)uptr4,&local_c,&local_24);
    UI_AlignSpriteToRect(self,(int *)uptr4,this_00,&local_2c,(int *)&arg2);
    arg2 = (uint32_t *)((intptr_t)arg2 + *(int *)((intptr_t)self + 0x28));
    Sprite_GetHotspot(this_00,&local_8,&local_18);
    Sprite_GetSize(this_00,&local_4,&local_14);
    value5 = local_14 + local_18 + (intptr_t)arg2;
    if (arg1 == 1) {
      if (local_24 < value5) {
        return;
      }
    }
    else if ((arg1 == 2) && (value5 <= local_24)) {
      return;
    }
  }
  uvalue8 = uptr4[2];
  local_20 = *(int *)(uvalue8 + 8 + value9);
  if (local_20 == 0) {
    UI_DrawObjectSprite(self,uptr4,this_00);
    if (arg3 == 1) {
      Map_UpdateVisibilityFlags(self,uptr4);
      return;
    }
  }
  else {
    value9 = 0;
    if (0 < local_20) {
      value5 = (arg3 * 3 + 3) * 4;
      ptr6 = (int *)(*(int *)(value5 + uvalue8) + 8);
      do {
        if (ptr6[-1] != 0) {
          value2 = *ptr6;
          if (*(char *)(value2 + 2) == '\x02') {
            UI_ComputeCenteredSpritePos
                      (self,(int *)uptr4,*(void **)(value2 + 0x48),&local_2c,(int *)&arg2);
            Record_DrawSprite48(*(void **)(value2 + 0x48),*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,
                                *(int *)(*(int *)(value5 + uptr4[2]) + value9 * 0xc));
            RecordList_TickFrame
                      (*(void **)(value2 + 0x48),*(int *)(*(int *)(value5 + uptr4[2]) + value9 * 0xc))
            ;
            local_1c = 1;
            goto LAB_004ee193;
          }
          this_00 = local_10;
        }
        value9 = value9 + 1;
        ptr6 = ptr6 + 3;
      } while (value9 < local_20);
    }
    flag1 = *(uint8_t *)(uvalue8 + 0x2d);
    if ((flag1 != 0) &&
       (uptr7 = (uint16_t *)Sprite_GetPalette((intptr_t)this_00), uptr7 != (uint16_t *)0x0)) {
      Palette_Expand(uptr7,(uint32_t)*(uint8_t *)(*(int *)((intptr_t)self + 8) + 0x18),flag1 - 1);
    }
    UI_DrawObjectSprite(self,uptr4,this_00);
LAB_004ee193:
    if (0 < local_20) {
      arg1 = local_20;
      value5 = (arg3 * 3 + 3) * 4;
      value9 = 0;
      do {
        value2 = *(int *)(*(int *)(uptr4[2] + value5) + 8 + value9);
        if (*(int *)(*(int *)(uptr4[2] + value5) + 4 + value9) == 0) {
          if ((*(char *)(value2 + 1) == '\x02') &&
             (uvalue8 = Random_RangeFast(1,10000), (intptr_t)uvalue8 < 0x3c)) {
            *(uint32_t *)(*(int *)(uptr4[2] + value5) + 4 + value9) = 1;
            Record_ApplyVariantState
                      (*(void **)(value2 + 0x48),*(int *)(*(int *)(uptr4[2] + value5) + value9),0,1);
          }
        }
        else {
          if (*(char *)(value2 + 2) == '\x01') {
            UI_ComputeCenteredSpritePos
                      (local_28,(int *)uptr4,*(void **)(value2 + 0x48),&local_2c,(int *)&arg2);
            Record_DrawSprite48(*(void **)(value2 + 0x48),*(uint32_t **)((intptr_t)local_28 + 8),DAT_0058072c,
                                *(int *)(*(int *)(uptr4[2] + value5) + value9));
            RecordList_TickFrame
                      (*(void **)(value2 + 0x48),*(int *)(*(int *)(uptr4[2] + value5) + value9));
          }
          if (*(char *)(value2 + 1) == '\x02') {
            value3 = *(int *)(*(int *)(uptr4[2] + value5) + value9);
            if (((value3 < 0) || (*(int *)(*(int *)(value2 + 0x48) + 0x48) <= value3)) ||
               (*(char *)(*(int *)(*(int *)(value2 + 0x48) + 0x4c) + 0x3e + value3 * 0x48) == '\0')) {
              *(uint32_t *)(*(int *)(uptr4[2] + value5) + value9 + 4) = 0;
            }
          }
        }
        value9 = value9 + 0xc;
        arg1 = arg1 + -1;
      } while (arg1 != 0);
      self = local_28;
    }
    if ((local_1c == 0) && (arg3 == 1)) {
      Map_UpdateVisibilityFlags(self,uptr4);
    }
  }
  return;
}
