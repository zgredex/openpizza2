// Branch_StartConstructionOnPlot: ported from Pizza Connection 2 at 0x47e930.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47e930
#include "pc2_port.h"


void __thiscall Branch_StartConstructionOnPlot(void *self,int arg1)

{
  int value1;
  int value2;
  void *this_00;
  int value3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Starts construction on a free branch plot. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055807b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value1 = IDMap_Lookup((void *)((intptr_t)self + 0x1998),arg1,(int *)0x0);
  if (value1 != 0) {
    *(uint32_t *)(value1 + 0x1c) = 1;
    value2 = Grid_GetCell(*(void **)((intptr_t)self + 0x14e0),*(int *)(value1 + 0x14),
                         *(int *)(value1 + 0x18));
    Map_SetTileFieldWithDefault(*(void **)((intptr_t)self + 0x14e0),value2,0x65,1);
    Game_FindRecordByTripleKey(DAT_0057c670,7,4,3,&arg1);
    this_00 = operator_new(0x24);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      value3 = 0;
    }
    else {
      value3 = ConstructionOrder_Construct(this_00,arg1,0);
    }
    *(uint32_t *)(value3 + 0x18) = *(uint32_t *)(value1 + 0x14);
    *(uint32_t *)(value3 + 0x1c) = *(uint32_t *)(value1 + 0x18);
    local_4 = 0xffffffff;
    *(uint32_t *)(value3 + 0x20) = **(uint32_t **)(value2 + 8);
    List_Add((void *)((intptr_t)self + 0x16f8),value3);
    *(uint32_t *)(*(int *)((intptr_t)self + 0x14e0) + 0xf4) = 1;
    Branch_UpdateConstructionQueue(self);
    Game_UpdateObjectList2((intptr_t)self);
  }
  ExceptionList = local_c;
  return;
}
