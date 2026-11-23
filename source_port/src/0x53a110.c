// Renderer_RestoreDisplay: ported from Pizza Connection 2 at 0x53a110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53a110
#include "pc2_port.h"

void __fastcall Renderer_RestoreDisplay(int arg1)

{
  if (*(int *)(arg1 + 0x4c) == 0) {
    (**(code **)(*(int *)**(uint32_t **)(arg1 + 0x40) + 0x54))
              ((int *)**(uint32_t **)(arg1 + 0x40),DAT_00574734,DAT_00574738,0x10);
  }
  Thread_WaitForExit(arg1);
  return;
}
