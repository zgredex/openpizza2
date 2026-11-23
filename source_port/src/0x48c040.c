// Game_SetMessageField34: ported from Pizza Connection 2 at 0x48c040.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c040
#include "pc2_port.h"

void __thiscall Game_SetMessageField34(void *self,int arg1,uint32_t arg2)

{
  MessageList_SetField34((void *)((intptr_t)self + 0x304),arg1,arg2);
  return;
}
