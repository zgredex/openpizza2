// CRT_TestLockFlag: ported from Pizza Connection 2 at 0x55542c.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55542c
#include "pc2_port.h"

uint8_t __cdecl CRT_TestLockFlag(uint32_t arg1)

{
  if (arg1 < DAT_00586d20) {
    return *(uint8_t *)((&DAT_00586c20)[(intptr_t)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) & 0x40;
  }
  return 0;
}
