// Array_GetRecordByKeyPtr: ported from Pizza Connection 2 at 0x52ff20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ff20
#include "pc2_port.h"

void __thiscall Array_GetRecordByKeyPtr(void *self,int arg1)

{
  Array_GetRecordByKey(self,arg1);
  return;
}
