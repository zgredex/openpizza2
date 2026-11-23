// Movie_PlayFile: ported from Pizza Connection 2 at 0x52e570.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e570
#include "pc2_port.h"


void __thiscall
Movie_PlayFile(void *self,int arg1,int arg2,int arg3,int arg4,char *arg5)

{
  char cVar1;
  void *this_00;
  uint16_t uvalue2;
  char *cptr3;
  char *cptr4;
  int value5;
  int value6;
  void *pvVar7;
  uint32_t *uptr8;
  uint16_t *uptr9;
  uint16_t *uptr10;
  uint32_t uvalue11;
  uint32_t uvalue12;
  uint32_t uvalue13;
  uint16_t *uptr14;
  char *cptr15;
  uint32_t local_14;
  uint32_t local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a94b;
  local_c = ExceptionList;
  if (*(int *)((intptr_t)self + 0x18) != 0) {
    ExceptionList = &local_c;
    *(uint32_t *)((intptr_t)self + 0x34) = 0;
    if (*(LPVOID *)((intptr_t)self + 0x30) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)((intptr_t)self + 0x30));
    }
    uvalue12 = 0xffffffff;
    cptr3 = arg5;
    do {
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cVar1 = *cptr3;
      cptr3 = cptr3 + 1;
    } while (cVar1 != '\0');
    cptr3 = operator_new(~uvalue12);
    uvalue12 = 0xffffffff;
    *(char **)((intptr_t)self + 0x30) = cptr3;
    do {
      cptr4 = arg5;
      if (uvalue12 == 0) break;
      uvalue12 = uvalue12 - 1;
      cptr4 = arg5 + 1;
      cVar1 = *arg5;
      arg5 = cptr4;
    } while (cVar1 != '\0');
    uvalue12 = ~uvalue12;
    cptr4 = cptr4 + -uvalue12;
    for (uvalue13 = uvalue12 >> 2; uvalue13 != 0; uvalue13 = uvalue13 - 1) {
      *(uint32_t *)cptr3 = *(uint32_t *)cptr4;
      cptr4 = cptr4 + 4;
      cptr3 = cptr3 + 4;
    }
    for (uvalue12 = uvalue12 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
      *cptr3 = *cptr4;
      cptr4 = cptr4 + 1;
      cptr3 = cptr3 + 1;
    }
    value6 = 0;
    cptr3 = *(char **)((intptr_t)self + 0x30);
    while (cptr3 != (char *)0x0) {
      *(int *)((intptr_t)self + 0x34) = *(int *)((intptr_t)self + 0x34) + 1;
      cptr4 = _strchr(cptr3,10);
      if (cptr4 == (char *)0x0) {
        cptr15 = (char *)0x0;
      }
      else {
        cptr15 = cptr4 + 1;
        *cptr4 = '\0';
      }
      value5 = Font_MeasureText(*(void **)((intptr_t)self + 0x18),cptr3);
      cptr3 = cptr15;
      if (value6 < value5) {
        value6 = value5;
      }
    }
    *(uint32_t *)((intptr_t)self + 0x14) = 1;
    uvalue12 = value6 + 8;
    value6 = *(int *)(*(int *)((intptr_t)self + 0x18) + 0x9b0) * *(int *)((intptr_t)self + 0x34);
    uvalue13 = value6 + 4;
    *(int *)((intptr_t)self + 0x10) = arg2;
    *(int *)((intptr_t)self + 0xc) = arg1;
    if (arg3 < (intptr_t)(uvalue12 + arg1)) {
      *(uint32_t *)((intptr_t)self + 0xc) = arg3 - uvalue12;
    }
    if (arg4 < (intptr_t)(arg2 + uvalue13)) {
      *(uint32_t *)((intptr_t)self + 0x10) = arg4 - uvalue13;
    }
    if (*(int *)((intptr_t)self + 0xc) < 0) {
      *(uint32_t *)((intptr_t)self + 0xc) = 0;
    }
    if (*(int *)((intptr_t)self + 0x10) < 0) {
      *(uint32_t *)((intptr_t)self + 0x10) = 0;
    }
    if (*(void **)((intptr_t)self + 0x20) != (void *)0x0) {
      Sprite_GetRenderSize(*(void **)((intptr_t)self + 0x20),&local_14,&local_10);
      local_14 = (intptr_t)local_14 / 2;
      if ((local_14 != uvalue12) || (local_10 != uvalue13)) {
        if (*(uint32_t **)((intptr_t)self + 0x20) != (uint32_t *)0x0) {
          (**(code **)**(uint32_t **)((intptr_t)self + 0x20))(1);
        }
        *(uint32_t *)((intptr_t)self + 0x20) = 0;
      }
    }
    *(uint32_t *)((intptr_t)self + 4) = uvalue12;
    *(uint32_t *)((intptr_t)self + 8) = uvalue13;
    if (*(int *)((intptr_t)self + 0x20) == 0) {
      pvVar7 = operator_new(0x50);
      uStack_4 = 0;
      if (pvVar7 == (void *)0x0) {
        uptr8 = (uint32_t *)0x0;
      }
      else {
        uptr8 = Sprite_CreateRaw(pvVar7,uvalue12,uvalue13,0,0x10,0);
      }
      uStack_4 = 0xffffffff;
      *(uint32_t **)((intptr_t)self + 0x20) = uptr8;
    }
    pvVar7 = *(void **)((intptr_t)self + 0x20);
    this_00 = *(void **)((intptr_t)self + 0x1c);
    if (*(char *)((intptr_t)pvVar7 + 0x39) == '\0') {
      Sprite_RealizeLazy(pvVar7);
    }
    Surface_Configure(this_00,*(uint32_t *)((intptr_t)pvVar7 + 0x2c),
                      (uint16_t)((intptr_t)*(short *)((intptr_t)pvVar7 + 6) >> 1),*(uint16_t *)((intptr_t)pvVar7 + 8),
                      (intptr_t)*(short *)((intptr_t)pvVar7 + 6));
    value5 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x1c),*(uint32_t *)((intptr_t)self + 0x28));
    Sprite_FillTransparentColor(*(void **)((intptr_t)self + 0x20),value5);
    uvalue2 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x1c),*(uint32_t *)((intptr_t)self + 0x2c));
    uptr9 = (uint16_t *)Sprite_GetPixelBuffer(*(void **)((intptr_t)self + 0x20));
    if (0 < (intptr_t)uvalue12) {
      uptr10 = uptr9 + (value6 + 3) * uvalue12;
      uptr14 = uptr9;
      uvalue13 = uvalue12;
      do {
        *uptr14 = uvalue2;
        *uptr10 = uvalue2;
        uptr14 = uptr14 + 1;
        uptr10 = uptr10 + 1;
        uvalue13 = uvalue13 - 1;
      } while (uvalue13 != 0);
    }
    if (1 < value6 + 3) {
      uptr10 = uptr9 + uvalue12 * 2 + -1;
      value6 = value6 + 2;
      do {
        uptr9 = uptr9 + uvalue12;
        *uptr9 = uvalue2;
        *uptr10 = uvalue2;
        uptr10 = uptr10 + uvalue12;
        value6 = value6 + -1;
      } while (value6 != 0);
    }
    uvalue11 = Color_RGBTo16FromDword(*(void **)((intptr_t)self + 0x1c),*(uint32_t *)((intptr_t)self + 0x24));
    Set_Field9B8(*(void **)((intptr_t)self + 0x18),uvalue11);
    cptr3 = *(char **)((intptr_t)self + 0x30);
    value6 = 0;
    if (0 < *(int *)((intptr_t)self + 0x34)) {
      do {
        Text_SetMetrics2(*(void **)((intptr_t)self + 0x18),4,
                         *(int *)((intptr_t)*(void **)((intptr_t)self + 0x18) + 0x9b0) * value6 + 2,0);
        Font_DrawTextLine(*(void **)((intptr_t)self + 0x18),*(void **)((intptr_t)self + 0x1c),(intptr_t)cptr3);
        uvalue12 = 0xffffffff;
        cptr4 = cptr3;
        do {
          if (uvalue12 == 0) break;
          uvalue12 = uvalue12 - 1;
          cVar1 = *cptr4;
          cptr4 = cptr4 + 1;
        } while (cVar1 != '\0');
        value6 = value6 + 1;
        cptr3 = cptr3 + ~uvalue12;
      } while (value6 < *(int *)((intptr_t)self + 0x34));
    }
    *(uint32_t *)((intptr_t)self + 0x3c) = 1;
  }
  ExceptionList = local_c;
  return;
}
