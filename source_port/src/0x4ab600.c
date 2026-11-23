// StatisticsBalance_UpdateHeader: ported from Pizza Connection 2 at 0x4ab600.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ab600
#include "pc2_port.h"

void __cdecl StatisticsBalance_UpdateHeader(void *arg1)

{
  uint32_t uvalue1;
  uint8_t local_40 [64];
  
  if (DAT_0057d5cc == -1) {
    uvalue1 = DAT_00582f6c;
  }
  else {
    uvalue1 = (&DAT_00582fc0)[DAT_0057d5cc];
  }
  Gadget_SetText(arg1,0x4b4,uvalue1);
  if (DAT_0057d5c8 < 1) {
    String_Format(local_40,&DAT_005694e0,DAT_00569354);
  }
  else {
    String_Format(local_40,(uint8_t *)s__d__s__02d_005682ec,DAT_0057d5c8);
  }
  Gadget_SetText(arg1,0x4b7,local_40);
  return;
}
