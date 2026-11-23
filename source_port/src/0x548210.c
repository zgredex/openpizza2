// Sound_HandleEvent: ported from Pizza Connection 2 at 0x548210.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548210
#include "pc2_port.h"

/* WARNING: Removing unreachable block (ram,0x00548299) */

void __thiscall Sound_HandleEvent(void *self,int arg1,int arg2)

{
  if (((*(char *)((intptr_t)self + 0xfc) != '\0') && (*(int *)(DAT_0057c670 + 0x290) == 4)) &&
     (*(int *)(DAT_0057c670 + 0x9c) == arg1)) {
    if (((arg2 == 0x25) || (arg2 == 0x26)) || (arg2 == 0x27)) {
      if (arg2 != 0x32) {
        if (*(int *)((intptr_t)self + 0x15c) == 0) {
          *(uint32_t *)((intptr_t)self + 0x15c) = 0x32;
          Sound_SetPosition(self,*(uint32_t *)((intptr_t)self + arg2 * 4 + 0x24));
          return;
        }
        return;
      }
    }
    else if (arg2 != 0x32) {
      Sound_SetParam(self,*(uint32_t *)((intptr_t)self + arg2 * 4 + 0x24));
      return;
    }
    (**(code **)(**(int **)((intptr_t)self + 8) + 0xf4))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0xec));
  }
  return;
}
