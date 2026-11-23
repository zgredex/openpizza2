// Game_GetSkillRating: ported from Pizza Connection 2 at 0x5139e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5139e0
#include "pc2_port.h"

int __thiscall Game_GetSkillRating(void *self,int arg1,float arg2,int arg3)

{
  int value1;
  int *ptr2;
  int local_4;
  
  local_4 = 0;
  if (arg3 == 8) {
    arg3 = 5;
  }
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(arg1 + 0x34),(int *)0x0);
  if (value1 == 0) {
    return 0;
  }
  if (arg3 != -1) {
    Game_ComputeSkillRatings(self,arg1,arg2);
    return *(int *)((intptr_t)self + arg3 * 4 + 0x2e4) + *(int *)((intptr_t)self + arg3 * 4 + 0x2c4);
  }
  ptr2 = (int *)((intptr_t)self + 0x2c4);
  value1 = 8;
  do {
    Game_ComputeSkillRatings(self,arg1,arg2);
    local_4 = local_4 + ptr2[8] + *ptr2;
    ptr2 = ptr2 + 1;
    value1 = value1 + -1;
  } while (value1 != 0);
  return (intptr_t)(local_4 + (local_4 >> 0x1f & 7U)) >> 3;
}
