// FUN_00555605: ported from Pizza Connection 2 at 0x555605.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x555605
#include "pc2_port.h"

uint32_t __thiscall FUN_00555605(void *self,uint32_t arg1,uint32_t arg2)

{
  uint32_t uvalue1;
  uint16_t in_FPUControlWord;
  uint32_t local_8;
  
  local_8 = CONCAT22((short)((uint32_t)self >> 0x10),in_FPUControlWord);
  uvalue1 = FUN_00555650(local_8);
  uvalue1 = uvalue1 & ~arg2 | arg1 & arg2;
  FUN_005556e2(uvalue1);
  return uvalue1;
}
