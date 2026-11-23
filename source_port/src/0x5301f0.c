// UI_RenderMapPreviewPanel: ported from Pizza Connection 2 at 0x5301f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5301f0
#include "pc2_port.h"


void __fastcall UI_RenderMapPreviewPanel(int arg1)

{
  short svalue1;
  short *psVar2;
  uint8_t uvalue3;
  uint32_t extraout_var;
  int value4;
  short *psVar5;
  uint32_t *uptr6;
  uint32_t uvalue7;
  int value8;
  int value9;
  uint32_t uvalue10;
  void *pvVar11;
  int value12;
  uint32_t uvalue13;
  char *cptr14;
  uint32_t *uptr15;
  int iStack_50;
  char *pcStack_4c;
  uint32_t local_48;
  uint32_t *local_44;
  uint32_t local_40;
  uint32_t local_3c;
  int iStack_38;
  uint32_t local_34;
  uint32_t local_30;
  int local_2c;
  int local_28;
  char *pcStack_24;
  char *local_20;
  tagRECT local_1c;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055ab56;
  local_c = ExceptionList;
  if ((*(int *)(arg1 + 0x138) != 0) && (*(int *)(arg1 + 0x168) == 0)) {
    return;
  }
  pvVar11 = *(void **)(arg1 + 0x50);
  if (pvVar11 == (void *)0x0) {
    if (*(int *)(arg1 + 0x168) == 0) {
      return;
    }
  }
  else if ((*(int *)(arg1 + 0x94) != 0) && (*(int *)(arg1 + 0x168) == 0)) {
    ExceptionList = &local_c;
    uvalue3 = Sprite_GetFormat(*(int *)(arg1 + 0x94));
    if (CONCAT31(extraout_var,uvalue3) != 0) {
      value4 = Sprite_GetColorKey(*(int *)(arg1 + 0x94));
      Sprite_SetColorKey(*(void **)(arg1 + 0x50),value4);
      Sprite_FillTransparentColor(*(void **)(arg1 + 0x50),value4);
    }
    Sprite_Draw(*(void **)(arg1 + 0x94),*(int *)(arg1 + 0xdc),(uint32_t *)0x0,0);
    ExceptionList = local_c;
    return;
  }
  if (*(int *)(arg1 + 0x168) == 0) {
    if ((*(int *)(arg1 + 0x10c) != 1) && (*(int *)(arg1 + 0xe4) != 0)) {
      ExceptionList = &local_c;
      Gfx_FillGradientDither(arg1);
      goto LAB_005308a8;
    }
    ExceptionList = &local_c;
    if (pvVar11 == (void *)0x0) goto LAB_005308a8;
    ExceptionList = &local_c;
    value4 = Color_RGBTo16FromDword(DAT_0057c5c8,*(uint32_t *)(arg1 + 0xfc));
    pvVar11 = *(void **)(arg1 + 0x50);
  }
  else {
    if ((0 < *(int *)(arg1 + 0x170)) && (0 < *(int *)(arg1 + 0x174))) {
      local_1c.left = (LONG)**(short **)(arg1 + 0x15c);
      local_1c.top = (LONG)(*(short **)(arg1 + 0x15c))[1];
      ExceptionList = &local_c;
      Sprite_GetRenderSize(*(void **)(*(int *)(arg1 + 0x160) + 0x148),&local_40,&local_3c);
      value4 = local_40 + local_1c.left;
      value12 = local_3c + local_1c.top;
      value8 = local_1c.top;
      local_1c.right = value4;
      local_1c.bottom = value12;
      if (1 < *(int *)(arg1 + 0x170)) {
        local_20 = (char *)(*(int *)(arg1 + 0x170) + -1);
        psVar2 = *(short **)(arg1 + 0x15c);
        do {
          psVar5 = psVar2 + 3;
          if (*psVar5 < local_1c.left) {
            local_1c.left = (intptr_t)*psVar5;
          }
          value9 = (intptr_t)psVar2[4];
          if (value9 < value8) {
            value8 = value9;
            local_1c.top = value9;
          }
          value9 = (intptr_t)*psVar5 + local_40;
          if (value4 < value9) {
            value4 = value9;
            local_1c.right = value9;
          }
          value9 = (intptr_t)psVar2[4] + local_3c;
          if (value12 < value9) {
            value12 = value9;
            local_1c.bottom = value9;
          }
          local_20 = (char *)((intptr_t)local_20 + -1);
          psVar2 = psVar5;
        } while (local_20 != (char *)0x0);
        local_20 = (char *)0x0;
      }
      local_48 = value12 - value8;
      local_44 = (uint32_t *)(value4 - local_1c.left);
      if ((0 < (intptr_t)local_44) && (0 < (intptr_t)local_48)) {
        if ((*(void **)(arg1 + 0x94) != (void *)0x0) &&
           (Sprite_GetRenderSize(*(void **)(arg1 + 0x94),&local_34,&local_30),
           (local_34 != (intptr_t)local_44 << ((uint8_t)local_30 & 0x1f)) != local_48)) {
          if (*(char *)(arg1 + 0x54) == '\0') {
            if (*(uint32_t **)(arg1 + 0x94) != (uint32_t *)0x0) {
              (**(code **)**(uint32_t **)(arg1 + 0x94))(1);
            }
          }
          else {
            UI_DecrementRowCounter(*(void **)(arg1 + 0x134),(uint8_t *)(arg1 + 0x54));
          }
          if (*(uint32_t **)(arg1 + 0x50) != (uint32_t *)0x0) {
            (**(code **)**(uint32_t **)(arg1 + 0x50))(1);
          }
          *(uint32_t *)(arg1 + 0x50) = 0;
          *(uint32_t *)(arg1 + 0x94) = 0;
          *(uint8_t *)(arg1 + 0x54) = 0;
        }
        if (*(int *)(arg1 + 0x94) == 0) {
          local_20 = operator_new(0x50);
          uStack_4 = 0;
          if (local_20 == (void *)0x0) {
            uptr6 = (uint32_t *)0x0;
          }
          else {
            uptr6 = Sprite_CreateRaw(local_20,(uint32_t)local_44,local_48,2,0x10,0);
          }
          uStack_4 = 0xffffffff;
          *(uint32_t **)(arg1 + 0x94) = uptr6;
          *(uint8_t *)(arg1 + 0x54) = 0;
          local_20 = operator_new(0x50);
          uStack_4 = 1;
          if (local_20 == (char *)0x0) {
            uptr6 = (uint32_t *)0x0;
          }
          else {
            uptr6 = Sprite_CreateRaw(local_20,(uint32_t)local_44,local_48,2,0x10,0);
          }
          pvVar11 = *(void **)(arg1 + 0xdc);
          *(uint32_t **)(arg1 + 0x50) = uptr6;
          uStack_4 = 0xffffffff;
          if (*(char *)((intptr_t)uptr6 + 0x39) == '\0') {
            Sprite_RealizeLazy(uptr6);
          }
          Surface_Configure(pvVar11,uptr6[0xb],(uint16_t)((intptr_t)*(short *)((intptr_t)uptr6 + 6) >> 1),
                            *(uint16_t *)(uptr6 + 2),(intptr_t)*(short *)((intptr_t)uptr6 + 6));
        }
        uvalue7 = Color_RGBTo16FromDword(DAT_0057c5c8,0xff00);
        Sprite_SetColorKey(*(void **)(arg1 + 0x94),uvalue7);
        uvalue7 = Color_RGBTo16FromDword(DAT_0057c5c8,0xff00);
        Sprite_SetColorKey(*(void **)(arg1 + 0x50),uvalue7);
        if (*(int *)(arg1 + 0xe4) == 0) {
          Sprite_FillTransparentColor(*(void **)(arg1 + 0x50),-1);
        }
        else if (*(int *)(arg1 + 0x10c) == 1) {
          value4 = Color_RGBTo16FromDword(DAT_0057c5c8,*(uint32_t *)(arg1 + 0xfc));
          Sprite_FillTransparentColor(*(void **)(arg1 + 0x50),value4);
        }
        else {
          Gfx_FillGradientDither(arg1);
        }
        Sprite_FillTransparentColor(*(void **)(arg1 + 0x94),-1);
        value4 = (intptr_t)local_44 / (intptr_t)local_40;
        iStack_38 = (intptr_t)local_48 / (intptr_t)local_3c;
        if (*(int *)(arg1 + 0xe4) == 0) {
          pcStack_4c = (char *)0x0;
        }
        else {
          uvalue13 = iStack_38 * value4;
          pcStack_4c = operator_new(uvalue13);
          cptr14 = pcStack_4c;
          for (uvalue10 = uvalue13 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
            cptr14[0] = '\0';
            cptr14[1] = '\0';
            cptr14[2] = '\0';
            cptr14[3] = '\0';
            cptr14 = cptr14 + 4;
          }
          for (uvalue13 = uvalue13 & 3; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
            *cptr14 = '\0';
            cptr14 = cptr14 + 1;
          }
        }
        iStack_50 = 0;
        if (0 < *(int *)(arg1 + 0x170)) {
          local_20 = (char *)0x0;
          do {
            value12 = *(int *)(arg1 + 0x15c);
            svalue1 = *(short *)(local_20 + value12 + 2);
            uptr15 = (uint32_t *)(*(short *)(local_20 + value12) - local_1c.left);
            pcStack_24 = (char *)((intptr_t)uptr15 / (intptr_t)local_40);
            value8 = (svalue1 - local_1c.top) / (intptr_t)local_3c;
            if ((((pcStack_4c != (char *)0x0) && (-1 < (intptr_t)pcStack_24)) && (-1 < value8)) &&
               (((intptr_t)pcStack_24 < value4 && (value8 < iStack_38)))) {
              (pcStack_24 + value8 * value4)[(intptr_t)pcStack_4c] = '\x02';
            }
            Sprite_Draw(*(void **)(*(int *)(arg1 + 0x160) + 0x148 +
                                  (uint32_t)*(uint8_t *)((intptr_t)(local_20 + value12) + 4) * 0x14c),
                        *(int *)(arg1 + 0xdc),uptr15,svalue1 - local_1c.top);
            iStack_50 = iStack_50 + 1;
            local_20 = local_20 + 6;
          } while (iStack_50 < *(int *)(arg1 + 0x170));
        }
        if (*(void **)(arg1 + 0xd8) != (void *)0x0) {
          Sprite_Draw(*(void **)(arg1 + 0xd8),*(int *)(arg1 + 0xdc),(uint32_t *)0x0,0);
        }
        value12 = iStack_38;
        if (*(int *)(arg1 + 0x13c) == 0) {
          *(int *)(arg1 + 8) = *(int *)(arg1 + 0x28);
          *(int *)(arg1 + 0xc) = *(int *)(arg1 + 0x2c);
          *(int *)(arg1 + 0x10) = (*(int *)(arg1 + 0x28) - local_1c.left) + local_1c.right;
          *(int *)(arg1 + 0x14) = (*(int *)(arg1 + 0x2c) - local_1c.top) + local_1c.bottom;
        }
        else {
          *(uint32_t *)(arg1 + 8) = 0;
          *(uint32_t *)(arg1 + 0xc) = 0;
          *(uint32_t *)(arg1 + 0x10) = 800;
          *(uint32_t *)(arg1 + 0x14) = 600;
        }
        *(LONG *)(arg1 + 0x140) = local_1c.left;
        *(LONG *)(arg1 + 0x144) = local_1c.top;
        *(uint32_t *)(arg1 + 0x18) = *(uint32_t *)(arg1 + 8);
        *(uint32_t *)(arg1 + 0x1c) = *(uint32_t *)(arg1 + 0xc);
        *(uint32_t *)(arg1 + 0x20) = *(uint32_t *)(arg1 + 0x10);
        *(uint32_t *)(arg1 + 0x24) = *(uint32_t *)(arg1 + 0x14);
        if (*(int *)(arg1 + 0xe4) != 0) {
          iStack_50 = 0;
          if (0 < value4) {
            local_20 = pcStack_4c + (iStack_38 + -1) * value4;
            do {
              if (pcStack_4c[iStack_50] == '\0') {
                Map_FloodFillMask((intptr_t)pcStack_4c,iStack_50,0,value4,value12);
              }
              if (local_20[iStack_50] == '\0') {
                Map_FloodFillMask((intptr_t)pcStack_4c,iStack_50,value12 + -1,value4,value12);
              }
              iStack_50 = iStack_50 + 1;
            } while (iStack_50 < value4);
          }
          iStack_50 = 0;
          if (0 < value12) {
            pcStack_24 = pcStack_4c;
            do {
              if (*pcStack_24 == '\0') {
                Map_FloodFillMask((intptr_t)pcStack_4c,0,iStack_50,value4,value12);
              }
              if (pcStack_24[value4 + -1] == '\0') {
                Map_FloodFillMask((intptr_t)pcStack_4c,value4 + -1,iStack_50,value4,value12);
              }
              iStack_50 = iStack_50 + 1;
              pcStack_24 = pcStack_24 + value4;
            } while (iStack_50 < value12);
          }
          value12 = 0;
          if (0 < value4) {
            do {
              value8 = 0;
              if (0 < iStack_38) {
                local_20 = pcStack_4c + value12;
                do {
                  if (*local_20 == '\x01') {
                    SetRect(&local_1c,value12 * local_40,value8 * local_3c,(value12 + 1) * local_40,
                            (value8 + 1) * local_40);
                    Surface_FillClippedRect(*(void **)(arg1 + 0xdc),&local_1c.left,0xff00,1);
                  }
                  value8 = value8 + 1;
                  local_20 = local_20 + value4;
                } while (value8 < iStack_38);
              }
              value12 = value12 + 1;
            } while (value12 < value4);
          }
          if (pcStack_4c != (char *)0x0) {
            Mem_Free(pcStack_4c);
          }
        }
      }
      goto LAB_005308a8;
    }
    ExceptionList = &local_c;
    if (pvVar11 != (void *)0x0) {
      ExceptionList = &local_c;
      Sprite_FillTransparentColor(pvVar11,-1);
    }
    pvVar11 = *(void **)(arg1 + 0x94);
    if (pvVar11 == (void *)0x0) goto LAB_005308a8;
    value4 = -1;
  }
  Sprite_FillTransparentColor(pvVar11,value4);
LAB_005308a8:
  if (*(void **)(arg1 + 0x50) != (void *)0x0) {
    Sprite_GetSize(*(void **)(arg1 + 0x50),&local_28,&local_2c);
    if (*(void **)(arg1 + 0x114) != (void *)0x0) {
      Sprite_GetRenderSize(*(void **)(arg1 + 0x114),(uint32_t *)&local_44,&local_48);
      Sprite_GetRenderSize(*(void **)(arg1 + 0x118),&local_34,&local_30);
      uptr15 = local_44;
      if ((intptr_t)local_44 < (intptr_t)(local_28 + local_34 * -2)) {
        do {
          Sprite_Draw(*(void **)(arg1 + 0x118),*(int *)(arg1 + 0xdc),uptr15,0);
          Sprite_Draw(*(void **)(arg1 + 0x128),*(int *)(arg1 + 0xdc),uptr15,
                      local_2c - local_30);
          uptr15 = (uint32_t *)((intptr_t)uptr15 + local_34);
        } while ((intptr_t)uptr15 < (intptr_t)(local_28 + local_34 * -2));
      }
      uvalue10 = local_48;
      if ((intptr_t)local_48 < (intptr_t)(local_2c + local_30 * -2)) {
        do {
          Sprite_Draw(*(void **)(arg1 + 0x130),*(int *)(arg1 + 0xdc),(uint32_t *)0x0,uvalue10);
          Sprite_Draw(*(void **)(arg1 + 0x120),*(int *)(arg1 + 0xdc),
                      (uint32_t *)(local_28 - local_34),uvalue10);
          uvalue10 = uvalue10 + local_30;
        } while ((intptr_t)uvalue10 < (intptr_t)(local_2c + local_30 * -2));
      }
      Sprite_Draw(*(void **)(arg1 + 0x114),*(int *)(arg1 + 0xdc),(uint32_t *)0x0,0);
      Sprite_Draw(*(void **)(arg1 + 0x11c),*(int *)(arg1 + 0xdc),
                  (uint32_t *)(local_28 - (intptr_t)local_44),0);
      Sprite_Draw(*(void **)(arg1 + 300),*(int *)(arg1 + 0xdc),(uint32_t *)0x0,local_2c - local_48
                 );
      Sprite_Draw(*(void **)(arg1 + 0x124),*(int *)(arg1 + 0xdc),
                  (uint32_t *)(local_28 - (intptr_t)local_44),local_2c - local_48);
      uvalue10 = Color_RGBTo16(*(void **)(arg1 + 0xdc),0,0xff,0);
      Sprite_SetColorKey(*(void **)(arg1 + 0x50),uvalue10);
    }
  }
  ExceptionList = local_c;
  return;
}
