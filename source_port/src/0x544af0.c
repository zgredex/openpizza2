// List_RemoveNodeLocked: ported from Pizza Connection 2 at 0x544af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x544af0
#include "pc2_port.h"


void __thiscall List_RemoveNodeLocked(void *self,uint32_t *arg1)

{
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b3f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  EnterCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x18));
  local_4 = 0;
  if (arg1 != (uint32_t *)0x0) {
    (**(code **)(*(int *)*arg1 + 4))((int *)*arg1);
    if (*(uint32_t **)((intptr_t)self + 0x10) == arg1) {
      *(uint32_t *)((intptr_t)self + 0x10) = (*(uint32_t **)((intptr_t)self + 0x10))[1];
    }
    if (arg1[2] == 0) {
      *(uint32_t *)((intptr_t)self + 8) = arg1[1];
    }
    else {
      *(uint32_t *)(arg1[2] + 4) = arg1[1];
    }
    if (arg1 == *(uint32_t **)((intptr_t)self + 0xc)) {
      *(uint32_t *)((intptr_t)self + 0xc) = arg1[2];
    }
    if (arg1[1] != 0) {
      *(uint32_t *)(arg1[1] + 8) = arg1[2];
    }
    *(int *)((intptr_t)self + 0x14) = *(int *)((intptr_t)self + 0x14) + -1;
    Mem_Free(arg1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((intptr_t)self + 0x18));
  ExceptionList = pvStack_c;
  return;
}
