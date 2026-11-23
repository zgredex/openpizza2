// Stats_ComputeWeightedAverages: ported from Pizza Connection 2 at 0x513100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513100
#include "pc2_port.h"

void __thiscall Stats_ComputeWeightedAverages(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int64_t lvalue7;
  int unaff_retaddr;
  float fVar8;
  float local_8;
  float local_4;
  
  value6 = 0;
  value5 = 0;
  *(uint32_t *)((intptr_t)self + 0x24c) = 0;
  *(uint32_t *)((intptr_t)self + 0x254) = 0;
  *(uint32_t *)((intptr_t)self + 0x250) = 0;
  value1 = *(int *)((intptr_t)self + 0x5c);
  if (0 < value1) {
    do {
      value4 = IDMap_Lookup((void *)((intptr_t)self + 0x48),value6,(int *)0x0);
      value2 = *(int *)(DAT_0057c670 + 0xa8 + (uint32_t)*(uint8_t *)(value4 + 4) * 4);
      value3 = *(int *)(value2 + 0xac + (uint32_t)*(uint8_t *)(value4 + 6) * 4);
      value5 = value5 + value3;
      *(int *)((intptr_t)self + 0x24c) =
           *(int *)((intptr_t)self + 0x24c) + *(char *)(*(uint8_t *)(value4 + 6) + 200 + value2) * value3;
      *(int *)((intptr_t)self + 0x254) =
           *(int *)((intptr_t)self + 0x254) +
           *(int *)(value2 + 0xac + (uint32_t)*(uint8_t *)(value4 + 6) * 4) * (intptr_t)*(char *)(value2 + 0xcc);
      value6 = value6 + 1;
      *(int *)((intptr_t)self + 0x250) =
           *(int *)((intptr_t)self + 0x250) +
           *(int *)(value2 + 0xac + (uint32_t)*(uint8_t *)(value4 + 6) * 4) * (intptr_t)*(char *)(value2 + 0xcd);
    } while (value6 < value1);
    if (0 < value5) {
      local_8 = (float)*(int *)((intptr_t)self + 0x24c) / (float)value5;
      goto LAB_005131ee;
    }
  }
  local_8 = 0.0;
LAB_005131ee:
  lvalue7 = Math_RoundFloat(local_8);
  *(int *)((intptr_t)self + 0x24c) = (intptr_t)lvalue7;
  if (value5 < 1) {
    local_4 = 0.0;
  }
  else {
    local_4 = (float)*(int *)((intptr_t)self + 0x254) / (float)unaff_retaddr;
  }
  lvalue7 = Math_RoundFloat(local_4);
  *(int *)((intptr_t)self + 0x254) = (intptr_t)lvalue7;
  if (value5 < 1) {
    fVar8 = 0.0;
  }
  else {
    fVar8 = (float)*(int *)((intptr_t)self + 0x250) / (float)arg1;
  }
  lvalue7 = Math_RoundFloat(fVar8);
  *(int *)((intptr_t)self + 0x250) = (intptr_t)lvalue7;
  return;
}
