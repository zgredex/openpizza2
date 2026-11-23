// Stream_TryAttachBuffer: ported from Pizza Connection 2 at 0x54d0b1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54d0b1
#include "pc2_port.h"

void * __thiscall Stream_TryAttachBuffer(void *self,int arg1,int arg2)

{
  if ((*(int *)((intptr_t)self + 0x4c) == -1) || (*(int *)((intptr_t)self + 0x14) == 0)) {
    if ((arg1 == 0) || (arg2 < 1)) {
      *(uint32_t *)((intptr_t)self + 8) = 1;
    }
    else {
      if (*(int *)((intptr_t)self + 0x30) < 0) {
        CS_EnterRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x34));
      }
      Stream_AttachBuffer(self,arg1,arg1 + arg2,0);
      if (*(int *)((intptr_t)self + 0x30) < 0) {
        CS_LeaveRaw((LPCRITICAL_SECTION)((intptr_t)self + 0x34));
      }
    }
  }
  else {
    self = (void *)0x0;
  }
  return self;
}
