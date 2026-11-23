// MovieWindow_AdvanceFrame: ported from Pizza Connection 2 at 0x52bbc0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52bbc0
#include "pc2_port.h"

void __thiscall MovieWindow_AdvanceFrame(void *self,int arg1)

{
  uint32_t *uptr1;
  uint32_t uvalue2;
  int unaff_retaddr;
  
  if ((*(uint32_t **)((intptr_t)self + 0xb8))[5] == 0) {
    _BinkDoFrame_4(**(uint32_t **)((intptr_t)self + 0xb8));
    uvalue2 = (*(char *)(unaff_retaddr + 0x18) != '\0') + 9;
    if ((*(uint32_t **)((intptr_t)self + 0xb8))[6] != 0) {
      uvalue2 = uvalue2 | 0x40000000;
    }
    _BinkCopyToBuffer_28
              (**(uint32_t **)((intptr_t)self + 0xb8),
               *(uint32_t *)(*(int *)((intptr_t)self + 0x54) + 0x18),
               *(int *)(*(int *)((intptr_t)self + 0x54) + 4) << 1,*(uint32_t *)(arg1 + 4),0,0,
               uvalue2 | 0x80000);
    uptr1 = *(uint32_t **)((intptr_t)self + 0xb8);
    if (*(int *)(arg1 + 0xc) == *(int *)(arg1 + 8)) {
      if (uptr1[4] == 0) {
        uptr1[3] = 1;
        UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),0x13,0);
        return;
      }
      _BinkGoto_12(*uptr1,1,0);
      return;
    }
    _BinkNextFrame_4(*uptr1);
  }
  return;
}
