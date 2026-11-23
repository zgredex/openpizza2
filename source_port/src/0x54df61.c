// CRT_Fputs: ported from Pizza Connection 2 at 0x54df61.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54df61
#include "pc2_port.h"

int __cdecl CRT_Fputs(char *arg1,int *arg2)

{
  size_t svalue1;
  int value2;
  uint32_t uvalue3;
  
  svalue1 = _strlen(arg1);
  CRT_LockFile((uint32_t)arg2);
  value2 = CRT_GetStreamBuffer(arg2);
  uvalue3 = CRT_Fwrite(arg1,1,svalue1,arg2);
  CRT_ReleaseStreamBuffer(value2,arg2);
  CS_LeaveObject((uint32_t)arg2);
  return (uvalue3 == svalue1) - 1;
}
