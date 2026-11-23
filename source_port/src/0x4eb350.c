// IsoMap_Destroy: ported from Pizza Connection 2 at 0x4eb350.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb350
#include "pc2_port.h"


void __fastcall IsoMap_Destroy(uint32_t *arg1)

{
  int value1;
  int value2;
  int value3;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_00559f7c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_IsoMap_Delete_0055c5d4;
  value2 = 0;
  local_4 = 1;
  if (0 < (intptr_t)(arg1[7] * arg1[8])) {
    value3 = 0;
    do {
      value1 = *(int *)(value3 + 8 + arg1[0x13]);
      if (value1 != 0) {
        Buffer_FreeLockedGlobal(value1 + 4);
        Buffer_FreeLockedGlobal(*(int *)(value3 + 8 + arg1[0x13]) + 0x10);
      }
      value2 = value2 + 1;
      value3 = value3 + 0xc;
    } while (value2 < (intptr_t)(arg1[7] * arg1[8]));
  }
  Mem_Free((LPVOID)arg1[0x4e]);
  Mem_Free((LPVOID)arg1[0x13]);
  Mem_Free((LPVOID)arg1[0x14]);
  Mem_Free((LPVOID)arg1[0x15]);
  Mem_Free((LPVOID)arg1[0x19]);
  Mem_Free((LPVOID)arg1[0x2c]);
  if ((uint32_t *)arg1[0x1c] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x1c])(1);
  }
  if ((uint32_t *)arg1[0x1d] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x1d])(1);
  }
  if ((uint32_t *)arg1[0x1e] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0x1e])(1);
  }
  if ((LPVOID)arg1[0x27] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x27]);
  }
  if ((LPVOID)arg1[0x28] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x28]);
  }
  IDMap_RemoveByKey((void *)(arg1[1] + 0x2c3f8),(intptr_t)arg1);
  DeleteCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x30));
  if ((uint32_t *)arg1[2] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[2])(1);
  }
  if ((LPVOID)arg1[0x44] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x44]);
  }
  if ((LPVOID)arg1[0x45] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x45]);
  }
  if ((LPVOID)arg1[0x46] != (LPVOID)0x0) {
    Mem_Free((LPVOID)arg1[0x46]);
  }
  local_4 = local_4 & 0xffffff00;
  List_Node_Destroy(arg1 + 0x50);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0x47);
  ExceptionList = pvStack_c;
  return;
}
