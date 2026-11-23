// CRT_Fputc: ported from Pizza Connection 2 at 0x54fc60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54fc60
#include "pc2_port.h"

uint32_t __cdecl CRT_Fputc(uint32_t arg1,int *arg2)

{
  int *ptr1;
  uint32_t uvalue2;
  
  CRT_LockFile((uint32_t)arg2);
  ptr1 = arg2 + 1;
  *ptr1 = *ptr1 + -1;
  if (*ptr1 < 0) {
    uvalue2 = CRT_FlushStreamBuffer(arg1,arg2);
  }
  else {
    uvalue2 = arg1 & 0xff;
    *(uint8_t *)*arg2 = (uint8_t)arg1;
    *arg2 = *arg2 + 1;
  }
  CS_LeaveObject((uint32_t)arg2);
  return uvalue2;
}
