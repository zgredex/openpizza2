// CRT_FwriteLocked: ported from Pizza Connection 2 at 0x54fb27.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fb27
#include "pc2_port.h"

uint32_t __cdecl CRT_FwriteLocked(char *arg1,uint32_t arg2,uint32_t arg3,int *arg4)

{
  uint32_t uvalue1;
  
  CRT_LockFile((uint32_t)arg4);
  uvalue1 = CRT_Fwrite(arg1,arg2,arg3,arg4);
  CS_LeaveObject((uint32_t)arg4);
  return uvalue1;
}
