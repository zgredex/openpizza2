// NameMap_GetRecordString: ported from Pizza Connection 2 at 0x4cda50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cda50
#include "pc2_port.h"

uint8_t * __cdecl NameMap_GetRecordString(void *arg1,int arg2)

{
  int value1;
  
  value1 = IDMap_Lookup(arg1,arg2,(int *)0x0);
  if (value1 == 0) {
    return &DAT_00568310;
  }
  return (uint8_t *)(value1 + 0x40);
}
