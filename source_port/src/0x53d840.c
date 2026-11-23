// Sprite_Rotate: ported from Pizza Connection 2 at 0x53d840.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d840
#include "pc2_port.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint16_t * __thiscall Sprite_Rotate(void *self,uint16_t *arg1)

{
  uint16_t *uptr1;
  void *pvVar2;
  uint32_t uvalue3;
  uint16_t *uptr4;
  int value5;
  int value6;
  uint32_t uvalue7;
  int value8;
  uint16_t *uptr9;
  uint32_t *uptr10;
  uint8_t *uptr11;
  uint8_t *uptr12;
  uint16_t *uptr13;
  uint32_t *uptr14;
  uint16_t *uptr15;
  uint8_t *uptr16;
  uint8_t *uptr17;
  int local_14;
  uint32_t *local_10;
  uint32_t *local_c;
  
  uptr1 = (uint16_t *)(uint32_t)*(uint8_t *)((intptr_t)self + 0x36);
  if (uptr1 != arg1) {
    uptr1 = (uint16_t *)(uint32_t)*(uint8_t *)((intptr_t)self + 0x39);
    uvalue3 = (uint32_t)arg1 & 7;
    *(char *)((intptr_t)self + 0x36) = (char)uvalue3;
    if (*(uint8_t *)((intptr_t)self + 0x39) == 0) {
      uptr1 = (uint16_t *)Sprite_RealizeLazy(self);
    }
    if (((*(uint8_t *)((intptr_t)self + 4) & 1) == 0) && (*(char *)((intptr_t)self + 5) == '\b')) {
      if (*(int *)((intptr_t)self + 0x30) == 0) {
        pvVar2 = operator_new(*(uint32_t *)((intptr_t)self + 0x18));
        *(void **)((intptr_t)self + 0x30) = pvVar2;
      }
      if ((*(uint8_t *)((intptr_t)self + 4) & 0x10) == 0) {
        local_14 = (intptr_t)(*(short *)((intptr_t)self + 6) >> 1);
        arg1 = (uint16_t *)(intptr_t)*(short *)((intptr_t)self + 6);
        if (*(char *)((intptr_t)self + 5) == '\b') {
          uvalue3 = uvalue3 + 8;
        }
      }
      else {
        local_14 = (intptr_t)*(short *)((intptr_t)self + 6);
        arg1 = (uint16_t *)(local_14 * 2);
      }
      uptr1 = arg1;
      value8 = (intptr_t)*(short *)((intptr_t)self + 8);
      switch(uvalue3) {
      case 0:
      case 8:
        uptr1 = *(uint16_t **)((intptr_t)self + 0x18);
        uptr10 = *(uint32_t **)((intptr_t)self + 0x2c);
        local_c = *(uint32_t **)((intptr_t)self + 0x30);
        break;
      case 1:
        uptr9 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr1 = (uint16_t *)(*(int *)((intptr_t)self + 0x30) + -2 + local_14 * 2);
        uptr4 = uptr9;
        do {
          value6 = local_14;
          uptr13 = uptr4;
          uptr15 = uptr1;
          do {
            *uptr15 = *uptr13;
            uptr15 = uptr15 + -1;
            value6 = value6 + -1;
            uptr13 = uptr13 + 1;
          } while (value6 != 0);
          uptr4 = (uint16_t *)((intptr_t)uptr4 + (intptr_t)arg1);
          uptr1 = (uint16_t *)((intptr_t)uptr1 + (intptr_t)arg1);
          value8 = value8 + -1;
        } while (value8 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 0;
        return uptr9;
      case 2:
        uptr9 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr1 = (uint16_t *)(*(int *)((intptr_t)self + 0x30) + -2 + value8 * 2);
        value6 = value8;
        do {
          value5 = local_14;
          uptr4 = uptr9;
          uptr13 = uptr1;
          do {
            *uptr13 = *uptr4;
            uptr13 = uptr13 + value8;
            value5 = value5 + -1;
            uptr4 = uptr4 + 1;
          } while (value5 != 0);
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          uptr1 = uptr1 + -1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return self;
      case 3:
        uptr9 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr1 = (uint16_t *)(*(int *)((intptr_t)self + 0x30) + -2 + value8 * local_14 * 2);
        value6 = value8;
        uptr4 = uptr1;
        do {
          value5 = local_14;
          uptr13 = uptr9;
          uptr15 = uptr4;
          do {
            *uptr15 = *uptr13;
            uptr15 = uptr15 + -value8;
            value5 = value5 + -1;
            uptr13 = uptr13 + 1;
          } while (value5 != 0);
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          uptr4 = uptr4 + -1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return uptr1;
      case 4:
        uptr4 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr9 = (uint16_t *)(*(int *)((intptr_t)self + 0x30) + -2 + local_14 * 2);
        uptr1 = uptr4 + (value8 + -1) * local_14;
        do {
          value6 = local_14;
          uptr13 = uptr1;
          uptr15 = uptr9;
          do {
            *uptr15 = *uptr13;
            uptr15 = uptr15 + -1;
            value6 = value6 + -1;
            uptr13 = uptr13 + 1;
          } while (value6 != 0);
          uptr1 = (uint16_t *)((intptr_t)uptr1 - (intptr_t)arg1);
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          value8 = value8 + -1;
        } while (value8 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 0;
        return uptr4;
      case 5:
        local_10 = *(uint32_t **)((intptr_t)self + 0x30);
        local_c = (uint32_t *)(*(int *)((intptr_t)self + 0x2c) + (value8 + -1) * local_14 * 2);
        arg1 = (uint16_t *)0x0;
        if (0 < value8 + -1) {
          do {
            uptr10 = local_c;
            uptr14 = local_10;
            for (uvalue3 = (uint32_t)uptr1 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *uptr14 = *uptr10;
              uptr10 = uptr10 + 1;
              uptr14 = uptr14 + 1;
            }
            for (uvalue3 = (uint32_t)uptr1 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *(uint8_t *)uptr14 = *(uint8_t *)uptr10;
              uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
              uptr14 = (uint32_t *)((intptr_t)uptr14 + 1);
            }
            local_10 = (uint32_t *)((intptr_t)local_10 + local_14 * 2);
            local_c = (uint32_t *)((intptr_t)local_c + local_14 * -2);
            arg1 = (uint16_t *)((intptr_t)arg1 + 1);
          } while ((intptr_t)arg1 < *(short *)((intptr_t)self + 8) + -1);
        }
        uptr10 = local_c;
        local_c = local_10;
        break;
      case 6:
        uptr9 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr1 = (uint16_t *)(*(int *)((intptr_t)self + 0x30) + (local_14 + -1) * value8 * 2);
        value6 = value8;
        uptr4 = uptr9;
        do {
          value5 = local_14;
          uptr13 = uptr4;
          uptr15 = uptr1;
          do {
            *uptr15 = *uptr13;
            uptr15 = uptr15 + -value8;
            value5 = value5 + -1;
            uptr13 = uptr13 + 1;
          } while (value5 != 0);
          uptr4 = (uint16_t *)((intptr_t)uptr4 + (intptr_t)arg1);
          uptr1 = uptr1 + 1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return uptr9;
      case 7:
        uptr1 = *(uint16_t **)((intptr_t)self + 0x30);
        uptr9 = *(uint16_t **)((intptr_t)self + 0x2c);
        value6 = value8;
        do {
          value5 = local_14;
          uptr4 = uptr9;
          uptr13 = uptr1;
          do {
            *uptr13 = *uptr4;
            uptr13 = uptr13 + value8;
            value5 = value5 + -1;
            uptr4 = uptr4 + 1;
          } while (value5 != 0);
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          uptr1 = uptr1 + 1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return self;
      case 9:
        uptr17 = *(uint8_t **)((intptr_t)self + 0x2c);
        uptr1 = (uint16_t *)((intptr_t)arg1 + *(int *)((intptr_t)self + 0x30) + -1);
        uptr9 = uptr1;
        do {
          uptr4 = arg1;
          uptr12 = uptr17;
          uptr13 = uptr9;
          do {
            *(uint8_t *)uptr13 = *uptr12;
            uptr13 = (uint16_t *)((intptr_t)uptr13 + -1);
            uptr4 = (uint16_t *)((intptr_t)uptr4 + -1);
            uptr12 = uptr12 + 1;
          } while (uptr4 != (uint16_t *)0x0);
          uptr17 = uptr17 + (intptr_t)arg1;
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          value8 = value8 + -1;
        } while (value8 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 0;
        return uptr1;
      case 10:
        uptr1 = *(uint16_t **)((intptr_t)self + 0x2c);
        uptr17 = (uint8_t *)(value8 + -1 + *(int *)((intptr_t)self + 0x30));
        value6 = value8;
        uptr9 = uptr1;
        do {
          uptr4 = arg1;
          uptr13 = uptr9;
          uptr12 = uptr17;
          do {
            *uptr12 = *(uint8_t *)uptr13;
            uptr12 = uptr12 + value8;
            uptr4 = (uint16_t *)((intptr_t)uptr4 + -1);
            uptr13 = (uint16_t *)((intptr_t)uptr13 + 1);
          } while (uptr4 != (uint16_t *)0x0);
          uptr9 = (uint16_t *)((intptr_t)uptr9 + (intptr_t)arg1);
          uptr17 = uptr17 + -1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return uptr1;
      case 0xb:
        uptr12 = *(uint8_t **)((intptr_t)self + 0x2c);
        uptr17 = (uint8_t *)(value8 * (intptr_t)arg1 + -1 + *(int *)((intptr_t)self + 0x30));
        value6 = value8;
        do {
          uptr1 = arg1;
          uptr11 = uptr12;
          uptr16 = uptr17;
          do {
            *uptr16 = *uptr11;
            uptr16 = uptr16 + -value8;
            uptr1 = (uint16_t *)((intptr_t)uptr1 + -1);
            uptr11 = uptr11 + 1;
          } while (uptr1 != (uint16_t *)0x0);
          uptr12 = uptr12 + (intptr_t)arg1;
          uptr17 = uptr17 + -1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return self;
      case 0xc:
        uptr17 = (uint8_t *)((intptr_t)arg1 + *(int *)((intptr_t)self + 0x30) + -1);
        uptr12 = (uint8_t *)((value8 + -1) * (intptr_t)arg1 + *(int *)((intptr_t)self + 0x2c));
        do {
          uptr1 = arg1;
          uptr11 = uptr12;
          uptr16 = uptr17;
          do {
            *uptr16 = *uptr11;
            uptr16 = uptr16 + -1;
            uptr1 = (uint16_t *)((intptr_t)uptr1 + -1);
            uptr11 = uptr11 + 1;
          } while (uptr1 != (uint16_t *)0x0);
          uptr12 = uptr12 + -(intptr_t)arg1;
          uptr17 = uptr17 + (intptr_t)arg1;
          value8 = value8 + -1;
        } while (value8 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 0;
        return self;
      case 0xd:
        local_c = *(uint32_t **)((intptr_t)self + 0x30);
        local_10 = (uint32_t *)((value8 + -1) * (intptr_t)arg1 + *(int *)((intptr_t)self + 0x2c));
        arg1 = (uint16_t *)0x0;
        if (0 < value8 + -1) {
          do {
            uptr10 = local_10;
            uptr14 = local_c;
            for (uvalue3 = (uint32_t)uptr1 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *uptr14 = *uptr10;
              uptr10 = uptr10 + 1;
              uptr14 = uptr14 + 1;
            }
            for (uvalue3 = (uint32_t)uptr1 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
              *(uint8_t *)uptr14 = *(uint8_t *)uptr10;
              uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
              uptr14 = (uint32_t *)((intptr_t)uptr14 + 1);
            }
            local_c = (uint32_t *)((intptr_t)local_c + (intptr_t)uptr1);
            local_10 = (uint32_t *)((intptr_t)local_10 - (intptr_t)uptr1);
            arg1 = (uint16_t *)((intptr_t)arg1 + 1);
          } while ((intptr_t)arg1 < *(short *)((intptr_t)self + 8) + -1);
        }
        uptr10 = local_10;
        break;
      case 0xe:
        uptr17 = *(uint8_t **)((intptr_t)self + 0x2c);
        uptr12 = (uint8_t *)(((intptr_t)arg1 + -1) * value8 + *(int *)((intptr_t)self + 0x30));
        value6 = value8;
        do {
          uptr1 = arg1;
          uptr11 = uptr17;
          uptr16 = uptr12;
          do {
            *uptr16 = *uptr11;
            uptr16 = uptr16 + -value8;
            uptr1 = (uint16_t *)((intptr_t)uptr1 + -1);
            uptr11 = uptr11 + 1;
          } while (uptr1 != (uint16_t *)0x0);
          uptr17 = uptr17 + (intptr_t)arg1;
          uptr12 = uptr12 + 1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return self;
      case 0xf:
        uptr17 = *(uint8_t **)((intptr_t)self + 0x30);
        uptr12 = *(uint8_t **)((intptr_t)self + 0x2c);
        value6 = value8;
        do {
          uptr1 = arg1;
          uptr11 = uptr12;
          uptr16 = uptr17;
          do {
            *uptr16 = *uptr11;
            uptr16 = uptr16 + value8;
            uptr1 = (uint16_t *)((intptr_t)uptr1 + -1);
            uptr11 = uptr11 + 1;
          } while (uptr1 != (uint16_t *)0x0);
          uptr12 = uptr12 + (intptr_t)arg1;
          uptr17 = uptr17 + 1;
          value6 = value6 + -1;
        } while (value6 != 0);
        *(uint8_t *)((intptr_t)self + 0x37) = 1;
        return self;
      default:
        uvalue3 = *(uint32_t *)((intptr_t)self + 0x18);
        *(uint8_t *)((intptr_t)self + 0x37) = 0;
        uptr10 = *(uint32_t **)((intptr_t)self + 0x2c);
        uptr14 = *(uint32_t **)((intptr_t)self + 0x30);
        for (uvalue7 = uvalue3 >> 2; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *uptr14 = *uptr10;
          uptr10 = uptr10 + 1;
          uptr14 = uptr14 + 1;
        }
        for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
          *(uint8_t *)uptr14 = *(uint8_t *)uptr10;
          uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
          uptr14 = (uint32_t *)((intptr_t)uptr14 + 1);
        }
        return arg1;
      }
      for (uvalue3 = (uint32_t)uptr1 >> 2; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *local_c = *uptr10;
        uptr10 = uptr10 + 1;
        local_c = local_c + 1;
      }
      for (uvalue3 = (uint32_t)uptr1 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
        *(uint8_t *)local_c = *(uint8_t *)uptr10;
        uptr10 = (uint32_t *)((intptr_t)uptr10 + 1);
        local_c = (uint32_t *)((intptr_t)local_c + 1);
      }
      *(uint8_t *)((intptr_t)self + 0x37) = 0;
      return uptr1;
    }
  }
  return uptr1;
}
