// CRT_Fsopen: ported from Pizza Connection 2 at 0x54dfaf.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54dfaf
#include "pc2_port.h"

uint32_t * __cdecl CRT_Fsopen(LPCSTR arg1,char *arg2,uint32_t arg3)

{
  uint32_t *uptr1;
  uint32_t *uptr2;
  
  uptr1 = CRT_GetStream();
  if (uptr1 == (uint32_t *)0x0) {
    return (uint32_t *)0x0;
  }
  uptr2 = CRT_OpenFile(arg1,arg2,arg3,uptr1);
  CS_LeaveObject((uint32_t)uptr1);
  return uptr2;
}
