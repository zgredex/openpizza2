// Profiler_StartTimer: ported from Pizza Connection 2 at 0x403790.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403790
#include "pc2_port.h"

void __cdecl Profiler_StartTimer(int arg1)

{
  DWORD DVar1;
  
  if (DAT_0057b558 != 0) {
    if (arg1 < 0) {
      DAT_00579cd8 = timeGetTime();
      return;
    }
    if (99 < arg1) {
      arg1 = 99;
    }
    DVar1 = timeGetTime();
    (&DAT_00579cd8)[arg1] = DVar1;
  }
  return;
}
