// UI_CreateSlider: ported from Pizza Connection 2 at 0x52fc00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fc00
#include "pc2_port.h"


uint32_t __thiscall
UI_CreateSlider(void *self,int arg1,int arg2,int arg3,uint32_t arg4,char *arg5,
               int arg6,uint32_t arg7)

{
  uint32_t *uptr1;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Creates and registers a slider gadget. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ab2b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x4f8);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = UI_Bar_Construct(local_10,arg1,arg6,arg2,arg3,arg4,(intptr_t)self,arg5,
                              arg7,&local_14);
  }
  local_4 = 0xffffffff;
  if (local_14 == 0) {
    UI_EnsureObjectArray(self,(intptr_t)uptr1,arg1);
    ExceptionList = local_c;
    return 1;
  }
  if (uptr1 != (uint32_t *)0x0) {
    (**(code **)*uptr1)(1);
  }
  ExceptionList = local_c;
  return 0;
}
