// Window_DestroyChild: ported from Pizza Connection 2 at 0x526700.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526700
#include "pc2_port.h"

void __thiscall Window_DestroyChild(void *self,uint32_t *arg1)

{
  uint32_t *uptr1;
  int value2;
  int value3;
  int *ptr4;
  
  uptr1 = arg1;
  value2 = 0;
  value3 = *(int *)((intptr_t)self + 0x23c);
  if (0 < value3) {
    ptr4 = (int *)((intptr_t)self + 0x14);
    do {
      if ((uint32_t *)*ptr4 == arg1) break;
      value2 = value2 + 1;
      ptr4 = ptr4 + 1;
    } while (value2 < value3);
  }
  if (value2 != value3) {
    if (arg1[0x13] != 0) {
      UI_SetWindowVisible(arg1,0);
      UI_ProcessCommandQueue((intptr_t)self);
    }
    CS_Enter(*(int *)((intptr_t)self + 0x1c8));
    UI_ForgetChildById(self,(intptr_t)uptr1);
    value3 = Object_GetId((intptr_t)uptr1);
    if (value3 == -1) {
      CS_Leave(*(int *)((intptr_t)self + 0x1c8));
      return;
    }
    UI_FindWindowByID(self,value3,(int *)&arg1);
    *(uint32_t *)((intptr_t)self + (intptr_t)arg1 * 4 + 0x14) = 0;
    value2 = (*(int *)((intptr_t)self + 0x23c) - (intptr_t)arg1) + -1;
    if (0 < value2) {
      _memmove((uint32_t *)((intptr_t)self + (intptr_t)arg1 * 4 + 0x14),
               (uint32_t *)((intptr_t)self + (intptr_t)arg1 * 4 + 0x18),value2 * 4);
    }
    *(uint32_t *)((intptr_t)self + *(int *)((intptr_t)self + 0x23c) * 4 + 0x10) = 0;
    *(int *)((intptr_t)self + 0x23c) = *(int *)((intptr_t)self + 0x23c) + -1;
    EventQueue_SetEntryState22(self,(intptr_t)uptr1);
    if (uptr1 != (uint32_t *)0x0) {
      (**(code **)*uptr1)(1);
    }
    CS_Leave(*(int *)((intptr_t)self + 0x1c8));
    RecordArray_CompactEmpty48((intptr_t)self);
    *(uint32_t *)((intptr_t)self + 0x83b8) = 1;
    *(uint32_t *)((intptr_t)self + 0x234) = 1;
    *(uint32_t *)((intptr_t)self + 0x238) = 1;
    DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_window__d__d__deleted_0057428c,value3);
  }
  return;
}
