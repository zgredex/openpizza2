// Branch_SetName: ported from Pizza Connection 2 at 0x481010.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x481010
#include "pc2_port.h"

void __thiscall Branch_SetName(void *self,char *arg1)

{
  char cVar1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  char *cptr4;
  char *cptr5;
  
  uvalue2 = 0xffffffff;
  do {
    cptr5 = arg1;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr5 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr5;
  } while (cVar1 != '\0');
  uvalue2 = ~uvalue2;
  cptr4 = cptr5 + -uvalue2;
  cptr5 = self;
  for (uvalue3 = uvalue2 >> 2; cptr5 = cptr5 + 4, uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *(uint32_t *)cptr5 = *(uint32_t *)cptr4;
    cptr4 = cptr4 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr5 = *cptr4;
    cptr4 = cptr4 + 1;
    cptr5 = cptr5 + 1;
  }
  Game_UpdateObjectMapMarker(*(int *)((intptr_t)self + 0x16f0));
  return;
}
