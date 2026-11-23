// Game_ComputePrice: ported from Pizza Connection 2 at 0x4e4060.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e4060
#include "pc2_port.h"

double __thiscall Game_ComputePrice(int arg1,int arg2)

{
  int value1;
  int64_t lvalue2;
  uint32_t local_40;
  uint32_t local_3c;
  uint32_t local_38;
  uint32_t uStack_34;
  uint32_t local_30;
  uint32_t local_2c;
  uint32_t local_28;
  uint32_t local_24;
  uint32_t local_20;
  uint32_t local_1c;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  uint32_t local_c;
  
  value1 = *(int *)(arg1 + 8);
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  uStack_34 = 0x40340000;
  local_30 = 0;
  local_2c = 0x40590000;
  local_28 = 0;
  local_24 = 0x407f4000;
  local_20 = 0;
  local_1c = 0x4062c000;
  local_18 = 0;
  local_14 = 0x4072c000;
  local_10 = 0;
  local_c = 0x40668000;
  if ((value1 < 1) || (6 < value1)) {
    value1 = 1;
  }
  lvalue2 = Math_RoundFloat((float)((*(int *)(arg2 + 0x54) + *(int *)(arg2 + 0x3c)) * -3 + 100)
                          * (float)*(double *)(&local_40 + value1 * 2) *
                          (float)*(double *)(arg1 + 0x70) * 0.01);
  return (double)(intptr_t)lvalue2;
}
