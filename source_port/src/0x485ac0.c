// Game_GetSpeedSetting: ported from Pizza Connection 2 at 0x485ac0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x485ac0
#include "pc2_port.h"

uint32_t __fastcall Game_GetSpeedSetting(int arg1)

{
  uint32_t uvalue1;
  
  if ((*(int *)(arg1 + 0x2e1c) < 0x41) || (uvalue1 = 2, *(int *)(arg1 + 0x2e20) < 8)) {
    uvalue1 = 1;
  }
  return uvalue1;
}
