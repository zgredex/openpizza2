// StatisticsBranchBalance_Load: ported from Pizza Connection 2 at 0x4ac3c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4ac3c0
#include "pc2_port.h"

void __cdecl StatisticsBranchBalance_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0056951c,4);
  CRT_Istream_Read(arg1,&DAT_0057d62c,4);
  CRT_Istream_Read(arg1,&DAT_0057d630,4);
  return;
}
