// CRT_Fgetc: ported from Pizza Connection 2 at 0x54e1f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e1f0
#include "pc2_port.h"

uint32_t __cdecl CRT_Fgetc(uint32_t *arg1)

{
  int *ptr1;
  uint32_t uvalue2;
  
  CRT_LockFile((uint32_t)arg1);
  ptr1 = arg1 + 1;
  *ptr1 = *ptr1 + -1;
  if (*ptr1 < 0) {
    uvalue2 = CRT_Filbuf(arg1);
  }
  else {
    uvalue2 = (uint32_t)*(uint8_t *)*arg1;
    *arg1 = (uint8_t *)*arg1 + 1;
  }
  CS_LeaveObject((uint32_t)arg1);
  return uvalue2;
}
