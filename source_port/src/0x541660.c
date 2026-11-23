// SoundBuffer_DestroyInterfaces: ported from Pizza Connection 2 at 0x541660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541660
#include "pc2_port.h"


void __fastcall SoundBuffer_DestroyInterfaces(uint32_t *arg1)

{
  int *ptr1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  int value4;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_0055af5b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_LAB_0055c8c8;
  ptr1 = (int *)arg1[0x17];
  local_4 = 0;
  if (ptr1 != (int *)0x0) {
    (**(code **)(*ptr1 + 8))(ptr1);
  }
  *arg1 = &PTR_LAB_0055c874;
  local_4 = 2;
  if (*(char *)(arg1 + 0xd) != '\0') {
    List_DestroyObjects((intptr_t)arg1);
  }
  ptr1 = (int *)arg1[0x12];
  if (ptr1 != (int *)0x0) {
    value4 = (**(code **)(*ptr1 + 0x48))(ptr1);
    if (-1 < value4) {
      if (*(char *)(arg1 + 0xd) != '\0') {
        List_DestroyObjects((intptr_t)arg1);
      }
      (**(code **)(*(int *)arg1[0x12] + 0x34))((int *)arg1[0x12],0);
    }
    (**(code **)(*(int *)arg1[0x12] + 8))((int *)arg1[0x12]);
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  pvVar3 = (LPVOID)arg1[0xe];
  while (pvVar3 != (LPVOID)0x0) {
    pvVar2 = *(LPVOID *)((intptr_t)pvVar3 + 4);
    Mem_Free(pvVar3);
    pvVar3 = pvVar2;
  }
  arg1[0xe] = 0;
  arg1[0x10] = 0;
  arg1[0x11] = 0;
  *arg1 = &PTR_LAB_0055c840;
  ExceptionList = pvStack_c;
  return;
}
