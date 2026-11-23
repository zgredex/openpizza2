// Branch_ClearConstructionSites: ported from Pizza Connection 2 at 0x47fd20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fd20
#include "pc2_port.h"

void __fastcall Branch_ClearConstructionSites(void *arg1)

{
  int value1;
  
  value1 = *(int *)((intptr_t)arg1 + 0x19ac);
  while (0 < value1) {
    Game_ConsumeObject(arg1,0);
    value1 = *(int *)((intptr_t)arg1 + 0x19ac);
  }
  return;
}
