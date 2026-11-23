// Person_DebugPrintLocation: ported from Pizza Connection 2 at 0x507170.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507170
#include "pc2_port.h"

void __fastcall Person_DebugPrintLocation(int arg1)

{
  if (*(int *)(DAT_0057c670 + 0x21c) == arg1) {
    if (*(int *)(arg1 + 0xfc) == 0) {
      DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_In__d__NULL_00572f1c,
                          (uint32_t)*(uint8_t *)(arg1 + 0x104));
      return;
    }
    DebugConsole_Printf(DAT_0057c1e0,0,(uint8_t *)s_In__d___s_00572f10,(uint32_t)*(uint8_t *)(arg1 + 0x104)
                       );
  }
  return;
}
