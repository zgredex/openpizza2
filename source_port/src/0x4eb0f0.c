// IsoMap_Construct: ported from Pizza Connection 2 at 0x4eb0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb0f0
#include "pc2_port.h"

uint32_t * __thiscall IsoMap_Construct(void *self,int arg1)

{
  void *pvVar1;
  int *ptr2;
  uint8_t local_110 [260];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs an isometric ground map and its viewport. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559f20;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  List_Construct((void *)((intptr_t)self + 0x11c),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x140),0);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  *(uint8_t ***)self = &PTR_IsoMap_Delete_0055c5d4;
  if (arg1 == 0) {
    NoOp_Stub();
  }
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0x70) = 0;
  *(uint32_t *)((intptr_t)self + 0x74) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x1015c) = 1;
  *(int *)((intptr_t)self + 4) = arg1;
  String_Format(local_110,(uint8_t *)s__sIsokarten__s_00571a60,&DAT_0057c278);
  pvVar1 = operator_new(0x5c);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  if (pvVar1 == (void *)0x0) {
    ptr2 = (int *)0x0;
  }
  else {
    ptr2 = CRT_Ifstream_Construct();
  }
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  if ((*(uint8_t *)(*(int *)(*ptr2 + 4) + 8 + (intptr_t)ptr2) & 6) != 0) {
    NoOp_Stub();
  }
  IsoMap_DeserializeGrid(self,ptr2);
  if (ptr2 != (int *)0x0) {
    (*(code *)**(uint32_t **)(*(int *)(*ptr2 + 4) + (intptr_t)ptr2))(1);
  }
  UI_SetWindowOffsets((intptr_t)self);
  Map_UpdateObjectScreenBounds(self);
  Map_SetScrollPosition(self,*(int *)((intptr_t)self + 0x24),*(int *)((intptr_t)self + 0x28));
  *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)((intptr_t)self + 0xe8);
  *(uint32_t *)((intptr_t)self + 0x28) = *(uint32_t *)((intptr_t)self + 0xec);
  Map_CompactVisibleDrawRecords((intptr_t)self);
  if (*(int *)((intptr_t)self + 0xc) != 0x10) {
    IsoMap_RenderViewport(self,DAT_0057c5c8,(int *)0x0);
  }
  ExceptionList = pvStack_c;
  return self;
}
