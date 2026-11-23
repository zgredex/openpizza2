// Window_HandleKeyInput: ported from Pizza Connection 2 at 0x5247f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5247f0
#include "pc2_port.h"

void __thiscall Window_HandleKeyInput(void *self,int arg1)

{
  int value1;
  int value2;
  uint32_t *uptr3;
  
  if ((*(int **)((intptr_t)self + 0x230) != (int *)0x0) &&
     (value1 = (**(code **)(**(int **)((intptr_t)self + 0x230) + 0xc))(0x20,arg1,0), value1 != 0)) {
    return;
  }
  value1 = *(int *)((intptr_t)self + 0x23c) + -1;
  if (-1 < value1) {
    uptr3 = (uint32_t *)((intptr_t)self + value1 * 4 + 0x14);
    do {
      if (((void *)*uptr3 != (void *)0x0) &&
         (value2 = UI_NotifyObjectsByKey((void *)*uptr3,arg1), value2 != 0)) {
        return;
      }
      value1 = value1 + -1;
      uptr3 = uptr3 + -1;
    } while (-1 < value1);
  }
  if (*(int *)((intptr_t)self + 0x8304) != 0) {
    UI_QueueCommand(self,*(int *)((intptr_t)self + 0x8304),0,(intptr_t)self,0xe,arg1);
  }
  return;
}
