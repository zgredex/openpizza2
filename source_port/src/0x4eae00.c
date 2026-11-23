// UI_SetWindowOffsets: ported from Pizza Connection 2 at 0x4eae00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eae00
#include "pc2_port.h"

void __fastcall UI_SetWindowOffsets(int arg1)

{
  if (*(int *)(arg1 + 0xc) == 0x10) {
    *(uint32_t *)(arg1 + 0x1016c) = 0x41;
    *(uint32_t *)(arg1 + 0x10168) = 0;
    *(uint32_t *)(arg1 + 0x10174) = 0xffffff2e;
    *(uint32_t *)(arg1 + 0x10170) = 0x28;
    return;
  }
  *(uint32_t *)(arg1 + 0x1016c) = 0x41;
  *(uint32_t *)(arg1 + 0x10168) = 0x41;
  *(uint32_t *)(arg1 + 0x10174) = 0x1e;
  *(uint32_t *)(arg1 + 0x10170) = 0x1e;
  return;
}
