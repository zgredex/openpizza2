// Surface_LockPrimary: ported from Pizza Connection 2 at 0x538f90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x538f90
#include "pc2_port.h"

void __fastcall Surface_LockPrimary(void *arg1)

{
  Surface_Lock(arg1,0);
  return;
}
