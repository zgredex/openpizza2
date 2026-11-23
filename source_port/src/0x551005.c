// CRT_FreeInternal: ported from Pizza Connection 2 at 0x551005.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551005
#include "pc2_port.h"

void __cdecl CRT_FreeInternal(LPVOID arg1)

{
  uint32_t *uptr1;
  
  if (arg1 != (LPVOID)0x0) {
    CRT_Lock(9);
    uptr1 = (uint32_t *)Heap_FindBlock((intptr_t)arg1);
    if (uptr1 != (uint32_t *)0x0) {
      CRT_Free(uptr1,(uint32_t)arg1);
      CS_LeaveIndexed(9);
      return;
    }
    CS_LeaveIndexed(9);
    HeapFree(DAT_00585be0,0,arg1);
  }
  return;
}
