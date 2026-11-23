// Rating_ComputeBuildingScore: ported from Pizza Connection 2 at 0x47a000.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47a000
#include "pc2_port.h"

int __thiscall Rating_ComputeBuildingScore(void *self,int arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int64_t lvalue9;
  int local_e8;
  int local_e0 [56];
  
  local_e0[0x28] = 0;
  local_e0[0x2b] = 0;
  local_e0[1] = 0;
  local_e0[0x11] = 0xfffffffe;
  local_e0[0x12] = 0xfffffffe;
  local_e0[0x22] = 0xfffffffe;
  local_e0[0x34] = 0xfffffffe;
  local_e0[0x36] = 0xfffffffe;
  local_e0[0x37] = 0xfffffffe;
  local_e0[8] = 1;
  local_e0[9] = 1;
  local_e0[0xe] = 3;
  local_e0[0xf] = 3;
  local_e0[0x2c] = 4;
  local_e0[0xc] = 4;
  local_e0[0x1b] = 4;
  local_e0[0x29] = 0xfffffffd;
  local_e0[3] = 0xfffffffd;
  local_e0[0x13] = 0xfffffffd;
  local_e0[0x21] = 0xfffffffd;
  local_e0[0x35] = 0xfffffffd;
  value8 = 0;
  local_e0[0x2a] = 0xfffffffb;
  local_e0[0x2d] = 5;
  local_e0[0x2e] = 3;
  local_e0[0x2f] = 2;
  local_e0[0] = -7;
  local_e0[2] = 0xfffffffb;
  local_e0[4] = 0xffffffef;
  local_e0[5] = 0xffffffec;
  local_e0[6] = 0xfffffff1;
  local_e0[7] = 0xfffffff5;
  local_e0[0x10] = 0xffffffff;
  local_e0[0x14] = 0xfffffffa;
  local_e0[0x15] = 0xfffffff9;
  local_e0[0x16] = 0xfffffffb;
  local_e0[0x17] = 0xfffffffc;
  local_e0[0x20] = 0xffffffff;
  local_e0[0x23] = 0xfffffffc;
  local_e0[0x24] = 0xfffffff9;
  local_e0[0x25] = 0xfffffff8;
  local_e0[0x26] = 0xfffffffa;
  local_e0[0x27] = 0xfffffffb;
  local_e0[0x30] = 0xffffffff;
  local_e0[0x31] = 0xffffffff;
  local_e0[0x32] = 0xffffffff;
  local_e0[0x33] = 0xffffffff;
  local_e0[10] = 2;
  local_e0[0xb] = 2;
  local_e0[0xd] = 5;
  local_e0[0x18] = 2;
  local_e0[0x19] = 8;
  local_e0[0x1a] = 6;
  local_e0[0x1c] = 0xe;
  local_e0[0x1d] = 0x10;
  local_e0[0x1e] = 0xc;
  local_e0[0x1f] = 10;
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this_00 = *(void **)((intptr_t)self + 0x16f0);
  if (this_00 == (void *)0x0) {
    return 0;
  }
  if (arg1 == -1) {
    local_e8 = 7;
    value2 = 0;
  }
  else {
    local_e8 = arg1;
    value2 = arg1;
  }
  for (; value2 <= local_e8; value2 = value2 + 1) {
    value3 = Game_CountFreeBuildingsByType(this_00,0x17);
    value7 = local_e0[value2 + 0x28];
    value4 = Game_CountFreeBuildingsByType(this_00,0x16);
    value1 = local_e0[value2];
    value5 = Game_CountFreeBuildingsByType(this_00,0xf);
    value6 = Game_CountFreeBuildingsByType(this_00,0x21);
    value8 = value8 + value3 * value7 + value4 * value1 + (value6 + value5) * local_e0[value2 + 0x18] * 2;
    if (*(int *)((intptr_t)this_00 + 0x74) != 0) {
      value8 = value8 + (*(int *)(*(int *)((intptr_t)this_00 + 0x74) + 0x18) / 0x3c +
                      *(int *)((intptr_t)self + 0x14b4)) * local_e0[value2 + 8];
    }
    value7 = Game_CountFreeBuildingsByType(this_00,0x1a);
    if (0 < value7) {
      value7 = value7 / 5 + 1;
      if (4 < value7) {
        value7 = 4;
      }
      lvalue9 = Math_RoundFloat((float)(local_e0[value2 + 0x10] * value7));
      value8 = value8 + (intptr_t)lvalue9;
    }
    value7 = Game_CountFreeBuildingsByType(this_00,0x1b);
    if (0 < value7) {
      value7 = value7 / 5 + 1;
      if (4 < value7) {
        value7 = 4;
      }
      lvalue9 = Math_RoundFloat((float)(local_e0[value2 + 0x20] * value7));
      value8 = value8 + (intptr_t)lvalue9;
    }
    value7 = Game_CountFreeBuildingsByType(this_00,0x1c);
    if (0 < value7) {
      value7 = value7 / 5 + 1;
      if (4 < value7) {
        value7 = 4;
      }
      lvalue9 = Math_RoundFloat((float)(local_e0[value2 + 0x30] * value7));
      value8 = value8 + (intptr_t)lvalue9;
    }
  }
  if (arg1 == -1) {
    value8 = (intptr_t)(value8 + (value8 >> 0x1f & 7U)) >> 3;
  }
  return value8;
}
