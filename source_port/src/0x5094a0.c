// Object_SyncChildState: ported from Pizza Connection 2 at 0x5094a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5094a0
#include "pc2_port.h"

void __thiscall Object_SyncChildState(void *self,int arg1,int arg2)

{
  int *ptr1;
  int value2;
  int value3;
  
  value2 = *(int *)(arg1 + 0x30);
  if (*(int *)((intptr_t)self + 0x58) == value2) {
    *(uint32_t *)((intptr_t)self + 0x58) = 0xffffffff;
  }
  if (arg2 < 0x60) {
    if (arg2 < 0x55) {
      if (arg2 < 0x4b) {
        if (arg2 < 0x41) {
          if (arg2 < 0x37) {
            if (0x2c < arg2) goto LAB_00509550;
            if (arg2 < 0x23) {
              if (arg2 < 0x19) {
                value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c);
                if (arg2 < 0xf) {
                  value3 = value3 + -0x14;
                }
                else {
                  value3 = value3 + -10;
                }
              }
              else {
                value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + -5;
              }
            }
            else {
              value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + -3;
            }
          }
          else {
            value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + 3;
          }
        }
        else {
          value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + 5;
        }
      }
      else {
        value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + 8;
      }
    }
    else {
      value3 = *(int *)((intptr_t)self + value2 * 4 + 0x5c) + 10;
    }
    *(int *)((intptr_t)self + value2 * 4 + 0x5c) = value3;
  }
  else {
    *(uint32_t *)((intptr_t)self + value2 * 4 + 0x5c) = 100;
    *(int *)((intptr_t)self + 0x58) = value2;
    value3 = 0;
    ptr1 = (int *)((intptr_t)self + 0x5c);
    do {
      if (value3 != value2) {
        *ptr1 = *ptr1 + -10;
      }
      value3 = value3 + 1;
      ptr1 = ptr1 + 1;
    } while (value3 < 6);
  }
LAB_00509550:
  ptr1 = (int *)((intptr_t)self + 0x5c);
  value2 = 6;
  do {
    if (100 < *ptr1) {
      *ptr1 = 100;
    }
    if (*ptr1 < -100) {
      *ptr1 = -100;
    }
    ptr1 = ptr1 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  return;
}
