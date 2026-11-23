// UI_WaitForMenuSelection: ported from Pizza Connection 2 at 0x500ec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x500ec0
#include "pc2_port.h"

void __thiscall UI_WaitForMenuSelection(void *self,int arg1)

{
  int value1;
  int local_10 [2];
  uint16_t local_8;
  int local_4;
  
  if (*(int *)((intptr_t)self + arg1 * 0x168 + 0x80) == 0) {
    local_4 = *(int *)((intptr_t)self + arg1 * 0x168 + 300);
    local_10[0] = -1;
    local_8 = (uint16_t)arg1;
    value1 = UI_ProcessMenuInput(self,local_10);
    while (value1 == 0) {
      value1 = UI_ProcessMenuInput(self,local_10);
    }
    Company_PushRecentEntry(self,arg1,local_4,local_10[0],-1);
  }
  return;
}
