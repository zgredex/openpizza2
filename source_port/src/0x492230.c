// BranchDesign_ColorIndex_Load: ported from Pizza Connection 2 at 0x492230.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492230
#include "pc2_port.h"

void __cdecl BranchDesign_ColorIndex_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057c6bc,4);
  return;
}
