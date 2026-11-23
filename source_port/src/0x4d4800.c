// City_Construct: ported from Pizza Connection 2 at 0x4d4800.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4800
#include "pc2_port.h"


uint32_t * __thiscall City_Construct(void *self,int *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558e2c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  List_Construct((void *)((intptr_t)self + 0xfac),0);
  local_4 = 0;
  List_Construct((void *)((intptr_t)self + 0xfc8),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_City_Delete_0055c500;
  MapObjectList_Load(self,arg1);
  Map_LoadMapSprite((intptr_t)self);
  ExceptionList = local_c;
  return self;
}
