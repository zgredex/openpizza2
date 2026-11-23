// Person_WatchTVProgram: ported from Pizza Connection 2 at 0x50e4e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50e4e0
#include "pc2_port.h"

void __fastcall Person_WatchTVProgram(void *arg1)

{
                    /* Marks a person as watching the current TV program. */
  *(uint32_t *)((intptr_t)arg1 + 0x108) = 10;
  if (*(int *)((intptr_t)arg1 + 0x74) == 0) {
    Game_GetTimeByMode(arg1,0);
    *(uint32_t *)((intptr_t)arg1 + 0x4c) = 0;
    *(uint32_t *)((intptr_t)arg1 + 0x54) = 0;
    Person_SetRandomResidentialTarget(arg1);
  }
  return;
}
