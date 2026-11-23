// Person_RecomputePathStep: ported from Pizza Connection 2 at 0x507920.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507920
#include "pc2_port.h"


int __fastcall Person_RecomputePathStep(int arg1)

{
  uint32_t *self;
  int value1;
  void *pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int value6;
  DWORD DVar7;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Recomputes a person's weighted path and advances a step. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a2bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(0x7c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    MessageList_Construct((uint32_t *)((intptr_t)pvVar2 + 0x14));
  }
  local_4 = 0xffffffff;
  uvalue3 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),
                        (intptr_t)*(short *)(*(int *)(arg1 + 200) + 0x28));
  uvalue4 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),
                        *(short *)(*(int *)(arg1 + 200) + 0x28) + 1);
  value5 = AI_ComputeWeightedPath();
  if (value5 == 0) {
    NoOp_Stub();
  }
  Object_ClearField4(*(int *)(arg1 + 200) + 0x14);
  Array_Grow((void *)(*(int *)(arg1 + 200) + 0x14),uvalue3);
  Array_Grow((void *)(*(int *)(arg1 + 200) + 0x14),uvalue4);
  self = (uint32_t *)((intptr_t)pvVar2 + 0x14);
  value6 = Array_GetPtr4(self,1);
  value1 = 1;
  while (value6 != 0) {
    uvalue3 = Array_GetPtr4(self,value1);
    Array_Grow((void *)(*(int *)(arg1 + 200) + 0x14),uvalue3);
    value6 = Array_GetPtr4(self,value1 + 1);
    value1 = value1 + 1;
  }
  Object_SetShort28(*(void **)(arg1 + 200),0);
  if (pvVar2 != (LPVOID)0x0) {
    Palette_Free(self);
    Mem_Free(pvVar2);
  }
  DVar7 = timeGetTime();
  Object_UpdateWalkStep(*(void **)(arg1 + 0xc4),*(uint32_t **)(arg1 + 200),DVar7);
  ExceptionList = local_c;
  return value5;
}
