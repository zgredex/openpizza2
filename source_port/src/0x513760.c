// Game_ComputeSkillRatings: ported from Pizza Connection 2 at 0x513760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513760
#include "pc2_port.h"

void __thiscall Game_ComputeSkillRatings(void *self,int arg1,float arg2)

{
  float fVar1;
  float fVar2;
  int value3;
  float *fptr4;
  int value5;
  uint32_t *uptr6;
  double fVar7;
  int64_t lvalue8;
  float local_20 [8];
  
  value3 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  uptr6 = (uint32_t *)((intptr_t)self + 0x2e4);
  for (value5 = 8; value5 != 0; value5 = value5 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  fVar7 = Rating_GetFloat(value3,0);
  local_20[0] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,1);
  local_20[1] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,2);
  local_20[2] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,3);
  local_20[3] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,4);
  local_20[4] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,5);
  local_20[5] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,6);
  local_20[6] = (float)fVar7;
  fVar7 = Rating_GetFloat(value3,7);
  local_20[7] = (float)fVar7;
  fVar1 = *(float *)(value3 + 0x98);
  value3 = *(int *)(arg1 + 0x38);
  fptr4 = local_20;
  value5 = 8;
  do {
    if (value3 == 1) {
      fVar2 = fVar1 + fVar1;
LAB_00513849:
      *fptr4 = fVar2 + *fptr4;
    }
    else if (value3 == 2) {
      fVar2 = fVar1 * 4.0;
      goto LAB_00513849;
    }
    fptr4 = fptr4 + 1;
    value5 = value5 + -1;
  } while (value5 != 0);
  value3 = 0;
  do {
    if (local_20[value3] < arg2) {
      lvalue8 = __ftol();
      *(int *)((intptr_t)self + value3 * 4 + 0x2e4) = (intptr_t)lvalue8;
    }
    if (local_20[value3] <= arg2) goto switchD_005138e6_default;
    if (arg2 == 0.0) {
      *(uint32_t *)((intptr_t)self + value3 * 4 + 0x2e4) = 100;
    }
    else {
      lvalue8 = __ftol();
      *(int *)((intptr_t)self + value3 * 4 + 0x2e4) = (intptr_t)lvalue8;
    }
    switch(value3) {
    case 0:
    case 6:
      if (0x28 < *(int *)((intptr_t)self + value3 * 4 + 0x2e4)) {
        *(uint32_t *)((intptr_t)self + value3 * 4 + 0x2e4) = 0x28;
      }
      break;
    case 1:
      value5 = 10;
      goto LAB_0051391d;
    case 2:
      value5 = *(int *)((intptr_t)self + value3 * 4 + 0x2e4);
      goto joined_r0x00513943;
    case 3:
      value5 = 0x1e;
      goto LAB_0051391d;
    case 4:
      value5 = 5;
LAB_0051391d:
      if (value5 < *(int *)((intptr_t)self + value3 * 4 + 0x2e4)) {
        *(int *)((intptr_t)self + value3 * 4 + 0x2e4) = value5;
      }
      break;
    case 5:
      *(uint32_t *)((intptr_t)self + value3 * 4 + 0x2e4) = 0;
      break;
    case 7:
      value5 = *(int *)((intptr_t)self + value3 * 4 + 0x2e4);
joined_r0x00513943:
      if (0x14 < value5) {
        *(uint32_t *)((intptr_t)self + value3 * 4 + 0x2e4) = 0x14;
      }
    }
switchD_005138e6_default:
    value3 = value3 + 1;
    if (7 < value3) {
      return;
    }
  } while( true );
}
