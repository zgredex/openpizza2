// UI_SyncSelectedChild: ported from Pizza Connection 2 at 0x483120.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x483120
#include "pc2_port.h"

void __fastcall UI_SyncSelectedChild(int arg1)

{
  int value1;
  
  value1 = IDMap_Lookup(*(void **)(arg1 + 0x27c),*(int *)(arg1 + 0x280),(int *)0x0);
  *(uint32_t *)(arg1 + 0x288) = *(uint32_t *)(value1 + 0x4c);
  return;
}
