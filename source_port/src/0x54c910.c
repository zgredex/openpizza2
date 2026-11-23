// Sound_DestroyAllChannels: ported from Pizza Connection 2 at 0x54c910.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54c910
#include "pc2_port.h"

void __fastcall Sound_DestroyAllChannels(uint8_t *arg1)

{
  LPVOID pvVar1;
  void *pvVar2;
  int value3;
  
  Sound_ShutdownThread(arg1);
  pvVar2 = *(void **)(arg1 + 0xc4);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 0xc4);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    if (*(uint32_t **)(arg1 + 0xc4) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 0xc4))(1);
    }
    *(uint32_t *)(arg1 + 0xc4) = 0;
  }
  pvVar2 = *(void **)(arg1 + 200);
  if (pvVar2 != (void *)0x0) {
    value3 = 0;
    if (0 < *(int *)((intptr_t)pvVar2 + 0x14)) {
      do {
        pvVar1 = (LPVOID)IDMap_Lookup(pvVar2,value3,(int *)0x0);
        Mem_Free(pvVar1);
        pvVar2 = *(void **)(arg1 + 200);
        value3 = value3 + 1;
      } while (value3 < *(int *)((intptr_t)pvVar2 + 0x14));
    }
    if (*(uint32_t **)(arg1 + 200) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)(arg1 + 200))(1);
    }
    *(uint32_t *)(arg1 + 200) = 0;
  }
  if (*(HANDLE *)(arg1 + 0x98) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(arg1 + 0x98));
    *(uint32_t *)(arg1 + 0x98) = 0;
  }
  if (*(HANDLE *)(arg1 + 0x9c) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(arg1 + 0x9c));
    *(uint32_t *)(arg1 + 0x9c) = 0;
  }
  if (*(HANDLE *)(arg1 + 0x94) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(arg1 + 0x94));
    *(uint32_t *)(arg1 + 0x94) = 0;
  }
  return;
}
