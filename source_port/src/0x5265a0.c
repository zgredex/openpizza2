// UI_ClearDestroyedObjectReferences: ported from Pizza Connection 2 at 0x5265a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5265a0
#include "pc2_port.h"

void __thiscall UI_ClearDestroyedObjectReferences(void *self,int arg1)

{
  int value1;
  
  if (arg1 == *(int *)((intptr_t)self + 0x82d4)) {
    *(uint32_t *)((intptr_t)self + 0x82c8) = 0;
    *(uint32_t *)((intptr_t)self + 0x82d4) = 0;
  }
  if (arg1 == *(int *)((intptr_t)self + 0x22c)) {
    *(uint32_t *)((intptr_t)self + 0x224) = 0;
    *(uint32_t *)((intptr_t)self + 0x22c) = 0;
  }
  if (arg1 == *(int *)((intptr_t)self + 0x82dc)) {
    if (*(int *)((intptr_t)self + 0x82d0) != 0) {
      value1 = Get_Field24(*(int *)((intptr_t)self + 0x82dc));
      if (value1 != 0) {
        UI_QueueControlCommand
                  (*(void **)((intptr_t)self + 0x82d0),*(int *)(*(int *)((intptr_t)self + 0x82dc) + 4),0xd,0);
      }
    }
    UI_RefreshChildRect(self);
    *(uint32_t *)((intptr_t)self + 0x82dc) = 0;
    *(uint32_t *)((intptr_t)self + 0x82d0) = 0;
  }
  if (arg1 == *(int *)((intptr_t)self + 0x833c)) {
    *(uint32_t *)((intptr_t)self + 0x833c) = 0;
    *(uint32_t *)((intptr_t)self + 0x8348) = 0;
  }
  return;
}
