// FreePlaySetup_FillGameLengthText: ported from Pizza Connection 2 at 0x4cb7e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb7e0
#include "pc2_port.h"

void __cdecl FreePlaySetup_FillGameLengthText(void *arg1)

{
  uint8_t local_20 [32];
  
  if ((DAT_0057bb2c < 2) || (DAT_0057bb2c != 0xb)) {
    String_Format(local_20,(uint8_t *)s__d__s_00568324,DAT_0057bb2c);
  }
  else {
    String_Format(local_20,&DAT_005630d0,DAT_00582768);
  }
  Window_GadgetNotify_Text_SetText(arg1,0x435,local_20);
  return;
}
