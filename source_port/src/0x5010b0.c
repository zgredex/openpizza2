// UI_ProcessMenuInput: ported from Pizza Connection 2 at 0x5010b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5010b0
#include "pc2_port.h"

uint32_t __thiscall UI_ProcessMenuInput(void *self,int *arg1)

{
  uint16_t *uptr1;
  uint32_t uvalue2;
  int value3;
  int value4;
  int *ptr5;
  int value6;
  uint32_t uvalue7;
  int local_e0 [2];
  uint16_t local_d8 [2];
  int aiStack_d4 [5];
  int local_c0 [4];
  uint32_t local_b0 [4];
  int local_a0 [4];
  int local_90 [36];
  
  value6 = *arg1;
  ptr5 = local_e0;
  for (value3 = 0x38; value3 != 0; value3 = value3 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  value3 = arg1[2];
  uptr1 = local_d8;
  value4 = 10;
  do {
    *(int *)(uptr1 + -4) = value6;
    *uptr1 = (short)value3;
    uptr1 = uptr1 + 8;
    value4 = value4 + -1;
  } while (value4 != 0);
  switch(arg1[3]) {
  case 3:
    Game_AssignPlanStepWeight(self,4,local_e0);
    Game_AssignPlanStepWeight(self,0xf,aiStack_d4 + 1);
    ptr5 = local_c0;
    value6 = 3;
    uvalue7 = 0x12;
    break;
  case 4:
    Game_AssignPlanStepWeight(self,5,local_e0);
    Game_AssignPlanStepWeight(self,6,aiStack_d4 + 1);
    ptr5 = local_c0;
    value6 = 3;
    uvalue7 = 0xe;
    break;
  default:
    goto switchD_00501101_caseD_5;
  case 6:
    Game_AssignPlanStepWeight(self,8,local_e0);
    Game_AssignPlanStepWeight(self,0xb,aiStack_d4 + 1);
    Game_AssignPlanStepWeight(self,9,local_c0);
    Game_AssignPlanStepWeight(self,10,local_b0);
    Game_AssignPlanStepWeight(self,0xc,local_a0);
    ptr5 = local_90;
    value6 = 6;
    uvalue7 = 0xd;
    break;
  case 0xf:
    Game_AssignPlanStepWeight(self,0x11,local_e0);
    ptr5 = aiStack_d4 + 1;
    value6 = 2;
    uvalue7 = 0x10;
    break;
  case 0x12:
    Game_AssignPlanStepWeight(self,0x13,local_e0);
    Game_AssignPlanStepWeight(self,0x14,aiStack_d4 + 1);
    Game_AssignPlanStepWeight(self,0x15,local_c0);
    Game_AssignPlanStepWeight(self,0x16,local_b0);
    ptr5 = local_a0;
    value6 = 5;
    uvalue7 = 0x17;
  }
  Game_AssignPlanStepWeight(self,uvalue7,ptr5);
  uvalue2 = 0;
  if (value6 != 0) {
    ptr5 = local_e0 + 1;
    value3 = value6;
    do {
      value4 = *ptr5;
      ptr5 = ptr5 + 4;
      uvalue2 = uvalue2 + value4;
      value3 = value3 + -1;
    } while (value3 != 0);
    if (uvalue2 != 0) {
      uvalue2 = Random_Mod(uvalue2);
      value3 = 0;
      ptr5 = local_e0 + 1;
      do {
        if ((intptr_t)uvalue2 < *ptr5) break;
        uvalue2 = uvalue2 - *ptr5;
        value3 = value3 + 1;
        ptr5 = ptr5 + 4;
      } while (value3 < value6);
      if (value3 != value6) {
        value6 = local_e0[value3 * 4];
        arg1[3] = aiStack_d4[value3 * 4];
        *arg1 = value6;
        return 0;
      }
      arg1[3] = 0;
switchD_00501101_caseD_5:
      return 1;
    }
  }
  arg1[3] = 0;
  return 1;
}
