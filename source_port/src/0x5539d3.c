// CRT_Calloc: ported from Pizza Connection 2 at 0x5539d3.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5539d3
#include "pc2_port.h"

int * __cdecl CRT_Calloc(int arg1,int arg2)

{
  int *ptr1;
  int value2;
  uint32_t *_Size;
  uint32_t *uptr3;
  
  _Size = (uint32_t *)(arg1 * arg2);
  uptr3 = _Size;
  if (_Size < (uint32_t *)0xffffffe1) {
    if (_Size == (uint32_t *)0x0) {
      uptr3 = (uint32_t *)0x1;
    }
    uptr3 = (uint32_t *)((intptr_t)uptr3 + 0xfU & 0xfffffff0);
  }
  do {
    if (uptr3 < (uint32_t *)0xffffffe1) {
      if (_Size <= DAT_00577168) {
        CRT_Lock(9);
        ptr1 = CRT_Malloc(_Size);
        CS_LeaveIndexed(9);
        if (ptr1 != (int *)0x0) {
          _memset(ptr1,0,(size_t)_Size);
          return ptr1;
        }
      }
      ptr1 = HeapAlloc(DAT_00585be0,8,(SIZE_T)uptr3);
      if (ptr1 != (int *)0x0) {
        return ptr1;
      }
    }
    if (DAT_005858f8 == 0) {
      return (int *)0x0;
    }
    value2 = FUN_00555d41(uptr3);
  } while (value2 != 0);
  return (int *)0x0;
}
