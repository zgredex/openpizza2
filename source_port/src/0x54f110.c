// __chkstk: ported from Pizza Connection 2 at 0x54f110.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f110
#include "pc2_port.h"

/* WARNING: Unable to track spacebase fully for stack */

void __cdecl __chkstk(uint8_t arg1)

{
  uint32_t in_EAX;
  uint8_t *uptr1;
  uint32_t unaff_retaddr;
  
  uptr1 = &arg1;
  for (; 0xfff < in_EAX; in_EAX = in_EAX - 0x1000) {
    uptr1 = uptr1 + -0x1000;
  }
  *(uint32_t *)(uptr1 + (-4 - in_EAX)) = unaff_retaddr;
  return;
}
