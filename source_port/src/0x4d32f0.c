// MapSprite_InitializeRecord: ported from Pizza Connection 2 at 0x4d32f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d32f0
#include "pc2_port.h"


void __fastcall MapSprite_InitializeRecord(int arg1)

{
  void *pvVar1;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558d8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x7c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    MessageList_Construct((uint32_t *)((intptr_t)pvVar1 + 0x14));
  }
  *(void **)(arg1 + 8) = pvVar1;
  local_4 = 0xffffffff;
  *(uint32_t *)((intptr_t)pvVar1 + 0x58) =
       *(uint32_t *)(DAT_0057c5cc + 0x2c0cc + *(int *)(arg1 + 0xc) * 4);
  pvVar1 = *(void **)(*(int *)(arg1 + 8) + 0x58);
  if (pvVar1 != (void *)0x0) {
    value2 = RecordList_FindFreeSlot(pvVar1,-1);
    **(int **)(arg1 + 8) = value2;
  }
  pvVar1 = *(void **)(DAT_0057c5cc + 0x2c180 + *(int *)(arg1 + 0xc) * 4);
  if (pvVar1 == (void *)0x0) {
    *(uint32_t *)(arg1 + 0x10) = 0xffffffff;
  }
  else {
    value2 = RecordList_FindFreeSlot(pvVar1,-1);
    *(int *)(arg1 + 0x10) = value2;
  }
  *(uint32_t *)(*(int *)(arg1 + 8) + 4) = 0xffffffff;
  *(uint16_t *)(*(int *)(arg1 + 8) + 8) = 0xffff;
  *(uint16_t *)(*(int *)(arg1 + 8) + 10) = 0xffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x6c) = 0;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x70) = 0;
  Object_SetShort28(*(void **)(arg1 + 8),0xffff);
  *(uint32_t *)(*(int *)(arg1 + 8) + 0xc) = 0;
  *(uint8_t *)(*(int *)(arg1 + 8) + 0x10) = 0;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x20) = 0;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x24) = 0;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x2c) = 0;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x30) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x34) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x38) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x3c) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x40) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x44) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x48) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x4c) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x50) = 0xffffffff;
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x54) = 0xffffffff;
  List_AppendNode(*(void **)(arg1 + 4),*(int *)(arg1 + 8));
  SetRect((LPRECT)(*(int *)(arg1 + 8) + 0x5c),0xffff,0xffff,-1,-1);
  *(uint32_t *)(*(int *)(arg1 + 8) + 0x74) = 0;
  *(int *)(*(int *)(arg1 + 8) + 0x78) = arg1;
  ExceptionList = local_c;
  return;
}
