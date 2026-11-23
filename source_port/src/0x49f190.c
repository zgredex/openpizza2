// Game_ClearObjectReferences: ported from Pizza Connection 2 at 0x49f190.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49f190
#include "pc2_port.h"

void __cdecl Game_ClearObjectReferences(int arg1)

{
  if (arg1 == DAT_0057cda0) {
    DAT_0057cda0 = 0;
  }
  if (*(int *)(DAT_0057c670 + 0x98) == arg1) {
    *(uint32_t *)(DAT_0057c670 + 0x98) = 0;
  }
  return;
}
