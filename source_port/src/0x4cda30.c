// NameMap_GetString: ported from Pizza Connection 2 at 0x4cda30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cda30
#include "pc2_port.h"

uint8_t * __cdecl NameMap_GetString(void *arg1,int arg2)

{
  uint8_t *uptr1;
  
  uptr1 = (uint8_t *)IDMap_Lookup(arg1,arg2,(int *)0x0);
  if (uptr1 == (uint8_t *)0x0) {
    uptr1 = &DAT_00568310;
  }
  return uptr1;
}
