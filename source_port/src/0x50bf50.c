// Person_FindFreeNeighborCell: ported from Pizza Connection 2 at 0x50bf50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50bf50
#include "pc2_port.h"


int __thiscall
Person_FindFreeNeighborCell(void *self,uint32_t arg1,int arg2,uint32_t *arg3)

{
  int value1;
  int value2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  int value5;
  int local_74;
  uint32_t local_70 [5];
  int local_5c;
  uint32_t local_54 [18];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a318;
  local_c = ExceptionList;
  value5 = 0;
  ExceptionList = &local_c;
  List_Construct(local_70,0);
  local_4 = 0;
  local_54[0] = 2;
  local_54[1] = 3;
  local_54[2] = 0;
  local_54[3] = 1;
  local_54[4] = 6;
  local_54[5] = 7;
  local_54[6] = 4;
  local_54[7] = 5;
  value1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),arg2,(int *)0x0);
  if (*(int *)(value1 + 200) != 0) {
    value1 = MapObject_ComputeBlitRect(value1);
    List_Node_Reset((intptr_t)local_70);
    uptr4 = local_54;
    do {
      value2 = Grid_GetNeighborCell(*(void **)((intptr_t)self + 0xc4),value1,value5);
      value2 = Grid_GetNeighborCell(*(void **)((intptr_t)self + 0xc4),value2,value5);
      if ((*(int *)(*(int *)(value2 + 8) + 0x28) != 0) &&
         (*(short *)(*(int *)(value2 + 8) + 0x24) != -1)) {
        local_74 = List_Add(local_70,value2);
        IDMap_Update(local_70,&local_74);
        local_54[local_74 + 8] = *uptr4;
      }
      value5 = value5 + 1;
      uptr4 = uptr4 + 1;
    } while (value5 < 8);
    if (0 < local_5c) {
      uvalue3 = Random_RangeFast(0,local_5c - 1);
      value1 = IDMap_Lookup(local_70,uvalue3,(int *)0x0);
      value1 = Array_GetRecord28(*(void **)((intptr_t)self + 0xc4),1,
                                (intptr_t)*(short *)(*(int *)(value1 + 8) + 0x24));
      local_4 = 0xffffffff;
      *arg3 = local_54[uvalue3 + 8];
      List_Node_Destroy(local_70);
      ExceptionList = local_c;
      return value1;
    }
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(local_70);
  ExceptionList = local_c;
  return 0;
}
