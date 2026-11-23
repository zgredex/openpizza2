// Rating_ComputeBranchScores: ported from Pizza Connection 2 at 0x478f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x478f60
#include "pc2_port.h"

void __fastcall Rating_ComputeBranchScores(int arg1)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  int *ptr7;
  int aiStack_e0 [8];
  int local_c0 [8];
  int local_a0 [8];
  int local_80 [8];
  int aiStack_60 [8];
  int local_40 [8];
  int local_20 [8];
  
  value5 = 0;
  value6 = 0;
  do {
    if (*(int *)(arg1 + 0x1850) < *(int *)((intptr_t)&DAT_00567838 + value6)) {
      *(int *)((intptr_t)local_a0 + value6) =
           (*(int *)(arg1 + 0x1850) - *(int *)((intptr_t)&DAT_00567838 + value6)) * 3 + 100;
      Clamp_0_100((int *)((intptr_t)local_a0 + value6));
    }
    else {
      *(uint32_t *)((intptr_t)local_a0 + value6) = 100;
    }
    if (*(int *)(arg1 + 0x1854) < *(int *)((intptr_t)&DAT_00567858 + value6)) {
      *(int *)((intptr_t)local_c0 + value6) =
           (*(int *)(arg1 + 0x1854) - *(int *)((intptr_t)&DAT_00567858 + value6)) * 3 + 100;
      Clamp_0_100((int *)((intptr_t)local_c0 + value6));
    }
    else {
      *(uint32_t *)((intptr_t)local_c0 + value6) = 100;
    }
    if (*(int *)(arg1 + 0x185c) < *(int *)((intptr_t)&DAT_00567878 + value6)) {
      *(int *)((intptr_t)local_80 + value6) =
           (*(int *)(arg1 + 0x185c) - *(int *)((intptr_t)&DAT_00567878 + value6)) * 3 + 100;
      Clamp_0_100((int *)((intptr_t)local_80 + value6));
    }
    else {
      *(uint32_t *)((intptr_t)local_80 + value6) = 100;
    }
    if (*(int *)(arg1 + 0x1868) < *(int *)((intptr_t)&DAT_00567898 + value6)) {
      *(int *)((intptr_t)local_40 + value6) =
           (*(int *)(arg1 + 0x1868) - *(int *)((intptr_t)&DAT_00567898 + value6)) * 3 + 100;
      Clamp_0_100((int *)((intptr_t)local_40 + value6));
    }
    else {
      *(uint32_t *)((intptr_t)local_40 + value6) = 100;
    }
    uvalue3 = *(int *)((intptr_t)&DAT_005678d8 + value6) - *(int *)(arg1 + 0x1858);
    uvalue4 = (intptr_t)uvalue3 >> 0x1f;
    *(int *)((intptr_t)local_20 + value6) = ((uvalue3 ^ uvalue4) - uvalue4) * -6 + 100;
    Clamp_0_100((int *)((intptr_t)local_20 + value6));
    if (*(int *)(arg1 + 0x1860) < *(int *)((intptr_t)&DAT_005678f8 + value6)) {
      *(uint32_t *)((intptr_t)aiStack_60 + value6) = 0;
    }
    else {
      *(uint32_t *)((intptr_t)aiStack_60 + value6) = 100;
    }
    value1 = *(int *)(arg1 + 0x1864);
    value2 = *(int *)((intptr_t)&DAT_00567918 + value6);
    *(uint32_t *)((intptr_t)aiStack_e0 + value6) = 100;
    if (value2 < value1) {
      *(int *)((intptr_t)aiStack_e0 + value6) = ((value2 - value1) + 2) * 0x32;
    }
    else {
      *(uint32_t *)((intptr_t)aiStack_e0 + value6) = 100;
    }
    value6 = value6 + 4;
  } while (value6 < 0x20);
  ptr7 = (int *)(arg1 + 0x17fc);
  do {
    value6 = *(int *)((intptr_t)local_40 + value5) + *(int *)((intptr_t)local_80 + value5) +
            *(int *)((intptr_t)local_c0 + value5) + *(int *)((intptr_t)local_a0 + value5);
    *ptr7 = ((*(int *)((intptr_t)aiStack_e0 + value5) + *(int *)((intptr_t)aiStack_60 + value5) +
               *(int *)((intptr_t)local_20 + value5)) / 3 + ((intptr_t)(value6 + (value6 >> 0x1f & 3U)) >> 2)) /
              2;
    Clamp_0_100(ptr7);
    value5 = value5 + 4;
    ptr7 = ptr7 + 1;
  } while (value5 < 0x20);
  return;
}
