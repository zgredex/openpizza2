// CRT_SetDefaultPrecision: ported from Pizza Connection 2 at 0x55196f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x55196f
#include "pc2_port.h"

void __fastcall CRT_SetDefaultPrecision(void *arg1)

{
                    /* Sets the x87 control uint16_t to 53-bit precision. */
  FUN_0055563a(arg1,0x10000,0x30000);
  return;
}
