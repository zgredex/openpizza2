// UI_FindFontByName: ported from Pizza Connection 2 at 0x526f60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526f60
#include "pc2_port.h"

uint8_t * __thiscall UI_FindFontByName(void *self,uint8_t *arg1)

{
  uint8_t *bptr1;
  uint32_t uvalue2;
  void *extraout_ECX;
  
                    /* Finds a cached font record by case-insensitive name. */
  bptr1 = *(uint8_t **)((intptr_t)self + 0x82c4);
  while( true ) {
    if (bptr1 == (uint8_t *)0x0) {
      return (uint8_t *)0x0;
    }
    uvalue2 = FUN_005570c0(self,bptr1,arg1);
    if (uvalue2 == 0) break;
    bptr1 = *(uint8_t **)(bptr1 + 0x10c);
    self = extraout_ECX;
  }
  return bptr1;
}
