// CRT_Ftell: ported from Pizza Connection 2 at 0x54ec5d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ec5d
#include "pc2_port.h"

int __cdecl CRT_Ftell(char *arg1)

{
  int value1;
  
  CRT_LockFile((uint32_t)arg1);
  value1 = CRT_FtellLocked(arg1);
  CS_LeaveObject((uint32_t)arg1);
  return value1;
}
