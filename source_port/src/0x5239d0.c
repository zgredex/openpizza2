// UI_CreateFixedWindow: ported from Pizza Connection 2 at 0x5239d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5239d0
#include "pc2_port.h"


uint32_t __thiscall
UI_CreateFixedWindow
          (void *self,int arg1,int arg2,int arg3,int arg4,uint32_t arg5,
          uint32_t arg6,uint32_t arg7,uint32_t arg8,uint32_t arg9,
          uint32_t arg10)

{
  int value1;
  uint32_t *uptr2;
  uint32_t local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a6fb;
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
    uptr2 = Dialog_ConstructFixed
                       (local_10,self,*(void **)((intptr_t)self + 0xc),arg1,arg2,arg3,arg4,
                        arg5,(uint32_t *)((intptr_t)self + 0x250),arg7,arg8,arg9,arg10);
  }
  *(uint32_t **)((intptr_t)self + value1 * 4 + 0x14) = uptr2;
  uptr2[1] = local_14;
  local_4 = 0xffffffff;
  DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_CreateWindow__ID__d_Type_Fixed_P_00574114,
                      local_14);
  CS_Leave(*(int *)((intptr_t)self + 0x1c8));
  ExceptionList = local_c;
  return local_14;
}
