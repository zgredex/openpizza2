// Window_GadgetNotify: ported from Pizza Connection 2 at 0x52fdd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52fdd0
#include "pc2_port.h"

uint32_t __thiscall
Window_GadgetNotify(void *self,int arg1,int arg2,uint32_t arg3,uint32_t arg4,
                   uint32_t arg5)

{
  DWORD DVar1;
  DWORD DVar2;
  int *ptr3;
  int value4;
  uint32_t uvalue5;
  uint32_t *uptr6;
  int value7;
  bool flag8;
  
  DVar1 = *(DWORD *)(*(int *)((intptr_t)self + 0x134) + 0x830c);
  DVar2 = GetCurrentThreadId();
  flag8 = DVar2 != DVar1;
  if (flag8) {
    CS_Enter(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  }
  ptr3 = (int *)Array_GetRecordByKey(self,arg1);
  if (ptr3 == (int *)0x0) {
    if (flag8) {
      CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
    }
    DebugConsole_Errorf(*(uint32_t *)((intptr_t)self + 0x134),0,
                        (uint8_t *)s_Window__GadgetNotify__Gadget___d_0057447c,arg1);
    return 0;
  }
  if ((arg2 == 0) || (arg2 == ptr3[0x10])) {
    uvalue5 = (**(code **)(*ptr3 + 0xc))(arg3,arg4,arg5);
    if (flag8) {
      CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
    }
    return uvalue5;
  }
  value7 = 0;
  if (flag8) {
    CS_Leave(*(int *)(*(int *)((intptr_t)self + 0x134) + 0x1c8));
  }
  if (DAT_005743a0 != arg2) {
    uptr6 = &DAT_005743a0;
    value4 = DAT_005743a0;
    do {
      if (value4 == 0) break;
      value4 = uptr6[2];
      uptr6 = uptr6 + 2;
      value7 = value7 + 1;
    } while (value4 != arg2);
  }
  DebugConsole_Errorf(*(uint32_t *)((intptr_t)self + 0x134),2,
                      (uint8_t *)s_Window__GadgetNotify__Gadget_is_n_00574450,
                      (&PTR_s_button_005743a4)[value7 * 2]);
  return 0;
}
