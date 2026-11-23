// Movie_ReleasePlayer: ported from Pizza Connection 2 at 0x5238c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5238c0
#include "pc2_port.h"

void __fastcall Movie_ReleasePlayer(int arg1)

{
  if (*(int *)(arg1 + 0x1c4) != 0) {
    CS_Enter(*(int *)(arg1 + 0x1c8));
    if (*(uint32_t **)(arg1 + 0x1c4) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 0x1c4))(1);
    }
    *(uint32_t *)(arg1 + 0x1c4) = 0;
    CS_Leave(*(int *)(arg1 + 0x1c8));
  }
  return;
}
