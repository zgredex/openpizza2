// FUN_0055563a: ported from Pizza Connection 2 at 0x55563a.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55563a
#include "pc2_port.h"

void __thiscall FUN_0055563a(void *self,uint32_t arg1,uint32_t arg2)

{
  FUN_00555605(self,arg1,arg2 & 0xfff7ffff);
  return;
}
