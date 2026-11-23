// Game_CollectObjectsByType: ported from Pizza Connection 2 at 0x4d6af0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d6af0
#include "pc2_port.h"


uint32_t __thiscall Game_CollectObjectsByType(void *self,uint32_t arg1)

{
  void *this_00;
  int value1;
  int *ptr2;
  int value3;
  uint32_t *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055907b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0x1c);
  value3 = 0;
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    local_10 = (uint32_t *)0x0;
  }
  else {
    local_10 = List_Construct(this_00,0);
  }
  local_4 = 0xffffffff;
  value1 = Game_CountObjectsByType2(self,0xffffffff);
  if (0 < value1) {
    do {
      ptr2 = (int *)Game_LookupObjectByIndex(self,value3);
      if (*(uint8_t *)(*ptr2 + 0x824) == arg1) {
        List_Add(local_10,ptr2);
      }
      value3 = value3 + 1;
    } while (value3 < value1);
  }
  ExceptionList = local_c;
  return -(uint32_t)(local_10[5] != 0) & (uint32_t)local_10;
}
