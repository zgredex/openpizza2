// CompanyMarketShare_Load: ported from Pizza Connection 2 at 0x49b460.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49b460
#include "pc2_port.h"

void __cdecl CompanyMarketShare_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057ca90,4);
  CRT_Istream_Read(arg1,&DAT_005689f0,1);
  return;
}
