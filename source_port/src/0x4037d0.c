// Profiler_StopTimer: ported from Pizza Connection 2 at 0x4037d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4037d0
#include "pc2_port.h"

void __cdecl Profiler_StopTimer(int arg1)

{
  DWORD DVar1;
  uint32_t uvalue2;
  
  if (DAT_0057b558 != 0) {
    if (arg1 < 0) {
      arg1 = 0;
    }
    else if (99 < arg1) {
      arg1 = 99;
    }
    DVar1 = timeGetTime();
    uvalue2 = DVar1 - (&DAT_00579cd8)[arg1];
    if ((uint32_t)(&DAT_0057b31c)[arg1] < uvalue2) {
      (&DAT_0057b31c)[arg1] = uvalue2;
      (&DAT_00579e68)[arg1] = (&DAT_00579b48)[arg1];
    }
    (&DAT_00579b48)[arg1] = (&DAT_00579b48)[arg1] + 1;
    (&DAT_0057a18c)[arg1] = (&DAT_0057a18c)[arg1] + uvalue2;
  }
  return;
}
