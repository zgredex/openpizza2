// WarehouseProduct_Save: ported from Pizza Connection 2 at 0x4c0d60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4c0d60
#include "pc2_port.h"

void __cdecl WarehouseProduct_Save(void *arg1)

{
  CRT_Ostream_Write(arg1,&DAT_0057d714,4);
  return;
}
