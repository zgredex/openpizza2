// Map_CollectObjectsOnFlaggedTiles: ported from Pizza Connection 2 at 0x4d5ab0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5ab0
#include "pc2_port.h"


uint32_t * __fastcall Map_CollectObjectsOnFlaggedTiles(int arg1)

{
  bool flag1;
  int value2;
  void *pvVar3;
  uint32_t extraout_var;
  int value4;
  uint32_t *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558ffb;
  local_c = ExceptionList;
  value4 = 0;
  ExceptionList = &local_c;
  value2 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  value2 = *(int *)(value2 + 0xfa8);
  pvVar3 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    local_14 = (uint32_t *)0x0;
  }
  else {
    local_14 = List_Construct(pvVar3,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(arg1 + 0xfc0) < 1) {
    ExceptionList = local_c;
    return local_14;
  }
  do {
    pvVar3 = (void *)IDMap_Lookup((void *)(arg1 + 0xfac),value4,(int *)0x0);
    flag1 = TileDef_TestFlag(pvVar3,value2,1);
    if (CONCAT31(extraout_var,flag1) != 0) {
      List_Add(local_14,pvVar3);
    }
    value4 = value4 + 1;
  } while (value4 < *(int *)(arg1 + 0xfc0));
  ExceptionList = local_c;
  return local_14;
}
