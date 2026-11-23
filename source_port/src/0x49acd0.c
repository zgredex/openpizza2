// AdvertisingPanel_Load: ported from Pizza Connection 2 at 0x49acd0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49acd0
#include "pc2_port.h"

void __cdecl AdvertisingPanel_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057ca30,4);
  CRT_Istream_Read(arg1,&DAT_0057ca34,4);
  return;
}
