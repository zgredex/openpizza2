// Object_SetWorkState: ported from Pizza Connection 2 at 0x50a920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50a920
#include "pc2_port.h"

void __fastcall Object_SetWorkState(void *arg1)

{
  Object_SetState(arg1,0x2e);
  *(uint32_t *)(DAT_0057c670 + 0x368) = 1;
  Object_SetFlag104(arg1,1);
  return;
}
