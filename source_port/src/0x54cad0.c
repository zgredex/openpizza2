// Thread_StopAndDestroy: ported from Pizza Connection 2 at 0x54cad0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54cad0
#include "pc2_port.h"


void __fastcall Thread_StopAndDestroy(int arg1)

{
  int value1;
  LPVOID pvVar2;
  uint32_t uvalue3;
  
  if (*(int *)(arg1 + 0x88) != 0) {
    *(uint32_t *)(*(int *)(arg1 + 0x88) + 0x6c) = 1;
    uvalue3 = (**(code **)(**(int **)(arg1 + 0x84) + 0x34))
                      (*(int **)(arg1 + 0x84),*(uint32_t *)(arg1 + 0x88),0,&LAB_0054c880,
                       *(uint32_t *)(arg1 + 0x88),0x30);
    NoOp_ReturnArg(uvalue3);
    value1 = *(int *)(*(int *)(arg1 + 0x88) + 0x6c);
    while (value1 == 0) {
      Sleep(10);
      value1 = *(int *)(*(int *)(arg1 + 0x88) + 0x6c);
    }
    Thread_ReleaseNodeValues(arg1);
    pvVar2 = *(LPVOID *)(arg1 + 0x88);
    if (pvVar2 != (LPVOID)0x0) {
      Thread_DestroyListNode50((intptr_t)pvVar2);
      Mem_Free(pvVar2);
    }
    *(uint32_t *)(arg1 + 0x88) = 0;
  }
  return;
}
