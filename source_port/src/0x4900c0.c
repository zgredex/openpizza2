// BranchMenu_Category_Save: ported from Pizza Connection 2 at 0x4900c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4900c0
#include "pc2_port.h"

void __cdecl BranchMenu_Category_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057c6a8,4);
  return;
}
