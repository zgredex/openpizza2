// Game_GetDateStage: ported from Pizza Connection 2 at 0x4ffa60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffa60
#include "pc2_port.h"

char __thiscall Game_GetDateStage(void *self,int arg1)

{
  int value1;
  
  value1 = Game_GetDateField0C(DAT_0057c670);
  return ((*(int *)((intptr_t)self + arg1 * 0x168 + 0x54) <= value1) - 1U & 3) + 1;
}
