// Object_SetChildShort: ported from Pizza Connection 2 at 0x509220.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509220
#include "pc2_port.h"

void __fastcall Object_SetChildShort(int arg1)

{
  if (*(int *)(arg1 + 200) != 0) {
    *(uint16_t *)(*(int *)(arg1 + 200) + 8) = 0xffff;
  }
  return;
}
