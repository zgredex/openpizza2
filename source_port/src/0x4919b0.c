// BranchStats_SeriesFlags_Load: ported from Pizza Connection 2 at 0x4919b0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4919b0
#include "pc2_port.h"

void __cdecl BranchStats_SeriesFlags_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_00568628,0x10);
  return;
}
