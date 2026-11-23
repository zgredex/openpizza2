// Game_ComputeCityConditionScore: ported from Pizza Connection 2 at 0x479ae0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x479ae0
#include "pc2_port.h"

void __fastcall Game_ComputeCityConditionScore(int arg1,uint32_t arg2)

{
  uint64_t uvalue1;
  
  uvalue1 = Game_ComputeAverageCategoryValue(arg1,arg2,'\x05');
  *(uint32_t *)(arg1 + 0x1870) = (uint32_t)uvalue1 & 0xff;
  return;
}
