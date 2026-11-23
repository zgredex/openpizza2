// SoundSystem_Destroy: ported from Pizza Connection 2 at 0x544ba0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544ba0
#include "pc2_port.h"

void __fastcall SoundSystem_Destroy(uint32_t *arg1)

{
  int value1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  int *ptr4;
  uint32_t *uptr5;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055b51d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  arg1[-1] = &PTR_LAB_0055c8f8;
  *arg1 = &PTR_LAB_0055c9f8;
  arg1[4] = &PTR_LAB_0055c8f4;
  arg1[6] = &PTR_LAB_0055c9f4;
  uptr5 = (uint32_t *)arg1[0x14];
  local_4 = 6;
  arg1[0x16] = uptr5;
  if (uptr5 != (uint32_t *)0x0) {
    arg1[0x16] = uptr5[1];
    while( true ) {
      (**(code **)(*(int *)*uptr5 + 4))((int *)*uptr5);
      uptr5 = (uint32_t *)arg1[0x16];
      if (uptr5 == (uint32_t *)0x0) break;
      arg1[0x16] = uptr5[1];
    }
  }
  ptr4 = (int *)arg1[0x18];
  arg1[0x1a] = ptr4;
  if (ptr4 != (int *)0x0) {
    arg1[0x1a] = ptr4[1];
    while( true ) {
      value1 = *ptr4;
      *(uint32_t *)(value1 + 0x20) = 0;
      *(uint32_t *)(value1 + 0x24) = 0;
      (**(code **)(*(int *)*ptr4 + 4))((int *)*ptr4);
      ptr4 = (int *)arg1[0x1a];
      if (ptr4 == (int *)0x0) break;
      arg1[0x1a] = ptr4[1];
    }
  }
  uptr5 = (uint32_t *)arg1[0x1c];
  arg1[0x1e] = uptr5;
  if (uptr5 != (uint32_t *)0x0) {
    arg1[0x1e] = uptr5[1];
    while( true ) {
      (**(code **)(*(int *)*uptr5 + 4))((int *)*uptr5);
      uptr5 = (uint32_t *)arg1[0x1e];
      if (uptr5 == (uint32_t *)0x0) break;
      arg1[0x1e] = uptr5[1];
    }
  }
  ptr4 = (int *)arg1[0x26];
  if (ptr4 != (int *)0x0) {
    (**(code **)(*ptr4 + 4))(ptr4);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x27));
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  uptr5 = (uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)(arg1 + 0x1c));
  pvVar3 = (LPVOID)*uptr5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((intptr_t)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  *uptr5 = 0;
  uptr5[2] = 0;
  uptr5[3] = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  uptr5 = (uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)(arg1 + 0x18));
  pvVar3 = (LPVOID)*uptr5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((intptr_t)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  *uptr5 = 0;
  uptr5[2] = 0;
  uptr5[3] = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  uptr5 = (uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)(arg1 + 0x14));
  pvVar3 = (LPVOID)*uptr5;
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((intptr_t)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  *uptr5 = 0;
  uptr5[2] = 0;
  uptr5[3] = 0;
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  SoundMixerThread_Destroy
            ((uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)(arg1 + 6)));
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  uptr5 = (uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)(arg1 + 4));
  *uptr5 = &PTR_DirectSoundBuffer_Delete_0055c860;
  ptr4 = (int *)uptr5[1];
  if (ptr4 != (int *)0x0) {
    (**(code **)(*ptr4 + 8))(ptr4);
  }
  local_4 = 0xffffffff;
  SoundBuffer_DestructBase((uint32_t *)(-(uint32_t)(arg1 != (uint32_t *)0x4) & (uint32_t)arg1));
  ExceptionList = pvStack_c;
  return;
}
