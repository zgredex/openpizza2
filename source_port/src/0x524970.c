// Window_NotifyMouseMove: ported from Pizza Connection 2 at 0x524970.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x524970
#include "pc2_port.h"

void __fastcall Window_NotifyMouseMove(void *arg1)

{
  Window_DispatchMouseEvent
            (arg1,0x200,*(int *)((intptr_t)arg1 + 0x248),*(int *)((intptr_t)arg1 + 0x24c),0);
  return;
}
