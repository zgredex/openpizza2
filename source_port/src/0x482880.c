// Game_DestroyRootWindow: ported from Pizza Connection 2 at 0x482880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482880
#include "pc2_port.h"

void __fastcall Game_DestroyRootWindow(int arg1)

{
  UI_DestroyWindowAt((uint32_t *)(arg1 + 0x264));
  return;
}
