// Game_AddScreenTimer: ported from Pizza Connection 2 at 0x482590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x482590
#include "pc2_port.h"


void __fastcall Game_AddScreenTimer(int arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = Timer_AddEntry((void *)(arg1 + 0x2d1c),&LAB_00481190,200,0);
  *(uint32_t *)(arg1 + 0x2d8c) = uvalue1;
  return;
}
