// UI_EnsureBackBufferWindow: ported from Pizza Connection 2 at 0x51fa80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x51fa80
#include "pc2_port.h"


void __thiscall UI_EnsureBackBufferWindow(void *self,void *arg1)

{
  void *this_00;
  uint32_t *uptr1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a57b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (*(int *)((intptr_t)self + 0x34) == 0) {
    ExceptionList = &local_c;
    this_00 = operator_new(0x11c);
    local_4 = 0;
    if (this_00 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = Window_Construct(this_00,*(int *)((intptr_t)self + 0x20),*(int *)((intptr_t)self + 0x24),0x10);
    }
    *(uint32_t **)((intptr_t)self + 0x34) = uptr1;
  }
  local_4 = 0xffffffff;
  Surface_ConfigureFromOwner(*(void **)((intptr_t)self + 0x34),arg1);
  ExceptionList = local_c;
  return;
}
