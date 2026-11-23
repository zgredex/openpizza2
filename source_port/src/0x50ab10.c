// Object_ActivateAndSetState: ported from Pizza Connection 2 at 0x50ab10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ab10
#include "pc2_port.h"

void __fastcall Object_ActivateAndSetState(void *arg1)

{
  Object_Activate(arg1,*(void **)((intptr_t)arg1 + 0xfc));
  Object_SetState(arg1,2);
  return;
}
