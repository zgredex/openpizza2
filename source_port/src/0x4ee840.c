// Map_RenderObjectList: ported from Pizza Connection 2 at 0x4ee840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ee840
#include "pc2_port.h"

void __thiscall Map_RenderObjectList(void *self,int arg1,int arg2,int arg3,int arg4)

{
  int yTop;
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  int *ptr4;
  uint32_t *uptr5;
  uint32_t local_64;
  int local_60;
  uint32_t local_5c;
  uint32_t local_58;
  int local_54;
  uint32_t local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint32_t local_40;
  int local_3c;
  uint32_t local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  
  if ((DAT_00580a50 != 2) &&
     (ptr4 = *(int **)(*(int *)(arg2 + 8) + 0x20), ptr4 != (int *)0x0)) {
    do {
      Record_GetTwoFloats48((void *)ptr4[0x16],*ptr4,&local_64,&local_60);
      if ((*(uint8_t *)(ptr4 + 4) & 1) == 0) {
        if (arg1 == 0) {
          if (arg3 == 1) {
            *(uint32_t *)((intptr_t)self + 0xac) = 0xffff;
          }
          else {
            *(uint32_t *)((intptr_t)self + 0xac) = 0;
          }
          pvVar1 = (void *)ptr4[0x16];
          if (pvVar1 == *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3cc)) {
            local_4c = *(int *)((intptr_t)self + 0x24);
            value2 = *ptr4;
            uptr5 = *(uint32_t **)((intptr_t)self + 8);
LAB_004eec4b:
            local_4c = local_64 - local_4c;
            Record_DrawSprite48(pvVar1,uptr5,DAT_0058072c,value2);
          }
          else if (ptr4[0x1d] == 0) {
            if (arg3 == 0) {
              local_4c = local_64 - *(int *)((intptr_t)self + 0x24);
              Record_DrawSprite48(pvVar1,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,*ptr4);
              pvVar1 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c180 +
                                 *(int *)(ptr4[0x1e] + 0xc) * 4);
              if (pvVar1 != (void *)0x0) {
                value2 = Record_GetValue48((void *)ptr4[0x16],*ptr4);
                Record_SetIndex48(pvVar1,*(int *)(ptr4[0x1e] + 0x10),value2);
                local_4c = local_64 - *(int *)((intptr_t)self + 0x24);
                RecordList_BlitIndexedRLE
                          (pvVar1,*(int *)((intptr_t)self + 8),DAT_0058072c,*(int *)(ptr4[0x1e] + 0x10)
                          );
              }
            }
          }
          else if (DAT_00580a50 == 0) {
            local_4c = local_64 - *(int *)((intptr_t)self + 0x24);
            Record_DrawSprite48(pvVar1,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,*ptr4);
            if ((arg3 == 0) && (DAT_00580730 != (void *)0x0)) {
              Sprite_BlitOwnedRLE(DAT_00580730,*(void **)((intptr_t)self + 8),
                                  (*(int *)((intptr_t)self + 0xf8) - *(int *)((intptr_t)self + 0x24)) + -0x40
                                  + local_64,
                                  (*(int *)((intptr_t)self + 0xfc) - *(int *)((intptr_t)self + 0x28)) + -0x4d
                                  + local_60);
            }
          }
          else if ((DAT_00580a50 == 1) && (arg3 == 0)) {
            local_4c = *(int *)((intptr_t)self + 0x24);
            value2 = *ptr4;
            uptr5 = *(uint32_t **)((intptr_t)self + 8);
            goto LAB_004eec4b;
          }
        }
        else {
          Record_GetBounds48((void *)ptr4[0x16],*ptr4,&local_48,&local_44,&local_5c,&local_58);
          Record_GetScreenRect48((void *)ptr4[0x16],*ptr4,(int *)&local_5c,(int *)&local_58);
          local_38 = local_5c + local_64;
          local_30 = local_38 + local_48;
          local_34 = local_58 + local_60;
          local_2c = local_34 + local_44;
          if (ptr4[0x1d] == 0) {
            pvVar1 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c180 + *(int *)(ptr4[0x1e] + 0xc) * 4
                               );
            if (pvVar1 != (void *)0x0) {
              value2 = Record_GetValue48((void *)ptr4[0x16],*ptr4);
              Record_SetIndex48(pvVar1,*(int *)(ptr4[0x1e] + 0x10),value2);
              Record_GetBounds48(pvVar1,*(int *)(ptr4[0x1e] + 0x10),&local_48,&local_44,&local_5c,
                                 &local_58);
              Record_GetScreenRect48
                        (pvVar1,*(int *)(ptr4[0x1e] + 0x10),(int *)&local_5c,(int *)&local_58);
              uvalue3 = local_64 + local_5c;
              value2 = local_58 + local_60;
              if ((intptr_t)uvalue3 < (intptr_t)local_38) {
                local_38 = uvalue3;
              }
              if (local_30 < (intptr_t)(local_48 + uvalue3)) {
                local_30 = local_48 + uvalue3;
              }
              if (value2 < local_34) {
                local_34 = value2;
              }
              if (local_2c < local_44 + value2) {
                local_2c = local_44 + value2;
              }
            }
          }
          else {
            value2 = (*(int *)((intptr_t)self + 0xf8) - *(int *)((intptr_t)self + 0x24)) + -7 + local_64;
            yTop = (*(int *)((intptr_t)self + 0xfc) - *(int *)((intptr_t)self + 0x28)) + -6 + local_60;
            SetRect(&local_18,value2,yTop,value2 + 0x20,yTop + 0xc);
            Gfx_BlitRectList(DAT_0058072c,(uint32_t *)&local_18);
          }
        }
      }
      if ((((short)ptr4[2] == -1) || ((short)ptr4[2] == 0)) ||
         ((*(uint8_t *)(ptr4 + 4) & 1) != 0)) {
LAB_004eee19:
        uvalue3 = local_38;
        if (arg1 != 0) {
          local_24 = local_34;
          local_20 = local_30;
          if (local_30 < ptr4[0x19]) {
            local_30 = ptr4[0x19];
          }
          value2 = local_2c;
          if (local_2c < ptr4[0x1a]) {
            value2 = ptr4[0x1a];
          }
          if (ptr4[0x17] < (intptr_t)local_38) {
            local_38 = ptr4[0x17];
          }
          if (ptr4[0x18] < local_34) {
            local_34 = ptr4[0x18];
          }
          local_38 = local_38 - *(int *)((intptr_t)self + 0x24);
          local_30 = local_30 - *(int *)((intptr_t)self + 0x24);
          local_34 = local_34 - *(int *)((intptr_t)self + 0x28);
          local_1c = local_2c;
          local_2c = value2 - *(int *)((intptr_t)self + 0x28);
          Gfx_BlitRectList(DAT_0058072c,&local_38);
          ptr4[0x17] = uvalue3;
          ptr4[0x18] = local_24;
          ptr4[0x19] = local_20;
          ptr4[0x1a] = local_1c;
        }
      }
      else {
        local_4c = local_64 - *(int *)((intptr_t)self + 0x24);
        local_54 = local_60 - *(int *)((intptr_t)self + 0x28);
        Record_GetScreenOffset((void *)ptr4[0x16],*ptr4,&local_4c,&local_54);
        pvVar1 = *(void **)(*(int *)((intptr_t)self + 4) + 0x2c3b4);
        Record_SetIndex48(pvVar1,ptr4[1],(intptr_t)(short)ptr4[2]);
        Get_WidthHeight(pvVar1,&local_40,&local_50);
        if (arg1 != 0) {
          local_64 = (local_4c - ((intptr_t)local_40 >> 2)) + *(int *)((intptr_t)self + 0x24);
          local_60 = (*(int *)((intptr_t)self + 0x28) - local_50) + -3 + local_54;
          if ((intptr_t)local_64 < (intptr_t)local_38) {
            local_38 = local_64;
          }
          if (local_30 < (intptr_t)(local_40 + local_64)) {
            local_30 = local_40 + local_64;
          }
          if (local_60 < local_34) {
            local_34 = local_60;
          }
          if (local_2c < (intptr_t)(local_50 + local_60)) {
            local_2c = local_50 + local_60;
          }
          goto LAB_004eee19;
        }
        local_3c = local_4c - ((intptr_t)local_40 >> 2);
        *(uint32_t *)((intptr_t)self + 0xac) = 0xffffff;
        Record_DrawSprite48(pvVar1,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,ptr4[1]);
        if (*(short *)((intptr_t)ptr4 + 10) != -1) {
          Record_SetIndex48(pvVar1,ptr4[1],(intptr_t)*(short *)((intptr_t)ptr4 + 10));
          local_3c = local_4c - ((intptr_t)local_40 >> 2);
          Record_DrawSprite48(pvVar1,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,ptr4[1]);
        }
      }
      ptr4 = (int *)ptr4[0x1b];
    } while (ptr4 != (int *)0x0);
    if (arg4 != 0) {
      *(uint32_t *)(*(int *)(arg2 + 8) + 0x20) = 0;
    }
  }
  return;
}
