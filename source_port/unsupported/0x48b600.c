// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x48b600.c:47:26: error: invalid operands to binary expression ('tagRECT' (aka 'struct tagRECT') and 'unsigned int')
// Map_DrawMinimap: ported from Pizza Connection 2 at 0x48b600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48b600
#include "pc2_port.h"

void __fastcall Map_DrawMinimap(void *arg1)

{
  void *self;
  int value1;
  int value2;
  uint16_t uvalue3;
  int value4;
  void *pvVar5;
  void *this_00;
  int value6;
  int value7;
  int64_t lvalue8;
  int64_t lvalue9;
  int64_t lvalue10;
  int local_50;
  tagRECT local_28;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  value4 = IDMap_Lookup((void *)((intptr_t)arg1 + 4),*(int *)((intptr_t)arg1 + 0x2f4),(int *)0x0);
  self = *(void **)(value4 + 0xfa8);
  pvVar5 = (void *)UI_FindWindowByID(DAT_0057c5e0,*(int *)((intptr_t)arg1 + 0x2dac),(int *)0x0);
  if (((pvVar5 != (void *)0x0) && (self != (void *)0x0)) &&
     (pvVar5 = (void *)UI_GetWindowObject(pvVar5,99999), pvVar5 != (void *)0x0)) {
    value4 = IDMap_Lookup((void *)((intptr_t)arg1 + 4),*(int *)((intptr_t)arg1 + 0x2f4),(int *)0x0);
    if (value4 == 0) {
      UI_RealizeSprite((intptr_t)pvVar5);
      return;
    }
    this_00 = (void *)Object_GetActiveValue((intptr_t)pvVar5);
    if ((*(int *)((intptr_t)arg1 + 0x2e18) == 0) && (*(void **)(value4 + 0x10a8) != (void *)0x0)) {
      Sprite_Draw(*(void **)(value4 + 0x10a8),(intptr_t)this_00,(uint32_t *)0x0,0);
    }
    else {
      SetRect(&local_28,0,0,0x80,0x80);
      Surface_FillClippedRect(this_00,&local_28.left,0,1);
    }
    UI_GetViewRect(self,&local_18);
    local_28 = (local_28 & ~(0x0u << 64)) | (((128.0 / (double)(local_10 - local_18)) & 0x0u) << 64);
    value1 = *(int *)(value4 + 0xfc0);
    local_50 = 0;
    if (0 < value1) {
      do {
        value6 = IDMap_Lookup((void *)(value4 + 0xfac),local_50,(int *)0x0);
        if (((value6 != 0) && (value2 = *(int *)(value6 + 8), value2 != -1)) &&
           ((*(int *)(value6 + 0x74) != 0 &&
            (value7 = Game_GetAdjustedValue(*(int *)(value6 + 0x74)), 0 < value7)))) {
          Game_GetObjectCenterY(value6);
          lvalue8 = __ftol();
          Game_GetObjectBottom(value6);
          lvalue9 = __ftol();
          value6 = Game_GetPlayerBySlot(arg1,value2);
          if (value6 != 0) {
            uvalue3 = Color_RGBTo16FromDword(this_00,*(uint32_t *)(value6 + 0x1dc));
            lvalue10 = __ftol();
            Gfx_DrawFilledEllipse((intptr_t)this_00,(intptr_t)lvalue8,(uint32_t)lvalue9,(intptr_t)lvalue10,uvalue3);
          }
        }
        local_50 = local_50 + 1;
      } while (local_50 < value1);
    }
    UI_DrawRectOutline(pvVar5,(uint32_t *)(((*(int *)((intptr_t)self + 0xe8) - local_18) * 0x80) /
                                      (local_10 - local_18)),
                       ((*(int *)((intptr_t)self + 0xec) - local_14) * 0x80) / (local_c - local_14),
                       (uint32_t *)((((DAT_00571950 - local_18) + *(int *)((intptr_t)self + 0xe8)) * 0x80) /
                               (local_10 - local_18)),
                       (((DAT_00571954 - local_14) + *(int *)((intptr_t)self + 0xec)) * 0x80) /
                       (local_c - local_14),0xffffff);
    UI_ClipChildRect((intptr_t)pvVar5);
  }
  return;
}
