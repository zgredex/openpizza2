// UI_Bar_BuildGradientFill: ported from Pizza Connection 2 at 0x52a440.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52a440
#include "pc2_port.h"

void __fastcall UI_Bar_BuildGradientFill(int arg1)

{
  void *pvVar1;
  double dVar2;
  int value3;
  uint32_t *self;
  FILE *pFVar4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  int value7;
  uint32_t *uptr8;
  int value9;
  uint32_t uvalue10;
  int64_t lvalue11;
  uint32_t **pptr12;
  uint32_t **pptr13;
  uint32_t uStack_b8;
  uint32_t *local_b4;
  uint32_t *local_b0;
  uint32_t local_ac;
  uint32_t local_a8;
  int local_a4;
  int local_a0;
  char local_9c [16];
  int local_8c;
  int local_88;
  int iStack_84;
  double dStack_80;
  double dStack_78;
  double dStack_70;
  int local_68;
  uint32_t uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  uint32_t uStack_50;
  uint32_t uStack_4c;
  uint32_t uStack_48;
  uint32_t uStack_44;
  double dStack_40;
  uint32_t uStack_38;
  uint32_t uStack_34;
  double dStack_30;
  uint32_t uStack_28;
  uint32_t uStack_24;
  double dStack_20;
  uint32_t uStack_18;
  uint32_t uStack_14;
  uint32_t uStack_10;
  uint32_t uStack_c;
  
  local_9c[1] = 0xfe;
  local_9c[4] = 0xfe;
  local_9c[5] = 2;
  local_9c[8] = 2;
  local_9c[0] = '\0';
  local_9c[2] = 1;
  local_9c[3] = 0xff;
  local_9c[6] = 0xfd;
  local_9c[7] = 3;
  local_9c[9] = 0;
  local_9c[10] = 1;
  local_9c[0xb] = 0xff;
  local_9c[0xc] = 0xfc;
  local_9c[0xd] = 4;
  local_9c[0xe] = 0xfd;
  local_9c[0xf] = 3;
  local_ac = 0;
  local_a8 = 999999;
  local_68 = arg1;
  self = Renderer_CreateChild(DAT_0057c5c8);
  pvVar1 = *(void **)(arg1 + 0x344);
  if (*(char *)((intptr_t)pvVar1 + 0x39) == '\0') {
    Sprite_RealizeLazy(pvVar1);
  }
  Surface_Configure(self,*(uint32_t *)((intptr_t)pvVar1 + 0x2c),
                    (uint16_t)((intptr_t)*(short *)((intptr_t)pvVar1 + 6) >> 1),*(uint16_t *)((intptr_t)pvVar1 + 8),
                    (intptr_t)*(short *)((intptr_t)pvVar1 + 6));
  Sprite_FillTransparentColor(*(void **)(arg1 + 0x344),-1);
  Sprite_Draw(*(void **)(arg1 + 0x120),(intptr_t)self,(uint32_t *)0x0,0);
  Sprite_GetSize(*(void **)(arg1 + 0x120),(int *)&local_b0,(int *)&local_b4);
  Sprite_GetSize(*(void **)(arg1 + 0x164),&local_a4,&local_a0);
  Sprite_GetSize(*(void **)(arg1 + 0x1a8),&local_88,&local_8c);
  if (*(int *)(arg1 + 0xc0) == 0) {
    Sprite_Draw(*(void **)(arg1 + 0x1a8),(intptr_t)self,(uint32_t *)(*(int *)(arg1 + 200) - local_a4),0
               );
    Surface_SetBounds(self,(intptr_t)local_b0,0,*(int *)(arg1 + 200) - local_88,local_a0);
    if ((0 < local_a4) && (uptr8 = local_b0, (intptr_t)local_b0 < *(int *)(arg1 + 200) - local_88)) {
      do {
        Sprite_Draw(*(void **)(arg1 + 0x164),(intptr_t)self,uptr8,0);
        uptr8 = (uint32_t *)((intptr_t)uptr8 + local_a4);
      } while ((intptr_t)uptr8 < *(int *)(arg1 + 200) - local_88);
    }
  }
  else {
    Sprite_Draw(*(void **)(arg1 + 0x1a8),(intptr_t)self,(uint32_t *)0x0,*(int *)(arg1 + 200) - local_a0
               );
    Surface_SetBounds(self,0,(intptr_t)local_b4,local_a4,*(int *)(arg1 + 200) - local_8c);
    if ((0 < local_a0) && (uptr8 = local_b4, (intptr_t)local_b4 < *(int *)(arg1 + 200) - local_8c)) {
      do {
        Sprite_Draw(*(void **)(arg1 + 0x164),(intptr_t)self,(uint32_t *)0x0,(intptr_t)uptr8);
        uptr8 = (uint32_t *)((intptr_t)uptr8 + local_a0);
      } while ((intptr_t)uptr8 < *(int *)(arg1 + 200) - local_8c);
    }
  }
  if (self != (uint32_t *)0x0) {
    (**(code **)*self)(1);
  }
  if (*(int *)(arg1 + 0xc0) == 0) {
    pptr13 = &local_b0;
    pptr12 = &local_b4;
  }
  else {
    pptr13 = &local_b4;
    pptr12 = &local_b0;
  }
  Sprite_GetSize(*(void **)(arg1 + 0x344),(int *)pptr12,(int *)pptr13);
  if (*(int *)(arg1 + 0xd8) == -0x1000000) {
    uvalue10 = *(uint32_t *)(arg1 + 0xdc);
    uvalue6 = *(uint32_t *)(arg1 + 0xd4);
    *(uint32_t *)(arg1 + 0xd8) =
         ((uvalue6 & 0xff) + (uvalue10 & 0xff) >> 1) +
         ((uvalue6 & 0xff0000) + (uvalue10 & 0xff0000) >> 1 & 0xff0000) +
         ((uvalue6 & 0xff00) + (uvalue10 & 0xff00) >> 1 & 0xff00);
  }
  iStack_84 = Sprite_GetPixelBuffer(*(void **)(arg1 + 0x344));
  Color_RGBTo16(DAT_0057c5c8,0xff,0,0xff);
  uStack_64 = Sprite_GetColorKey(*(int *)(arg1 + 0x344));
  pFVar4 = (FILE *)CRT_Fopen(s_C__test_spr_00574318,&DAT_00563114);
  Sprite_Serialize(*(void **)(arg1 + 0x344),(intptr_t)DAT_0057c5c8,(int *)pFVar4,(void *)0x0);
  CRT_Fclose(pFVar4);
  uvalue10 = 0;
  uptr8 = local_b4;
  if ((intptr_t)local_b4 < 1) {
LAB_0052aad6:
    *(uint32_t *)(arg1 + 0xa8) = local_a8;
    *(uint32_t *)(arg1 + 0xa4) = (local_ac - local_a8) + 1;
    return;
  }
LAB_0052a762:
  if (uvalue10 == 0) {
    uStack_28 = *(uint32_t *)(arg1 + 0xd4);
    uStack_34 = 0;
    uStack_c = 0;
    uStack_38 = uStack_28 >> 0x10 & 0xff;
    uStack_24 = 0;
    dStack_80 = (double)uStack_38;
    uStack_10 = uStack_28 >> 8 & 0xff;
    uStack_28 = uStack_28 & 0xff;
    dStack_70 = (double)uStack_10;
    uvalue6 = *(uint32_t *)(arg1 + 0xd8);
    dVar2 = (double)(uvalue6 >> 0x10 & 0xff) - dStack_80;
    dStack_40 = (dVar2 + dVar2) / (double)(intptr_t)local_b4;
    dVar2 = (double)(uvalue6 >> 8 & 0xff) - dStack_70;
    dStack_30 = (dVar2 + dVar2) / (double)(intptr_t)local_b4;
    uvalue5 = uStack_28;
LAB_0052a903:
    dStack_78 = (double)uvalue5;
    dVar2 = (double)(uvalue6 & 0xff) - dStack_78;
    dStack_20 = (dVar2 + dVar2) / (double)(intptr_t)local_b4;
  }
  else if (uvalue10 == (intptr_t)uptr8 / 2) {
    uStack_48 = *(uint32_t *)(arg1 + 0xd8);
    uStack_4c = 0;
    uStack_14 = 0;
    uStack_50 = uStack_48 >> 0x10 & 0xff;
    uStack_44 = 0;
    dStack_80 = (double)uStack_50;
    uStack_18 = uStack_48 >> 8 & 0xff;
    uStack_48 = uStack_48 & 0xff;
    dStack_70 = (double)uStack_18;
    uvalue6 = *(uint32_t *)(arg1 + 0xdc);
    dVar2 = (double)(uvalue6 >> 0x10 & 0xff) - dStack_80;
    dStack_40 = (dVar2 + dVar2) / (double)(intptr_t)local_b4;
    dVar2 = (double)(uvalue6 >> 8 & 0xff) - dStack_70;
    dStack_30 = (dVar2 + dVar2) / (double)(intptr_t)local_b4;
    uvalue5 = uStack_48;
    goto LAB_0052a903;
  }
  uStack_b8 = 0;
  if (0 < (intptr_t)local_b0) {
    lvalue11 = __ftol();
    iStack_58 = (intptr_t)lvalue11;
    lvalue11 = __ftol();
    iStack_60 = (intptr_t)lvalue11;
    value9 = (uvalue10 & 3) << 2;
    iStack_54 = value9;
    lvalue11 = __ftol();
    iStack_5c = (intptr_t)lvalue11;
    do {
      value3 = iStack_84;
      value9 = (intptr_t)local_9c[(uStack_b8 & 3) + value9];
      uvalue6 = iStack_58 + value9;
      if ((intptr_t)uvalue6 < 0) {
        uvalue6 = 0;
      }
      else if (0xff < (intptr_t)uvalue6) {
        uvalue6 = 0xff;
      }
      value7 = iStack_60 + value9;
      if (value7 < 0) {
        value7 = 0;
      }
      else if (0xff < value7) {
        value7 = 0xff;
      }
      value9 = value9 + iStack_5c;
      if (value9 < 0) {
        value9 = 0;
      }
      else if (0xff < value9) {
        value9 = 0xff;
      }
      if (*(int *)(arg1 + 0xc0) == 0) {
        if (*(uint16_t *)(iStack_84 + (uStack_b8 * (intptr_t)local_b4 + uvalue10) * 2) == uStack_64)
        goto LAB_0052aa83;
        uvalue6 = Color_RGBTo16(DAT_0057c5c8,(uint8_t)value9,(uint8_t)value7,uvalue6);
        *(short *)(value3 + (uStack_b8 * (intptr_t)local_b4 + uvalue10) * 2) = (short)uvalue6;
        if ((intptr_t)uvalue10 < (intptr_t)local_a8) {
          local_a8 = uvalue10;
        }
        if ((intptr_t)local_ac < (intptr_t)uvalue10) {
          local_ac = uvalue10;
        }
      }
      else if (*(uint16_t *)
                (iStack_84 + (((intptr_t)local_b4 + (-1 - uvalue10)) * (intptr_t)local_b0 + uStack_b8) * 2) ==
               uStack_64) {
LAB_0052aa83:
      }
      else {
        uvalue6 = Color_RGBTo16(DAT_0057c5c8,(uint8_t)value9,(uint8_t)value7,uvalue6);
        *(short *)(value3 + (((intptr_t)local_b4 + (-1 - uvalue10)) * (intptr_t)local_b0 + uStack_b8) * 2) =
             (short)uvalue6;
        uvalue6 = (intptr_t)local_b4 + (-1 - uvalue10);
        if ((intptr_t)uvalue6 < (intptr_t)local_a8) {
          local_a8 = uvalue6;
        }
        if ((intptr_t)local_ac < (intptr_t)uvalue6) {
          local_ac = uvalue6;
        }
      }
      uStack_b8 = uStack_b8 + 1;
      arg1 = local_68;
      if ((intptr_t)local_b0 <= (intptr_t)uStack_b8) goto code_r0x0052aa98;
      value9 = iStack_54;
    } while( true );
  }
  goto LAB_0052aaa0;
code_r0x0052aa98:
  uptr8 = local_b4;
LAB_0052aaa0:
  dStack_80 = dStack_40 + dStack_80;
  uvalue10 = uvalue10 + 1;
  dStack_70 = dStack_30 + dStack_70;
  dStack_78 = dStack_20 + dStack_78;
  if ((intptr_t)uptr8 <= (intptr_t)uvalue10) goto LAB_0052aad6;
  goto LAB_0052a762;
}
