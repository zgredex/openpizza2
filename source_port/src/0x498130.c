// CityCompanyList_Save: ported from Pizza Connection 2 at 0x498130.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498130
#include "pc2_port.h"

void __cdecl CityCompanyList_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057c9fc,4);
  CRT_Ostream_Write(arg1,&DAT_0057ca00,4);
  return;
}
