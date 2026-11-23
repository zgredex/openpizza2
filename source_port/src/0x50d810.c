// UI_UpdateValueBar: ported from Pizza Connection 2 at 0x50d810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50d810
#include "pc2_port.h"

void __thiscall UI_UpdateValueBar(void *self,void *arg1,int arg2)

{
  void *pvVar1;
  uint8_t *uptr2;
  int value3;
  int64_t lvalue4;
  
  if (*(int *)((intptr_t)self + 0x30) == 0xd) {
    uptr2 = (uint8_t *)Object_GetLevelProperty(self,2);
  }
  else {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110));
    if (pvVar1 == (void *)0x0) {
      return;
    }
    uptr2 = Economy_GetModifier(pvVar1,*(int *)((intptr_t)self + 0x30),2);
  }
  if (*(int *)((intptr_t)arg1 + 0x30) == 0xd) {
    Object_GetLevelProperty(arg1,1);
  }
  else {
    pvVar1 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)arg1 + 0x110));
    if (pvVar1 == (void *)0x0) {
      return;
    }
    Economy_GetModifier(pvVar1,*(int *)((intptr_t)arg1 + 0x30),1);
  }
  if (uptr2 == (uint8_t *)0x0) {
    value3 = 100;
  }
  else {
    lvalue4 = __ftol();
    value3 = (intptr_t)lvalue4;
  }
  if (*(int *)((intptr_t)self + 0xa8) <= value3) {
    *(uint32_t *)((intptr_t)self + 0xa8) = 0;
    return;
  }
  value3 = *(int *)((intptr_t)self + 0xa8) - value3;
  *(int *)((intptr_t)self + 0xa8) = value3;
  if (value3 < 0) {
    *(uint32_t *)((intptr_t)self + 0xa8) = 0;
  }
  if (arg2 == 0) {
    UI_SetChildHeightFromValue((intptr_t)self);
  }
  return;
}
