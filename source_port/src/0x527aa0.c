// UI_ResetInputHelper: ported from Pizza Connection 2 at 0x527aa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527aa0
#include "pc2_port.h"

void __fastcall UI_ResetInputHelper(int arg1)

{
  Object_GetByte36Max7(*(int **)(arg1 + 0x8310));
  return;
}
