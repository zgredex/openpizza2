// UI_SetObjectTextByKey: ported from Pizza Connection 2 at 0x531f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531f50
#include "pc2_port.h"

void __thiscall UI_SetObjectTextByKey(void *self,int arg1,char *arg2)

{
  int value1;
  
  value1 = BinarySearch8(self,arg1,'\0');
  if (value1 != -1) {
    UI_SetTextString(*(void **)(*(int *)((intptr_t)self + 0xe8) + value1 * 8),arg2);
  }
  return;
}
