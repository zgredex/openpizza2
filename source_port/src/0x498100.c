// CityCompanyList_Load: ported from Pizza Connection 2 at 0x498100.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x498100
#include "pc2_port.h"

void __cdecl CityCompanyList_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057c9fc,4);
  CRT_Istream_Read(arg1,&DAT_0057ca00,4);
  return;
}
