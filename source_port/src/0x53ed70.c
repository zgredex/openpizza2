// SoundDevice_Construct: ported from Pizza Connection 2 at 0x53ed70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53ed70
#include "pc2_port.h"

uint32_t * __thiscall
SoundDevice_Construct(char *self,uint32_t arg1,HWND arg2,int arg3,int *arg4)

{
  LPVOID *ppv;
  void *pvVar1;
  HRESULT HVar2;
  int value3;
  uint32_t unaff_EDI;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_0055ade8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t *)((intptr_t)self + 4) = 1;
  ppv = (LPVOID *)((intptr_t)self + 8);
  local_4 = 0;
  *ppv = (LPVOID)0x0;
  *(uint8_t *)((intptr_t)self + 0xc) = 0;
  *(uint8_t ***)self = &PTR_LAB_0055c830;
  if (arg4 != (int *)0x0) {
    if (*arg4 < 0) {
      ExceptionList = pvVar1;
      return self;
    }
    *arg4 = 0;
  }
  HVar2 = CoInitialize((LPVOID)0x0);
  if (HVar2 < 0) {
    *(uint8_t *)((intptr_t)self + 0xc) = 0;
    if (HVar2 != -0x7ffefefa) {
      NoOp_Stub();
      if (arg4 == (int *)0x0) {
        ExceptionList = local_c;
        return self;
      }
      *arg4 = HVar2;
      ExceptionList = local_c;
      return self;
    }
  }
  else {
    *(uint8_t *)((intptr_t)self + 0xc) = 1;
  }
  HVar2 = CoCreateInstance((IID *)&DAT_0055cba8,(LPUNKNOWN)0x0,1,(IID *)&DAT_0055cb98,ppv);
  if (HVar2 < 0) {
    NoOp_Stub();
    *ppv = (LPVOID)0x0;
    if (arg4 == (int *)0x0) {
      ExceptionList = local_c;
      return self;
    }
    *arg4 = HVar2;
    ExceptionList = local_c;
    return self;
  }
  value3 = (**(code **)(*(int *)*ppv + 0x28))(*ppv,arg1);
  if (value3 < 0) {
    Sound_SetLastError(&DAT_00585578,s_initializing_DirectSound__00574b30,value3,unaff_EDI);
  }
  else {
    if ((arg2 == (HWND)0x0) && (arg2 = GetForegroundWindow(), arg2 == (HWND)0x0)) {
      arg2 = GetDesktopWindow();
    }
    value3 = (**(code **)(*(int *)*ppv + 0x18))(*ppv,arg2,arg3);
    if (-1 < value3) {
      if (arg3 == 3) {
        (**(code **)(*(int *)*ppv + 0x1c))(*ppv);
        ExceptionList = local_c;
        return self;
      }
      ExceptionList = local_c;
      return self;
    }
    Sound_SetLastError(&DAT_00585578,s_setting_cooperative_level__00574b4c,value3,unaff_EDI);
  }
  (**(code **)(*(int *)*ppv + 8))(*ppv);
  *ppv = (LPVOID)0x0;
  if (value3 < -0x7ffbfeef) {
    if (value3 == -0x7ffbfef0) {
      value3 = -0x7ffbfef0;
      goto LAB_0053ef42;
    }
    if (value3 == -0x7fffbfff) {
      value3 = -0x7fffbfff;
      goto LAB_0053ef42;
    }
    if (value3 == -0x7fffbffe) {
      value3 = -0x7fffbffe;
      goto LAB_0053ef42;
    }
    if (value3 == -0x7fffbffb) {
      value3 = -0x7fffbffb;
      goto LAB_0053ef42;
    }
  }
  else {
    if (value3 == -0x7ff8fff2) {
      value3 = -0x7ff8fff2;
      goto LAB_0053ef42;
    }
    if (value3 == -0x7ff8ffa9) {
      value3 = -0x7ff8ffa9;
      goto LAB_0053ef42;
    }
  }
  value3 = -0x7fff0001;
LAB_0053ef42:
  if (arg4 != (int *)0x0) {
    *arg4 = value3;
  }
  ExceptionList = local_c;
  return self;
}
