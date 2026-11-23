// CRT_Fflush: ported from Pizza Connection 2 at 0x550655.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x550655
#include "pc2_port.h"

int __cdecl CRT_Fflush(int *arg1)

{
  int value1;
  
  if (arg1 == (int *)0x0) {
    value1 = CRT_FlushAllStreams(0);
    return value1;
  }
  CRT_LockFile((uint32_t)arg1);
  value1 = CRT_FflushLocked(arg1);
  CS_LeaveObject((uint32_t)arg1);
  return value1;
}
