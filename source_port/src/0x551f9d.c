// __nh_malloc: ported from Pizza Connection 2 at 0x551f9d.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551f9d
#include "pc2_port.h"

/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *ptr1;
  int value2;
  
  if (_Size < 0xffffffe1) {
    do {
      ptr1 = CRT_HeapAlloc((uint32_t *)_Size);
      if (ptr1 != (int *)0x0) {
        return ptr1;
      }
      if (_NhFlag == 0) {
        return (void *)0x0;
      }
      value2 = FUN_00555d41(_Size);
    } while (value2 != 0);
  }
  return (void *)0x0;
}
