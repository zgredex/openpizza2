// Map_DrawPlayerMarkerRing: ported from Pizza Connection 2 at 0x4f3510.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f3510
#include "pc2_port.h"

uint32_t __thiscall Map_DrawPlayerMarkerRing(void *self)

{
  int value1;
  double *pdVar2;
  double *pdVar3;
  int value4;
  int value5;
  uint32_t uvalue6;
  int value7;
  void *this_00;
  int value8;
  uint32_t *uptr9;
  int *ptr10;
  int *ptr11;
  double fVar12;
  int64_t lvalue13;
  int64_t lvalue14;
  int in_stack_00000014;
  int in_stack_00000018;
  uint32_t in_stack_0000001c;
  int in_stack_00000020;
  uint32_t local_11c;
  int local_118;
  int local_f8 [20];
  int local_a8 [20];
  uint32_t auStack_58 [21];
  
  local_f8[3] = 0x78;
  local_f8[4] = 0x78;
  local_f8[5] = 0x78;
  local_f8[6] = 0xb4;
  local_f8[7] = 0xb4;
  local_f8[8] = 0xb4;
  local_f8[9] = 0xb4;
  local_f8[10] = 0xb4;
  local_f8[0xb] = 0xb4;
  local_f8[0] = 0x30;
  local_f8[1] = 0x48;
  local_f8[2] = 0x5a;
  value8 = 0;
  ptr10 = local_f8 + 0xc;
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *ptr10 = 0;
    ptr10 = ptr10 + 1;
  }
  if (DAT_005719f4 != 0) {
    DAT_005719f4 = 0;
    local_118 = 0;
    pdVar2 = (double *)&DAT_00580750;
    do {
      fVar12 = (double)local_118;
      pdVar3 = pdVar2 + 1;
      local_118 = local_118 + 1;
      fVar12 = (double)fsin(fVar12 * (double)0.017453292222222222);
      *pdVar2 = (double)fVar12;
      pdVar2 = pdVar3;
    } while ((intptr_t)pdVar3 < 0x580a21);
  }
  value5 = *(int *)((intptr_t)self + 0x24);
  value1 = *(int *)((intptr_t)self + 0x28);
  if ((intptr_t)in_stack_0000001c < 1) {
    return in_stack_0000001c & 0xffffff00;
  }
  local_11c = 100;
  if (100 < (intptr_t)(in_stack_0000001c - 0x14)) {
    ptr10 = local_f8;
    ptr11 = local_a8;
    for (uvalue6 = (in_stack_0000001c - 0x47) / 0x32; ptr10 = ptr10 + 1, uvalue6 != 0;
        uvalue6 = uvalue6 - 1) {
      *ptr11 = *ptr10;
      ptr11 = ptr11 + 1;
    }
    do {
      auStack_58[value8] = local_11c;
      local_11c = local_11c + 0x32;
      value8 = value8 + 1;
    } while ((intptr_t)local_11c < (intptr_t)(in_stack_0000001c - 0x14));
  }
  auStack_58[value8] = in_stack_0000001c;
  value4 = local_f8[value8];
  local_a8[value8] = value4;
  local_11c = 0;
  if (0 < value8 + 1) {
    do {
      value4 = local_a8[local_11c];
      if ((intptr_t)local_11c < value8) {
        this_00 = (void *)(&DAT_005806ec)[in_stack_00000020];
      }
      else {
        this_00 = (void *)(&DAT_0058070c)[in_stack_00000020];
      }
      uptr9 = &DAT_00581290;
      do {
        lvalue13 = __ftol();
        lvalue14 = __ftol();
        value7 = DAT_00585518;
        if (DAT_00585518 < 0xa1) {
          value7 = 0xa0;
        }
        Sprite_BlitWithDefaultAlpha
                  (this_00,*(uint32_t **)((intptr_t)self + 8),DAT_0058072c,
                   (uint32_t *)((in_stack_00000014 - value5) + -8 + (intptr_t)lvalue13),
                   (in_stack_00000018 - value1) + -8 + (intptr_t)lvalue14,value7);
        uptr9 = uptr9 + (intptr_t)(0x168 / (int64_t)value4) * -2;
      } while (0x580750 < (intptr_t)uptr9);
      value4 = local_11c + 1;
      local_11c = value4;
    } while (value4 < value8 + 1);
  }
  return CONCAT31((int3)((uint32_t)value4 >> 8),1);
}
