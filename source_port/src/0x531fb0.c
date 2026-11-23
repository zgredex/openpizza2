// UI_SetChildLabelText: ported from Pizza Connection 2 at 0x531fb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531fb0
#include "pc2_port.h"

void __thiscall UI_SetChildLabelText(void *self,int arg1,uint32_t arg2,char *arg3)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 != -1) {
    UI_SetLabelIdText(*(void **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8),arg2,arg3);
  }
  return;
}
