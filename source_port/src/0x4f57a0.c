// Map_SetCellObjectFrame: ported from Pizza Connection 2 at 0x4f57a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f57a0
#include "pc2_port.h"

void __thiscall Map_SetCellObjectFrame(void *self,int arg1,char arg2)

{
  int *ptr1;
  int value2;
  
  ptr1 = (int *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0xc);
  if ((ptr1 != (int *)0x0) && (value2 = ptr1[2], value2 != 0)) {
    if ((arg2 != *(char *)(value2 + 0x2e)) &&
       (*(char *)(value2 + 0x2e) = arg2, DAT_0058072c != 0)) {
      UI_DrawObjectWithBounds(self,ptr1,(int *)0x0);
    }
  }
  return;
}
