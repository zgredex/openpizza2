// UI_AddSprite: ported from Pizza Connection 2 at 0x531850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x531850
#include "pc2_port.h"


uint32_t __thiscall UI_AddSprite(void *self,int arg1,int arg2,int arg3,char *arg4)

{
  int value1;
  void *this_00;
  uint32_t *uptr2;
  uint32_t local_50 [17];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055ab8b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  value1 = Window_LoadSpriteCached(*(void **)((intptr_t)self + 0x134),arg4,(uint32_t *)0x0,local_50);
  if (value1 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  this_00 = operator_new(0xbc);
  local_4 = 0;
  if (this_00 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = MovieWindow_Construct
                       (this_00,arg1,arg2,arg3,0,local_50,(char *)0x0,1,(intptr_t)self);
  }
  local_4 = 0xffffffff;
  UI_EnsureObjectArray(self,(intptr_t)uptr2,arg1);
  ExceptionList = local_c;
  return 1;
}
