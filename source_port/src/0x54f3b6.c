// CRT_RunAtexitRange: ported from Pizza Connection 2 at 0x54f3b6.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f3b6
#include "pc2_port.h"

void __cdecl CRT_RunAtexitRange(uint32_t *arg1,uint32_t *arg2)

{
  for (; arg1 < arg2; arg1 = arg1 + 1) {
    if ((code *)*arg1 != (code *)0x0) {
      (*(code *)*arg1)();
    }
  }
  return;
}
