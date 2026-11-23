// BranchMenu_Category_Load: ported from Pizza Connection 2 at 0x4900a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4900a0
#include "pc2_port.h"

void __cdecl BranchMenu_Category_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057c6a8,4);
  return;
}
