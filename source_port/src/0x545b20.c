// List_ContainerDestruct: ported from Pizza Connection 2 at 0x545b20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x545b20
#include "pc2_port.h"

void __fastcall List_ContainerDestruct(uint32_t *arg1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint32_t *uptr1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  void *pvStack_c;
  uint8_t *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055b686;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_LAB_0055cb04;
  local_4 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(arg1 + 6);
  EnterCriticalSection(lpCriticalSection);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  arg1[4] = arg1[2];
  while (uptr1 = (uint32_t *)arg1[4], uptr1 != (uint32_t *)0x0) {
    arg1[4] = uptr1[1];
    (**(code **)(*(int *)*uptr1 + 4))((int *)*uptr1);
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  pvVar3 = (LPVOID)arg1[2];
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((intptr_t)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  arg1[2] = 0;
  arg1[4] = 0;
  arg1[5] = 0;
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = pvStack_c;
  return;
}
