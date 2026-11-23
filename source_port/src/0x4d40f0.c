// Game_ResetPlayerStatsByCity: ported from Pizza Connection 2 at 0x4d40f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d40f0
#include "pc2_port.h"

void __fastcall Game_ResetPlayerStatsByCity(int arg1)

{
  void *pvVar1;
  
  pvVar1 = (void *)Game_GetPlayerSubmapValue
                             (DAT_0057c670,*(int *)(arg1 + 0x81c),*(int *)(arg1 + 0x820));
  if (pvVar1 == (void *)0x0) {
    return;
  }
  Stats_ResetAverages(pvVar1);
  return;
}
