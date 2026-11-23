// Sprite_ConvertTo16Bit: ported from Pizza Connection 2 at 0x536ea0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x536ea0
#include "pc2_port.h"

uint16_t * __thiscall Sprite_ConvertTo16Bit(void *self,int arg1,int arg2,int arg3)

{
  uint8_t *bptr1;
  uint8_t flag2;
  uint16_t *uptr3;
  int value4;
  uint8_t *bptr5;
  uint8_t *bptr6;
  uint16_t uvalue7;
  int value8;
  uint32_t uvalue9;
  int value10;
  uint32_t uvalue11;
  uint16_t uvalue12;
  uint32_t uvalue13;
  uint16_t *uptr14;
  uint32_t uvalue15;
  uint32_t *uptr16;
  uint16_t uvalue17;
  int value18;
  uint32_t local_1c;
  char local_10 [16];
  
  if ((arg3 != 0) &&
     ((*(char *)((intptr_t)self + 0x10) == '\x10' || (*(char *)((intptr_t)self + 0x10) == '\x0f')))) {
    return *(uint16_t **)((intptr_t)self + 0x18);
  }
  uptr3 = operator_new(*(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4) * 2);
  if (uptr3 == (uint16_t *)0x0) {
    return (uint16_t *)0x0;
  }
  switch(*(char *)((intptr_t)self + 0x10)) {
  case '\b':
    value10 = *(int *)((intptr_t)self + 0x14);
    value8 = *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4);
    value18 = *(int *)((intptr_t)self + 0x18);
    value4 = 0;
    uptr14 = uptr3;
    if (0 < value8) {
      do {
        bptr6 = (uint8_t *)(value4 + value18);
        value4 = value4 + 1;
        *uptr14 = *(uint16_t *)(value10 + 4 + (uint32_t)*bptr6 * 2);
        uptr14 = uptr14 + 1;
      } while (value4 < value8);
    }
    break;
  case '\x0f':
  case '\x10':
    uvalue9 = *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4);
    uptr16 = *(uint32_t **)((intptr_t)self + 0x18);
    uptr14 = uptr3;
    for (uvalue15 = (uvalue9 & 0x7fffffff) >> 1; uvalue15 != 0; uvalue15 = uvalue15 - 1) {
      *(uint32_t *)uptr14 = *uptr16;
      uptr16 = uptr16 + 1;
      uptr14 = uptr14 + 2;
    }
    for (uvalue9 = uvalue9 * 2 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *(uint8_t *)uptr14 = *(uint8_t *)uptr16;
      uptr16 = (uint32_t *)((intptr_t)uptr16 + 1);
      uptr14 = (uint16_t *)((intptr_t)uptr14 + 1);
    }
    break;
  case '\x18':
  case ' ':
    bptr6 = *(uint8_t **)((intptr_t)self + 0x18);
    uvalue9 = (uint32_t)(*(char *)((intptr_t)self + 0x10) == ' ');
    if (arg2 == 0) {
      value10 = *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4);
      if (*(char *)(arg1 + 0x18) == '\0') {
        if (0 < value10) {
          uptr14 = uptr3;
          do {
            bptr1 = bptr6 + 1;
            flag2 = *bptr6;
            bptr5 = bptr6 + 2;
            bptr6 = bptr5 + uvalue9 + 1;
            value10 = value10 + -1;
            *uptr14 = (*bptr5 & 0xf8) << 7 | (*bptr1 & 0xf8) << 2 | (uint16_t)(flag2 >> 3);
            uptr14 = uptr14 + 1;
          } while (value10 != 0);
        }
      }
      else if (0 < value10) {
        uptr14 = uptr3;
        do {
          bptr1 = bptr6 + 1;
          flag2 = *bptr6;
          bptr5 = bptr6 + 2;
          bptr6 = bptr5 + uvalue9 + 1;
          value10 = value10 + -1;
          *uptr14 = (*bptr5 & 0xf8) << 8 | (*bptr1 & 0xfc) << 3 | (uint16_t)(flag2 >> 3);
          uptr14 = uptr14 + 1;
        } while (value10 != 0);
      }
    }
    else {
      local_10[1] = 0xfe;
      local_10[3] = 0xff;
      local_10[4] = 0xfe;
      local_10[0xb] = 0xff;
      local_10[6] = 0xfd;
      local_10[0xe] = 0xfd;
      local_10[0] = '\0';
      local_10[2] = 1;
      local_10[5] = 2;
      local_10[7] = 3;
      local_10[8] = 2;
      local_10[9] = 0;
      local_10[10] = 1;
      local_10[0xc] = 0xfc;
      local_10[0xd] = 4;
      local_10[0xf] = 3;
      arg2 = 0;
      local_1c = 0;
      if (0 < *(int *)((intptr_t)self + 8)) {
        do {
          uvalue15 = 0;
          if (0 < *(int *)((intptr_t)self + 4)) {
            uptr14 = uptr3 + arg2;
            do {
              value10 = (intptr_t)local_10[(uvalue15 & 3) + (local_1c & 3) * 4];
              value18 = (uint32_t)*bptr6 + value10;
              uvalue11 = (uint32_t)bptr6[1] + value10;
              uvalue13 = (uint32_t)bptr6[2] + value10;
              if (value18 < 0x100) {
                if (value18 < 1) {
                  uvalue17 = 0;
                }
                else {
                  uvalue17 = (uint16_t)(value18 >> 3);
                }
              }
              else {
                uvalue17 = 0x1f;
              }
              if (*(char *)(arg1 + 0x18) == '\0') {
                if ((intptr_t)uvalue11 < 0x100) {
                  if ((intptr_t)uvalue11 < 1) {
                    uvalue7 = 0;
                  }
                  else {
                    uvalue7 = (uint16_t)((uvalue11 & 0xf8) << 2);
                  }
                }
                else {
                  uvalue7 = 0x3e0;
                }
                if ((intptr_t)uvalue13 < 0x100) {
                  if ((intptr_t)uvalue13 < 1) goto LAB_0053717d;
                  uvalue12 = (uint16_t)((uvalue13 & 0xf8) << 7);
                }
                else {
                  uvalue12 = 0x7c00;
                }
              }
              else {
                if ((intptr_t)uvalue11 < 0x100) {
                  if ((intptr_t)uvalue11 < 1) {
                    uvalue7 = 0;
                  }
                  else {
                    uvalue7 = (uint16_t)((uvalue11 & 0xfc) << 3);
                  }
                }
                else {
                  uvalue7 = 0x7e0;
                }
                if ((intptr_t)uvalue13 < 0x100) {
                  if ((intptr_t)uvalue13 < 1) {
LAB_0053717d:
                    uvalue12 = 0;
                  }
                  else {
                    uvalue12 = (uint16_t)((uvalue13 & 0xf8) << 8);
                  }
                }
                else {
                  uvalue12 = 0xf800;
                }
              }
              *uptr14 = uvalue12 | uvalue7 | uvalue17;
              arg2 = arg2 + 1;
              uptr14 = uptr14 + 1;
              bptr6 = bptr6 + uvalue9 + 3;
              uvalue15 = uvalue15 + 1;
            } while ((intptr_t)uvalue15 < *(int *)((intptr_t)self + 4));
          }
          local_1c = local_1c + 1;
        } while ((intptr_t)local_1c < *(int *)((intptr_t)self + 8));
      }
    }
  }
  if (arg3 != 0) {
    Mem_Free(*(LPVOID *)((intptr_t)self + 0x18));
    *(uint16_t **)((intptr_t)self + 0x18) = uptr3;
    *(uint8_t *)((intptr_t)self + 0x10) = 0x10;
    *(int *)((intptr_t)self + 0xc) = *(int *)((intptr_t)self + 8) * *(int *)((intptr_t)self + 4) * 2;
  }
  return uptr3;
}
