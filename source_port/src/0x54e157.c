// CRT_AtoiThunk: ported from Pizza Connection 2 at 0x54e157.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e157
#include "pc2_port.h"

void __thiscall CRT_AtoiThunk(void *self,uint8_t *arg1)

{
  CRT_Atoi(self,arg1);
  return;
}
