// Person_ReturnToHomeBase: ported from Pizza Connection 2 at 0x507fd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507fd0
#include "pc2_port.h"

void __fastcall Person_ReturnToHomeBase(void *arg1)

{
  uint32_t unaff_ESI;
  
                    /* Returns a person to its home/base destination. */
  if (*(void **)(DAT_0057c670 + 0x21c) == arg1) {
    DebugConsole_Printf(DAT_0057c1e0,0,&DAT_0057301c,unaff_ESI);
  }
  Object_SetState(arg1,2);
  if (*(int *)((intptr_t)arg1 + 0xa0) == 0) {
    *(uint32_t *)((intptr_t)arg1 + 0xd0) = *(uint32_t *)((intptr_t)arg1 + 0xcc);
  }
  else {
    *(uint32_t *)((intptr_t)arg1 + 0xd0) =
         *(uint32_t *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x3c) * 4 + 0xd4);
  }
  Object_SetDestinationAndTarget
            (arg1,6,*(int *)((intptr_t)arg1 + *(int *)((intptr_t)arg1 + 0x3c) * 4 + 0xd4));
  return;
}
