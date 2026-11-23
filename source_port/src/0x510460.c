// Stats_GetMaxTimelineCategoryValue: ported from Pizza Connection 2 at 0x510460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510460
#include "pc2_port.h"

double __thiscall Stats_GetMaxTimelineCategoryValue(int arg1,int arg2)

{
  int value1;
  int value2;
  double fVar3;
  float local_4;
  
  local_4 = 0.0;
  if (*(int *)(arg1 + 0x304) == 0) {
    return (double)0.0;
  }
  value1 = Stats_GetMinMapField10(arg1);
  value2 = UI_GetMaxChildField10(arg1);
  for (; value1 <= value2; value1 = value1 + 1) {
    fVar3 = Stats_SumMaskedMapFloats(arg1,value1,arg2,-1);
    if ((double)local_4 < fVar3) {
      local_4 = (float)fVar3;
    }
  }
  return (double)local_4;
}
