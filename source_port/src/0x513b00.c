// Game_ComputeCompanyProductScore: ported from Pizza Connection 2 at 0x513b00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x513b00
#include "pc2_port.h"

int __thiscall Game_ComputeCompanyProductScore(void *self,int arg1,uint32_t arg2,float arg3)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  uint32_t local_8;
  int local_4;
  
  value2 = 0;
  this_00 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  uvalue4 = arg2;
  if (arg2 == 8) {
    uvalue4 = 5;
  }
  value1 = Game_GetSkillRating(self,arg1,arg3,uvalue4);
  arg1 = 0;
  arg2 = 0;
  value3 = 0xa8;
  do {
    if (0 < *(int *)((intptr_t)self + value3 + -0x44)) {
      Market_ComputeValueAdjustment
                (this_00,'\0',uvalue4,*(int *)(value3 + DAT_0057c670),&local_8,&local_4);
      if (value3 != 0xa8) {
        value2 = value2 + local_8;
        arg1 = arg1 + 1;
      }
      arg2 = arg2 + local_4;
    }
    value3 = value3 + 4;
  } while (value3 < 0x200);
  if (arg1 < 1) {
    value2 = -0x28;
  }
  else {
    value2 = value2 / arg1 + arg2;
  }
  value2 = value2 + value1;
  if (value2 < 0) {
    return 0;
  }
  if (100 < value2) {
    value2 = 100;
  }
  return value2;
}
