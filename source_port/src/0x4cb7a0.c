// FreePlaySetup_FillStartCapitalText: ported from Pizza Connection 2 at 0x4cb7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb7a0
#include "pc2_port.h"

void __cdecl FreePlaySetup_FillStartCapitalText(void *arg1)

{
  uint8_t local_20 [32];
  
  String_Format(local_20,(uint8_t *)s__d__s_00568324,DAT_0057bb28);
  Window_GadgetNotify_Text_SetText(arg1,0x438,local_20);
  return;
}
