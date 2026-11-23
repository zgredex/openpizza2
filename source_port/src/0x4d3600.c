// Gfx_BlitShiftedRect: ported from Pizza Connection 2 at 0x4d3600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3600
#include "pc2_port.h"

void __fastcall Gfx_BlitShiftedRect(int arg1)

{
  int value1;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  value1 = *(int *)(arg1 + 8);
  if (value1 != 0) {
    *(int *)(value1 + 0x5c) = *(int *)(value1 + 0x5c) - *(int *)(*(int *)(arg1 + 4) + 0x24);
    *(int *)(*(int *)(arg1 + 8) + 100) =
         *(int *)(*(int *)(arg1 + 8) + 100) - *(int *)(*(int *)(arg1 + 4) + 0x24);
    *(int *)(*(int *)(arg1 + 8) + 0x60) =
         *(int *)(*(int *)(arg1 + 8) + 0x60) - *(int *)(*(int *)(arg1 + 4) + 0x28);
    *(int *)(*(int *)(arg1 + 8) + 0x68) =
         *(int *)(*(int *)(arg1 + 8) + 0x68) - *(int *)(*(int *)(arg1 + 4) + 0x28);
    Gfx_BlitRectList(DAT_0058072c,(uint32_t *)(*(int *)(arg1 + 8) + 0x5c));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}
