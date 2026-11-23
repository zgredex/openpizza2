// Timer_AddEntry: ported from Pizza Connection 2 at 0x403ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403ac0
#include "pc2_port.h"

uint32_t __thiscall Timer_AddEntry(void *self,uint32_t arg1,int arg2,uint32_t arg3)

{
  uint32_t *uptr1;
  int value2;
  
  if (arg2 < 1) {
    return 0xffffffff;
  }
  uptr1 = operator_new(0x18);
  *uptr1 = arg1;
  uptr1[2] = arg2;
  uptr1[1] = arg3;
  uptr1[4] = *(uint32_t *)((intptr_t)self + 0x68);
  *(int *)((intptr_t)self + 0x68) = *(int *)((intptr_t)self + 0x68) + 1;
  CS_Enter((intptr_t)self + 0x10);
  value2 = *(int *)((intptr_t)self + 0xc);
  if (value2 == 0) {
    uptr1[3] = arg2;
  }
  else {
    value2 = (*(int *)(value2 + 0xc) - *(int *)(value2 + 8)) + uptr1[2];
    uptr1[3] = value2;
    while (value2 < 1) {
      value2 = uptr1[3] + uptr1[2];
      uptr1[3] = value2;
    }
  }
  uptr1[5] = *(uint32_t *)((intptr_t)self + 0xc);
  *(uint32_t **)((intptr_t)self + 0xc) = uptr1;
  CS_Leave((intptr_t)self + 0x10);
  return uptr1[4];
}
