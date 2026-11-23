// UI_ClearPendingCommand: ported from Pizza Connection 2 at 0x520cf0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x520cf0
#include "pc2_port.h"

void __fastcall UI_ClearPendingCommand(int *arg1)

{
  if (arg1[7] != 0) {
    arg1[7] = 0;
    (**(code **)(*arg1 + 0xc))(0x35,0,0);
  }
  return;
}
