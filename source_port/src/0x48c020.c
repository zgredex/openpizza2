// Game_HasKeyedRecordEntry: ported from Pizza Connection 2 at 0x48c020.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c020
#include "pc2_port.h"

void __thiscall Game_HasKeyedRecordEntry(void *self,int arg1,int arg2)

{
  Array_FindEntryByKeys((void *)((intptr_t)self + 0x304),arg1,arg2);
  return;
}
