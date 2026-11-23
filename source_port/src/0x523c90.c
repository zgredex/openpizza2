// Window_CreatePictureWindow: ported from Pizza Connection 2 at 0x523c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x523c90
#include "pc2_port.h"


uint32_t __thiscall Window_CreatePictureWindow(void *self,char *arg1,uint32_t arg2)

{
  int value1;
  uint32_t *uptr2;
  uint32_t local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a75b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CS_Enter(*(int *)((intptr_t)self + 0x1c8));
  value1 = UI_AllocWindowSlot(self,&local_14);
  local_10 = operator_new(0x2c8);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = Dialog_ConstructWithPicture
                       (local_10,self,*(void **)((intptr_t)self + 0xc),arg1,
                        *(void **)((intptr_t)self + 0x10),arg2);
  }
  *(uint32_t **)((intptr_t)self + value1 * 4 + 0x14) = uptr2;
  uptr2[1] = local_14;
  local_4 = 0xffffffff;
  DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_CreateWindow__ID__d_Type_Picture_005741bc,
                      local_14);
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  ExceptionList = local_c;
  return local_14;
}
