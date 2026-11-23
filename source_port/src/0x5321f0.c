// UI_ClipRect: ported from Pizza Connection 2 at 0x5321f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5321f0
#include "pc2_port.h"

void __thiscall UI_ClipRect(void *self,int *arg1,int arg2)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value4 = *arg1;
  value5 = arg1[1];
  value2 = arg1[2];
  value3 = arg1[3];
  if (arg2 != 0) {
    value4 = value4 + *(int *)((intptr_t)self + 0x18);
    value2 = value2 + *(int *)((intptr_t)self + 0x18);
    value5 = value5 + *(int *)((intptr_t)self + 0x1c);
    value3 = value3 + *(int *)((intptr_t)self + 0x1c);
  }
  if (value4 < *(int *)((intptr_t)self + 8)) {
    value4 = *(int *)((intptr_t)self + 8);
  }
  if (value5 < *(int *)((intptr_t)self + 0xc)) {
    value5 = *(int *)((intptr_t)self + 0xc);
  }
  if (*(int *)((intptr_t)self + 0x10) < value2) {
    value2 = *(int *)((intptr_t)self + 0x10);
  }
  if (*(int *)((intptr_t)self + 0x14) < value3) {
    value3 = *(int *)((intptr_t)self + 0x14);
  }
  if ((0 < value2 - value4) && (0 < value3 - value5)) {
    value1 = *(int *)((intptr_t)self + 0x38);
    if (value1 == -999) {
      *(int *)((intptr_t)self + 0x38) = value4;
      *(int *)((intptr_t)self + 0x3c) = value5;
      *(int *)((intptr_t)self + 0x40) = value2;
      *(int *)((intptr_t)self + 0x44) = value3;
      return;
    }
    if (value1 < value4) {
      value4 = value1;
    }
    *(int *)((intptr_t)self + 0x38) = value4;
    value4 = *(int *)((intptr_t)self + 0x40);
    if (*(int *)((intptr_t)self + 0x40) <= value2) {
      value4 = value2;
    }
    *(int *)((intptr_t)self + 0x40) = value4;
    value4 = *(int *)((intptr_t)self + 0x3c);
    if (value5 <= *(int *)((intptr_t)self + 0x3c)) {
      value4 = value5;
    }
    *(int *)((intptr_t)self + 0x3c) = value4;
    value4 = *(int *)((intptr_t)self + 0x44);
    if (*(int *)((intptr_t)self + 0x44) <= value3) {
      value4 = value3;
    }
    *(int *)((intptr_t)self + 0x44) = value4;
  }
  return;
}
