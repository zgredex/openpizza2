// Personnel_Load: ported from Pizza Connection 2 at 0x4b0d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b0d40
#include "pc2_port.h"

void __cdecl Personnel_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0056a6d8,4);
  return;
}
