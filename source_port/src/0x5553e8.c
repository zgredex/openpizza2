// CRT_StreamAllocBuffer: ported from Pizza Connection 2 at 0x5553e8.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5553e8
#include "pc2_port.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CRT_StreamAllocBuffer(uint32_t *arg1)

{
  void *pvVar1;
  
  _DAT_00585660 = _DAT_00585660 + 1;
  pvVar1 = _malloc(0x1000);
  arg1[2] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    arg1[3] = arg1[3] | 4;
    arg1[2] = arg1 + 5;
    arg1[6] = 2;
  }
  else {
    arg1[3] = arg1[3] | 8;
    arg1[6] = 0x1000;
  }
  arg1[1] = 0;
  *arg1 = arg1[2];
  return;
}
