// CRT_StreamPutc: ported from Pizza Connection 2 at 0x5518a6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5518a6
#include "pc2_port.h"

void __cdecl CRT_StreamPutc(uint32_t arg1,int *arg2,int *arg3)

{
  int *ptr1;
  uint32_t uvalue2;
  
  ptr1 = arg2 + 1;
  *ptr1 = *ptr1 + -1;
  if (*ptr1 < 0) {
    uvalue2 = CRT_FlushStreamBuffer(arg1,arg2);
  }
  else {
    *(uint8_t *)*arg2 = (uint8_t)arg1;
    *arg2 = *arg2 + 1;
    uvalue2 = arg1 & 0xff;
  }
  if (uvalue2 == 0xffffffff) {
    *arg3 = -1;
    return;
  }
  *arg3 = *arg3 + 1;
  return;
}
