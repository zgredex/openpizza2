// UI_ReleaseRefCount: ported from Pizza Connection 2 at 0x5271d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5271d0
#include "pc2_port.h"

void __thiscall UI_ReleaseRefCount(void *self,int arg1)

{
  int *ptr1;
  LPVOID pvVar2;
  int value3;
  LPVOID pvVar4;
  
  pvVar4 = *(LPVOID *)((intptr_t)self + 0x82c4);
  pvVar2 = (LPVOID)0x0;
  if (pvVar4 != (LPVOID)0x0) {
    while (*(int *)((intptr_t)pvVar4 + 0x104) != arg1) {
      ptr1 = (int *)((intptr_t)pvVar4 + 0x10c);
      pvVar2 = pvVar4;
      pvVar4 = (LPVOID)*ptr1;
      if ((LPVOID)*ptr1 == (LPVOID)0x0) {
        return;
      }
    }
    value3 = *(int *)((intptr_t)pvVar4 + 0x108) + -1;
    *(int *)((intptr_t)pvVar4 + 0x108) = value3;
    if (value3 == 0) {
      if (pvVar2 == (LPVOID)0x0) {
        *(uint32_t *)((intptr_t)self + 0x82c4) = *(uint32_t *)((intptr_t)pvVar4 + 0x10c);
      }
      else {
        *(uint32_t *)((intptr_t)pvVar2 + 0x10c) = *(uint32_t *)((intptr_t)pvVar4 + 0x10c);
      }
      pvVar2 = *(LPVOID *)((intptr_t)pvVar4 + 0x104);
      if (pvVar2 != (LPVOID)0x0) {
        Image_FreePixelData((intptr_t)pvVar2);
        Mem_Free(pvVar2);
      }
      Mem_Free(pvVar4);
    }
  }
  return;
}
