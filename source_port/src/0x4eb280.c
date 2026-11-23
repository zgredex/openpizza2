// IsoMap_ConstructFromStream: ported from Pizza Connection 2 at 0x4eb280.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4eb280
#include "pc2_port.h"


uint32_t * __thiscall IsoMap_ConstructFromStream(void *self,uint32_t arg1,void *arg2)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs an isometric map from a save stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00559f4c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0x11c),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0x140),0);
  *(uint32_t *)((intptr_t)self + 4) = arg1;
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_IsoMap_Delete_0055c5d4;
  *(uint32_t *)((intptr_t)self + 8) = 0;
  *(uint32_t *)((intptr_t)self + 0x70) = 0;
  *(uint32_t *)((intptr_t)self + 0x74) = 0;
  *(uint32_t *)((intptr_t)self + 0x78) = 0;
  *(uint32_t *)((intptr_t)self + 0x1015c) = 1;
  IsoMap_DeserializeGrid(self,arg2);
  UI_SetWindowOffsets((intptr_t)self);
  Map_UpdateObjectScreenBounds(self);
  Map_SetScrollPosition(self,*(int *)((intptr_t)self + 0x24),*(int *)((intptr_t)self + 0x28));
  *(uint32_t *)((intptr_t)self + 0x24) = *(uint32_t *)((intptr_t)self + 0xe8);
  *(uint32_t *)((intptr_t)self + 0x28) = *(uint32_t *)((intptr_t)self + 0xec);
  Map_CompactVisibleDrawRecords((intptr_t)self);
  if (*(int *)((intptr_t)self + 0xc) != 0x10) {
    IsoMap_RenderViewport(self,DAT_0057c5c8,(int *)0x0);
  }
  ExceptionList = local_c;
  return self;
}
