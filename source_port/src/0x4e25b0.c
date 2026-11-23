// Economy_GetModifier: ported from Pizza Connection 2 at 0x4e25b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e25b0
#include "pc2_port.h"

uint8_t * __thiscall Economy_GetModifier(void *self,int arg1,int arg2)

{
  uint8_t *uptr1;
  int value2;
  int value3;
  
  uptr1 = (uint8_t *)0x0;
  if (arg1 == 0x17) {
    uptr1 = *(uint8_t **)(&DAT_0056d0d4 + (arg2 + *(int *)((intptr_t)self + 100) * 3) * 4);
    if (arg2 == 1) {
      value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      value2 = *(int *)(value3 + 0x168);
      if (0 < value2) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 0xf) / 10);
          value2 = value2 + -1;
        } while (value2 != 0);
      }
      value3 = *(int *)(value3 + 0x24c);
      if (0 < value3) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 9) / 10);
          value3 = value3 + -1;
        } while (value3 != 0);
        return uptr1;
      }
    }
    else if (arg2 == 2) {
      value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      value2 = *(int *)(value3 + 0x164);
      if (0 < value2) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 0xf) / 10);
          value2 = value2 + -1;
        } while (value2 != 0);
      }
      value3 = *(int *)(value3 + 0x248);
      if (0 < value3) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 9) / 10);
          value3 = value3 + -1;
        } while (value3 != 0);
      }
    }
  }
  else if (arg1 == 0x1d) {
    uptr1 = *(uint8_t **)(&DAT_0056d0b0 + (arg2 + *(int *)((intptr_t)self + 0x6c) * 3) * 4);
    if (arg2 == 1) {
      value3 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
      value2 = *(int *)(value3 + 0xa8);
      if (0 < value2) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 0xf) / 10);
          value2 = value2 + -1;
        } while (value2 != 0);
      }
      value3 = *(int *)(value3 + 0x18c);
      if (0 < value3) {
        do {
          uptr1 = (uint8_t *)(((intptr_t)uptr1 * 9) / 10);
          value3 = value3 + -1;
        } while (value3 != 0);
        return uptr1;
      }
    }
  }
  else if (arg1 == 0x1e) {
    return (&PTR_s_can_t_perform_action_0056d08c)[arg2 + *(int *)((intptr_t)self + 0x68) * 3];
  }
  return uptr1;
}
