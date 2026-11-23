// UI_AdvanceBriefing: ported from Pizza Connection 2 at 0x54ae60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ae60
#include "pc2_port.h"

void __thiscall UI_AdvanceBriefing(void *self,int arg1)

{
  int value1;
  int64_t lvalue2;
  
  value1 = IDMap_Lookup((void *)((intptr_t)self + 4),arg1,(int *)0x0);
  if ((value1 != 0) && (*(int *)(value1 + 0x10) == 0)) {
    *(uint32_t *)(value1 + 0x10) = 1;
    if (*(int *)(value1 + 8) != -1) {
      UI_RemoveObject(*(void **)((intptr_t)self + 0x34),*(int *)(value1 + 8));
      lvalue2 = __ftol();
      UI_AddBriefingButton(self,value1,*(int *)(value1 + 8),(intptr_t)lvalue2);
    }
  }
  return;
}
