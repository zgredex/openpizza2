// List_FreeAll: ported from Pizza Connection 2 at 0x541250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541250
#include "pc2_port.h"

void __fastcall List_FreeAll(uint32_t *arg1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  
  pvVar2 = (LPVOID)*arg1;
  while (pvVar2 != (LPVOID)0x0) {
    pvVar1 = *(LPVOID *)((intptr_t)pvVar2 + 4);
    Mem_Free(pvVar2);
    pvVar2 = pvVar1;
  }
  *arg1 = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  return;
}
