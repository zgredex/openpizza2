// MovieWindow_CreateForScreen: ported from Pizza Connection 2 at 0x5319c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5319c0
#include "pc2_port.h"


uint32_t __thiscall
MovieWindow_CreateForScreen(void *self,int arg1,int arg2,int arg3,uint32_t *arg4)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055abab;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = operator_new(0xbc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = MovieWindow_Construct
                       (this_00,arg1,arg2,arg3,1,arg4,&DAT_00579aec,0,(intptr_t)self);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(self,(intptr_t)uptr1,arg1);
  ExceptionList = local_c;
  return 1;
}
