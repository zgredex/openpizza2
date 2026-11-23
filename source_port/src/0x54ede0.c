// CRT_Fseek: ported from Pizza Connection 2 at 0x54ede0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54ede0
#include "pc2_port.h"

int __cdecl CRT_Fseek(int *arg1,int arg2,DWORD arg3)

{
  int value1;
  
  CRT_LockFile((uint32_t)arg1);
  value1 = CRT_FseekLocked(arg1,arg2,arg3);
  CS_LeaveObject((uint32_t)arg1);
  return value1;
}
