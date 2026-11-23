// Game_UpdateAndFetchMapEntryFAC: ported from Pizza Connection 2 at 0x4d75d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d75d0
#include "pc2_port.h"

void __thiscall Game_UpdateAndFetchMapEntryFAC(void *self,int arg1)

{
  IDMap_Update((void *)((intptr_t)self + 0xfac),&arg1);
  IDMap_Lookup((void *)((intptr_t)self + 0xfac),arg1,(int *)0x0);
  return;
}
