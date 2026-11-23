// Sprite_TestCollision: ported from Pizza Connection 2 at 0x53d720.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53d720
#include "pc2_port.h"

uint32_t __thiscall Sprite_TestCollision(void *self,int arg1,int arg2,int arg3)

{
  uint8_t flag1;
  int value2;
  char *cptr3;
  int value4;
  int value5;
  int value6;
  
  if (*(char *)((intptr_t)self + 0x39) == '\0') {
    Sprite_RealizeLazy(self);
  }
  flag1 = *(uint8_t *)((intptr_t)self + 4);
  if ((flag1 & 4) == 0) {
    value5 = arg2;
  }
  else {
    arg1 = arg1 - *(short *)((intptr_t)self + 10);
    value5 = arg2 - *(short *)((intptr_t)self + 0xc);
  }
  if ((*(char *)((intptr_t)self + 5) == '\b') && ((flag1 & 0x10) != 0)) {
    value6 = value5 * 800 + arg1 + arg3;
    cptr3 = *(char **)((intptr_t)self + 0x30);
    if (cptr3 == (char *)0x0) {
      arg2 = (intptr_t)*(short *)((intptr_t)self + 8);
      value4 = (intptr_t)*(short *)((intptr_t)self + 6);
      cptr3 = *(char **)((intptr_t)self + 0x2c);
    }
    else if (*(char *)((intptr_t)self + 0x37) == '\0') {
      arg2 = (intptr_t)*(short *)((intptr_t)self + 8);
      value4 = (intptr_t)*(short *)((intptr_t)self + 6);
    }
    else {
      arg2 = (intptr_t)*(short *)((intptr_t)self + 6);
      value4 = (intptr_t)*(short *)((intptr_t)self + 8);
    }
    if ((((-1 < arg1) && (-1 < value5)) && (value4 + arg1 < 0x321)) && (value5 + arg2 < 0x259)
       ) {
      value5 = 0;
      if (0 < arg2) {
        do {
          value2 = 0;
          if (0 < value4) {
            do {
              if (*cptr3 == '\0') {
                if ((flag1 & 1) == 0) {
                  value2 = value2 + 1;
                }
                else {
                  value2 = value2 + (uint32_t)(uint8_t)cptr3[1];
                }
              }
              else {
                if (*(char *)(value2 + value6) == '\0') {
                  return 0;
                }
                if (*(char *)(value2 + value6) == -1) {
                  return 0;
                }
                value2 = value2 + 1;
              }
              cptr3 = cptr3 + 2;
            } while (value2 < value4);
          }
          value6 = value6 + 800;
          value5 = value5 + 1;
        } while (value5 < arg2);
      }
      return 1;
    }
  }
  return 0;
}
