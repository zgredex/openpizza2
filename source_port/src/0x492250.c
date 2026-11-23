// BranchDesign_ColorIndex_Save: ported from Pizza Connection 2 at 0x492250.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x492250
#include "pc2_port.h"

void __cdecl BranchDesign_ColorIndex_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057c6bc,4);
  return;
}
