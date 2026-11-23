// BranchStats_SeriesFlags_Save: ported from Pizza Connection 2 at 0x4919d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4919d0
#include "pc2_port.h"

void __cdecl BranchStats_SeriesFlags_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_00568628,0x10);
  return;
}
