// ConstructionMenu_FillTimeLeft: ported from Pizza Connection 2 at 0x4c0390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0390
#include "pc2_port.h"

void __cdecl ConstructionMenu_FillTimeLeft(void *arg1)

{
  Gadget_SetTextf(arg1,0x418,(uint8_t *)s__d__s_00568324,*(uint32_t *)(DAT_0057d708 + 0x38));
  return;
}
