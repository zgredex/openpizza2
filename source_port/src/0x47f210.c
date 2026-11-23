// Branch_UpdateActiveConstruction: ported from Pizza Connection 2 at 0x47f210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f210
#include "pc2_port.h"

void __fastcall Branch_UpdateActiveConstruction(void *arg1)

{
  void *local_4;
  
  if (*(int *)((intptr_t)arg1 + 0x14c4) != 0) {
    local_4 = arg1;
    Game_GetBestObject(arg1,1,*(int *)((intptr_t)arg1 + 0x14cc),(float *)&local_4);
  }
  return;
}
