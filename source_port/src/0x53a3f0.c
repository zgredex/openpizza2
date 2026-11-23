// Sprite_BlitClipped: ported from Pizza Connection 2 at 0x53a3f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a3f0
#include "pc2_port.h"

bool __thiscall Sprite_BlitClipped(void *self,uint16_t *arg1,int arg2,int arg3,uint32_t *arg4)

{
  uint8_t flag1;
  int value2;
  int value3;
  uint16_t *uptr4;
  int value5;
  int value6;
  int value7;
  
  flag1 = *(uint8_t *)((intptr_t)self + 4);
  if ((flag1 & 4) != 0) {
    arg2 = arg2 - *(short *)((intptr_t)self + 10);
    arg3 = arg3 - *(short *)((intptr_t)self + 0xc);
  }
  if ((((-1 < arg2) && (-1 < arg3)) &&
      (value5 = (intptr_t)*(short *)((intptr_t)self + 6), arg2 < value5)) &&
     (value2 = (intptr_t)*(short *)((intptr_t)self + 8), arg3 < value2)) {
    value7 = value5 >> 1;
    if ((flag1 & 2) == 0) {
      if (arg4 != (uint32_t *)0x0) {
        if (0xe < *(uint8_t *)((intptr_t)self + 5)) {
          *arg4 = (uint32_t)arg1[value7 * arg3 + arg2];
          return true;
        }
        *arg4 = (uint32_t)*(uint8_t *)((intptr_t)arg1 + arg2 + value5 * arg3);
      }
      return true;
    }
    if (0xe < *(uint8_t *)((intptr_t)self + 5)) {
      if ((flag1 & 0x10) == 0) {
        if ((flag1 & 1) == 0) {
          if (arg4 != (uint32_t *)0x0) {
            *arg4 = (uint32_t)arg1[value7 * arg3 + arg2];
          }
          return (uint32_t)arg1[((intptr_t)*(short *)((intptr_t)self + 6) >> 1) * arg3 + arg2] !=
                 *(uint32_t *)((intptr_t)self + 0x1c);
        }
        value6 = 0;
        uptr4 = arg1;
        if (0 < value2) {
          do {
            value3 = 0;
            if (0 < value7) {
              do {
                if ((value6 == arg3) && (value3 == arg2)) {
                  if (arg4 != (uint32_t *)0x0) {
                    *arg4 = (uint32_t)*uptr4;
                  }
                  return (uint32_t)*uptr4 != *(uint32_t *)((intptr_t)self + 0x1c);
                }
                if ((uint32_t)*uptr4 == *(uint32_t *)((intptr_t)self + 0x1c)) {
                  value3 = value3 + (uint32_t)uptr4[1];
                  if ((value6 == arg3) && (arg2 < value3)) {
                    return false;
                  }
                  uptr4 = uptr4 + 2;
                }
                else {
                  uptr4 = uptr4 + 1;
                  value3 = value3 + 1;
                }
              } while (value3 < value7);
            }
            value6 = value6 + 1;
          } while (value6 < value2);
        }
      }
      else {
        value6 = 0;
        uptr4 = arg1;
        if (0 < value2) {
          do {
            value3 = 0;
            if (0 < value7) {
              do {
                if ((value6 == arg3) && (value3 == arg2)) {
                  if (arg4 != (uint32_t *)0x0) {
                    *arg4 = (uint32_t)*uptr4;
                  }
                  return *uptr4 != 0;
                }
                if (*uptr4 == 0) {
                  value3 = value3 + (uint32_t)uptr4[1];
                  if ((value6 == arg3) && (arg2 <= value3)) {
                    return false;
                  }
                }
                else {
                  value3 = value3 + 1;
                }
                uptr4 = uptr4 + 2;
              } while (value3 < value7);
            }
            value6 = value6 + 1;
          } while (value6 < value2);
        }
      }
    }
    if (*(char *)((intptr_t)self + 5) == '\b') {
      if ((*(uint8_t *)((intptr_t)self + 4) & 0x10) == 0) {
        if ((*(uint8_t *)((intptr_t)self + 4) & 1) == 0) {
          if (arg4 != (uint32_t *)0x0) {
            *arg4 = (uint32_t)*(uint8_t *)((intptr_t)arg1 + arg2 + value5 * arg3);
          }
          return (uint32_t)*(uint8_t *)((intptr_t)arg1 + arg2 + *(short *)((intptr_t)self + 6) * arg3) !=
                 *(uint32_t *)((intptr_t)self + 0x1c);
        }
        value7 = 0;
        if (0 < value2) {
          do {
            value6 = 0;
            if (0 < value5) {
              do {
                if ((value7 == arg3) && (value6 == arg2)) {
                  if (arg4 != (uint32_t *)0x0) {
                    *arg4 = (uint32_t)(uint8_t)*arg1;
                  }
                  return (uint32_t)(uint8_t)*arg1 != *(uint32_t *)((intptr_t)self + 0x1c);
                }
                if ((uint32_t)(uint8_t)*arg1 == *(uint32_t *)((intptr_t)self + 0x1c)) {
                  value6 = value6 + (uint32_t)*(uint8_t *)((intptr_t)arg1 + 1);
                  if ((value7 == arg3) && (arg2 <= value6)) {
                    return false;
                  }
                  arg1 = arg1 + 1;
                }
                else {
                  arg1 = (uint16_t *)((intptr_t)arg1 + 1);
                  value6 = value6 + 1;
                }
              } while (value6 < value5);
            }
            value7 = value7 + 1;
          } while (value7 < value2);
        }
      }
      else {
        value7 = 0;
        if (0 < value2) {
          do {
            value6 = 0;
            if (0 < value5) {
              do {
                if ((value7 == arg3) && (value6 == arg2)) {
                  if (arg4 != (uint32_t *)0x0) {
                    *arg4 = (uint32_t)(uint8_t)*arg1;
                  }
                  return (uint8_t)*arg1 != 0;
                }
                if ((uint8_t)*arg1 == 0) {
                  value6 = value6 + (uint32_t)*(uint8_t *)((intptr_t)arg1 + 1);
                  if ((value7 == arg3) && (arg2 <= value6)) {
                    return false;
                  }
                }
                else {
                  value6 = value6 + 1;
                }
                arg1 = arg1 + 1;
              } while (value6 < value5);
            }
            value7 = value7 + 1;
            if (value2 <= value7) {
              return false;
            }
          } while( true );
        }
      }
    }
  }
  return false;
}
