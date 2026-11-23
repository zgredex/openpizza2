// Array_GetRecordField40: ported from Pizza Connection 2 at 0x52ff30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ff30
#include "pc2_port.h"

uint32_t __thiscall Array_GetRecordField40(void *self,int arg1)

{
  int value1;
  
  value1 = Array_GetRecordByKey(self,arg1);
  if (value1 == 0) {
    return 0xffffffff;
  }
  return *(uint32_t *)(value1 + 0x40);
}
