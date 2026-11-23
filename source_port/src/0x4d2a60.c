// Game_MapRecordToGlobal: ported from Pizza Connection 2 at 0x4d2a60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d2a60
#include "pc2_port.h"

void __thiscall Game_MapRecordToGlobal(void *self,int arg1)

{
  int value1;
  
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x78),arg1,(int *)0x0);
  IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value1,(int *)0x0);
  return;
}
