// UI_DetachObject: ported from Pizza Connection 2 at 0x521b90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521b90
#include "pc2_port.h"

void __fastcall UI_DetachObject(int arg1)

{
  if (*(int *)(arg1 + 0x4c) != 0) {
    UI_RemoveEffectObject(*(void **)(*(int *)(arg1 + 8) + 0x134),arg1);
    *(uint32_t *)(arg1 + 0x4c) = 0;
  }
  *(uint32_t *)(arg1 + 0x74) = 0;
  *(uint32_t *)(arg1 + 0x70) = 0;
  return;
}
