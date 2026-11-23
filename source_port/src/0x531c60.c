// UI_CreateBitmapGadget: ported from Pizza Connection 2 at 0x531c60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531c60
#include "pc2_port.h"


uint32_t * __thiscall
UI_CreateBitmapGadget
          (void *self,int arg1,int arg2,int arg3,uint32_t arg4,int arg5,uint32_t arg6)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and registers an offscreen bitmap gadget. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ac0b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0xa0);
  uptr1 = (uint32_t *)0x0;
  local_4 = 0;
  if (this_00 != (void *)0x0) {
    uptr1 = UI_ImageChild_Construct(this_00,arg1,arg2,arg3,arg4,arg5,arg6,self);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(self,(intptr_t)uptr1,arg1);
  ExceptionList = local_c;
  return uptr1;
}
