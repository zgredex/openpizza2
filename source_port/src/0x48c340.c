// City_CollectVacantLots: ported from Pizza Connection 2 at 0x48c340.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c340
#include "pc2_port.h"


uint32_t * __fastcall City_CollectVacantLots(int arg1)

{
  void *self;
  int value1;
  int value2;
  uint32_t *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005583eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  self = operator_new(0x1c);
  value2 = 0;
  local_4 = 0;
  if (self == (void *)0x0) {
    local_10 = (uint32_t *)0x0;
  }
  else {
    local_10 = List_Construct(self,0);
  }
  local_4 = 0xffffffff;
  if (*(int *)(arg1 + 0x50) < 1) {
    ExceptionList = local_c;
    return local_10;
  }
  do {
    value1 = IDMap_Lookup((void *)(arg1 + 0x3c),value2,(int *)0x0);
    if (((*(int *)(value1 + 0x30) < 8) && (*(int *)(value1 + 0xa4) == -1)) &&
       (*(int *)(value1 + 0x90) != 7)) {
      List_Add(local_10,value1);
    }
    value2 = value2 + 1;
  } while (value2 < *(int *)(arg1 + 0x50));
  ExceptionList = local_c;
  return local_10;
}
