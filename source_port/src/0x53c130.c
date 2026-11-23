// Gfx_BlitRLEScaled: ported from Pizza Connection 2 at 0x53c130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53c130
#include "pc2_port.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __thiscall
Gfx_BlitRLEScaled(void *self,int arg1,uint32_t *arg2,uint32_t *arg3,int arg4,int arg5,
                 int arg6)

{
  uint16_t uvalue1;
  void *pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  int value7;
  int value8;
  int value9;
  uint16_t *uptr10;
  uint32_t *uptr11;
  uint32_t *uptr12;
  short *psVar13;
  int local_1c;
  uint32_t local_10;
  uint32_t local_c;
  int local_8;
  
  if (DAT_005747a8 != 0) {
    DAT_00584510 = operator_new(0x1000);
    local_1c = 0;
    do {
      uvalue5 = 0;
      value9 = 0;
      do {
        *(int *)((intptr_t)DAT_00584510 + (local_1c << 5 | uvalue5) * 4) =
             (intptr_t)(value9 + (value9 >> 0x1f & 0x1fU)) >> 5;
        uvalue5 = uvalue5 + 1;
        value9 = value9 + local_1c;
      } while ((intptr_t)uvalue5 < 0x20);
      local_1c = local_1c + 1;
    } while (local_1c < 0x20);
    DAT_005747a8 = 0;
  }
  Object_GetPair4(arg2,&local_10,&local_c);
  if ((intptr_t)*(short *)((intptr_t)self + 8) <= (intptr_t)local_c) {
    local_c = (intptr_t)*(short *)((intptr_t)self + 8);
  }
  value9 = *(int *)(arg1 + 0x28) + (*(int *)(arg1 + 0x20) * arg5 + arg4) * 2;
  arg2 = (uint32_t *)Object_GetPair10(arg2,&local_8);
  value8 = local_8;
  value7 = (intptr_t)*(short *)((intptr_t)self + 6);
  value6 = *(int *)(arg1 + 0x20) * 2;
  local_8 = local_8 * 2;
  if (arg6 == 0) {
    if (*(char *)(arg1 + 0x18) == '\0') {
      uptr11 = arg3;
      do {
        arg3 = arg2;
        arg2 = (uint32_t *)((intptr_t)arg2 + local_8);
        while( true ) {
          pvVar2 = DAT_00584510;
          uvalue5 = *arg3;
          arg3 = arg3 + 1;
          uvalue3 = uvalue5 & 0xffff;
          if (uvalue3 == 0xffff) break;
          uptr10 = (uint16_t *)((intptr_t)uptr11 + uvalue3 * 3);
          value8 = (uvalue5 >> 0x10) - uvalue3;
          uvalue5 = *(uint32_t *)(&DAT_00574798 + (local_c & 3) * 4);
          psVar13 = (short *)(value9 + uvalue3 * 2);
          do {
            uvalue1 = *uptr10;
            uvalue3 = (uint32_t)(uint8_t)((uint8_t)uptr10[1] + (uint8_t)uvalue5);
            if ((CARRY1((uint8_t)uptr10[1],(uint8_t)uvalue5)) && ((uvalue5 & 8) == 0)) {
              uvalue3 = 0xff;
            }
            uvalue5 = uvalue5 << 8 | uvalue5 >> 0x18;
            uptr10 = (uint16_t *)((intptr_t)uptr10 + 3);
            uvalue3 = uvalue3 & 0xf8;
            *psVar13 = ((short)*(uint32_t *)((intptr_t)pvVar2 + (uint32_t)(uvalue1 >> 10) * 4 + uvalue3 * 0x10)
                        * 0x20 + (short)*(uint32_t *)
                                         ((intptr_t)pvVar2 + ((uvalue1 & 0x3c0) >> 5) * 4 + uvalue3 * 0x10))
                       * 0x20 + (short)*(uint32_t *)
                                        ((intptr_t)pvVar2 + (uvalue1 & 0x1f) * 4 + uvalue3 * 0x10);
            value8 = value8 + -1;
            psVar13 = psVar13 + 1;
          } while (value8 != 0);
        }
        value9 = value9 + value6;
        uptr11 = (uint32_t *)((intptr_t)uptr11 + value7);
        local_c = local_c - 1;
      } while (local_c != 0);
      return;
    }
    uptr11 = arg3;
    do {
      arg3 = arg2;
      arg2 = (uint32_t *)((intptr_t)arg2 + local_8);
      while( true ) {
        pvVar2 = DAT_00584510;
        uvalue5 = *arg3;
        arg3 = arg3 + 1;
        uvalue3 = uvalue5 & 0xffff;
        if (uvalue3 == 0xffff) break;
        uptr10 = (uint16_t *)((intptr_t)uptr11 + uvalue3 * 3);
        value8 = (uvalue5 >> 0x10) - uvalue3;
        uvalue5 = *(uint32_t *)(&DAT_00574798 + (local_c & 3) * 4);
        psVar13 = (short *)(value9 + uvalue3 * 2);
        do {
          uvalue1 = *uptr10;
          uvalue3 = (uint32_t)(uint8_t)((uint8_t)uptr10[1] + (uint8_t)uvalue5);
          if ((CARRY1((uint8_t)uptr10[1],(uint8_t)uvalue5)) && ((uvalue5 & 8) == 0)) {
            uvalue3 = 0xff;
          }
          uvalue5 = uvalue5 << 8 | uvalue5 >> 0x18;
          uptr10 = (uint16_t *)((intptr_t)uptr10 + 3);
          uvalue3 = uvalue3 & 0xf8;
          *psVar13 = ((short)*(uint32_t *)((intptr_t)pvVar2 + (uint32_t)(uvalue1 >> 0xb) * 4 + uvalue3 * 0x10)
                      * 0x20 + (short)*(uint32_t *)
                                       ((intptr_t)pvVar2 + ((uvalue1 & 0x7c0) >> 6) * 4 + uvalue3 * 0x10)) *
                     0x40 + (short)*(uint32_t *)((intptr_t)pvVar2 + (uvalue1 & 0x1f) * 4 + uvalue3 * 0x10);
          value8 = value8 + -1;
          psVar13 = psVar13 + 1;
        } while (value8 != 0);
      }
      value9 = value9 + value6;
      uptr11 = (uint32_t *)((intptr_t)uptr11 + value7);
      local_c = local_c - 1;
    } while (local_c != 0);
    return;
  }
  if (arg6 != 1) {
    if (arg6 == 2) {
      local_8 = value8 * 8;
      if (*(char *)(arg1 + 0x18) != '\0') {
        local_c = local_c >> 2;
        uptr11 = arg3;
        do {
          arg3 = arg2;
          arg2 = arg2 + value8 * 2;
          while( true ) {
            pvVar2 = DAT_00584510;
            uvalue5 = *arg3;
            arg3 = arg3 + 1;
            uvalue3 = uvalue5 & 0xffff;
            if (uvalue3 == 0xffff) break;
            uvalue4 = uvalue3 + 3 >> 2;
            uptr12 = uptr11 + uvalue4 * 3;
            uvalue5 = (uvalue5 >> 0x10) - uvalue3 >> 2;
            if (uvalue5 != 0) {
              uvalue3 = *(uint32_t *)(&DAT_00574798 + (local_c & 3) * 4);
              psVar13 = (short *)(value9 + uvalue4 * 2);
              do {
                uvalue1 = (uint16_t)*uptr12;
                uvalue4 = (uint32_t)(uint8_t)(*(uint8_t *)((intptr_t)uptr12 + 2) + (uint8_t)uvalue3);
                if ((CARRY1(*(uint8_t *)((intptr_t)uptr12 + 2),(uint8_t)uvalue3)) && ((uvalue3 & 8) == 0)) {
                  uvalue4 = 0xff;
                }
                uvalue3 = uvalue3 << 8 | uvalue3 >> 0x18;
                uptr12 = uptr12 + 3;
                uvalue4 = uvalue4 & 0xf8;
                *psVar13 = ((short)*(uint32_t *)
                                    ((intptr_t)pvVar2 + (uint32_t)(uvalue1 >> 0xb) * 4 + uvalue4 * 0x10) * 0x20 +
                           (short)*(uint32_t *)
                                   ((intptr_t)pvVar2 + ((uvalue1 & 0x7c0) >> 6) * 4 + uvalue4 * 0x10)) * 0x40
                           + (short)*(uint32_t *)((intptr_t)pvVar2 + (uvalue1 & 0x1f) * 4 + uvalue4 * 0x10)
                ;
                uvalue5 = uvalue5 - 1;
                psVar13 = psVar13 + 1;
              } while (uvalue5 != 0);
            }
          }
          value9 = value9 + value6;
          uptr11 = uptr11 + value7;
          local_c = local_c - 1;
        } while (local_c != 0);
      }
    }
    return;
  }
  local_8 = value8 * 4;
  if (*(char *)(arg1 + 0x18) == '\0') {
    local_c = local_c >> 1;
    uptr11 = arg3;
    do {
      arg3 = arg2;
      arg2 = arg2 + value8;
      while( true ) {
        pvVar2 = DAT_00584510;
        uvalue5 = *arg3;
        arg3 = arg3 + 1;
        uvalue3 = uvalue5 & 0xffff;
        if (uvalue3 == 0xffff) break;
        uvalue4 = uvalue3 + 1 >> 1;
        uptr10 = (uint16_t *)((intptr_t)uptr11 + uvalue4 * 6);
        uvalue5 = (uvalue5 >> 0x10) - uvalue3 >> 1;
        if (uvalue5 != 0) {
          uvalue3 = *(uint32_t *)(&DAT_00574798 + (local_c & 3) * 4);
          psVar13 = (short *)(value9 + uvalue4 * 2);
          do {
            uvalue1 = *uptr10;
            uvalue4 = (uint32_t)(uint8_t)((uint8_t)uptr10[1] + (uint8_t)uvalue3);
            if ((CARRY1((uint8_t)uptr10[1],(uint8_t)uvalue3)) && ((uvalue3 & 8) == 0)) {
              uvalue4 = 0xff;
            }
            uvalue3 = uvalue3 << 8 | uvalue3 >> 0x18;
            uptr10 = uptr10 + 3;
            uvalue4 = uvalue4 & 0xf8;
            *psVar13 = ((short)*(uint32_t *)((intptr_t)pvVar2 + (uint32_t)(uvalue1 >> 10) * 4 + uvalue4 * 0x10)
                        * 0x20 + (short)*(uint32_t *)
                                         ((intptr_t)pvVar2 + ((uvalue1 & 0x3c0) >> 5) * 4 + uvalue4 * 0x10))
                       * 0x20 + (short)*(uint32_t *)
                                        ((intptr_t)pvVar2 + (uvalue1 & 0x1f) * 4 + uvalue4 * 0x10);
            uvalue5 = uvalue5 - 1;
            psVar13 = psVar13 + 1;
          } while (uvalue5 != 0);
        }
      }
      value9 = value9 + value6;
      uptr11 = (uint32_t *)((intptr_t)uptr11 + value7 * 2);
      local_c = local_c - 1;
    } while (local_c != 0);
    return;
  }
  local_c = local_c >> 1;
  uptr11 = arg3;
  do {
    arg3 = arg2;
    arg2 = arg2 + value8;
    while( true ) {
      pvVar2 = DAT_00584510;
      uvalue5 = *arg3;
      arg3 = arg3 + 1;
      uvalue3 = uvalue5 & 0xffff;
      if (uvalue3 == 0xffff) break;
      uvalue4 = uvalue3 + 1 >> 1;
      uptr10 = (uint16_t *)((intptr_t)uptr11 + uvalue4 * 6);
      uvalue5 = (uvalue5 >> 0x10) - uvalue3 >> 1;
      if (uvalue5 != 0) {
        uvalue3 = *(uint32_t *)(&DAT_00574798 + (local_c & 3) * 4);
        psVar13 = (short *)(value9 + uvalue4 * 2);
        do {
          uvalue1 = *uptr10;
          uvalue4 = (uint32_t)(uint8_t)((uint8_t)uptr10[1] + (uint8_t)uvalue3);
          if ((CARRY1((uint8_t)uptr10[1],(uint8_t)uvalue3)) && ((uvalue3 & 8) == 0)) {
            uvalue4 = 0xff;
          }
          uvalue3 = uvalue3 << 8 | uvalue3 >> 0x18;
          uptr10 = uptr10 + 3;
          uvalue4 = uvalue4 & 0xf8;
          *psVar13 = ((short)*(uint32_t *)((intptr_t)pvVar2 + (uint32_t)(uvalue1 >> 0xb) * 4 + uvalue4 * 0x10)
                      * 0x20 + (short)*(uint32_t *)
                                       ((intptr_t)pvVar2 + ((uvalue1 & 0x7c0) >> 6) * 4 + uvalue4 * 0x10)) *
                     0x40 + (short)*(uint32_t *)((intptr_t)pvVar2 + (uvalue1 & 0x1f) * 4 + uvalue4 * 0x10);
          uvalue5 = uvalue5 - 1;
          psVar13 = psVar13 + 1;
        } while (uvalue5 != 0);
      }
    }
    value9 = value9 + value6;
    uptr11 = (uint32_t *)((intptr_t)uptr11 + value7 * 2);
    local_c = local_c - 1;
  } while (local_c != 0);
  return;
}
