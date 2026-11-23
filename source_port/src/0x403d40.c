// Input_LeaveLock: ported from Pizza Connection 2 at 0x403d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403d40
#include "pc2_port.h"

void __fastcall Input_LeaveLock(int arg1)

{
  CS_Leave(arg1 + 0x10);
  return;
}
