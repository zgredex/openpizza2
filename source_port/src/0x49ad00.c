// AdvertisingPanel_Save: ported from Pizza Connection 2 at 0x49ad00.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49ad00
#include "pc2_port.h"

void __cdecl AdvertisingPanel_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057ca30,4);
  CRT_Ostream_Write(arg1,&DAT_0057ca34,4);
  return;
}
