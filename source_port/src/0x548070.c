// Sound_SetState: ported from Pizza Connection 2 at 0x548070.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548070
#include "pc2_port.h"

/* WARNING: Removing unreachable block (ram,0x005480a6) */

void __thiscall Sound_SetState(void *self,int arg1)

{
  if ((*(char *)((intptr_t)self + 0xfc) != '\0') && (arg1 != 7)) {
    (**(code **)(**(int **)((intptr_t)self + 8) + 0xf4))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + 0x7c));
  }
  return;
}
