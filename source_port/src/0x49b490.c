// CompanyMarketShare_Save: ported from Pizza Connection 2 at 0x49b490.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49b490
#include "pc2_port.h"

void __cdecl CompanyMarketShare_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057ca90,4);
  CRT_Ostream_Write(arg1,&DAT_005689f0,1);
  return;
}
