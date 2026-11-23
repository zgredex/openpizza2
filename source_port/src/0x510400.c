// Stats_GetMaxTimelineCount: ported from Pizza Connection 2 at 0x510400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510400
#include "pc2_port.h"

int __thiscall Stats_GetMaxTimelineCount(void *self,int arg1)

{
  int value1;
  int value2;
  int value3;
  int value4;
  
  value4 = 0;
  if (*(int *)((intptr_t)self + 0x304) == 0) {
    return 0;
  }
  value1 = Stats_GetMinMapField10((intptr_t)self);
  value2 = UI_GetMaxChildField10((intptr_t)self);
  for (; value1 <= value2; value1 = value1 + 1) {
    value3 = AI_CountPlanSteps(self,value1,arg1,-1);
    if (value4 < value3) {
      value4 = value3;
    }
  }
  return value4;
}
