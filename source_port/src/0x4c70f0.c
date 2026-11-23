// UI_SetOnlineHelpText: ported from Pizza Connection 2 at 0x4c70f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c70f0
#include "pc2_port.h"

void __cdecl UI_SetOnlineHelpText(void *arg1,uint32_t arg2)

{
  Window_GadgetNotify_Text_SetText(arg1,0x429,arg2);
  return;
}
