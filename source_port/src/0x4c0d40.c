// WarehouseProduct_Load: ported from Pizza Connection 2 at 0x4c0d40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0d40
#include "pc2_port.h"

void __cdecl WarehouseProduct_Load(void *arg1)

{
  CRT_Istream_Read(arg1,&DAT_0057d714,4);
  return;
}
