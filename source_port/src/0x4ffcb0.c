// CityMap_TryPlaceBuilding: ported from Pizza Connection 2 at 0x4ffcb0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ffcb0
#include "pc2_port.h"

uint32_t CityMap_TryPlaceBuilding(void)

{
  void *pvVar1;
  void *self;
  uint32_t uvalue2;
  uint8_t local_res0;
  uint32_t uStack00000004;
  uint32_t uStack00000008;
  uint32_t *puStack0000000c;
  uint32_t uStack00000010;
  uint32_t uStack00000014;
  uint32_t uStack00000018;
  uint32_t uStack0000001c;
  uint32_t uStack00000020;
  uint32_t uStack00000024;
  void *in_stack_00001928;
  void *in_stack_00001938;
  int in_stack_0000193c;
  uint8_t uvalue3;
  int local_8 [2];
  
                    /* Places building blocks, charges the cost, and commits the map edit. */
  pvVar1 = ExceptionList;
  local_8[1] = 0xffffffff;
  uvalue3 = SUB41(ExceptionList,0);
  ExceptionList = local_8 + -1;
  __chkstk(uvalue3);
  uStack00000004 = *(uint32_t *)((intptr_t)in_stack_00001938 + 0x38);
  uStack00000014 = 2;
  uStack00000018 = 2;
  uStack00000020 = *(uint32_t *)((intptr_t)in_stack_00001938 + 0x1a00);
  uStack00000010 = *(uint32_t *)((intptr_t)in_stack_00001938 + 0x14e0);
  uStack00000008 = 1;
  puStack0000000c = (uint32_t *)0x0;
  uStack0000001c = 0;
  uStack00000024 = uStack00000020;
  self = operator_new(0x1c);
  if (self == (void *)0x0) {
    puStack0000000c = (uint32_t *)0x0;
  }
  else {
    puStack0000000c = List_Construct(self,0);
  }
  Map_BuildTerrainGrid((intptr_t)&local_res0);
  CityMap_PlaceBuildingBlocks((int *)&local_res0,5,'-',in_stack_0000193c);
  Stats_SumRecordCounts(puStack0000000c,local_8 + 1,local_8 + -1);
  if (pvVar1 == (void *)0x0) {
    IDMap_FreeValuesAndDestroy(puStack0000000c);
    uvalue2 = 0;
  }
  else {
    uvalue2 = Game_CanAfford(in_stack_00001938,4,(float)(intptr_t)pvVar1,'\x01',-1);
    uvalue2 = uvalue2 & 0xff;
    uStack0000001c = 1;
    if (uvalue2 != 0) {
      Map_CommitPendingObjectEdits((int *)&local_res0,'\x01');
    }
  }
  ExceptionList = in_stack_00001928;
  return uvalue2;
}
