// RecordMap_Lookup1998: ported from Pizza Connection 2 at 0x47f400.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47f400
#include "pc2_port.h"

void __thiscall RecordMap_Lookup1998(void *self,int arg1)

{
  IDMap_Lookup((void *)((intptr_t)self + 0x1998),arg1,(int *)0x0);
  return;
}
