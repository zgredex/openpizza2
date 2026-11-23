// Game_AddRecordTo19C4: ported from Pizza Connection 2 at 0x47eba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47eba0
#include "pc2_port.h"

void __thiscall Game_AddRecordTo19C4(void *self,uint32_t *arg1)

{
  *arg1 = 0;
  List_Add((void *)((intptr_t)self + 0x19c4),arg1);
  return;
}
