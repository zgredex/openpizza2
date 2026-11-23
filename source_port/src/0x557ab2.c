// FUN_00557ab2: ported from Pizza Connection 2 at 0x557ab2.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x557ab2
#include "pc2_port.h"

uint32_t * __cdecl FUN_00557ab2(uint32_t *arg1)

{
  size_t svalue1;
  uint32_t *uptr2;
  
  if (arg1 != (uint32_t *)0x0) {
    svalue1 = _strlen((char *)arg1);
    uptr2 = _malloc(svalue1 + 1);
    if (uptr2 != (uint32_t *)0x0) {
      uptr2 = _strcpy(uptr2,arg1);
      return uptr2;
    }
  }
  return (uint32_t *)0x0;
}
