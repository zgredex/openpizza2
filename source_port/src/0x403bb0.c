// Timer_RemoveById: ported from Pizza Connection 2 at 0x403bb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403bb0
#include "pc2_port.h"

uint32_t __thiscall Timer_RemoveById(void *self,int arg1)

{
  LPVOID pvVar1;
  uint32_t uvalue2;
  
  pvVar1 = *(LPVOID *)((intptr_t)self + 0xc);
  while( true ) {
    if (pvVar1 == (LPVOID)0x0) {
      return 0;
    }
    if (*(int *)((intptr_t)pvVar1 + 0x10) == arg1) break;
    pvVar1 = *(LPVOID *)((intptr_t)pvVar1 + 0x14);
  }
  uvalue2 = Timer_RemoveEntry(self,pvVar1);
  return uvalue2;
}
