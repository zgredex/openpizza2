// Personnel_Save: ported from Pizza Connection 2 at 0x4b0d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0d60
#include "pc2_port.h"

void __cdecl Personnel_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0056a6d8,4);
  return;
}
