// Map_RenderVisibleObjects: ported from Pizza Connection 2 at 0x4ef4f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ef4f0
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall Map_RenderVisibleObjects(void *arg1)

{
  uint32_t *uptr1;
  int *ptr2;
  void *pvVar3;
  int value4;
  int value5;
  int value6;
  uint32_t local_70;
  uint32_t local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  uint32_t local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  uint32_t local_30;
  int local_2c;
  int local_28;
  int local_24;
  tagRECT local_20;
  tagRECT local_10;
  
  if (*(int *)((intptr_t)arg1 + 0x60) != 0) {
    if (*(int *)(DAT_0057c670 + 0x358) == 0) {
      DAT_00580a4c = 0;
      Map_DrawSelectedObjectSprite(arg1);
      *(uint32_t *)(DAT_0057c670 + 0x348) = 0xffffffff;
      *(uint32_t *)(DAT_0057c670 + 0x34c) = 0xffffffff;
    }
    else {
      uptr1 = (uint32_t *)
               Grid_GetCell(arg1,*(int *)(DAT_0057c670 + 0x348),*(int *)(DAT_0057c670 + 0x34c));
      if ((uptr1 == (uint32_t *)0x0) || (uptr1[2] == 0)) {
        DAT_00580a4c = 0;
      }
      else {
        Map_SetHoverTile(arg1,uptr1);
        DAT_00580a4c = 1;
      }
    }
  }
  if (*(int *)((intptr_t)arg1 + 0xf4) != 0) {
    SetRect(&local_20,0,0,DAT_00571950,DAT_00571954);
    Gfx_BlitRectList(DAT_0058072c,(uint32_t *)&local_20);
    *(uint32_t *)((intptr_t)arg1 + 0xf4) = 0;
    Map_UpdateVisibleObjects(arg1,0);
    return;
  }
  Map_UpdateVisibleObjects(arg1,1);
  value6 = *(int *)((intptr_t)arg1 + 0xe4) + *(int *)((intptr_t)arg1 + 0x28) + DAT_00571954;
  value5 = *(int *)((intptr_t)arg1 + 0x28) - *(int *)((intptr_t)arg1 + 0xe0);
  SetRect(&local_10,*(int *)((intptr_t)arg1 + 0x24) - *(int *)((intptr_t)arg1 + 0xd8),value5,
          *(int *)((intptr_t)arg1 + 0xdc) + *(int *)((intptr_t)arg1 + 0x24) + DAT_00571950,value6);
  Map_ComputeVisibleTileRange
            (arg1,&local_10.left,&local_50,&local_54,&local_4c,&local_3c,&local_48);
  local_38 = 0;
  value4 = *(int *)((intptr_t)arg1 + 0x10) >> 1;
  value4 = (value6 - value5) / value4 + 3 + *(int *)((intptr_t)arg1 + 0xe4) / value4;
  local_34 = value4;
  if (0 < value4) {
    value5 = local_50;
    value6 = local_4c;
    do {
      local_58 = local_54;
      local_40 = value5;
      if (value5 <= value6) {
        do {
          value4 = local_40;
          ptr2 = (int *)Grid_GetCell(arg1,local_40,local_58);
          local_58 = local_58 + -1;
          if ((ptr2 != (int *)0x0) && (ptr2[2] != 0)) {
            value5 = *(int *)(ptr2[2] + 0x14);
            if (0 < value5) {
              value4 = 0;
              local_44 = value5;
              do {
                value5 = *(int *)(*(int *)(ptr2[2] + 0x18) + 8 + value4);
                UI_ComputeCenteredSpritePos
                          (arg1,ptr2,*(void **)(value5 + 0x48),&local_68,&local_64);
                Sprite_DrawMasked(*(void **)(value5 + 0x48),&local_60,&local_5c,&local_70,&local_6c);
                local_30 = local_70 + local_68;
                local_2c = local_64 + local_6c;
                local_28 = local_30 + local_60;
                local_24 = local_2c + local_5c;
                Gfx_BlitRectList(DAT_0058072c,&local_30);
                value4 = value4 + 0xc;
                local_44 = local_44 + -1;
              } while (local_44 != 0);
              local_44 = 0;
              value4 = local_40;
            }
            Map_RenderObjectList(arg1,1,(intptr_t)ptr2,0,0);
            if ((((DAT_00580a4c != 0) && (*(char *)((intptr_t)arg1 + 0xb8) == '\0')) &&
                (*(int *)((intptr_t)arg1 + 0x60) != 0)) &&
               ((*(int *)((intptr_t)arg1 + 100) != 0 &&
                (*(int *)ptr2[2] == **(int **)(*(int *)((intptr_t)arg1 + 100) + 8))))) {
              if (*(char *)((intptr_t)*(void **)((intptr_t)arg1 + 4) +
                           *(int *)((intptr_t)arg1 + 0x68) * 0x48 + 0x24) == '\x01') {
                pvVar3 = (void *)SparseMap_Lookup48(*(void **)((intptr_t)arg1 + 4),
                                                    *(int *)((intptr_t)arg1 + 0x68));
                if (pvVar3 == (void *)0x0) {
                  return;
                }
                UI_AlignSpriteToRect
                          (arg1,*(int **)((intptr_t)arg1 + 100),pvVar3,&local_68,&local_64);
                Sprite_GetSize(pvVar3,&local_60,&local_5c);
                Sprite_GetHotspot(pvVar3,(int *)&local_70,(int *)&local_6c);
                local_30 = local_70 + local_68;
                local_2c = local_64 + local_6c;
                local_28 = local_30 + local_60;
                local_24 = local_2c + local_5c;
                Gfx_BlitRectList(DAT_0058072c,&local_30);
                if (DAT_005719b0 != -1) {
                  Gfx_BlitRectList(DAT_0058072c,(uint32_t *)&DAT_005719a8);
                }
                _DAT_005719a8 = local_30;
                _DAT_005719ac = local_2c;
                DAT_005719b0 = local_28;
                _DAT_005719b4 = local_24;
              }
            }
          }
          local_40 = value4 + 1;
        } while (local_40 <= local_4c);
        value5 = local_50;
        value4 = local_34;
        value6 = local_4c;
      }
      if (local_48 == 0) {
        value5 = value5 + 1;
        value6 = value6 + 1;
        local_50 = value5;
        local_4c = value6;
      }
      else {
        local_54 = local_54 + 1;
        local_3c = local_3c + 1;
      }
      local_48 = (uint32_t)(local_48 == 0);
      local_38 = local_38 + 1;
    } while (local_38 < value4);
  }
  if (*(int *)((intptr_t)arg1 + 0xc) == 0x40) {
    local_38 = 0x2c41c;
    pvVar3 = *(void **)(*(int *)((intptr_t)arg1 + 4) + 0x2c3d4);
    do {
      value4 = *(int *)(local_38 + *(int *)((intptr_t)arg1 + 4));
      if (((-1 < value4) && (value4 < *(int *)((intptr_t)pvVar3 + 0x48))) &&
         (*(char *)(*(int *)((intptr_t)pvVar3 + 0x4c) + 0x3e + value4 * 0x48) != '\0')) {
        Record_GetTwoFloats48(pvVar3,value4,&local_68,&local_64);
        Record_GetBounds48(pvVar3,value4,&local_60,&local_5c,&local_70,&local_6c);
        Record_GetScreenRect48(pvVar3,value4,(int *)&local_70,(int *)&local_6c);
        value4 = (local_70 - 10) + local_68;
        value5 = (local_6c - 10) + local_64;
        local_30 = value4 - *(int *)((intptr_t)arg1 + 0x24);
        local_28 = (value4 + 10 + local_60) - *(int *)((intptr_t)arg1 + 0x24);
        local_2c = value5 - *(int *)((intptr_t)arg1 + 0x28);
        local_24 = (value5 + 10 + local_5c) - *(int *)((intptr_t)arg1 + 0x28);
        Gfx_BlitRectList(DAT_0058072c,&local_30);
      }
      local_38 = local_38 + 4;
    } while (local_38 < 0x2c434);
  }
  return;
}
