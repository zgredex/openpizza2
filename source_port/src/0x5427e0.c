// SoundMixerThread_Destroy: ported from Pizza Connection 2 at 0x5427e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5427e0
#include "pc2_port.h"


void __fastcall SoundMixerThread_Destroy(uint32_t *arg1)

{
  LPVOID pvVar1;
  LPVOID pvVar2;
  uint32_t *uptr3;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055b036;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_SoundMixerThread_Delete_0055c8f0;
  local_4 = 1;
  *(uint8_t *)(arg1 + 0xd) = 1;
  if ((HANDLE)arg1[0xb] != (HANDLE)0x0) {
    SetEvent((HANDLE)arg1[0xb]);
    if ((HANDLE)arg1[0xc] != (HANDLE)0xffffffff) {
      WaitForSingleObject((HANDLE)arg1[0xc],0xffffffff);
    }
    CloseHandle((HANDLE)arg1[0xb]);
  }
  uptr3 = (uint32_t *)arg1[1];
  arg1[3] = uptr3;
  if (uptr3 != (uint32_t *)0x0) {
    arg1[3] = uptr3[1];
    while( true ) {
      (**(code **)(*(int *)*uptr3 + 4))((int *)*uptr3);
      uptr3 = (uint32_t *)arg1[3];
      if (uptr3 == (uint32_t *)0x0) break;
      arg1[3] = uptr3[1];
    }
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 5));
  local_4 = 0xffffffff;
  pvVar2 = (LPVOID)arg1[1];
  while (pvVar2 != (LPVOID)0x0) {
    pvVar1 = *(LPVOID *)((intptr_t)pvVar2 + 4);
    Mem_Free(pvVar2);
    pvVar2 = pvVar1;
  }
  arg1[1] = 0;
  arg1[3] = 0;
  arg1[4] = 0;
  ExceptionList = pvStack_c;
  return;
}
