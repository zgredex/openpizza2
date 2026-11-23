// Game_FormatObjectNameRandom: ported from Pizza Connection 2 at 0x403150.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403150
#include "pc2_port.h"

void __thiscall Game_FormatObjectNameRandom(void *self,uint8_t *arg1,uint32_t arg2)

{
  Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x14));
  String_Format(arg1,(uint8_t *)s__s__s_00563314,arg2);
  return;
}
