// Sound_SetTimeout: ported from Pizza Connection 2 at 0x548d70.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x548d70
#include "pc2_port.h"

void __fastcall Sound_SetTimeout(int arg1)

{
  if (*(char *)(arg1 + 0xfc) != '\0') {
    *(uint32_t *)(arg1 + 0x150) = 500;
  }
  return;
}
