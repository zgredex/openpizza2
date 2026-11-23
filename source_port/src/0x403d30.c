// CS_EnterObject: ported from Pizza Connection 2 at 0x403d30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x403d30
#include "pc2_port.h"

void __fastcall CS_EnterObject(int arg1)

{
  CS_Enter(arg1 + 0x10);
  return;
}
