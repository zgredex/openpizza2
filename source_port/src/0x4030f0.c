// Game_FormatObjectName: ported from Pizza Connection 2 at 0x4030f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4030f0
#include "pc2_port.h"

void __thiscall Game_FormatObjectName(void *self,int arg1,uint8_t *arg2,uint32_t arg3)

{
  if (arg1 == 0) {
    Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x10));
  }
  else {
    Random_Mod((intptr_t)*(short *)((intptr_t)self + 0x12));
  }
  String_Format(arg2,(uint8_t *)s__s__s_00563314,arg3);
  return;
}
