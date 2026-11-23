// UI_AddImage: ported from Pizza Connection 2 at 0x52f5b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52f5b0
#include "pc2_port.h"


uint32_t __thiscall
UI_AddImage(void *self,int arg1,int arg2,int arg3,char *arg4,int arg5,int arg6)

{
  int *ptr1;
  void *unaff_EBX;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055aaab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x174);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    ptr1 = (int *)0x0;
  }
  else {
    ptr1 = UI_Image_Construct(local_10,arg1,arg5,arg2,arg3,(intptr_t)self,arg4,&local_14
                               );
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    if (ptr1 != (int *)0x0) {
      (**(code **)*ptr1)(1);
    }
    ExceptionList = local_c;
    return 0;
  }
  UI_EnsureObjectArray(self,(intptr_t)ptr1,arg1);
  if (arg6 == 0) {
    (**(code **)(*ptr1 + 0xc))(0,0,0);
  }
  else {
    (**(code **)(*ptr1 + 0xc))(0,1,0);
  }
  ExceptionList = unaff_EBX;
  return 1;
}
