// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x551f46.c:6:26: error: unknown type name 'LPCVOID'; did you mean 'LPVOID'?
// CRT_Msize: ported from Pizza Connection 2 at 0x551f46.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551f46
#include "pc2_port.h"

SIZE_T __cdecl CRT_Msize(LPCVOID arg1)

{
  uint32_t uvalue1;
  SIZE_T SVar2;
  
  CRT_Lock(9);
  uvalue1 = Heap_FindBlock((intptr_t)arg1);
  if (uvalue1 == 0) {
    CS_LeaveIndexed(9);
    SVar2 = HeapSize(DAT_00585be0,0,arg1);
  }
  else {
    SVar2 = *(int *)((intptr_t)arg1 + -4) - 9;
    CS_LeaveIndexed(9);
  }
  return SVar2;
}
