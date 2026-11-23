// ImageCache_Clear: ported from Pizza Connection 2 at 0x527250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527250
#include "pc2_port.h"

void __fastcall ImageCache_Clear(int arg1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  
  pvVar1 = *(LPVOID *)(arg1 + 0x82c4);
  while (pvVar1 != (LPVOID)0x0) {
    *(uint32_t *)(arg1 + 0x82c4) = *(uint32_t *)((intptr_t)pvVar1 + 0x10c);
    pvVar2 = *(LPVOID *)((intptr_t)pvVar1 + 0x104);
    if (pvVar2 != (LPVOID)0x0) {
      Image_FreePixelData((intptr_t)pvVar2);
      Mem_Free(pvVar2);
    }
    Mem_Free(pvVar1);
    pvVar1 = *(LPVOID *)(arg1 + 0x82c4);
  }
  return;
}
