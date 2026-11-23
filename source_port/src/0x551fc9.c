// CRT_HeapAlloc: ported from Pizza Connection 2 at 0x551fc9.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551fc9
#include "pc2_port.h"

int * __cdecl CRT_HeapAlloc(uint32_t *arg1)

{
  int *ptr1;
  
  if (arg1 <= DAT_00577168) {
    CRT_Lock(9);
    ptr1 = CRT_Malloc(arg1);
    CS_LeaveIndexed(9);
    if (ptr1 != (int *)0x0) {
      return ptr1;
    }
  }
  if (arg1 == (uint32_t *)0x0) {
    arg1 = (uint32_t *)0x1;
  }
  ptr1 = HeapAlloc(DAT_00585be0,0,(intptr_t)arg1 + 0xfU & 0xfffffff0);
  return ptr1;
}
