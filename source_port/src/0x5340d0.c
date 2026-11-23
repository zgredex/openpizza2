// Record_GetScreenRect48: ported from Pizza Connection 2 at 0x5340d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5340d0
#include "pc2_port.h"

void __thiscall Record_GetScreenRect48(void *self,int arg1,int *arg2,int *arg3)

{
  uint16_t uvalue1;
  int64_t lvalue2;
  
  uvalue1 = *(uint16_t *)
           (*(int *)((intptr_t)self + 0x28) +
           *(short *)(*(int *)((intptr_t)self + 0x4c) + arg1 * 0x48 + 0x32) * 2);
  lvalue2 = __ftol();
  *arg2 = (uint32_t)uvalue1 + (intptr_t)lvalue2;
  uvalue1 = *(uint16_t *)
           (*(int *)((intptr_t)self + 0x2c) +
           *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x32 + arg1 * 0x48) * 2);
  lvalue2 = __ftol();
  *arg3 = (uint32_t)uvalue1 + (intptr_t)lvalue2;
  return;
}
