// Stats_ComputeAverageGroupScoreThunk: ported from Pizza Connection 2 at 0x4781d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4781d0
#include "pc2_port.h"

int64_t __fastcall Stats_ComputeAverageGroupScoreThunk(int arg1,uint32_t arg2)

{
  int value1;
  int value2;
  int value3;
  float *fptr4;
  int *ptr5;
  int value6;
  int64_t lvalue7;
  float fStack_a4;
  float afStack_a0 [20];
  int aiStack_50 [20];
  
  fptr4 = afStack_a0;
  for (value3 = 0x14; value3 != 0; value3 = value3 + -1) {
    *fptr4 = 0.0;
    fptr4 = fptr4 + 1;
  }
  ptr5 = aiStack_50;
  for (value3 = 0x14; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  value3 = 0;
  value6 = 0;
  if (0 < *(int *)(arg1 + 0x170c)) {
    do {
      value1 = IDMap_Lookup((void *)(arg1 + 0x16f8),value6,(int *)0x0);
      if (value1 != 0) {
        value2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),*(int *)(value1 + 4),(int *)0x0);
        afStack_a0[*(int *)(value2 + 8)] =
             (float)*(int *)(value1 + 0xc) + afStack_a0[*(int *)(value2 + 8)];
        value3 = value3 + 1;
        aiStack_50[*(int *)(value2 + 8)] = aiStack_50[*(int *)(value2 + 8)] + 1;
      }
      value6 = value6 + 1;
    } while (value6 < *(int *)(arg1 + 0x170c));
    arg2 = 0;
    if (0 < value3) {
      value3 = 0;
      do {
        value6 = *(int *)((intptr_t)aiStack_50 + value3 + 4);
        if (value6 < 1) {
          *(uint32_t *)((intptr_t)afStack_a0 + value3 + 4) = 0;
        }
        else {
          *(float *)((intptr_t)afStack_a0 + value3 + 4) =
               *(float *)((intptr_t)afStack_a0 + value3 + 4) / (float)value6;
        }
        value3 = value3 + 4;
      } while (value3 < 0x2c);
      fStack_a4 = (afStack_a0[3] + afStack_a0[5] + afStack_a0[4] + afStack_a0[2] + afStack_a0[1]) *
                  0.2;
      if (0.0 <= fStack_a4) {
        if (100.0 < fStack_a4) {
          fStack_a4 = 100.0;
        }
        lvalue7 = Math_RoundFloat(fStack_a4);
        return lvalue7;
      }
      lvalue7 = Math_RoundFloat(0.0);
      return lvalue7;
    }
  }
  return (uint64_t)arg2 << 0x20;
}
