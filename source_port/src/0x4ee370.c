// Map_RenderObject: ported from Pizza Connection 2 at 0x4ee370.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ee370
#include "pc2_port.h"

void __thiscall Map_RenderObject(void *self,uint32_t *arg1,int arg2)

{
  void *pvVar1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  uint32_t *uptr4;
  int value5;
  int value6;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  void *local_28;
  uint32_t local_24;
  uint32_t local_20;
  int local_1c;
  uint32_t local_18;
  int local_14;
  int local_10;
  int local_c;
  
  value5 = 0;
  if (*(int *)((intptr_t)self + 0xc) == 0x10) {
    pvVar1 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),*(int *)(arg1[2] + 0x1c));
    if (pvVar1 != (void *)0x0) {
      if (arg2 == 0) {
        UI_DrawObjectSprite(self,arg1,pvVar1);
        return;
      }
      UI_AlignSpriteToRect(self,(int *)arg1,pvVar1,&local_48,&local_44);
      Sprite_GetHotspot(pvVar1,&local_38,&local_40);
      Sprite_GetSize(pvVar1,&local_3c,&local_34);
      local_18 = local_38 + local_48;
      local_14 = local_44 + local_40;
      local_10 = local_18 + local_3c;
      local_c = local_14 + local_34;
      Gfx_BlitRectList(DAT_0058072c,&local_18);
      return;
    }
  }
  else {
    pvVar1 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)self + 4),*(int *)(arg1[2] + 0x10));
    if (pvVar1 != (void *)0x0) {
      UI_AlignSpriteToRect(self,(int *)arg1,pvVar1,&local_48,&local_44);
      Sprite_GetHotspot(pvVar1,&local_38,&local_40);
      Sprite_GetSize(pvVar1,&local_3c,&local_34);
      local_28 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3b4);
      local_30 = *(int *)(*(int *)((intptr_t)self + 4) + 0x2c418);
      Sprite_DrawMasked(local_28,&local_2c,&local_1c,&local_20,&local_24);
      if (arg2 == 0) {
        if (DAT_00571968 != 0xffffffff) {
          uptr4 = &DAT_00571968;
          uvalue2 = DAT_00571968;
          do {
            if ((*(uint32_t *)(arg1[2] + 0x1c) & uvalue2) != 0) {
              value5 = value5 + local_2c;
            }
            uvalue2 = uptr4[1];
            uptr4 = uptr4 + 1;
          } while (uvalue2 != 0xffffffff);
        }
        local_44 = local_44 + local_40;
        value6 = 0;
        local_48 = local_48 + ((local_3c >> 1) - (value5 >> 1)) + local_38;
        if (DAT_00571968 != 0xffffffff) {
          value5 = 0;
          uptr3 = &DAT_00571968;
          do {
            pvVar1 = local_28;
            if ((*uptr3 & *(uint32_t *)(arg1[2] + 0x1c)) != 0) {
              if (value6 == 0) {
                value5 = (uint32_t)*(uint8_t *)(arg1[2] + 0x2c) + DAT_00571988;
              }
              else {
                value5 = *(int *)((intptr_t)&DAT_00571988 + value5);
              }
              Record_SetIndex48(local_28,local_30,value5);
              Record_DrawSprite48(pvVar1,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,local_30);
              local_48 = local_48 + local_2c;
            }
            value6 = value6 + 1;
            value5 = value6 * 4;
            uptr3 = &DAT_00571968 + value6;
          } while ((&DAT_00571968)[value6] != -1);
        }
      }
      else {
        local_14 = local_44 + local_40;
        local_18 = ((local_3c >> 1) - (local_2c * 8 >> 1)) + local_38 + local_48;
        local_10 = local_18 + local_2c * 8;
        local_c = local_14 + local_34;
        if (DAT_0058072c != (void *)0x0) {
          Gfx_BlitRectList(DAT_0058072c,&local_18);
          return;
        }
      }
    }
  }
  return;
}
