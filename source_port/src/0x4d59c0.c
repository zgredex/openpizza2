// City_CollectBuildingsByType: ported from Pizza Connection 2 at 0x4d59c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d59c0
#include "pc2_port.h"


uint32_t * __thiscall City_CollectBuildingsByType(void *self,int arg1,int arg2,char arg3)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  uint32_t *local_14;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558fdb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  value3 = 0;
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_14 = (uint32_t *)0x0;
  }
  else {
    local_14 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)((intptr_t)self + 0xfc0) < 1) {
    ExceptionList = local_c;
    return local_14;
  }
  do {
    value1 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value3,(int *)0x0);
    if ((*(int *)(value1 + 4) == arg1) || (arg1 == -1)) {
      if (arg3 != '\0') {
        value2 = Game_CanShowObject(value1);
        if (value2 == 0) goto LAB_004d5a67;
      }
      if ((arg2 != value1) && (*(int *)(value1 + 0x48) != -1)) {
        List_Add(local_14,value1);
      }
    }
LAB_004d5a67:
    value3 = value3 + 1;
    if (*(int *)((intptr_t)self + 0xfc0) <= value3) {
      ExceptionList = local_c;
      return local_14;
    }
  } while( true );
}
