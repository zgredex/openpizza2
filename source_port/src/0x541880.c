// Parser_ResetTokenState: ported from Pizza Connection 2 at 0x541880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x541880
#include "pc2_port.h"

void __fastcall Parser_ResetTokenState(uint32_t *arg1)

{
  StreamBuffer_Reset(arg1 + 2);
  if (arg1[2] == 0) {
    *arg1 = 1;
  }
  if (arg1[1] == 0) {
    *arg1 = *arg1 | 2;
    return;
  }
  arg1[1] = arg1[5];
  return;
}
