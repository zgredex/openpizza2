// CompanyOverview_Save: ported from Pizza Connection 2 at 0x4b3ce0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b3ce0
#include "pc2_port.h"

void __cdecl CompanyOverview_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0056a7d4,4);
  CRT_Ostream_Write(arg1,&DAT_0057d69c,4);
  CRT_Ostream_Write(arg1,&DAT_0056a734,9);
  return;
}
