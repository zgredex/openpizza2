// UI_DetachChildRecord: ported from Pizza Connection 2 at 0x5090e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5090e0
#include "pc2_port.h"

void __fastcall UI_DetachChildRecord(int arg1)

{
  int *ptr1;
  
  ptr1 = *(int **)(arg1 + 200);
  if ((ptr1 != (int *)0x0) && ((void *)ptr1[0x16] != (void *)0x0)) {
    Record_ClearFlags48((void *)ptr1[0x16],*ptr1);
    if (*(int *)(arg1 + 200) != 0) {
      *(uint32_t *)(*(int *)(arg1 + 200) + 0xc) = 0xffffffff;
    }
    if (*(int *)((intptr_t)*(void **)(arg1 + 200) + 0x18) == 0) {
      Object_SetShort28(*(void **)(arg1 + 200),0xffff);
    }
  }
  return;
}
