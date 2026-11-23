// Dialog_Construct: ported from Pizza Connection 2 at 0x52e8f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52e8f0
#include "pc2_port.h"


uint32_t * __thiscall
Dialog_Construct(void *self,uint32_t arg1,void *arg2,int arg3,int arg4,uint32_t arg5,
                int arg6,uint32_t arg7)

{
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a97c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Array_Construct((void *)((intptr_t)self + 0x148),0);
  local_4 = 0;
  Array_Construct((void *)((intptr_t)self + 0x2a8),0);
  local_4 = CONCAT31(((uint8_t)((local_4) >> 24)),1);
  *(uint8_t ***)self = &PTR_Dialog_Delete_0055c808;
  SetRect((LPRECT)((intptr_t)self + 0x28),arg3,arg4,arg5,arg6);
  Dialog_InitBase(self,arg2,arg1,arg7);
  *(uint32_t *)((intptr_t)self + 0xfc) = 0;
  UI_SetWindowBounds(self,arg3,arg4,arg5,arg6);
  ExceptionList = local_c;
  return self;
}
