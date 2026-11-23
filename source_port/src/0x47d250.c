// Game_QueueObjectTask: ported from Pizza Connection 2 at 0x47d250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47d250
#include "pc2_port.h"

void __thiscall Game_QueueObjectTask(void *self,int arg1)

{
  List_Add((void *)((intptr_t)self + 0x1760),*(uint32_t *)(arg1 + 0x164));
  return;
}
