// UI_ShiftChildRect: ported from Pizza Connection 2 at 0x5086e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5086e0
#include "pc2_port.h"

void __fastcall UI_ShiftChildRect(int arg1)

{
  int value1;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  value1 = *(int *)(arg1 + 200);
  if (value1 != 0) {
    *(int *)(value1 + 0x5c) = *(int *)(value1 + 0x5c) - *(int *)(*(int *)(arg1 + 0xc4) + 0x24);
    *(int *)(*(int *)(arg1 + 200) + 100) =
         *(int *)(*(int *)(arg1 + 200) + 100) - *(int *)(*(int *)(arg1 + 0xc4) + 0x24);
    *(int *)(*(int *)(arg1 + 200) + 0x60) =
         *(int *)(*(int *)(arg1 + 200) + 0x60) - *(int *)(*(int *)(arg1 + 0xc4) + 0x28);
    *(int *)(*(int *)(arg1 + 200) + 0x68) =
         *(int *)(*(int *)(arg1 + 200) + 0x68) - *(int *)(*(int *)(arg1 + 0xc4) + 0x28);
    Gfx_BlitRectList(DAT_0058072c,(uint32_t *)(*(int *)(arg1 + 200) + 0x5c));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
