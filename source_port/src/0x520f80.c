// UI_DetachChild: ported from Pizza Connection 2 at 0x520f80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520f80
#include "pc2_port.h"

void __fastcall UI_DetachChild(int arg1)

{
  if (*(int *)(arg1 + 0x4c) != 0) {
    UI_RemoveEffectObject(*(void **)(*(int *)(arg1 + 8) + 0x134),arg1);
    *(uint32_t *)(arg1 + 0x48) = 0;
    *(uint32_t *)(arg1 + 0x44) = 0;
    *(uint32_t *)(arg1 + 0x4c) = 0;
  }
  return;
}
