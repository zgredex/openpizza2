// Game_PickRandomTableValue: ported from Pizza Connection 2 at 0x502cb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x502cb0
#include "pc2_port.h"

uint32_t __thiscall Game_PickRandomTableValue(void *self,int arg1)

{
  uint32_t uvalue1;
  
  uvalue1 = Random_RangeFast(0,1);
  return *(uint32_t *)
          (&DAT_005728dc + (*(int *)((intptr_t)self + 0x44) + (uvalue1 + arg1 * 2) * 4) * 4);
}
