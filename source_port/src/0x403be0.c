// Timer_RemoveEntry: ported from Pizza Connection 2 at 0x403be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403be0
#include "pc2_port.h"

uint32_t __thiscall Timer_RemoveEntry(void *self,LPVOID arg1)

{
  int value1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  
  value1 = (intptr_t)self + 0x10;
  CS_Enter(value1);
  pvVar2 = *(LPVOID *)((intptr_t)self + 0xc);
  if (pvVar2 == arg1) {
    *(uint32_t *)((intptr_t)self + 0xc) = *(uint32_t *)((intptr_t)arg1 + 0x14);
  }
  else {
    pvVar3 = *(LPVOID *)((intptr_t)pvVar2 + 0x14);
    while( true ) {
      if (pvVar3 == (LPVOID)0x0) {
        CS_Leave(value1);
        return 0;
      }
      if (pvVar3 == arg1) break;
      pvVar2 = pvVar3;
      pvVar3 = *(LPVOID *)((intptr_t)pvVar3 + 0x14);
    }
    *(uint32_t *)((intptr_t)pvVar2 + 0x14) = *(uint32_t *)((intptr_t)arg1 + 0x14);
  }
  Mem_Free(arg1);
  CS_Leave(value1);
  return 1;
}
