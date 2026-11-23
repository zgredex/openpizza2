// City_CollectBusinessBuildings: ported from Pizza Connection 2 at 0x4d5c40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d5c40
#include "pc2_port.h"


uint32_t * __fastcall City_CollectBusinessBuildings(int arg1)

{
  void *self;
  uint32_t *this_00;
  int value1;
  int value2;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055903b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  self = operator_new(0x1c);
  value2 = 0;
  local_4 = 0;
  if (self == (void *)0x0) {
    this_00 = (uint32_t *)0x0;
  }
  else {
    this_00 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(arg1 + 0xfc0) < 1) {
    ExceptionList = local_c;
    return this_00;
  }
  do {
    value1 = IDMap_Lookup((void *)(arg1 + 0xfac),value2,(int *)0x0);
    if ((0x1c < *(int *)(value1 + 4)) && (*(int *)(value1 + 4) < 0x20)) {
      List_Add(this_00,value1);
    }
    value2 = value2 + 1;
  } while (value2 < *(int *)(arg1 + 0xfc0));
  ExceptionList = local_c;
  return this_00;
}
