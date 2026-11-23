// UI_DrawCenteredSelectionRect: ported from Pizza Connection 2 at 0x4f5bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f5bb0
#include "pc2_port.h"

void __thiscall UI_DrawCenteredSelectionRect(void *self,int *arg1)

{
  int local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
  UI_ComputeCenteredRect(self,arg1,(int *)&arg1,&local_14);
  arg1 = (int *)((intptr_t)arg1 - *(int *)((intptr_t)self + 0x24));
  local_14 = local_14 + (-0x1e - *(int *)((intptr_t)self + 0x28));
  local_10 = (intptr_t)arg1 - 0x1e;
  local_c = local_14 + -0x1e;
  local_8 = (intptr_t)arg1 + 0x1e;
  local_4 = local_14 + 0x1e;
  Gfx_BlitRectList(DAT_0058072c,&local_10);
  return;
}
